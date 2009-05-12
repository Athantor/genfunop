/*
 * Chromosome.cpp
 *
 *  Created on: 2009-05-09
 *      Author: Krzys
 */

#include "Chromosome.h"

Chromosome::Chromosome()
{
	// TODO Auto-generated constructor stub

}

Chromosome::~Chromosome()
{
	// TODO Auto-generated destructor stub
}

bool Chromosome::get_gene( size_t chrom, size_t gene ) const
{
	return (genes[chrom] >> gene) & 0x1;
}

void Chromosome::set_gene( size_t chrom, size_t gene, bool gval )
{
	gene_t::value_type tmp = gval;

	if(!gval)
		genes[chrom] &= ~(tmp << gene);
	else
		genes[chrom] |= (tmp << gene);
}

void Chromosome::set_gene( size_t chrom, gene_t::value_type newval )
{
	genes[chrom] = newval;
}

void Chromosome::add_chrom( gene_t::value_type newval )
{
	genes.push_back(newval);
}

/**
 * @brief randomizes genes
 */
void Chromosome::Randomize_genes()
{
	timeval tv = { 0, 0 };
	gettimeofday(&tv, 0);

	srandom(tv.tv_sec + tv.tv_usec);

	for(size_t i = 0; i < genes.size(); ++i)
	{
		Randomize_gene(i);
	}

}

void Chromosome::Randomize_gene( size_t chrom )
{
	genes[chrom] = 0;
	for(size_t j = 0; j < (sizeof(gene_t::value_type) / sizeof(uint32_t)); ++j)
	{
		genes[chrom] |= static_cast<uint32_t> (random());
		genes[chrom] <<= 32;
	}
}

Chromosome::gene_t::value_type Chromosome::del_chrom( size_t chromno )
{
	gene_t::value_type ret = genes[chromno];
	genes.erase(genes.begin() + chromno);

	return ret;
}

