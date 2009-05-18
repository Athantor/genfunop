/*
 * Population.h
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include <vector>
#include <cstddef>
#include <cfloat> //dbl_eps
#include <set>

#include <boost/shared_ptr.hpp>

#include "World.h"
#include "Creature.h"
#include "Chromosome.h" // frand
using boost::shared_ptr;

inline bool probability( double p = 0.5 )
{
	double prob = p;

	if(p < (0 + DBL_EPSILON))
		prob = 0.0;
	if(p > (1 - DBL_EPSILON))
		prob = 1.0;

	return frand(100) < (prob * 100.0);
}

class Creature;
class World;
class Population
{
	public:

		Population( World * w, size_t = 100, size_t = 2 );
		virtual ~Population();

		const size_t ELITE_SIZE;

		typedef std::vector<shared_ptr<Creature> > creat_t;
		typedef std::vector<double > creatfitdict_t;

		virtual void add_creature(const Creature&);

		virtual double Evaluate_fitness();

		const World * get_world() const;
		const creat_t& get_creatures() const;
		const creatfitdict_t& get_creatures_fdict() const;

	protected:

		World * world;
		creat_t creats;
		creatfitdict_t fitdict;
};

#endif /* POPULATION_H_ */
