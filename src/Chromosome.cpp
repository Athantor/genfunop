/*
 * Chromosome.cpp
 *
 *  Created on: 2009-05-09
 *      Author: Krzys
 */

#include "Chromosome.h"

Chromosome::Chromosome( size_t as ) :
	CHROMOSOME_SIZE(CHROMSIZE), ALLELE_SIZE(as)
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

Chromosome::gene_t Chromosome::get_allele( size_t gene , size_t bstart ) const
{
	gene_t tmp(std::string(ALLELE_SIZE, '1'));
	tmp <<= bstart;
	tmp &= genes[gene];
	tmp >>= bstart;

	return tmp;

}

