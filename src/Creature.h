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
#include <cstddef>

#include <boost/shared_ptr.hpp>

#include "Population.h"
#include "Chromosome.h"

class Chromosome;
class Population;
class Creature
{
	public:
		Creature(Population *, size_t = 1);
		virtual ~Creature();

		typedef std::vector<boost::shared_ptr<Chromosome> > chroms_t;
		typedef std::pair<double, double> domain_t;

		void set_bounds(domain_t::first_type, domain_t::second_type);
		const domain_t& get_bounds() const;

		double get_phenotype(size_t , size_t, size_t = 0 ) const;

		virtual double Evaluate_fitness() ;

	protected:
		chroms_t chroms;
		domain_t domain;

		Population* pntpop;

};

#endif /* CREATURE_H_ */
