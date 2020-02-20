
TEMPLATE = app
TARGET = chess
QT += qml
CONFIG += c++14

win32 {
    RC_FILE = chess.rc
}

SOURCES =	main.cpp \
			figures.cpp \
			board.cpp \
			game.cpp
			
HEADERS =	figures.hpp \
			board.hpp \
			game.hpp \
			signals.hpp

RESOURCES = resources.qrc

DISTFILES += qml/Board.qml \
    qml/Cell.qml \
	qml/main.qml \
    qml/TransformDialog.qml \
    qml/DrawGameDialog.qml \
    qml/CheckMateDialog.qml \
    qml/UndoBtn.qml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += android/AndroidManifest.xml
