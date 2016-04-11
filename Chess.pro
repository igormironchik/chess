
TEMPLATE = app
TARGET = chess
QT += qml
CONFIG += c++14

OTHER_FILES =	Board.qml \
				Cell.qml \
				main.qml
				
SOURCES =	main.cpp \
			figures.cpp \
			board.cpp \
			game.cpp
			
HEADERS =	figures.hpp \
			board.hpp \
			game.hpp

RESOURCES = resources.qrc
