/*
 * Population.cpp
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#include "Population.h"

Population::Population( World * w, size_t creatno, size_t els ) :
	ELITE_SIZE(els), world(w)
{
	for(size_t i = 0; i < creatno; ++i)
	{
		boost::shared_ptr<Creature> nc(new Creature(this));
		creats.push_back(nc);
		fitdict.push_back(nc->get_fitness());

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

const Population::creatfitdict_t & Population::get_creatures_fdict() const
{
	return fitdict;
}

void Population::add_creature( const Creature& crt )
{
	boost::shared_ptr<Creature> nc(new Creature(crt));
	creats.push_back(nc);

	fitdict.push_back(nc->get_fitness());
}

void Population::breed_creatures( size_t c1, size_t c2, size_t x )
{
	creats.at(c1) -> make_sweet_sweet_love(*creats.at(c2), x);
}

size_t Population::mutate( size_t cr, double prob )
{
	return creats.at(cr)->mutate(prob);
}

void Population::inverse( size_t cr, size_t ip1, size_t ip2 )
{
	Population::creats.at(cr)->inverse(ip1, ip2);
}
