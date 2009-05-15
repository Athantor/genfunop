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
 * File_logger.h
 *
 *  Created on: 2009-05-15
 *      Author: athantor
 */

#ifndef FILE_LOGGER_H_
#define FILE_LOGGER_H_

#include <fstream>

#include <boost/shared_ptr.hpp>

#include "Ostream_logger.h"

using boost::shared_ptr;

namespace util
{

	namespace logging
	{

		class File_logger : public util::logging::Ostream_logger
		{
			public:
				File_logger( const std::string& = std::string("genfunop.log"), shared_ptr<Formatter> = shared_ptr<
						Formatter> (new Datetime_formatter()), uint16_t = 0x7F );
				virtual ~File_logger();

				std::string getLogfile_path() const;

			protected:
				const std::string logfile_path;
				shared_ptr<std::ofstream> logfile;
		};

	}

}

#endif /* FILE_LOGGER_H_ */
