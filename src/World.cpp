/*
 * World.cpp
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#include "World.h"

World::World() :
	LOGFILE(new util::logging::File_logger())
{
}

World::~World()
{
	// TODO Auto-generated destructor stub
}

void World::swap_pop( pop_t& pop )
{
	oldpops.push_back(pops);

	pops.clear();
	pops = pop_t(pop);
	//std::copy(pop.begin(), pop.end(), pops.begin());

}
