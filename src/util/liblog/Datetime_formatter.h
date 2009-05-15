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
 * Datetime_formatter.h
 *
 *  Created on: 2009-05-15
 *      Author: athantor
 */

#ifndef DATETIME_FORMATTER_H_
#define DATETIME_FORMATTER_H_

#include <ctime>
#include <sys/time.h>

#include <boost/lexical_cast.hpp>

#include "Formatter.h"

namespace util
{

	namespace logging
	{

		class Datetime_formatter : public util::logging::Formatter
		{
			public:
				Datetime_formatter(const std::string & = std::string("%Y-%m-%dT%H:%M:%S%z") );
				virtual ~Datetime_formatter();

				virtual std::string do_formatting(const Msg&);
			protected:
				std::string format;
		};

	}

}

#endif /* DATETIME_FORMATTER_H_ */
