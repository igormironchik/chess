
cmake_minimum_required( VERSION 3.1 )

if( NOT CMAKE_BUILD_TYPE )
	set( CMAKE_BUILD_TYPE "Release"
		CACHE STRING "Choose the type of build."
		FORCE)
endif( NOT CMAKE_BUILD_TYPE )

SET( CMAKE_CXX_STANDARD 14 )

SET( CMAKE_CXX_STANDARD_REQUIRED ON )

project( Chess )

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )
set( CMAKE_AUTOUIC ON )

find_package( Qt6Qml REQUIRED )
find_package( Qt6Gui REQUIRED )

set( SRC main.cpp
    figures.cpp
    board.cpp
	game.cpp
	figures.hpp
    board.hpp
    game.hpp
    signals.hpp
    qml/Board.qml
    qml/Cell.qml
    qml/TransformRadioButton.qml
	qml/main.qml
    qml/TransformDialog.qml
    qml/DrawGameDialog.qml
    qml/CheckMateDialog.qml
    qml/UndoBtn.qml )
    
if( WIN32 )
	list( APPEND SRC chess.rc )
endif()

set( CMAKE_CXX_STANDARD 14 )

set( CMAKE_CXX_STANDARD_REQUIRED ON )

qt6_add_resources( SRC resources.qrc )

qt_add_executable( Chess
	MANUAL_FINALIZATION
	${SRC} )

set_property( TARGET Chess APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/android )

target_link_libraries( Chess PUBLIC Qt::Qml Qt::Gui )

qt_finalize_executable( Chess )
