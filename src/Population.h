/*
 * Population.h
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include <boost/weak_ptr.hpp>

#include "World.h"
#include "Creature.h"

#include <vector>

using boost::weak_ptr;

class World;
class Population
{
	public:
		Population(weak_ptr<World> w);
		virtual ~Population();

		typedef std::vector<Creature> creat_t;

		virtual void Evaluate_fitness();

	protected:
		weak_ptr<World> world;
		creat_t creats;
};

#endif /* POPULATION_H_ */
