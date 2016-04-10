
// Chess include.
#include "figures.hpp"

// Qt include.
#include <QList>
#include <QSharedPointer>

namespace Chess {


//
// Board
//

//! Board.
class Board final {
public:
	Board();
	~Board();

	//! Figures on board.
	typedef Figure* FiguresOnBoard[ 8 ][ 8 ];

	//! \return Figures on board.
	FiguresOnBoard & figures();

	//! New game.
	void newGame();

private:
	//! Board.
	FiguresOnBoard m_board;
	//! Figures.
	static const QList< QSharedPointer< Figure > > m_figures;
}; // class Board

} /* namespace Chess */
