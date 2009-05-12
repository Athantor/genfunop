/*
 * World_3df.cpp
 *
 *  Created on: 2009-05-09
 *      Author: Krzys
 */

#include "World_3df.h"

World_3df::World_3df() {
	fitfun = &fun3d;
}

World_3df::~World_3df() {
	// TODO Auto-generated destructor stub
}

double World_3df::fun3d(const std::vector<any>& args)
{
	double x = boost::any_cast<double>(args[0]);
	double y = boost::any_cast<double>(args[1]);

	double z1 = ( std::pow( std::sin( std::sqrt( std::pow(x,2) + std::pow(y,2) ) ), 2) )  - 0.5;
	double z2 = std::pow( ( 1.0 + 0.001 * (std::pow(x,2) + std::pow(y,2) ) ), 2) ;

	return 0.5 + (z1/z2);
}

/*World_3df::fitfun_t World_3df::get_fitfun() const
{
	return &fun3d;
}*/

void World_3df::Evaluate_fitness()
{
}