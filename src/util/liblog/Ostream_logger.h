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
 * Ostream_logger.h
 *
 *  Created on: 2009-05-15
 *      Author: athantor
 */

#ifndef OSTREAM_LOGGER_H_
#define OSTREAM_LOGGER_H_

#include <ostream>
#include <stdexcept>

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include "Logger.h"
#include "Formatter.h"
#include "Datetime_formatter.h"

using boost::shared_ptr;
using boost::weak_ptr;

namespace util
{

	namespace logging
	{

		class Ostream_logger : public util::logging::Logger
		{
			public:
				Ostream_logger(weak_ptr<std::ostream>, shared_ptr<Formatter> = shared_ptr<Formatter>(new Datetime_formatter()), uint16_t = 0x7F );
				virtual ~Ostream_logger();

				virtual Logger& do_output( const Msg& );
			protected:
				Ostream_logger(shared_ptr<Formatter> = shared_ptr<Formatter>(new Datetime_formatter()), uint16_t = 0x7F );
				void set_stream(weak_ptr<std::ostream>);
				weak_ptr<std::ostream> outstream;
		};

	}

}

#endif /* OSTREAM_LOGGER_H_ */
