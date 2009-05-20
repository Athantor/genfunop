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
 * Msg.h
 *
 *  Created on: 2009-05-15
 *      Author: athantor
 */

#ifndef MSG_H_
#define MSG_H_

#include <string>

#include <boost/lexical_cast.hpp>

namespace util
{

	namespace logging
	{

		class Msg
		{
			public:

				enum M_Level
				{ //silent → verbose
					L_ERROR = 0x1, L_WARN = 0x2, L_NORM = 0x4, L_INFO = 0x10, L_DEBUG = 0x20, L_VERYDEBUG = 0x40
				} ;

				Msg( const std::string&, M_Level = L_NORM );
				Msg( const char *, M_Level = L_NORM );
				virtual ~Msg();

				std::string getMsg_txt() const;
				M_Level getMsg_lvl() const;

				//Msg operator+(const char *);
				Msg operator+(const std::string &);
				Msg operator+(long long);
				Msg operator+(double);

				operator std::string() const;

		protected:
				const std::string msg_txt;
				const M_Level msg_lvl;
			};

		}

	}

#endif /* MSG_H_ */
