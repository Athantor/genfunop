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

#include <boost/shared_ptr.hpp>

#include "World.h"
#include "Creature.h"

using boost::shared_ptr;

class Creature;
class World;
class Population
{
	public:
		Population(World * w, size_t = 100);
		virtual ~Population();

		typedef std::vector<shared_ptr<Creature> > creat_t;

		virtual double Evaluate_fitness();

		const World * get_world() const;

	protected:
		World * world;
		creat_t creats;
};

#endif /* POPULATION_H_ */
