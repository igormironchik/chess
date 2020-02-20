
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

// Chess include.
#include "figures.hpp"


namespace Chess {

//
// Move
//

Move::Move( Types t, Distance d )
	:	m_types( t )
	,	m_dist( d )
{
}

Move::~Move()
{
}

Move::Types
Move::types() const
{
	return m_types;
}

Move::Distance
Move::dist() const
{
	return m_dist;
}


//
// Figure
//

Figure::Figure( int xv, int yv, Color c, const QString & n, int index )
	:	m_x( xv )
	,	m_y( yv )
	,	m_c( c )
	,	m_name( n )
	,	m_firstMoveDone( false )
	,	m_index( index )
{
}

int
Figure::index() const
{
	return m_index;
}

Figure::~Figure()
{
}

int
Figure::x() const
{
	return m_x;
}

void
Figure::setX( int value )
{
	m_x = value;
}

int
Figure::y() const
{
	return m_y;
}

void
Figure::setY( int value )
{
	m_y = value;
}

Figure::Color
Figure::color() const
{
	return m_c;
}

const QString &
Figure::name() const
{
	return m_name;
}

bool
Figure::isFirstMoveDone() const
{
	return m_firstMoveDone;
}

void
Figure::firstMoveDone( bool done )
{
	m_firstMoveDone = done;
}


//
// Pawn.
//

Pawn::Pawn( int xv, int yv, Color c, const QString & n, int index )
	:	Figure( xv, yv, c, n, index )
	,	m_isPass( false )
{
}

Pawn::~Pawn()
{
}

bool
Pawn::isPass() const
{
	return m_isPass;
}

void
Pawn::setPass( bool on )
{
	m_isPass = on;
}

const Pawn::Moves &
Pawn::moves() const
{
	return m_moves;
}

Pawn::FigureType
Pawn::type() const
{
	return PawnFigure;
}

QSharedPointer< Figure >
Pawn::copy() const
{
	QSharedPointer< Figure > res( new Pawn( x(), y(), color(),
		name(), index() ) );
	res->firstMoveDone( isFirstMoveDone() );
	static_cast< Pawn* > ( res.data() )->m_isPass = m_isPass;

	return res;
}

const Pawn::Moves Pawn::m_moves = {
	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Hit, Move::One },
		Move{ Move::Movement, Move::TwoFirstTime }, Move{ Move::Hit, Move::One },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } } };


//
// Castle
//

Castle::Castle( int xv, int yv, Color c, const QString & n, int index )
	:	Figure( xv, yv, c, n, index )
{
}

Castle::~Castle()
{
}

const Castle::Moves &
Castle::moves() const
{
	return m_moves;
}

Castle::FigureType
Castle::type() const
{
	return CastleFigure;
}

QSharedPointer< Figure >
Castle::copy() const
{
	QSharedPointer< Figure > res( new Castle( x(), y(), color(),
		name(), index() ) );
	res->firstMoveDone( isFirstMoveDone() );

	return res;
}

const Castle::Moves Castle::m_moves = {
	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } } };


//
// Knight
//

Knight::Knight( int xv, int yv, Color c, const QString & n, int index )
	:	Figure( xv, yv, c, n, index )
{
}

Knight::~Knight()
{
}

const Knight::Moves &
Knight::moves() const
{
	return m_moves;
}

Knight::FigureType
Knight::type() const
{
	return KnightFigure;
}

QSharedPointer< Figure >
Knight::copy() const
{
	QSharedPointer< Figure > res( new Knight( x(), y(), color(),
		name(), index() ) );
	res->firstMoveDone( isFirstMoveDone() );

	return res;
}

const Knight::Moves Knight::m_moves = {
	std::array< Move, 5 >{ Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::One } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::One } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Unknown, Move::No } } };


//
// Bishop
//


Bishop::Bishop( int xv, int yv, Color c, const QString & n, int index )
	:	Figure( xv, yv, c, n, index )
{
}

Bishop::~Bishop()
{
}

const Bishop::Moves &
Bishop::moves() const
{
	return m_moves;
}

Bishop::FigureType
Bishop::type() const
{
	return BishopFigure;
}

QSharedPointer< Figure >
Bishop::copy() const
{
	QSharedPointer< Figure > res( new Bishop( x(), y(), color(),
		name(), index() ) );
	res->firstMoveDone( isFirstMoveDone() );

	return res;
}

const Bishop::Moves Bishop::m_moves = {
	std::array< Move, 5 >{ Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 >{ Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } } };


//
// Queen
//

Queen::Queen( int xv, int yv, Color c, const QString & n, int index )
	:	Figure( xv, yv, c, n, index )
{
}

Queen::~Queen()
{
}

const Queen::Moves &
Queen::moves() const
{
	return m_moves;
}

Queen::FigureType
Queen::type() const
{
	return QueenFigure;
}

QSharedPointer< Figure >
Queen::copy() const
{
	QSharedPointer< Figure > res( new Queen( x(), y(), color(),
		name(), index() ) );
	res->firstMoveDone( isFirstMoveDone() );

	return res;
}

const Queen::Moves Queen::m_moves = {
	std::array< Move, 5 >{ Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Movement | Move::Hit, Move::Any },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } } };


//
// King
//

King::King( int xv, int yv, Color c, const QString & n, int index )
	:	Figure( xv, yv, c, n, index )
{
}

King::~King()
{
}

const King::Moves &
King::moves() const
{
	return m_moves;
}

King::FigureType
King::type() const
{
	return KingFigure;
}

QSharedPointer< Figure >
King::copy() const
{
	QSharedPointer< Figure > res( new King( x(), y(), color(),
		name(), index() ) );
	res->firstMoveDone( isFirstMoveDone() );

	return res;
}

const King::Moves King::m_moves = {
	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Movement | Move::Hit, Move::One },
		Move{ Move::Unknown, Move::No } },

	std::array< Move, 5 > { Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No }, Move{ Move::Unknown, Move::No },
		Move{ Move::Unknown, Move::No } } };

} /* namespace Chess */
