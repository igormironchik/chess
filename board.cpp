
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
#include "board.hpp"

// C++ include.
#include <algorithm>

// Qt include.
#include <QColor>
#include <QVariant>


namespace Chess {

//
// Board
//

Board::Board()
{
	newGame();
}

Board::~Board()
{
}

Board::FiguresOnBoard &
Board::figures()
{
	return m_board;
}

void
Board::newGame()
{
	FiguresOnBoard tmp = {
		{
			m_figures.at( 0 ).data(),
			m_figures.at( 1 ).data(),
			m_figures.at( 2 ).data(),
			m_figures.at( 3 ).data(),
			m_figures.at( 4 ).data(),
			m_figures.at( 5 ).data(),
			m_figures.at( 6 ).data(),
			m_figures.at( 7 ).data()
		},

		{
			m_figures.at( 8 ).data(),
			m_figures.at( 9 ).data(),
			m_figures.at( 10 ).data(),
			m_figures.at( 11 ).data(),
			m_figures.at( 12 ).data(),
			m_figures.at( 13 ).data(),
			m_figures.at( 14 ).data(),
			m_figures.at( 15 ).data()
		},

		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },

		{
			m_figures.at( 24 ).data(),
			m_figures.at( 25 ).data(),
			m_figures.at( 26 ).data(),
			m_figures.at( 27 ).data(),
			m_figures.at( 28 ).data(),
			m_figures.at( 29 ).data(),
			m_figures.at( 30 ).data(),
			m_figures.at( 31 ).data()
		},

		{
			m_figures.at( 16 ).data(),
			m_figures.at( 17 ).data(),
			m_figures.at( 18 ).data(),
			m_figures.at( 19 ).data(),
			m_figures.at( 20 ).data(),
			m_figures.at( 21 ).data(),
			m_figures.at( 22 ).data(),
			m_figures.at( 23 ).data()
		} };

	std::copy( &tmp[ 0 ][ 0 ], &tmp[ 0 ][ 0 ] +
		sizeof( FiguresOnBoard ) / sizeof( Figure* ), &m_board[ 0 ][ 0 ] );

	Colors ctmp = {
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None }
	};

	std::copy( &ctmp[ 0 ][ 0 ], &ctmp[ 0 ][ 0 ] +
		sizeof( Colors ) / sizeof( Color ), &m_colors[ 0 ][ 0 ] );
}

const QList< QSharedPointer< Figure > > Board::m_figures = {
	QSharedPointer< Figure >{ new Castle{ 0, 0, Figure::Black,
		QLatin1String( "castle-black-1" ) } },
	QSharedPointer< Figure >{ new Knight{ 1, 0, Figure::Black,
		QLatin1String( "knight-black-1" ) } },
	QSharedPointer< Figure >{ new Bishop{ 2, 0, Figure::Black,
		QLatin1String( "bishop-black-1" ) } },
	QSharedPointer< Figure >{ new Queen{ 3, 0, Figure::Black,
		QLatin1String( "queen-black" ) } },
	QSharedPointer< Figure >{ new King{ 4, 0, Figure::Black,
		QLatin1String( "king-black" ) } },
	QSharedPointer< Figure >{ new Bishop{ 5, 0, Figure::Black,
		QLatin1String( "bishop-black-2" ) } },
	QSharedPointer< Figure >{ new Knight{ 6, 0, Figure::Black,
		QLatin1String( "knight-black-2" ) } },
	QSharedPointer< Figure >{ new Castle{ 7, 0, Figure::Black,
		QLatin1String( "castle-black-2" ) } },
	QSharedPointer< Figure >{ new Pawn{ 0, 1, Figure::Black,
		QLatin1String( "pawn-black-1" ) } },
	QSharedPointer< Figure >{ new Pawn{ 1, 1, Figure::Black,
		QLatin1String( "pawn-black-2" ) } },
	QSharedPointer< Figure >{ new Pawn{ 2, 1, Figure::Black,
		QLatin1String( "pawn-black-3" ) } },
	QSharedPointer< Figure >{ new Pawn{ 3, 1, Figure::Black,
		QLatin1String( "pawn-black-4" ) } },
	QSharedPointer< Figure >{ new Pawn{ 4, 1, Figure::Black,
		QLatin1String( "pawn-black-5" ) } },
	QSharedPointer< Figure >{ new Pawn{ 5, 1, Figure::Black,
		QLatin1String( "pawn-black-6" ) } },
	QSharedPointer< Figure >{ new Pawn{ 6, 1, Figure::Black,
		QLatin1String( "pawn-black-7" ) } },
	QSharedPointer< Figure >{ new Pawn{ 7, 1, Figure::Black,
		QLatin1String( "pawn-black-8" ) } },

	QSharedPointer< Figure >{ new Castle{ 0, 7, Figure::White,
		QLatin1String( "castle-white-1" ) } },
	QSharedPointer< Figure >{ new Knight{ 1, 7, Figure::White,
		QLatin1String( "knight-white-1" ) } },
	QSharedPointer< Figure >{ new Bishop{ 2, 7, Figure::White,
		QLatin1String( "bishop-white-1" ) } },
	QSharedPointer< Figure >{ new Queen{ 3, 7, Figure::White,
		QLatin1String( "queen-white" ) } },
	QSharedPointer< Figure >{ new King{ 4, 7, Figure::White,
		QLatin1String( "king-white" ) } },
	QSharedPointer< Figure >{ new Bishop{ 5, 7, Figure::White,
		QLatin1String( "bishop-white-2" ) } },
	QSharedPointer< Figure >{ new Knight{ 6, 7, Figure::White,
		QLatin1String( "knight-white-2" ) } },
	QSharedPointer< Figure >{ new Castle{ 7, 7, Figure::White,
		QLatin1String( "castle-white-2" ) } },
	QSharedPointer< Figure >{ new Pawn{ 0, 6, Figure::White,
		QLatin1String( "pawn-white-1" ) } },
	QSharedPointer< Figure >{ new Pawn{ 1, 6, Figure::White,
		QLatin1String( "pawn-white-2" ) } },
	QSharedPointer< Figure >{ new Pawn{ 2, 6, Figure::White,
		QLatin1String( "pawn-white-3" ) } },
	QSharedPointer< Figure >{ new Pawn{ 3, 6, Figure::White,
		QLatin1String( "pawn-white-4" ) } },
	QSharedPointer< Figure >{ new Pawn{ 4, 6, Figure::White,
		QLatin1String( "pawn-white-5" ) } },
	QSharedPointer< Figure >{ new Pawn{ 5, 6, Figure::White,
		QLatin1String( "pawn-white-6" ) } },
	QSharedPointer< Figure >{ new Pawn{ 6, 6, Figure::White,
		QLatin1String( "pawn-white-7" ) } },
	QSharedPointer< Figure >{ new Pawn{ 7, 6, Figure::White,
		QLatin1String( "pawn-white-8" ) } }
};

void
Board::move( int fromX, int fromY, int toX, int toY )
{
	Figure * from = m_board[ fromY ][ fromX ];

	m_board[ fromY ][ fromX ] = 0;
	m_board[ toY ][ toX ] = from;

	const QModelIndex fromIndex = index( fromY * 8 + fromX, 0 );
	const QModelIndex toIndex = index( toY * 8 + toX, 0 );

	emit dataChanged( fromIndex, fromIndex );
	emit dataChanged( toIndex, toIndex );
}

int
Board::rowCount( const QModelIndex & parent ) const
{
	Q_UNUSED( parent )

	return 8 * 8;
}

QVariant
Board::data( const QModelIndex & index, int role ) const
{
	int row = index.row();

	if( row < 0 || row >= rowCount() )
		return QVariant();

	int r = row / 8;
	int c = row % 8;

	const Figure * f = m_board[ r ][ c ];

	switch( role )
	{
		case CellImageSourceRole :
		{
			if( f )
			{
				QString res = QLatin1String( "qrc:/img/" );

				switch( f->type() )
				{
					case Figure::KingFigure :
						res.append( QLatin1String( "king" ) );
						break;

					case Figure::QueenFigure :
						res.append( QLatin1String( "queen" ) );
						break;

					case Figure::CastleFigure :
						res.append( QLatin1String( "castle" ) );
						break;

					case Figure::KnightFigure :
						res.append( QLatin1String( "knight" ) );
						break;

					case Figure::BishopFigure :
						res.append( QLatin1String( "bishop" ) );
						break;

					case Figure::PawnFigure :
						res.append( QLatin1String( "pawn" ) );
						break;

					default :
						break;
				}

				switch( f->color() )
				{
					case Figure::White :
						res.append( QLatin1String( "-white" ) );
						break;

					case Figure::Black :
						res.append( QLatin1String( "-black" ) );
						break;

					default :
						break;
				}

				res.append( QLatin1String( ".png" ) );

				return res;
			}
			else
				return QLatin1String( "qrc:/img/empty.png" );
		}
			break;

		case CurrentPieceColorRole :
			return ( r % 2 == 0 ? ( c % 2 == 0 ? QColor( Qt::white ) :
					QColor( Qt::lightGray ) ) :
				( c % 2 == 0 ? QColor( Qt::lightGray ) : QColor( Qt::white ) ) );

		case BluePieceColorRole :
			return ( m_colors[ r ][ c ] == Blue ? true : false );

		case RedPieceColorRole :
			return ( m_colors[ r ][ c ] == Red ? true : false );

		default :
			break;
	}

	return QVariant();
}

QHash< int, QByteArray >
Board::roleNames() const
{
	QHash< int, QByteArray > names;

	names[ CellImageSourceRole ] = "CellImageSource";
	names[ CurrentPieceColorRole ] = "CurrentPieceColor";
	names[ BluePieceColorRole ] = "BluePieceColor";
	names[ RedPieceColorRole ] = "RedPieceColor";

	return names;
}

void
Board::markBlue( int x, int y )
{
	m_colors[ y ][ x ] = Blue;

	const QModelIndex idx = index( y * 8 + x, 0 );

	emit dataChanged( idx, idx );
}

void
Board::markRed( int x, int y )
{
	m_colors[ y ][ x ] = Red;

	const QModelIndex idx = index( y * 8 + x, 0 );

	emit dataChanged( idx, idx );
}

void
Board::clearBlueRed()
{
	Colors ctmp = {
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None },
		{ None, None, None, None, None, None, None, None }
	};

	std::copy( &ctmp[ 0 ][ 0 ], &ctmp[ 0 ][ 0 ] +
		sizeof( Colors ) / sizeof( Color ), &m_colors[ 0 ][ 0 ] );

	const QModelIndex from = index( 0, 0 );
	const QModelIndex to = index( 8 * 8 - 1, 0 );

	emit dataChanged( from, to );
}

} /* namespace Chess */
