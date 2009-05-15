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
 * Raw_formatter.cpp
 *
 *  Created on: 2009-05-15
 *      Author: athantor
 */

#include "Raw_formatter.h"

namespace util
{

	namespace logging
	{

		Raw_formatter::Raw_formatter()
		{
			// TODO Auto-generated constructor stub

		}

		Raw_formatter::~Raw_formatter()
		{
			// TODO Auto-generated destructor stub
		}

	    std::string Raw_formatter::do_formatting(const Msg & msg)
	    {
	    	return msg.getMsg_txt();
	    }

	}

}
