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
 * Msg.cpp
 *
 *  Created on: 2009-05-15
 *      Author: athantor
 */

#include "Msg.h"

namespace util
{

	namespace logging
	{
		Msg::Msg( const std::string & txt, M_Level lvl ) :
			msg_txt(txt), msg_lvl(lvl)
		{
		}

		Msg::Msg( const char * txt, M_Level lvl ) :
			msg_txt(txt), msg_lvl(lvl)
		{
		}

		Msg::~Msg()
		{
			// TODO Auto-generated destructor stub
		}

		std::string Msg::getMsg_txt() const
		{
			return msg_txt;
		}

		Msg::M_Level Msg::getMsg_lvl() const
		{
			return msg_lvl;
		}

		/*Msg Msg::operator+( const char * val)
		{
			return operator+(std::string(val));
		}*/

		Msg Msg::operator+( const std::string & val)
		{
			return Msg(getMsg_txt() + val, getMsg_lvl());
		}

		Msg Msg::operator+( long long val )
		{
			return operator+( boost::lexical_cast<std::string>(val) );
		}

		Msg Msg::operator+( double val)
		{
			return operator+( boost::lexical_cast<std::string>(val) );
		}

		Msg::operator std::string() const
		{
			return getMsg_txt();
		}


	}

}
