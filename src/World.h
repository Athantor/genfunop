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
		typedef std::vector<pop_t> oldpop_t;

		enum SEL_TYPE
		{
			S_TOURNAMENT
		};

		virtual double Evaluate_fitness(size_t) = 0;

		virtual const pop_t& Get_pop()
		{
			return pops;
		}

		virtual const oldpop_t& Get_oldpops()
		{
			return oldpops;
		}

		virtual void swap_pop( pop_t& pop )
		{
			oldpops.push_back(pops);

			pops.clear();
			pops = pop;
		}

		virtual fitfun_t get_fitfun() const
		{
			return fitfun;
		}

		boost::shared_ptr<util::logging::File_logger> get_log() const
		{
			return LOGFILE;
		}

		virtual void tng() = 0;

	protected:

		virtual void perform_selection( boost::shared_ptr<Population>&,  boost::shared_ptr<Population>& , SEL_TYPE = S_TOURNAMENT ) = 0;
		virtual void tournament_selection( boost::shared_ptr<Population>&, boost::shared_ptr<Population>& ) = 0;
		virtual void save_elite( shared_ptr<Population>& , boost::shared_ptr<Population>& ) = 0;

		pop_t pops;
		oldpop_t oldpops;
		fitfun_t fitfun;

		boost::shared_ptr<util::logging::File_logger> LOGFILE;

};

#endif /* WORLD_H_ */
