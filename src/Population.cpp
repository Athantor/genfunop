/*
 * Population.cpp
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#include "Population.h"

Population::Population(World * w, size_t creatno) : world(w)
{
	for(size_t i = 0; i < creatno; ++i)
	{
		creats.push_back( boost::shared_ptr<Creature>(new Creature(this)) );
	}
}

Population::~Population()
{
	// TODO Auto-generated destructor stub
}

double Population::Evaluate_fitness()
{
	double ret = 0;
	for(creat_t::iterator it = creats.begin(); it != creats.end(); ++it)
	{
		ret += (*it)->Evaluate_fitness();
	}

	return ret;
}

const World * Population::get_world() const
{
	return world;
}
