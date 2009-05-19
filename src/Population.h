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
using boost::shared_ptr;


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

		virtual void breed_creatures(size_t, size_t, size_t);
		virtual size_t mutate( size_t, double);
		virtual void inverse(size_t, size_t, size_t);

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
