/*
 * Chromosome.h
 *
 *  Created on: 2009-05-09
 *      Author: Krzys
 */

#ifndef CHROMOSOME_H_
#define CHROMOSOME_H_

#include <vector>
#include <boost/cstdint.hpp>
#include <cstddef>
#include <sys/time.h> //gettimeofday
#include <bitset>
#include <stdexcept>

static inline uint64_t frand( uint64_t max = RAND_MAX )
{
	return static_cast<double> (rand()) / ((static_cast<double> (RAND_MAX) + 1.0) / (static_cast<double> (max)));
}

class Chromosome
{
	public:
		Chromosome(size_t = CHROMSIZE/2);
		virtual ~Chromosome();

		const size_t CHROMOSOME_SIZE;
		const size_t ALLELE_SIZE;

		typedef std::bitset<CHROMSIZE> gene_t;
		typedef std::vector< gene_t > genes_t;

		bool get_gene( size_t, size_t ) const;
		void set_gene( size_t, size_t, bool );
		void set_gene( size_t, genes_t::value_type );

		void Randomize_gene( size_t );
		void Randomize_genes();

		void add_gene( genes_t::value_type = 0 );
		genes_t::value_type del_gene( size_t );

		gene_t get_allele(size_t = 0, size_t = 0) const;


	protected:
		genes_t genes;
};

#endif /* CHROMOSOME_H_ */
