
// Qt include.
#include <QObject>
#include <QVector>

// Chess include.
#include "board.hpp"

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
	explicit Game( QObject * root );
	~Game();

private slots:
	//! Clicked.
	void clicked( int x, int y );
	//! Hovered.
	void hovered( int x, int y );

private:
	//! Mark cells for move.
	void markCellsForMove( int x, int y, int dx, int dy, Move::Distance d,
		Figure * figure );
	//! Mark cell for hit.
	void markCellForHit( int x, int y, int dx, int dy, Move::Distance d,
		Figure * figure );

private:
	//! Board.
	Board m_board;
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
}; // class Game

} /* namespace Chess */
