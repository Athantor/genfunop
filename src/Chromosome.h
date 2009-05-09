/*
 * Chromosome.h
 *
 *  Created on: 2009-05-09
 *      Author: Krzys
 */

#ifndef CHROMOSOME_H_
#define CHROMOSOME_H_

#include <vector>
#include <stdint.h>

class Chromosome {
public:
	Chromosome();
	virtual ~Chromosome();

	typedef std::vector<uint64_t> gene_t;

protected:
	gene_t genes;
};

#endif /* CHROMOSOME_H_ */
