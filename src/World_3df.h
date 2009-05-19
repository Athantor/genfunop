/*
 * World_3df.h
 *
 *  Created on: 2009-05-09
 *      Author: Krzys
 */

#ifndef WORLD_3DF_H_
#define WORLD_3DF_H_

#include <vector>
#include <cmath>
#include <stdexcept>
#include <iterator>
#include <utility>
#include <algorithm>
#include <functional>

#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>


#include "World.h"

using boost::any;

class World_3df : public World
{
	public:
		World_3df( size_t = 1, size_t = 100 );
		virtual ~World_3df();

		virtual double Evaluate_fitness(size_t);
		//virtual fitfun_t get_fitfun() const;

		virtual void tng();

	protected:
		static double fun3d( const std::vector<any>& );

		virtual void perform_selection( boost::shared_ptr<Population>&,  boost::shared_ptr<Population>&, SEL_TYPE = S_TOURNAMENT );
		virtual void tournament_selection( boost::shared_ptr<Population>&, boost::shared_ptr<Population>& ) ;
		virtual void save_elite( shared_ptr<Population>& , boost::shared_ptr<Population>& );
		virtual void breed(shared_ptr<Population>& , boost::shared_ptr<Population>& ) ;
		virtual void mutate(shared_ptr<Population>& , boost::shared_ptr<Population>& );
		virtual void inverse(shared_ptr<Population>& , boost::shared_ptr<Population>& ) ;
};

#endif /* WORLD_3DF_H_ */
