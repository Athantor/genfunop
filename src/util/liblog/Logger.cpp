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
 * Logger.cpp
 *
 *  Created on: 2009-05-15
 *      Author: athantor
 */

#include "Logger.h"

namespace util
{
	namespace logging
	{

		Logger::Logger( shared_ptr<Formatter> fmt, uint16_t lvl) : verb_lvl(lvl), formatter(fmt)
		{
			// TODO Auto-generated constructor stub

		}

		Logger::~Logger()
		{
			// TODO Auto-generated destructor stub
		}

	    Logger & Logger::operator <<(const Msg & msg)
	    {
	    	return do_output(msg);
	    }

	}
}
