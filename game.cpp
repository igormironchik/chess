
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

Game::Game( QObject * root, Board & board )
	:	m_board( board )
	,	m_root( root )
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
				m_board.markBlue( x, y );

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
			m_board.markBlue( x, y );

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
			if( m_board.figures()[ y ][ x ] )
			{
				if( figure->color() != m_board.figures()[ y ][ x ]->color() )
				{
					m_board.markRed( x, y );

					m_possibleMoves.append( x * 10 + y );
				}

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
			m_board.markRed( x, y );

			m_possibleMoves.append( x * 10 + y );
		}
	}
}

void
Game::clearCellsColor()
{
	m_board.clearBlueRed();
}

void
Game::clicked( int x, int y )
{
	clearCellsColor();

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

				m_board.markBlue( x, y );

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

						// Moves highlight.
						if( moves[ i ][ j ].types().testFlag( Move::Movement ) )
						{
							markCellsForMove( x, y, dx, dy,
								moves[ i ][ j ].dist(), figure );
						}

						// Castling highlight.
						if( figure->type() == Figure::KingFigure &&
							!figure->isFirstMoveDone() )
						{
							if( !m_board.figures()[ y ][ x - 1 ] &&
								!m_board.figures()[ y ][ x - 2 ] &&
								!m_board.figures()[ y ][ x - 3 ] &&
								m_board.figures()[ y ][ x - 4 ] &&
								!m_board.figures()[ y ][ x - 4 ]->isFirstMoveDone() )
							{
								m_possibleMoves.append( ( x - 3 ) * 10 + y );

								m_board.markBlue( x - 3, y );
							}

							if( !m_board.figures()[ y ][ x + 1 ] &&
								!m_board.figures()[ y ][ x + 2 ] &&
								m_board.figures()[ y ][ x + 3 ] &&
								!m_board.figures()[ y ][ x + 3 ]->isFirstMoveDone() )
							{
								m_possibleMoves.append( ( x + 2 ) * 10 + y );

								m_board.markBlue( x + 2, y );
							}
						}

						// Hit highlight.
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
	else
	{
		if( m_possibleMoves.contains( x * 10 + y ) )
		{
			m_board.move( m_selectedX, m_selectedY, x, y );

			// Castling.
			if( m_selected->type() == Figure::KingFigure &&
				!m_selected->isFirstMoveDone() )
			{
				switch( m_selected->color() )
				{
					case Figure::White :
					{
						if( x == 1 )
							m_board.move( 0, 7, 2, 7 );
						else if( x == 6 )
							m_board.move( 7, 7, 5, 7 );
					}
						break;

					case Figure::Black :
					{
						if( x == 1 )
							m_board.move( 0, 0, 2, 0 );
						else if( x == 6 )
							m_board.move( 7, 0, 5, 0 );
					}
						break;

					default :
						break;
				}
			}

			m_selected->firstMoveDone();
			m_possibleMoves.clear();

			if( m_turnColor == Figure::White )
			{
				m_turnColor = Figure::Black;

				QObject * turn = m_root->findChild< QObject* > (
					QLatin1String( "turn" ) );

				if( turn )
					turn->setProperty( "text", QLatin1String( "Black" ) );
			}
			else
			{
				m_turnColor = Figure::White;

				QObject * turn = m_root->findChild< QObject* > (
					QLatin1String( "turn" ) );

				if( turn )
					turn->setProperty( "text", QLatin1String( "White" ) );
			}
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
