/*
 * Creature.h
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include <vector>
#include <utility>
#include <cmath>
#include <cstddef>
#include <stdint.h>

#include <boost/shared_ptr.hpp>
#include <boost/operators.hpp>

#include "Population.h"
#include "Chromosome.h"

extern inline uint64_t frand( uint64_t );

class Chromosome;
class Population;
class Creature : boost::less_than_comparable<Creature>, boost::less_than_comparable<Creature, boost::shared_ptr<
		Creature> >
{
	public:
		Creature( Population *, size_t = 1 );
		virtual ~Creature();

		typedef std::vector<boost::shared_ptr<Chromosome> > chroms_t;
		typedef std::pair<double, double> domain_t;

		void set_bounds( domain_t::first_type, domain_t::second_type );
		const domain_t& get_bounds() const;

		double get_phenotype( size_t, size_t, size_t = 0 ) const;

		virtual double Evaluate_fitness();

		void kill( bool = true );
		bool is_dead() const;

		bool is_elite() const;
		void set_elite( bool );

		bool operator<( const Creature& ) const;
		bool operator<( const boost::shared_ptr<Creature>& ) const;
		bool operator>( const boost::shared_ptr<Creature>& ) const;

		inline double get_fitness() const
		{
			return fitness;
		}

		const chroms_t& get_chroms() const
		{
			return chroms;
		}

		uint64_t get_serial_no() const
		{
			return SERIALNO;
		}

		virtual void make_sweet_sweet_love( Creature &, size_t = frand(CHROMSIZE - 1) );
		virtual size_t mutate( double );
		virtual void inverse( size_t, size_t );

	protected:

		double make_fitness();

		chroms_t chroms;
		domain_t domain;

		double fitness;

		Population* pntpop;

		bool dead; ///< denotes if creature is part of next generation
		bool elite;
		const uint64_t SERIALNO;

	private:
		static uint64_t SERIALCTR;
};

#endif /* CREATURE_H_ */

