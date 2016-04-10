
// Qt include.
#include <QFlags>
#include <QString>


namespace Chess {

//
// Move
//

//! Move.
class Move final {
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

	Figure( int xv, int yv, Color c, const QString & name );
	virtual ~Figure();

	//! Moves.
	typedef Move Moves[ 5 ][ 5 ];

	//! \return Possible moves.
	virtual const Moves & moves() const = 0;

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
	void firstMoveDone();

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
}; // class Figure


//
// Pawn.
//

//! Pawn.
class Pawn final
	:	public Figure
{
public:
	Pawn( int xv, int yv, Color c, const QString & n );
	~Pawn();

	//! \return Possible moves.
	const Moves & moves() const;

private:
	static const Moves m_moves;
}; // class Pawn


//
// Castle
//

//! Castle.
class Castle final
	:	public Figure
{
public:
	Castle( int xv, int yv, Color c, const QString & n );
	~Castle();

	//! \return Possible moves.
	const Moves & moves() const;

private:
	static const Moves m_moves;
}; // class Castle


//
// Knight
//

//! Knight.
class Knight final
	:	public Figure
{
public:
	Knight( int xv, int yv, Color c, const QString & n );
	~Knight();

	//! \return Possible moves.
	const Moves & moves() const;

private:
	static const Moves m_moves;
}; // class Knight


//
// Bishop
//

//! Bishop.
class Bishop final
	:	public Figure
{
public:
	Bishop( int xv, int yv, Color c, const QString & n );
	~Bishop();

	//! \return Possible moves.
	const Moves & moves() const;

private:
	static const Moves m_moves;
}; // class


//
// Queen
//

//! Queen.
class Queen final
	:	public Figure
{
public:
	Queen( int xv, int yv, Color c, const QString & n );
	~Queen();

	//! \return Possible moves.
	const Moves & moves() const;

private:
	static const Moves m_moves;
}; // class Queen


//
// King
//

//! King.
class King final
	:	public Figure
{
public:
	King( int xv, int yv, Color c, const QString & n );
	~King();

	//! \return Possible moves.
	const Moves & moves() const;

private:
	static const Moves m_moves;
}; // class King

} /* namespace Chess */

Q_DECLARE_OPERATORS_FOR_FLAGS( Chess::Move::Types )
