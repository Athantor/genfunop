/*
 * genfunop.cc
 *
 *  Created on: 2009-05-09
 *      Author: athantor
 *
 *      Licensed under GPLv3
 */

#include <iostream>
#include <cstdlib>
#include <cstddef>

#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>

#include "World.h"
#include "World_3df.h"


int main( int argc, char **argv )
{
	if(argc != 3)
	{
		std::cerr << "Zla ilosc argumentow: " << argc << std::endl << "Uzycie: " << std::endl << argv[0]
				<< " 'rozmiar_pop' 'ilosc_pokolen'" << std::endl;

		std::exit(1);
	}

	size_t pops = 0, geners = 0;
	try
	{
		pops = boost::lexical_cast<size_t>(argv[1]);
	}
	catch(const boost::bad_lexical_cast & exc)
	{
		std::cerr << "Niepoprawny rozmiar populacji: '" << argv[1] << "'" << std::endl;
	}

	try
	{
		geners = boost::lexical_cast<size_t>(argv[2]);
	}
	catch(const boost::bad_lexical_cast & exc)
	{
		std::cerr << "Niepoprawna ilosc pokolen: '" << argv[2] << "'" << std::endl;
	}

	boost::shared_ptr<World> world(new World_3df(1, pops));

	*(world->get_log()) << (std::string(60, '=') + " START ===");

	world->Evaluate_fitness(0);

	for(size_t gens = 0; gens < geners; ++gens)
	{
		world->tng();
		world->Evaluate_fitness(gens+1);
	}


	*(world->get_log()) << (std::string(60, '=') + "  STOP ===");

}
