
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

#ifndef CHESS__BOARD_HPP__INCLUDED
#define CHESS__BOARD_HPP__INCLUDED

// Chess include.
#include "figures.hpp"
#include "signals.hpp"

// Qt include.
#include <QList>
#include <QSharedPointer>
#include <QAbstractListModel>

namespace Chess {


//
// Board
//

//! Board.
class Board Q_DECL_FINAL
	:	public QAbstractListModel
{
	Q_OBJECT

public:
	Board();
	virtual ~Board();

	Board( const Board & other );
	Board & operator = ( const Board & other );

	enum RoleNames {
		CellImageSourceRole = Qt::UserRole,
		CurrentPieceColorRole = CellImageSourceRole + 1,
		BluePieceColorRole = CurrentPieceColorRole + 1,
		RedPieceColorRole = BluePieceColorRole + 1,
		CheckPieceColorRole = RedPieceColorRole + 1,
		BorderColorRole = CheckPieceColorRole + 1
	}; // enum RoleNames

	//! Figures on board.
	typedef Figure* FiguresOnBoard[ 8 ][ 8 ];

	//! \return Figures on board.
	FiguresOnBoard & figures();

	//! \return Figure by index in the array.
	Figure * figure( int index ) const;

	//! Make move.
	void move( int fromX, int fromY, int toX, int toY );

	//! Mark blue.
	void markBlue( int x, int y );
	//! Mark red.
	void markRed( int x, int y );
	//! Mark check.
	void markCheck( int x, int y );
	//! Clear blue|red.
	void clearColors();

	//! \return White king.
	King * whiteKing() const;
	//! \return Black king.
	King * blackKing() const;

	int rowCount( const QModelIndex & parent = QModelIndex() ) const
		Q_DECL_OVERRIDE;
	QVariant data( const QModelIndex & index, int role = Qt::DisplayRole ) const
		Q_DECL_OVERRIDE;
	QHash< int, QByteArray > roleNames() const Q_DECL_OVERRIDE;

public slots:
	//! New game.
	void newGame();
	//! Update.
	void update();
	//! Transformation.
	void transformation( Chess::Signals::TransformationFigure figure,
		Chess::Signals::Color c, int x, int y );

private:
	//! Init figures.
	QList< QSharedPointer< Figure > > initFigures() const;
	//! Copy state of the board.
	void copyState( const Board & other );

private:
	//! Board.
	FiguresOnBoard m_board;
	//! Figures.
	QList< QSharedPointer< Figure > > m_figures;
	//! Transformed figures.
	QList< QSharedPointer< Figure > > m_transformed;
	//! White king.
	King * m_whiteKing;
	//! Black king.
	King * m_blackKing;

	enum Color {
		Blue,
		Red,
		Check,
		None
	}; // enum Color

	//! Figures on board.
	typedef Color Colors[ 8 ][ 8 ];

	//! Cells' marks.
	Colors m_colors;
}; // class Board

} /* namespace Chess */

#endif // CHESS__BOARD_HPP__INCLUDED
