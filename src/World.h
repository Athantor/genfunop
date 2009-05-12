/*
 * World.h
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include <boost/any.hpp>

#include "Population.h"

using boost::any;

class Population;
class World
{
	public:
		World();
		virtual ~World();

		typedef double (*fitfun_t)(const std::vector<any>&);
		typedef std::vector<Population> pop_t;

		virtual void Evaluate_fitness() = 0;

		virtual const pop_t& Get_pop()
		{
			return pops;
		}

	protected:
		 pop_t pops;

};

#endif /* WORLD_H_ */
