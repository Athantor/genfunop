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
 * File_logger.cpp
 *
 *  Created on: 2009-05-15
 *      Author: athantor
 */

#include "File_logger.h"

namespace util
{

	namespace logging
	{

		File_logger::File_logger( const std::string& p, shared_ptr<Formatter> fmt, uint16_t l ) :
			Ostream_logger(fmt, l), logfile_path(p), logfile(new std::ofstream())
		{
			logfile->exceptions(std::ofstream::eofbit | std::ofstream::failbit | std::ofstream::badbit);

			try
			{
				logfile->open(logfile_path.c_str(), std::ofstream::app);

				set_stream(logfile);
			}
			catch(const std::ofstream::failure &e)
			{
				throw std::ofstream::failure("Error opening log file '" + p + "': " + e.what());
			}

		}

		File_logger::~File_logger()
		{
			logfile->flush();
			logfile->close();
		}

		std::string File_logger::getLogfile_path() const
		{
			return logfile_path;
		}

	}

}
