/*
 * World_3df.h
 *
 *  Created on: 2009-05-09
 *      Author: Krzys
 */

#ifndef WORLD_3DF_H_
#define WORLD_3DF_H_

#include <vector>
#include <boost/any.hpp>
#include <cmath>

#include "World.h"

using boost::any;

class World_3df: public World {
public:
	World_3df();
	virtual ~World_3df();

	virtual void Evaluate_fitness();
	//virtual fitfun_t get_fitfun() const;

protected:
	static double fun3d(const std::vector<any>&);

};

#endif /* WORLD_3DF_H_ */