/*
 * Creature.cpp
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#include "Creature.h"

Creature::Creature( Population * pop, size_t chromnom ) :
	pntpop(pop)
{
	for(size_t i = 0; i < chromnom; ++i)
	{
		chroms.push_back(shared_ptr<Chromosome> (new Chromosome()));
	}

	set_bounds(-10, 10);
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

	double ret = 0, tmp = 0;

	for(size_t h = 0; h < chroms.size(); ++h)
	{
		boost::shared_ptr<Chromosome> chr = chroms[h];

		for(size_t i = 0; i < chr->get_genes().size(); ++i)
		{
			double x1 = get_phenotype(h, i, 0), x2 = get_phenotype(0, 0, chr->ALLELE_SIZE);
			std::vector<any> av;
			av.push_back(x1);
			av.push_back(x2);

			tmp = (wld->get_fitfun())(av);

			(*wld->get_log()) << util::logging::Msg(chr->get_whole_chrom().to_string()) + " | "
					+ (long long) (chr->get_whole_chrom().to_ulong()) + " | " + x1 + " | " + x2 + " | "
					+ tmp ;

			ret += tmp;
		}
	}

	return ret;

}
