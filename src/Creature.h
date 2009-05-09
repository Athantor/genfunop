/*
 * Creature.h
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include <vector>

#include "Chromosome.h"

class Creature
{
	public:
		Creature();
		virtual ~Creature();

		typedef std::vector<Chromosome> chroms_t;

	protected:
		chroms_t chroms;

};

#endif /* CREATURE_H_ */
