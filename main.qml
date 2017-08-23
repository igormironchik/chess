
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
import QtQuick 2.0
import QtQuick.Controls 2.2
import ChessSignals 1.0

ApplicationWindow {
    id: appWindow
    visible: true

    property int offset: 16
    property int minSize: offset * 2 + 50 * 8

    width: minSize
    height: minSize + offset

    Rectangle {
        id: rect
        anchors.fill: parent

        Board {
            id: board
            width: Math.max( Math.min( parent.width, parent.height - offset ), minSize )
            height: Math.max( Math.min( parent.width, parent.height - offset ), minSize )
            anchors.horizontalCenter: rect.horizontalCenter

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

    Dialog {
        id: checkmate
        title: qsTr( "Checkmate..." )
        standardButtons: Dialog.Ok
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        x: appWindow.width / 2 - width / 2
        y: appWindow.height / 2 - height / 2

        Text {
            anchors.centerIn: parent
            font.pixelSize: 30
            font.bold: true
            text: ( turn.text === qsTr( "Black" ) ?
                qsTr( "White" ) : qsTr( "Black" ) ) + qsTr( " won!!!" )
        }

        onClosed: { board.newGame() }
    }

    Dialog {
        id: drawgame
        title: qsTr( "Draw Game..." )
        standardButtons: Dialog.Ok
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        x: appWindow.width / 2 - width / 2
        y: appWindow.height / 2 - height / 2

        Text {
            anchors.centerIn: parent
            font.pixelSize: 30
            font.bold: true
            text: qsTr( "Draw Game!!!" )
        }

        onClosed: { board.newGame() }
    }

    Dialog {
        id: transform
        title: qsTr( "Choose figure..." )
        standardButtons: Dialog.Ok
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape
        x: appWindow.width / 2 - width / 2
        y: appWindow.height / 2 - height / 2

        property int color: Chess.White
        property int fx: -1
        property int fy: -1
        property int figure: Chess.Queen

        contentItem: Rectangle {
            ButtonGroup {
                buttons: column.children
            }

            Column {
                id: column

                property alias figure: transform.figure

                RadioButton {
                    checked: true
                    text: qsTr( "Queen" )

                    onClicked: {
                        column.figure = Chess.Queen
                    }
                }

                RadioButton {
                    text: qsTr( "Castle" )

                    onClicked: {
                        column.figure = Chess.Castle
                    }
                }

                RadioButton {
                    text: qsTr( "Knight" )

                    onClicked: {
                        column.figure = Chess.Knight
                    }
                }

                RadioButton {
                    text: qsTr( "Bishop" )

                    onClicked: {
                        column.figure = Chess.Bishop
                    }
                }
            }
        }

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
    }
}
