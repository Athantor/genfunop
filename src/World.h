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
#include <cstddef>

#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>

#include "Population.h"
#include "util/liblog/File_logger.h"

using boost::any;
using boost::shared_ptr;

class Population;
class World
{
	public:
		World();
		virtual ~World();

		typedef double (*fitfun_t)( const std::vector<any>& );
		typedef std::vector<shared_ptr<Population> > pop_t;

		virtual double Evaluate_fitness() = 0;

		virtual const pop_t& Get_pop()
		{
			return pops;
		}

		virtual fitfun_t get_fitfun() const
		{
			return fitfun;
		}

		boost::shared_ptr<util::logging::File_logger> get_log() const
		{
			return LOGFILE;
		}

	protected:
		pop_t pops;
		fitfun_t fitfun;

		boost::shared_ptr<util::logging::File_logger> LOGFILE;

};

#endif /* WORLD_H_ */
