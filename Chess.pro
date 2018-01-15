
TEMPLATE = app
TARGET = chess
QT += qml
CONFIG += c++14

win32 {
    RC_FILE = chess.rc
}

OTHER_FILES =	Board.qml \
				Cell.qml \
				main.qml
				
SOURCES =	main.cpp \
			figures.cpp \
			board.cpp \
			game.cpp
			
HEADERS =	figures.hpp \
			board.hpp \
			game.hpp \
			signals.hpp

RESOURCES = resources.qrc

DISTFILES += \
    TransformDialog.qml \
    DrawGameDialog.qml \
    CheckMateDialog.qml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += android/AndroidManifest.xml
