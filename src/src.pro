
TEMPLATE = app
TARGET = Chess
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
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml \
    qml/Cell.qml \
    qml/TransformRadioButton.qml \
	qml/main.qml \
    qml/TransformDialog.qml \
    qml/DrawGameDialog.qml \
    qml/CheckMateDialog.qml \
    qml/UndoBtn.qml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += android/AndroidManifest.xml

ANDROID_ABIS = armeabi-v7a x86_64
