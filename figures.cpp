
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

Figure::Figure( int xv, int yv, Color c, const QString & n )
	:	m_x( xv )
	,	m_y( yv )
	,	m_c( c )
	,	m_name( n )
	,	m_firstMoveDone( false )
{
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
Figure::firstMoveDone()
{
	m_firstMoveDone = true;
}


//
// Pawn.
//

Pawn::Pawn( int xv, int yv, Color c, const QString & n )
	:	Figure( xv, yv, c, n )
{
}

Pawn::~Pawn()
{
}

const Pawn::Moves &
Pawn::moves() const
{
	return m_moves;
}

const Pawn::Moves Pawn::m_moves = {
	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Hit, Move::One },
	{ Move::Movement, Move::TwoFirstTime }, { Move::Hit, Move::One },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } } };


//
// Castle
//

Castle::Castle( int xv, int yv, Color c, const QString & n )
	:	Figure( xv, yv, c, n )
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

const Castle::Moves Castle::m_moves = {
	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Movement | Move::Hit, Move::Any }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::Any },
	{ Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::Any },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Movement | Move::Hit, Move::Any }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } } };


//
// Knight
//

Knight::Knight( int xv, int yv, Color c, const QString & n )
	:	Figure( xv, yv, c, n )
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

const Knight::Moves Knight::m_moves = {
	{ { Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::One },
	{ Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::One },
	{ Move::Unknown, Move::No } },

	{ { Move::Movement | Move::Hit, Move::One }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Movement | Move::Hit, Move::One } },

	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } },

	{ { Move::Movement | Move::Hit, Move::One }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Movement | Move::Hit, Move::One } },

	{ { Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::One },
	{ Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::One },
	{ Move::Unknown, Move::No } } };


//
// Bishop
//


Bishop::Bishop( int xv, int yv, Color c, const QString & n )
	:	Figure( xv, yv, c, n )
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

const Bishop::Moves Bishop::m_moves = {
	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::Any },
	{ Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::Any },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::Any },
	{ Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::Any },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } } };


//
// Queen
//

Queen::Queen( int xv, int yv, Color c, const QString & n )
	:	Figure( xv, yv, c, n )
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

const Queen::Moves Queen::m_moves = {
	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No },
	{ Move::Movement | Move::Hit, Move::Any },
	{ Move::Movement | Move::Hit, Move::Any },
	{ Move::Movement | Move::Hit, Move::Any },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::Any },
	{ Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::Any },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::Any },
	{ Move::Movement | Move::Hit, Move::Any },
	{ Move::Movement | Move::Hit, Move::Any },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } } };


//
// King
//

King::King( int xv, int yv, Color c, const QString & n )
	:	Figure( xv, yv, c, n )
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

const King::Moves King::m_moves = {
	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No },
	{ Move::Movement | Move::Hit, Move::One },
	{ Move::Movement | Move::Hit, Move::One },
	{ Move::Movement | Move::Hit, Move::One },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::One },
	{ Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::One },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Movement | Move::Hit, Move::One },
	{ Move::Movement | Move::Hit, Move::One },
	{ Move::Movement | Move::Hit, Move::One },
	{ Move::Unknown, Move::No } },

	{ { Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No }, { Move::Unknown, Move::No },
	{ Move::Unknown, Move::No } } };

} /* namespace Chess */
