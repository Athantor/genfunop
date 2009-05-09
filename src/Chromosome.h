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

class Chromosome {
public:
	Chromosome();
	virtual ~Chromosome();

	typedef std::vector<uint64_t> gene_t;

	bool get_gene(size_t, size_t) const;
	void set_gene(size_t, size_t, bool);
	void set_gene(size_t, gene_t::value_type);

	void add_chrom(gene_t::value_type = 0);
	gene_t::value_type del_chrom(size_t);

protected:
	gene_t genes;
};

#endif /* CHROMOSOME_H_ */
