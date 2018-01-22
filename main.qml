
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

import QtQuick.Window 2.2
import QtQuick 2.7
import QtQuick.Controls 2.2
import ChessSignals 1.0

ApplicationWindow {
    id: appWindow
    visible: true

    property int offset: 16
    property int minSize: offset * 2 + 50 * 8

    width: minSize
    height: minSize + offset + 64

    Rectangle {
        id: rect
        anchors.fill: parent

        UndoBtn {
            id: undoBtn
            width: Math.min( Math.min( appWindow.width, appWindow.height ) / 10, 64 )
            height: width
            x: appWindow.width - width - 10
            y: 10
        }

        Board {
            id: board
            width: Math.min( parent.width,
                parent.height - offset - undoBtn.height - 10 - turn.height )
            height: Math.min( parent.width,
                parent.height - offset - undoBtn.height - 10 - turn.height )
            x: Math.abs( rect.width - width ) / 2
            y: Math.abs( rect.height - height - turn.height - undoBtn.height - 10 ) / 2 + undoBtn.height + 10

            objectName: "board"
        }

        Text {
            id: turn
            objectName: "turn"
            height: offset
            anchors.horizontalCenter: rect.horizontalCenter
            y: board.y + board.height
            font.bold: true
            font.pixelSize: 14

            text: qsTr( "White" )
        }
    }

    CheckMateDialog {
        id: checkmate

        appWindowSize: Qt.size( appWindow.width, appWindow.height )
        turnText: turn.text

        onClosed: { board.newGame() }
    }

    DrawGameDialog {
        id: drawgame

        appWindowSize: Qt.size( appWindow.width, appWindow.height )

        onClosed: { board.newGame() }
    }

    TransformDialog {
        id: transform

        appWindowSize: Qt.size( appWindow.width, appWindow.height )

        onClosed: { board.transformation( figure, color, fx, fy ) }
    }

    Connections {
        target: game

        onCheckmate: {
            checkmate.open()
        }

        onDrawgame: {
            drawgame.open()
        }

        onPawnTransformation: {
            transform.color = color
            transform.fx = fx
            transform.fy = fy

            transform.open()
        }

        onNoMoreUndo: {
            undoBtn.disable()
        }

        onTurnMade: {
            undoBtn.enable()
        }
    }
}
