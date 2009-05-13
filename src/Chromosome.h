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

static inline uint64_t frand( uint64_t max = RAND_MAX )
{
	return static_cast<double> (rand()) / ((static_cast<double> (RAND_MAX) + 1.0) / (static_cast<double> (max)));
}

class Chromosome
{
	public:
		Chromosome();
		virtual ~Chromosome();

		const size_t CHROMOSOME_SIZE;

		typedef std::vector<std::bitset<CHROMSIZE> > gene_t;

		bool get_gene( size_t, size_t ) const;
		void set_gene( size_t, size_t, bool );
		void set_gene( size_t, gene_t::value_type );

		void Randomize_gene( size_t );
		void Randomize_genes();

		void add_gene( gene_t::value_type = 0 );
		gene_t::value_type del_gene( size_t );

	protected:
		gene_t genes;
};

#endif /* CHROMOSOME_H_ */
