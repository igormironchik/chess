
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
	:	m_figures( initFigures() )
	,	m_whiteKing( static_cast< King* > ( m_figures.at( 20 ).data() ) )
	,	m_blackKing( static_cast< King* > ( m_figures.at( 4 ).data() ) )
{
	newGame();
}

Board::~Board()
{
}

Board::Board( const Board & other )
	:	QAbstractListModel( Q_NULLPTR )
	,	m_figures( initFigures() )
	,	m_whiteKing( static_cast< King* > ( m_figures.at( 20 ).data() ) )
	,	m_blackKing( static_cast< King* > ( m_figures.at( 4 ).data() ) )
{
	copyState( other );
}

Board &
Board::operator = ( const Board & other )
{
	if( this != &other )
	{
		m_figures = initFigures();
		m_whiteKing = static_cast< King* > ( m_figures.at( 20 ).data() );
		m_blackKing = static_cast< King* > ( m_figures.at( 4 ).data() );

		copyState( other );
	}

	return *this;
}

void
Board::copyState( const Board & other )
{
	for( const auto & o : qAsConst( other.m_transformed ) )
		m_transformed.append( o->copy() );

	for( int i = 0; i < 8; ++i )
	{
		for( int j = 0; j < 8; ++j )
		{
			if( other.m_board[ i ][ j ] )
			{
				Figure * o = other.m_board[ i ][ j ];
				Figure * f = ( o->index() < 32 ?
					m_figures.at( o->index() ).data() :
					m_transformed.at( o->index() - 32 ).data() );

				m_board[ i ][ j ] = f;

				f->setX( o->x() );
				f->setY( o->y() );
				f->firstMoveDone( o->isFirstMoveDone() );

				if( f->type() == Figure::PawnFigure )
				{
					static_cast< Pawn* > ( f )->setPass(
						static_cast< Pawn* > ( o )->isPass() );
				}
			}
			else
				m_board[ i ][ j ] = nullptr;

			m_colors[ i ][ j ] = other.m_colors[ i ][ j ];
		}
	}
}

QVector< QSharedPointer< Figure > >
Board::initFigures() const
{
	QVector< QSharedPointer< Figure > > res = {
		QSharedPointer< Figure >{ new Castle{ 0, 0, Figure::Black,
			QLatin1String( "castle-black-1" ), 0 } },
		QSharedPointer< Figure >{ new Knight{ 1, 0, Figure::Black,
			QLatin1String( "knight-black-1" ), 1 } },
		QSharedPointer< Figure >{ new Bishop{ 2, 0, Figure::Black,
			QLatin1String( "bishop-black-1" ), 2 } },
		QSharedPointer< Figure >{ new Queen{ 3, 0, Figure::Black,
			QLatin1String( "queen-black" ), 3 } },
		QSharedPointer< Figure >{ new King{ 4, 0, Figure::Black,
			QLatin1String( "king-black" ), 4 } },
		QSharedPointer< Figure >{ new Bishop{ 5, 0, Figure::Black,
			QLatin1String( "bishop-black-2" ), 5 } },
		QSharedPointer< Figure >{ new Knight{ 6, 0, Figure::Black,
			QLatin1String( "knight-black-2" ), 6 } },
		QSharedPointer< Figure >{ new Castle{ 7, 0, Figure::Black,
			QLatin1String( "castle-black-2" ), 7 } },
		QSharedPointer< Figure >{ new Pawn{ 0, 1, Figure::Black,
			QLatin1String( "pawn-black-1" ), 8 } },
		QSharedPointer< Figure >{ new Pawn{ 1, 1, Figure::Black,
			QLatin1String( "pawn-black-2" ), 9 } },
		QSharedPointer< Figure >{ new Pawn{ 2, 1, Figure::Black,
			QLatin1String( "pawn-black-3" ), 10 } },
		QSharedPointer< Figure >{ new Pawn{ 3, 1, Figure::Black,
			QLatin1String( "pawn-black-4" ), 11 } },
		QSharedPointer< Figure >{ new Pawn{ 4, 1, Figure::Black,
			QLatin1String( "pawn-black-5" ), 12 } },
		QSharedPointer< Figure >{ new Pawn{ 5, 1, Figure::Black,
			QLatin1String( "pawn-black-6" ), 13 } },
		QSharedPointer< Figure >{ new Pawn{ 6, 1, Figure::Black,
			QLatin1String( "pawn-black-7" ), 14 } },
		QSharedPointer< Figure >{ new Pawn{ 7, 1, Figure::Black,
			QLatin1String( "pawn-black-8" ), 15 } },

		QSharedPointer< Figure >{ new Castle{ 0, 7, Figure::White,
			QLatin1String( "castle-white-1" ), 16 } },
		QSharedPointer< Figure >{ new Knight{ 1, 7, Figure::White,
			QLatin1String( "knight-white-1" ), 17 } },
		QSharedPointer< Figure >{ new Bishop{ 2, 7, Figure::White,
			QLatin1String( "bishop-white-1" ), 18 } },
		QSharedPointer< Figure >{ new Queen{ 3, 7, Figure::White,
			QLatin1String( "queen-white" ), 19 } },
		QSharedPointer< Figure >{ new King{ 4, 7, Figure::White,
			QLatin1String( "king-white" ), 20 } },
		QSharedPointer< Figure >{ new Bishop{ 5, 7, Figure::White,
			QLatin1String( "bishop-white-2" ), 21 } },
		QSharedPointer< Figure >{ new Knight{ 6, 7, Figure::White,
			QLatin1String( "knight-white-2" ), 22 } },
		QSharedPointer< Figure >{ new Castle{ 7, 7, Figure::White,
			QLatin1String( "castle-white-2" ), 23 } },
		QSharedPointer< Figure >{ new Pawn{ 0, 6, Figure::White,
			QLatin1String( "pawn-white-1" ), 24 } },
		QSharedPointer< Figure >{ new Pawn{ 1, 6, Figure::White,
			QLatin1String( "pawn-white-2" ), 25 } },
		QSharedPointer< Figure >{ new Pawn{ 2, 6, Figure::White,
			QLatin1String( "pawn-white-3" ), 26 } },
		QSharedPointer< Figure >{ new Pawn{ 3, 6, Figure::White,
			QLatin1String( "pawn-white-4" ), 27 } },
		QSharedPointer< Figure >{ new Pawn{ 4, 6, Figure::White,
			QLatin1String( "pawn-white-5" ), 28 } },
		QSharedPointer< Figure >{ new Pawn{ 5, 6, Figure::White,
			QLatin1String( "pawn-white-6" ), 29 } },
		QSharedPointer< Figure >{ new Pawn{ 6, 6, Figure::White,
			QLatin1String( "pawn-white-7" ), 30 } },
		QSharedPointer< Figure >{ new Pawn{ 7, 6, Figure::White,
			QLatin1String( "pawn-white-8" ), 31 } }
	};

	return res;
}

Board::FiguresOnBoard &
Board::figures()
{
	return m_board;
}

Figure *
Board::figure( int index ) const
{
	return ( index < 32 ? m_figures.at( index ).data() :
		m_transformed.at( index - 32 ).data() );
}

void
Board::newGame()
{
	m_transformed.clear();

	m_figures.at( 0 )->setX( 0 );
	m_figures.at( 0 )->setY( 0 );
	m_figures.at( 1 )->setX( 1 );
	m_figures.at( 1 )->setY( 0 );
	m_figures.at( 2 )->setX( 2 );
	m_figures.at( 2 )->setY( 0 );
	m_figures.at( 3 )->setX( 3 );
	m_figures.at( 3 )->setY( 0 );
	m_figures.at( 4 )->setX( 4 );
	m_figures.at( 4 )->setY( 0 );
	m_figures.at( 5 )->setX( 5 );
	m_figures.at( 5 )->setY( 0 );
	m_figures.at( 6 )->setX( 6 );
	m_figures.at( 6 )->setY( 0 );
	m_figures.at( 7 )->setX( 7 );
	m_figures.at( 7 )->setY( 0 );

	m_figures.at( 8 )->setX( 0 );
	m_figures.at( 8 )->setY( 1 );
	m_figures.at( 9 )->setX( 1 );
	m_figures.at( 9 )->setY( 1 );
	m_figures.at( 10 )->setX( 2 );
	m_figures.at( 10 )->setY( 1 );
	m_figures.at( 11 )->setX( 3 );
	m_figures.at( 11 )->setY( 1 );
	m_figures.at( 12 )->setX( 4 );
	m_figures.at( 12 )->setY( 1 );
	m_figures.at( 13 )->setX( 5 );
	m_figures.at( 13 )->setY( 1 );
	m_figures.at( 14 )->setX( 6 );
	m_figures.at( 14 )->setY( 1 );
	m_figures.at( 15 )->setX( 7 );
	m_figures.at( 15 )->setY( 1 );

	for( int i = 8; i < 16; ++i )
		static_cast< Pawn* > ( m_figures.at( i ).data() )->setPass( false );

	m_figures.at( 16 )->setX( 0 );
	m_figures.at( 16 )->setY( 7 );
	m_figures.at( 17 )->setX( 1 );
	m_figures.at( 17 )->setY( 7 );
	m_figures.at( 18 )->setX( 2 );
	m_figures.at( 18 )->setY( 7 );
	m_figures.at( 19 )->setX( 3 );
	m_figures.at( 19 )->setY( 7 );
	m_figures.at( 20 )->setX( 4 );
	m_figures.at( 20 )->setY( 7 );
	m_figures.at( 21 )->setX( 5 );
	m_figures.at( 21 )->setY( 7 );
	m_figures.at( 22 )->setX( 6 );
	m_figures.at( 22 )->setY( 7 );
	m_figures.at( 23 )->setX( 7 );
	m_figures.at( 23 )->setY( 7 );

	m_figures.at( 24 )->setX( 0 );
	m_figures.at( 24 )->setY( 6 );
	m_figures.at( 25 )->setX( 1 );
	m_figures.at( 25 )->setY( 6 );
	m_figures.at( 26 )->setX( 2 );
	m_figures.at( 26 )->setY( 6 );
	m_figures.at( 27 )->setX( 3 );
	m_figures.at( 27 )->setY( 6 );
	m_figures.at( 28 )->setX( 4 );
	m_figures.at( 28 )->setY( 6 );
	m_figures.at( 29 )->setX( 5 );
	m_figures.at( 29 )->setY( 6 );
	m_figures.at( 30 )->setX( 6 );
	m_figures.at( 30 )->setY( 6 );
	m_figures.at( 31 )->setX( 7 );
	m_figures.at( 31 )->setY( 6 );

	for( int i = 24; i < 32; ++i )
		static_cast< Pawn* > ( m_figures.at( i ).data() )->setPass( false );

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

	std::for_each( m_figures.begin(), m_figures.end(),
		[] ( auto & figure ) { figure->firstMoveDone( false ); } );
}

void
Board::update()
{
	emit dataChanged( index( 0 ), index( 63 ) );
}

void
Board::move( int fromX, int fromY, int toX, int toY )
{
	Figure * from = m_board[ fromY ][ fromX ];

	if( from )
	{
		m_board[ fromY ][ fromX ] = 0;
		m_board[ toY ][ toX ] = from;

		from->setX( toX );
		from->setY( toY );

		const QModelIndex fromIndex = index( fromY * 8 + fromX, 0 );
		const QModelIndex toIndex = index( toY * 8 + toX, 0 );

		emit dataChanged( fromIndex, fromIndex );
		emit dataChanged( toIndex, toIndex );

		// Take on the pass.
		if( from->type() == Figure::PawnFigure )
		{
			Pawn * p = static_cast< Pawn* > ( from );

			switch( p->color() )
			{
				case Figure::White :
					toY += 1;
					break;

				case Figure::Black :
					toY -= 1;
					break;

				default :
					break;
			}

			if( m_board[ toY ][ toX ] &&
				m_board[ toY ][ toX ]->type() == Figure::PawnFigure )
			{
				Pawn * killed = static_cast< Pawn* > ( m_board[ toY ][ toX ] );

				if( killed && killed->isPass() )
				{
					m_board[ toY ][ toX ] = nullptr;

					const QModelIndex toIndex = index( toY * 8 + toX, 0 );

					emit dataChanged( toIndex, toIndex );
				}
			}
		}
	}
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

		case BorderColorRole :
			return QColor( Qt::lightGray );

		case BluePieceColorRole :
			return ( m_colors[ r ][ c ] == Blue ? true : false );

		case RedPieceColorRole :
			return ( m_colors[ r ][ c ] == Red ? true : false );

		case CheckPieceColorRole :
			return ( m_colors[ r ][ c ] == Check ? true : false );

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
	names[ CheckPieceColorRole ] = "CheckPieceColor";
	names[ BorderColorRole ] = "BorderColor";

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
Board::markCheck( int x, int y )
{
	m_colors[ y ][ x ] = Check;

	const QModelIndex idx = index( y * 8 + x, 0 );

	emit dataChanged( idx, idx );
}

void
Board::clearColors()
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

King *
Board::whiteKing() const
{
	return m_whiteKing;
}

King *
Board::blackKing() const
{
	return m_blackKing;
}

void
Board::transformation( Chess::Signals::TransformationFigure figure,
	Chess::Signals::Color c, int x, int y )
{
	switch( figure )
	{
		case Signals::Queen :
		{
			m_transformed.append( QSharedPointer< Figure> ( new Queen( x, y,
				( c == Signals::White ? Figure::White : Figure::Black ),
				QLatin1String( "queen" ), 32 + m_transformed.size() ) ) );

			m_board[ y ][ x ] = m_transformed.last().data();

			const QModelIndex idx = index( y * 8 + x, 0 );

			emit dataChanged( idx, idx );
		}
			break;

		case Signals::Castle :
		{
			m_transformed.append( QSharedPointer< Figure> ( new Castle( x, y,
				( c == Signals::White ? Figure::White : Figure::Black ),
				QLatin1String( "queen" ), 32 + m_transformed.size() ) ) );

			m_board[ y ][ x ] = m_transformed.last().data();

			const QModelIndex idx = index( y * 8 + x, 0 );

			emit dataChanged( idx, idx );
		}
			break;

		case Signals::Knight :
		{
			m_transformed.append( QSharedPointer< Figure> ( new Knight( x, y,
				( c == Signals::White ? Figure::White : Figure::Black ),
				QLatin1String( "queen" ), 32 + m_transformed.size() ) ) );

			m_board[ y ][ x ] = m_transformed.last().data();

			const QModelIndex idx = index( y * 8 + x, 0 );

			emit dataChanged( idx, idx );
		}
			break;

		case Signals::Bishop :
		{
			m_transformed.append( QSharedPointer< Figure> ( new Bishop( x, y,
				( c == Signals::White ? Figure::White : Figure::Black ),
				QLatin1String( "queen" ), 32 + m_transformed.size() ) ) );

			m_board[ y ][ x ] = m_transformed.last().data();

			const QModelIndex idx = index( y * 8 + x, 0 );

			emit dataChanged( idx, idx );
		}
			break;

		default :
			break;
	}
}

} /* namespace Chess */
