/*
 *  This file is part of genfunop.
 *
 *  genfunop is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  genfunop is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *   along with genfunop.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Datetime_formatter.cpp
 *
 *  Created on: 2009-05-15
 *      Author: athantor
 */

#include "Datetime_formatter.h"

namespace util
{

	namespace logging
	{

		Datetime_formatter::Datetime_formatter(const std::string & f) : format(f)
		{
		}

		Datetime_formatter::~Datetime_formatter()
		{
		}

	    std::string Datetime_formatter::do_formatting(const Msg & msg)
	    {

	    	timeval tv;
	    	tm ttm;
	    	char buf[128] = "";

	    	gettimeofday(&tv, 0);
	    	ttm = *localtime(&tv.tv_sec);

	    	strftime(buf, sizeof(buf), format.c_str(), &ttm  ) ;

	    	//return boost::posix_time::to_iso_string(boost::posix_time::ptime(boost::posix_time::microsec_clock::local_time())) + ": " + msg.getMsg_txt();

	    	return std::string( buf ) + "." + boost::lexical_cast<std::string>(tv.tv_usec) + ": " + msg.getMsg_txt();
	    }

	}

}
