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
 * Ostream_logger.cpp
 *
 *  Created on: 2009-05-15
 *      Author: athantor
 */

#include "Ostream_logger.h"

namespace util
{

	namespace logging
	{

		Ostream_logger::Ostream_logger( weak_ptr<std::ostream> os, shared_ptr<Formatter> fmt, uint16_t lvl ) :
			Logger(fmt, lvl), outstream(os)
		{

			if((os.expired()) or (static_cast<bool> (os.lock().get()) == false))
				throw std::runtime_error("pointer is null");
		}

		Ostream_logger::Ostream_logger( shared_ptr<Formatter> fmt, uint16_t l ) :
			Logger(fmt, l)
		{

		}

		Ostream_logger::~Ostream_logger()
		{
		}

		Logger& Ostream_logger::do_output( const Msg& msg )
		{
			if((msg.getMsg_lvl() & verb_lvl) != 0 and (not outstream.expired()))
			{
				shared_ptr<std::ostream> tout = outstream.lock();

				std::string fmtmsg = formatter->do_formatting(msg);
				tout->write(fmtmsg.c_str(), fmtmsg.size());
				std::endl(*tout);
			}

			return *this;

		}

		void Ostream_logger::set_stream( weak_ptr<std::ostream> os )
		{
			if((os.expired()) or (static_cast<bool> (os.lock().get()) == false))
				throw std::runtime_error("pointer is null");

			outstream = os;
		}

	}

}
