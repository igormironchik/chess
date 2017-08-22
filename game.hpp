
/*!
	\file

	\author Igor Mironchik (igor.mironchik at gmail dot com).

	Copyright (c) 2016 Igor Mironchik

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

#ifndef CHESS__GAME_HPP__INCLUDED
#define CHESS__GAME_HPP__INCLUDED

// Qt include.
#include <QObject>
#include <QVector>

// Chess include.
#include "board.hpp"
#include "signals.hpp"

// C++ include.
#include <stdexcept>


namespace Chess {

//
// Error
//

//! Error.
class Error
	:	public std::runtime_error
{
public:
	Error();
	~Error() noexcept;
}; // class Error


//
// Game
//

//! Game.
class Game final
	:	public QObject
{
	Q_OBJECT

public:
	Game( QObject * root, Board & board, Signals & s );
	~Game();

private slots:
	//! Clicked.
	void clicked( int x, int y );
	//! Hovered.
	void hovered( int x, int y );
	//! New game.
	void newGame();

private:
	//! Mark cells for move.
	void markCellsForMove( int x, int y, int dx, int dy, Move::Distance d,
		Figure * figure, Board & tmpBoard );
	//! Mark cell for hit.
	void markCellForHit( int x, int y, int dx, int dy, Move::Distance d,
		Figure * figure, Board & tmpBoard );
	//! Clear cells color.
	void clearCellsColor();
	//! First click.
	void firstClick( int x, int y );
	//! Second click.
	bool secondClick( int x, int y );
	//! Mark turn.
	void markTurnLabel();
	//! Handle castling.
	void handleCastling( int x, int y,
		Figure * figure, Board & board ) const;
	//! Check check.
	bool checkCheck( bool checkmate = false );
	//! Mark check.
	bool markCheck( King * king, Figure * figure, bool checkmate = false );
	//! Will be a check after move?
	bool isCheckAfterMove( int x, int y,
		Figure * figure, Board & tmpBoard ) const;
	//! Check checkmate.
	bool isCheckMate();
	//! Check stalemate.
	bool isStaleMate();

private:
	//! Board.
	Board & m_board;
	//! Root object in QML.
	QObject * m_root;
	//! Board object in QML.
	QObject * m_boardObject;
	//! Color of turn.
	Figure::Color m_turnColor;
	//! Selected figure.
	Figure * m_selected;
	//! Selected X.
	int m_selectedX;
	//! Selected Y.
	int m_selectedY;
	//! Possible moves.
	QVector< int > m_possibleMoves;
	//! Is chess?
	bool m_isChess;
	//! Signals.
	Signals & m_signals;
}; // class Game

} /* namespace Chess */

#endif // CHESS__GAME_HPP__INCLUDED
