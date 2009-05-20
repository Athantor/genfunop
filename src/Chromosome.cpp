/*
 * Chromosome.cpp
 *
 *  Created on: 2009-05-09
 *      Author: Krzys
 */

#include "Chromosome.h"

Chromosome::Chromosome( size_t g, size_t as ) :
	CHROMOSOME_SIZE(CHROMSIZE), ALLELE_SIZE(as)
{
	for(size_t i = 0; i < g; ++i)
	{
		add_gene();
	}

	Randomize_genes();

}

Chromosome::~Chromosome()
{
	// TODO Auto-generated destructor stub
}

bool Chromosome::get_gene( size_t chrom, size_t gene ) const
{
	return genes[chrom][gene];
}

void Chromosome::set_gene( size_t chrom, size_t gene, bool gval )
{
	genes[chrom][gene] = gval;
}

void Chromosome::set_gene( size_t chrom, genes_t::value_type newval )
{
	genes[chrom] = newval;
}

void Chromosome::add_gene( genes_t::value_type newval )
{
	genes.push_back(newval);
}

/**
 * @brief randomizes genes
 */
void Chromosome::Randomize_genes()
{
	for(size_t i = 0; i < genes.size(); ++i)
	{
		Randomize_gene(i);
	}
}

void Chromosome::Randomize_gene( size_t chrom )
{
	timeval tv = { 0, 0 };
	gettimeofday(&tv, 0);

	srand(tv.tv_sec + tv.tv_usec);
	for(size_t i = 0; i < genes[chrom].size(); ++i)
	{
		genes[chrom][i] = frand() % 2;
	}

}

Chromosome::genes_t::value_type Chromosome::del_gene( size_t chromno )
{
	genes_t::value_type ret = genes[chromno];
	genes.erase(genes.begin() + chromno);

	return ret;
}

Chromosome::gene_t Chromosome::get_allele( size_t gene, size_t bstart ) const
{
	gene_t tmp(std::string(ALLELE_SIZE, '1'));
	tmp <<= bstart;
	tmp &= genes[gene];
	tmp >>= bstart;

	return tmp;
}

Chromosome::gene_t Chromosome::get_whole_chrom( size_t g ) const
{
	return genes[g];
}

const Chromosome::genes_t & Chromosome::get_genes() const
{
	return genes;
}

void Chromosome::crossover( boost::shared_ptr<Chromosome> & matechrom, size_t xpnt )
{
	if(genes.size() != matechrom->genes.size())
		throw std::runtime_error("Mate is frome different spiecies! Ewwww! Gene count in chromosome doesn't match!");

	for(genes_t::iterator it = genes.begin(); it != genes.end(); ++it)
	{
		for(size_t i = xpnt; i < CHROMOSOME_SIZE; ++i)
		{
			bool tmp= (*it)[i];
			(*it)[i] = matechrom->genes[std::distance(genes.begin(), it)][i];
			matechrom->genes[std::distance(genes.begin(), it)][i] = tmp;

		}
	}
}

size_t Chromosome::mutate( double prob )
{
	size_t flipctr = 0;
	for(genes_t::iterator it = genes.begin(); it != genes.end(); ++it)
	{
		for(size_t i = 0; i < CHROMOSOME_SIZE; ++i)
		{
			if(probability(prob))
			{
				it->flip(i);
				flipctr++;
			}
		}
	}

	return flipctr;
}

void Chromosome::inverse( size_t ip1, size_t ip2 )
{
	for(genes_t::iterator it = genes.begin(); it != genes.end(); ++it)
	{
		for(size_t i = ip1; i < ip2; ++i)
		{
			size_t ctr = i - ip1;

			bool tmp = (*it)[i];
			(*it)[i] = (*it)[ (ip2-1) - i];
			(*it)[ (ip2-1) - i] = tmp;
		}
	}
}
