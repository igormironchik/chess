
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
#include "game.hpp"

// Qt include.
#include <QVariant>
#include <QString>
#include <QMetaObject>


namespace Chess {

//
// Error
//

Error::Error()
	:	std::runtime_error( "error" )
{
}

Error::~Error() noexcept
{
}


//
// Game
//

Game::Game( QObject * root )
	:	m_root( root )
	,	m_boardObject( 0 )
	,	m_turnColor( Figure::White )
	,	m_selected( 0 )
	,	m_selectedX( 0 )
	,	m_selectedY( 0 )
{
	m_boardObject = m_root->findChild< QObject* > ( QLatin1String( "board" ) );

	if( !m_boardObject )
		throw Error();

	connect( m_boardObject, SIGNAL( clicked( int, int ) ),
		this, SLOT( clicked( int, int ) ) );
	connect( m_boardObject, SIGNAL( hovered( int, int ) ),
		this, SLOT( hovered( int, int ) ) );
}

Game::~Game()
{
}

static inline QString cellName( int x, int y )
{
	return QString( "c" ) + QString::number( x ) +
		QString::number( y );
}

void
Game::markCellsForMove( int x, int y, int dx, int dy, Move::Distance d,
	Figure * figure )
{
	x += dx;
	y += dy;

	int move = 0;

	if( d == Move::Any || d == Move::TwoFirstTime )
	{
		while( x >= 0 && x < 8 && y >= 0 && y < 8 )
		{
			if( !m_board.figures()[ y ][ x ] )
			{
				QObject * cell = m_boardObject->findChild< QObject* > (
					cellName( x, y ) );

				if( cell )
					QMetaObject::invokeMethod( cell, "markBlue" );

				m_possibleMoves.append( x * 10 + y );
			}
			else
				break;

			x += dx;
			y += dy;
			++move;

			if( d == Move::TwoFirstTime && figure->isFirstMoveDone() )
				break;

			if( d == Move::TwoFirstTime && move == 2 )
				break;
		}
	}
	else if( x >= 0 && x < 8 && y >= 0 && y < 8 )
	{
		if( !m_board.figures()[ y ][ x ] )
		{
			QObject * cell = m_boardObject->findChild< QObject* > (
				cellName( x, y ) );

			if( cell )
				QMetaObject::invokeMethod( cell, "markBlue" );

			m_possibleMoves.append( x * 10 + y );
		}
	}
}

void
Game::markCellForHit( int x, int y, int dx, int dy, Move::Distance d,
	Figure * figure )
{
	x += dx;
	y += dy;

	if( d == Move::Any )
	{
		while( x >= 0 && x < 8 && y >= 0 && y < 8 )
		{
			if( m_board.figures()[ y ][ x ] &&
				figure->color() != m_board.figures()[ y ][ x ]->color() )
			{
				QObject * cell = m_boardObject->findChild< QObject* > (
					cellName( x, y ) );

				if( cell )
					QMetaObject::invokeMethod( cell, "markRed" );

				m_possibleMoves.append( x * 10 + y );

				break;
			}

			x += dx;
			y += dy;
		}
	}
	else if( x >= 0 && x < 8 && y >= 0 && y < 8 )
	{
		if( m_board.figures()[ y ][ x ] &&
			figure->color() != m_board.figures()[ y ][ x ]->color() )
		{
			QObject * cell = m_boardObject->findChild< QObject* > (
				cellName( x, y ) );

			if( cell )
				QMetaObject::invokeMethod( cell, "markRed" );

			m_possibleMoves.append( x * 10 + y );
		}
	}
}

void
Game::clicked( int x, int y )
{
	QMetaObject::invokeMethod( m_boardObject, "clearColor" );

	if( !m_selected )
	{
		Figure * figure = m_board.figures()[ y ][ x ];

		if( figure != 0 )
		{
			if( figure->color() == m_turnColor )
			{
				m_selected = figure;
				m_selectedX = x;
				m_selectedY = y;

				QObject * cell = m_boardObject->findChild< QObject* > (
					cellName( x, y ) );

				if( cell )
				{
					QMetaObject::invokeMethod( cell, "markBlue" );

					const Figure::Moves moves = figure->moves();

					for( int i = 0; i < 5; ++i )
					{
						for( int j = 0; j < 5; ++j )
						{
							int dx = 0;
							int dy = 0;

							if( figure->color() == Figure::White )
							{
								dx = j - 2;
								dy = i - 2;
							}
							else
							{
								dx = 2 - j;
								dy = 2 - i;
							}

							if( moves[ i ][ j ].types().testFlag( Move::Movement ) )
							{
								markCellsForMove( x, y, dx, dy,
									moves[ i ][ j ].dist(), figure );
							}

							if( moves[ i ][ j ].types().testFlag( Move::Hit ) )
							{
								markCellForHit( x, y, dx, dy,
									moves[ i ][ j ].dist(), figure );
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if( m_possibleMoves.contains( x * 10 + y ) )
		{
			QObject * figure = m_boardObject->findChild< QObject* >
				( m_selected->name() );

			QObject * cell = m_boardObject->findChild< QObject* >
				( cellName( x, y ) );

			if( figure && cell )
			{
				figure->setProperty( "x", cell->property( "x" ) );
				figure->setProperty( "y", cell->property( "y" ) );
			}

			if( m_board.figures()[ y ][ x ] )
			{
				QObject * hitted = m_boardObject->findChild< QObject* >
					( m_board.figures()[ y ][ x ]->name() );

				if( hitted )
					hitted->setProperty( "visible", false );
			}

			m_board.figures()[ m_selectedY ][ m_selectedX ] = 0;
			m_board.figures()[ y ][ x ] = m_selected;

			m_selected->firstMoveDone();
			m_possibleMoves.clear();

			if( m_turnColor == Figure::White )
				m_turnColor = Figure::Black;
			else
				m_turnColor = Figure::White;
		}

		m_selected = 0;
	}
}

void
Game::hovered( int x, int y )
{
	Q_UNUSED( x )
	Q_UNUSED( y )
}

} /* namespace Chess */
