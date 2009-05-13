/*
 * Creature.cpp
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#include "Creature.h"

Creature::Creature()
{
	// TODO Auto-generated constructor stub
}

Creature::~Creature()
{
	// TODO Auto-generated destructor stub
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
	Chromosome::gene_t al1 = chroms[chrom].get_allele(gene, off);

	return static_cast<double>( domain.first + al1.to_ulong() * ((domain.second - domain.first) / (exp2(chroms[chrom].ALLELE_SIZE) - 1)) );

}

