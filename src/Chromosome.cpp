/*
 * Chromosome.cpp
 *
 *  Created on: 2009-05-09
 *      Author: Krzys
 */

#include "Chromosome.h"

Chromosome::Chromosome() :
	CHROMOSOME_SIZE(CHROMSIZE)
{
	// TODO Auto-generated constructor stub

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

void Chromosome::set_gene( size_t chrom, gene_t::value_type newval )
{
	genes[chrom] = newval;
}

void Chromosome::add_gene( gene_t::value_type newval )
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

Chromosome::gene_t::value_type Chromosome::del_gene( size_t chromno )
{
	gene_t::value_type ret = genes[chromno];
	genes.erase(genes.begin() + chromno);

	return ret;
}

