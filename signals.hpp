
/*!
	\file

	\author Igor Mironchik (igor.mironchik at gmail dot com).

	Copyright (c) 2017 Igor Mironchik

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CHESS__SIGNALS_HPP__INCLUDED
#define CHESS__SIGNALS_HPP__INCLUDED

// Qt include.
#include <QObject>


namespace Chess {

//
// Signals
//

//! Signals.
class Signals Q_DECL_FINAL
	:	public QObject
{
	Q_OBJECT

signals:
	//! Checkmate.
	void checkmate();
	//! Draw game.
	void drawgame();

public:
	Signals()
	{
	}

	~Signals()
	{
	}
}; // class Signals

} /* namespace Chess */

#endif // CHESS__SIGNALS_HPP__INCLUDED
