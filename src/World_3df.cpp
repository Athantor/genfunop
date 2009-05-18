/*
 * World_3df.cpp
 *
 *  Created on: 2009-05-09
 *      Author: Krzys
 */

#include "World_3df.h"

World_3df::World_3df( size_t ps, size_t popsize )
{
	fitfun = &fun3d;

	for(size_t i = 0; i < ps; ++i)
	{
		pops.push_back(boost::shared_ptr<Population>(new Population(this, popsize, std::ceil(popsize * 0.05))));
	}

}

World_3df::~World_3df()
{
	// TODO Auto-generated destructor stub
}

double World_3df::fun3d( const std::vector<any>& args )
{
	double x = boost::any_cast<double>(args[0]);
	double y = boost::any_cast<double>(args[1]);

	double z1 = (std::pow(std::sin(std::sqrt(std::pow(x, 2) + std::pow(y, 2))), 2)) - 0.5;
	double z2 = std::pow((1.0 + 0.001 * (std::pow(x, 2) + std::pow(y, 2))), 2);

	return 0.5 + (z1 / z2);
}

/*World_3df::fitfun_t World_3df::get_fitfun() const
 {
 return &fun3d;
 }*/

double World_3df::Evaluate_fitness()
{
	double ret = 0, tmp = 0;
	size_t ctr = 0;
	for(pop_t::iterator it = pops.begin(); it != pops.end(); ++it)
	{
		tmp = (*it)->Evaluate_fitness();

		(*get_log()) << util::logging::Msg(std::string(15, '-') + " Fitnes populacji nr")
				+ static_cast<long long> (ctr) + " (" + static_cast<long long> ((*it)->get_creatures().size())
				+ ")  = " + tmp;

		ctr++;
		ret += tmp;

	}

	return ret;

}

void World_3df::tng()
{

	pop_t newpops(pops.size());

	for(pop_t::iterator it = pops.begin(); it != pops.end(); ++it)
	{
		//boost::shared_ptr<Population> selpop;
	}
}

void World_3df::perform_selection( boost::shared_ptr<Population>& src, boost::shared_ptr<Population>& dst, SEL_TYPE sel )
{

	save_elite(src, dst);

	switch(sel)
	{
		case S_TOURNAMENT:
			tournament_selection(src, dst);
			break;
		default:
			throw std::runtime_error("Unknown selection type");
			break;
	}

}

void World_3df::tournament_selection( boost::shared_ptr<Population>& src, boost::shared_ptr<Population>& dst )
{
	const size_t start = dst->get_creatures().size();
	const size_t stop = src->get_creatures().size();

	/*
	 * Creates array with three random indexes, then array with  fitness values of creatures t corresponding
	 * indexes, then finds maximum element in that, computes index value from distance and finally ads the creature
	 */
	for(size_t i = 0; i < stop - start; ++i)
	{
		const size_t WAT = 3; //< for control

		size_t idx[WAT] = { (start + frand(stop - start)), (start + frand(stop - start)), (start + frand(stop - start)) };
		double ivals[WAT] = { src->get_creatures_fdict()[idx[0]], src->get_creatures_fdict()[idx[1]],
				src->get_creatures_fdict()[idx[2]] };

		dst->add_creature(*(src->get_creatures()[idx[std::distance(ivals, std::max_element(ivals, ivals + WAT))]]));
	}

}

void World_3df::save_elite( shared_ptr<Population>& src, boost::shared_ptr<Population>& dst )
{
	Population::creatfitdict_t tmp(src->get_creatures_fdict());
	Population::creat_t tmps(src->get_creatures());

	for(size_t i = 0; i < src->ELITE_SIZE; ++i)
	{
		Population::creatfitdict_t::iterator mxit = max_element(tmp.begin(), tmp.end());
		size_t dist = std::distance(tmp.begin(), mxit);

		dst->add_creature(*tmps[dist]);
		tmps.erase(tmps.begin() + dist);
		tmp.erase(tmp.begin() + dist);
	}
}

