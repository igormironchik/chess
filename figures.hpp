
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

#ifndef CHESS__FIGURES_HPP__INCLUDED
#define CHESS__FIGURES_HPP__INCLUDED

// Qt include.
#include <QFlags>
#include <QString>
#include <QSharedPointer>

// C++ include.
#include <array>


namespace Chess {

//
// Move
//

//! Move.
class Move Q_DECL_FINAL {
public:
	//! Type of movement.
	enum Type {
		Unknown = 0x00,
		Movement = 0x01,
		Hit = 0x02
	}; // enum Type

	Q_DECLARE_FLAGS( Types, Type )

	//! Distance.
	enum Distance {
		No,
		One,
		Any,
		TwoFirstTime
	}; // enum Distance

	Move( Types t, Distance d );
	~Move();

	//! \return Types.
	Types types() const;

	//! \return Distance.
	Distance dist() const;

private:
	//! Types.
	Types m_types;
	//! Distance.
	Distance m_dist;
}; // class Move


//
// Figure
//

//! Chess figure on the board.
class Figure {
public:
	//! Color.
	enum Color {
		White,
		Black
	}; // enum Color

	enum FigureType {
		KingFigure,
		QueenFigure,
		CastleFigure,
		KnightFigure,
		BishopFigure,
		PawnFigure
	}; // enum FigureType

	Figure( int xv, int yv, Color c, const QString & name,
		int index );
	virtual ~Figure();

	//! Moves.
	using Moves = std::array< std::array< Move, 5 >, 5 >;

	//! \return Possible moves.
	virtual const Moves & moves() const = 0;

	//! \return Type of figure.
	virtual FigureType type() const = 0;

	//! \return Index in the array.
	int index() const;

	//! \return X.
	int x() const;
	//! Set X.
	void setX( int value );

	//! \return Y.
	int y() const;
	//! Set Y.
	void setY( int value );

	//! \return Color.
	Color color() const;

	//! \return Name.
	const QString & name() const;

	//! \return Is first move done?
	bool isFirstMoveDone() const;
	//! Mark figure as did first move.
	void firstMoveDone( bool done = true );

	//! Copy.
	virtual QSharedPointer< Figure > copy() const = 0;

private:
	//! X.
	int m_x;
	//! Y.
	int m_y;
	//! Color.
	Color m_c;
	//! Name.
	QString m_name;
	//! First move has been done.
	bool m_firstMoveDone;
	//! Index in the array.
	int m_index;
}; // class Figure


//
// Pawn.
//

//! Pawn.
class Pawn Q_DECL_FINAL
	:	public Figure
{
public:
	Pawn( int xv, int yv, Color c, const QString & n, int index );
	virtual ~Pawn();

	//! \return Possible moves.
	const Moves & moves() const Q_DECL_OVERRIDE;

	//! \return Type of figure.
	FigureType type() const Q_DECL_OVERRIDE;

	//! Is pass?
	bool isPass() const;
	//! Set pass.
	void setPass( bool on = true );

	//! Copy.
	QSharedPointer< Figure > copy() const Q_DECL_OVERRIDE;

private:
	static const Moves m_moves;
	//! Is aisle?
	bool m_isPass;
}; // class Pawn


//
// Castle
//

//! Castle.
class Castle Q_DECL_FINAL
	:	public Figure
{
public:
	Castle( int xv, int yv, Color c, const QString & n, int index );
	virtual ~Castle();

	//! \return Possible moves.
	const Moves & moves() const Q_DECL_OVERRIDE;

	//! \return Type of figure.
	FigureType type() const Q_DECL_OVERRIDE;

	//! Copy.
	QSharedPointer< Figure > copy() const Q_DECL_OVERRIDE;

private:
	static const Moves m_moves;
}; // class Castle


//
// Knight
//

//! Knight.
class Knight Q_DECL_FINAL
	:	public Figure
{
public:
	Knight( int xv, int yv, Color c, const QString & n, int index );
	virtual ~Knight();

	//! \return Possible moves.
	const Moves & moves() const Q_DECL_OVERRIDE;

	//! \return Type of figure.
	FigureType type() const Q_DECL_OVERRIDE;

	//! Copy.
	QSharedPointer< Figure > copy() const Q_DECL_OVERRIDE;

private:
	static const Moves m_moves;
}; // class Knight


//
// Bishop
//

//! Bishop.
class Bishop Q_DECL_FINAL
	:	public Figure
{
public:
	Bishop( int xv, int yv, Color c, const QString & n, int index );
	virtual ~Bishop();

	//! \return Possible moves.
	const Moves & moves() const Q_DECL_OVERRIDE;

	//! \return Type of figure.
	FigureType type() const Q_DECL_OVERRIDE;

	//! Copy.
	QSharedPointer< Figure > copy() const Q_DECL_OVERRIDE;

private:
	static const Moves m_moves;
}; // class


//
// Queen
//

//! Queen.
class Queen Q_DECL_FINAL
	:	public Figure
{
public:
	Queen( int xv, int yv, Color c, const QString & n, int index );
	virtual ~Queen();

	//! \return Possible moves.
	const Moves & moves() const Q_DECL_OVERRIDE;

	//! \return Type of figure.
	FigureType type() const Q_DECL_OVERRIDE;

	//! Copy.
	QSharedPointer< Figure > copy() const Q_DECL_OVERRIDE;

private:
	static const Moves m_moves;
}; // class Queen


//
// King
//

//! King.
class King Q_DECL_FINAL
	:	public Figure
{
public:
	King( int xv, int yv, Color c, const QString & n, int index );
	virtual ~King();

	//! \return Possible moves.
	const Moves & moves() const Q_DECL_OVERRIDE;

	//! \return Type of figure.
	FigureType type() const Q_DECL_OVERRIDE;

	//! Copy.
	QSharedPointer< Figure > copy() const Q_DECL_OVERRIDE;

private:
	static const Moves m_moves;
}; // class King

} /* namespace Chess */

Q_DECLARE_OPERATORS_FOR_FLAGS( Chess::Move::Types )

#endif // CHESS__FIGURES_HPP__INCLUDED
