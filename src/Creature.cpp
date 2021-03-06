/*
 * Creature.cpp
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#include "Creature.h"

uint64_t Creature::SERIALCTR = 0;

Creature::Creature( Population * pop, size_t chromnom ) :
	pntpop(pop), dead(false), SERIALNO(++Creature::SERIALCTR)
{
	for(size_t i = 0; i < chromnom; ++i)
	{
		chroms.push_back(shared_ptr<Chromosome> (new Chromosome()));
	}

	set_bounds(-10, 10);
	fitness = make_fitness();
}

Creature::~Creature()
{
}

void Creature::set_bounds( domain_t::first_type lower, domain_t::second_type upper )
{
	domain = std::make_pair(lower, upper);
}

const Creature::domain_t & Creature::get_bounds() const
{
	return domain;
}

double Creature::get_phenotype( size_t chrom, size_t gene, size_t off ) const
{
	Chromosome::gene_t al1 = chroms[chrom]->get_allele(gene, off);

	return static_cast<double> (domain.first + al1.to_ulong() * ((domain.second - domain.first) / (exp2(
			chroms[chrom]->ALLELE_SIZE) - 1)));

}

double Creature::Evaluate_fitness()
{
	if(!pntpop)
		return 0;

	const World* wld = pntpop->get_world();
	if(!wld)
		return 0;

	for(size_t h = 0; h < chroms.size(); ++h)
	{
		boost::shared_ptr<Chromosome> chr = chroms[h];

		for(size_t i = 0; i < chr->get_genes().size(); ++i)
		{
			(*wld->get_log()) << util::logging::Msg(chr->get_whole_chrom().to_string()) + " | "
					+ (long long) (chr->get_whole_chrom().to_ulong()) + " | " + get_phenotype(h, i, 0) + " | "
					+ get_phenotype(h, i, chr->ALLELE_SIZE) + " | " + fitness;
		}
	}

	return fitness;
}

double Creature::make_fitness()
{
	if(!pntpop)
		return 0;

	const World* wld = pntpop->get_world();
	if(!wld)
		return 0;

	double ret = 0;

	for(size_t h = 0; h < chroms.size(); ++h)
	{
		boost::shared_ptr<Chromosome> chr = chroms[h];

		for(size_t i = 0; i < chr->get_genes().size(); ++i)
		{
			std::vector<any> av;
			av.push_back(get_phenotype(h, i, 0));
			av.push_back(get_phenotype(h, i, chr->ALLELE_SIZE));

			ret += (wld->get_fitfun())(av);
		}
	}

	return ret;

}

void Creature::kill( bool k )
{
	dead = k;
}
bool Creature::is_dead() const
{
	return dead;
}

bool Creature::operator<( const Creature& cr ) const
{
	return fitness < cr.fitness;
}

bool Creature::operator<( const boost::shared_ptr<Creature>& ptr ) const
{
	return fitness < ptr->fitness;
}

bool Creature::operator>( const boost::shared_ptr<Creature>& ptr ) const
{
	return fitness > ptr->fitness;
}

bool Creature::is_elite() const
{
	return elite;
}

void Creature::set_elite( bool e )
{
	elite = e;
}

void Creature::make_sweet_sweet_love( Creature & mate, size_t xpnt )
{
	if(chroms.size() != mate.chroms.size())
	{
		throw std::runtime_error("Mate has wrong number of chromosomes! Sick!");
	}

	for(chroms_t::iterator it = chroms.begin(); it != chroms.end(); ++it)
	{
		(*it)->crossover(mate.chroms[std::distance(chroms.begin(), it)], xpnt);
	}

	fitness = make_fitness();
	mate.fitness = make_fitness();
}

size_t Creature::mutate( double prob )
{
	size_t flipctr = 0;

	for(chroms_t::iterator it = chroms.begin(); it != chroms.end(); ++it)
	{
		flipctr += (*it)->mutate(prob);
	}

	if(flipctr)
		fitness = make_fitness();

	return flipctr;
}

void Creature::inverse( size_t ip1, size_t ip2 )
{
	for(chroms_t::iterator it = chroms.begin(); it != chroms.end(); ++it)
	{
		(*it)->inverse(ip1, ip2);
	}

	fitness = make_fitness();
}
