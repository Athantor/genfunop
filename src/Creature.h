/*
 * Creature.h
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include <vector>
#include <utility>
#include <cmath>

#include "Chromosome.h"

class Creature
{
	public:
		Creature();
		virtual ~Creature();

		typedef std::vector<Chromosome> chroms_t;
		typedef std::pair<double, double> domain_t;

		void set_bounds(domain_t::first_type, domain_t::second_type);
		const domain_t& get_bounds() const;

		double get_phenotype(size_t , size_t, size_t = 0 ) const;

	protected:
		chroms_t chroms;
		domain_t domain;

};

#endif /* CREATURE_H_ */
