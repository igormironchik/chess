
// Qt include.
#include <QGuiApplication>
#include <QQmlApplicationEngine>

// Chess include.
#include "game.hpp"

int main( int argc, char ** argv )
{
	QGuiApplication app( argc, argv );
	QQmlApplicationEngine engine( QUrl( "qrc:/main.qml" ) );

	if( engine.rootObjects().isEmpty() )
		return -1;

	try {
		Chess::Game game( engine.rootObjects().first() );

		return app.exec();
	}
	catch( const Chess::Error & )
	{
		return -1;
	}
}
