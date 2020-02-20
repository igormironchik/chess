
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
class Signals
	:	public QObject
{
	Q_OBJECT

public:
	//! Color.
	enum Color {
		//! White.
		White = 0,
		//! Black.
		Black = 1
	}; // enum Color

	Q_ENUM( Color )

	enum TransformationFigure {
		Queen = 0,
		Castle = 1,
		Knight = 2,
		Bishop = 3
	}; // enum TransformationFigure

	Q_ENUM( TransformationFigure )

signals:
	//! Checkmate.
	void checkmate();
	//! Draw game.
	void drawgame();
	//! Transformation.
	void pawnTransformation( int color, int fx, int fy );
	//! Rotate board.
	void rotate( int angle );
	//! Turn made.
	void turnMade();
	//! No more undo.
	void noMoreUndo();

public:
	Signals()
	{
	}

	virtual ~Signals()
	{
	}
}; // class Signals

} /* namespace Chess */

#endif // CHESS__SIGNALS_HPP__INCLUDED
