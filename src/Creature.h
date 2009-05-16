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

		void kill(bool = true);
		bool is_dead() const;

	protected:

		double make_fitness();

		chroms_t chroms;
		domain_t domain;

		double fitness;

		Population* pntpop;

		bool dead; ///< denotes if creature is part of next generation

};

#endif /* CREATURE_H_ */
