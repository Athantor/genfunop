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
		pops.push_back(boost::shared_ptr<Population>(new Population(this, popsize)));
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

double World_3df::Evaluate_fitness( size_t genno )
{
	double ret = 0, tmp = 0;
	size_t ctr = 0;
	for(pop_t::iterator it = pops.begin(); it != pops.end(); ++it)
	{
		tmp = (*it)->Evaluate_fitness();

		(*get_log()) << util::logging::Msg(std::string(15, '-')) + "[" + static_cast<long long> (genno)
				+ "]: Fitnes populacji nr " + static_cast<long long> (ctr) + " ("
				+ static_cast<long long> ((*it)->get_creatures().size()) + ")  = " + tmp;

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

		boost::shared_ptr<Population> newpop(new Population(this, 0, (*it)->ELITE_SIZE));
		save_elite(*it, newpop);
		perform_selection(*it, newpop);

	}
}

void World_3df::perform_selection( boost::shared_ptr<Population>& src, boost::shared_ptr<Population>& dst, SEL_TYPE sel )
{

	//save_elite(src, dst);

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
	//assumes that elite has been saved before this
	const size_t start = dst->get_creatures().size();
	const size_t stop = src->get_creatures().size();

	(*get_log()) << "Selekcja turniejowa...";

	std::vector<uint64_t> srl(start);
	for(size_t i = 0; i < start; ++i)
	{
		srl.push_back(dst->get_creatures()[0]->get_serial_no());
	}

	/*
	 * Creates array with three random indexes, then array with  fitness values of creatures t corresponding
	 * indexes, then finds maximum element in that, computes index value from distance and finally ads the creature
	 *
	 * Checks if drawn creature doesn't belong to elite
	 */
	for(size_t i = 0; i < stop; ++i)
	{
		const size_t WAT = 3; //< for control
		boost::shared_ptr<Creature> tmpc;
		size_t dist = 0;
		size_t idxxx;

		do
		{
			size_t idx[WAT] = { frand(stop), frand(stop), frand(stop) };

			double ivals[WAT] = { src->get_creatures_fdict()[idx[0]], src->get_creatures_fdict()[idx[1]],
					src->get_creatures_fdict()[idx[2]] };

			dist = std::distance(ivals, std::max_element(ivals, ivals + WAT));
			tmpc = src->get_creatures()[idx[dist]];
			idxxx = idx[dist];

		} while(std::find(srl.begin(), srl.end(), tmpc->get_serial_no()) != srl.end());

		dst->add_creature(*tmpc);

		(*get_log()) << util::logging::Msg("...Zachowano stwora z pozycji [") + static_cast<long long> (idxxx)
				+ "]: x1 = " + tmpc->get_phenotype(0, 0, 0) + "; x2 = " + tmpc->get_phenotype(0, 0,
				tmpc->get_chroms()[0]->ALLELE_SIZE) + "; fitness: " + tmpc->get_fitness();

	}
	(*get_log()) << "Już...";

}

void World_3df::save_elite( shared_ptr<Population>& src, boost::shared_ptr<Population>& dst )
{
	Population::creatfitdict_t tmp(src->get_creatures_fdict());
	Population::creat_t tmps(src->get_creatures());

	(*get_log()) << "Zachowuję elity...";

	for(size_t i = 0; i < src->ELITE_SIZE; ++i)
	{
		Population::creatfitdict_t::iterator mxit = max_element(tmp.begin(), tmp.end());
		size_t dist = std::distance(tmp.begin(), mxit);

		(*get_log()) << util::logging::Msg("...Zachowano stwora z pozycji [") + static_cast<long long> (dist)
				+ "]: x1 = " + tmps[dist]->get_phenotype(0, 0, 0) + "; x2 = " + tmps[dist]->get_phenotype(0, 0,
				tmps[dist]->get_chroms()[0]->ALLELE_SIZE) + "; fitness: " + tmps[dist]-> get_fitness();

		dst->add_creature(*tmps[dist]);

		tmps.erase(tmps.begin() + dist);
		tmp.erase(tmp.begin() + dist);
	}

	(*get_log()) << "Już";
}

