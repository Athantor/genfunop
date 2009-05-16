/*
 * Population.cpp
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#include "Population.h"

Population::Population( World * w, size_t creatno ) :
	world(w)
{
	for(size_t i = 0; i < creatno; ++i)
	{
		creats.push_back(boost::shared_ptr<Creature>(new Creature(this)));
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

const Population::creat_t& Population::get_creatures() const
{
	return creats;
}


boost::shared_ptr<Population> Population::perform_selection(SEL_TYPE sel)
{
	switch(sel)
	{
		case S_TOURNAMENT:
			return tournament_selection();
			break;
		default:
			throw std::runtime_error("Unknown selection type");
			break;
	}
}

boost::shared_ptr<Population> Population::tournament_selection(size_t k)
{
	boost::shared_ptr<Population> newpop( new Population(world, 0) );

	for(size_t i = 0; i < creats.size(); i += k)
	{

	}

	return newpop;

}
