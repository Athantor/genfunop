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
 * Logger.h
 *
 *  Created on: 2009-05-15
 *      Author: athantor
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <boost/shared_ptr.hpp>

#include <stdint.h>

#include "Formatter.h"
#include "Msg.h"

using boost::shared_ptr;

namespace util
{
	namespace logging
	{
		class Logger
		{
			public:
				Logger( shared_ptr<Formatter> , uint16_t = 0x7F );
				virtual ~Logger();

				virtual Logger& do_output( const Msg& ) = 0;
				virtual Logger& operator<<( const Msg& );

			protected:
				uint16_t verb_lvl;
				shared_ptr<Formatter> formatter;

		};

	}
}
#endif /* LOGGER_H_ */
