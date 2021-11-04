
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

import QtQuick 2.7
import QtQuick.Window 2.15

Rectangle {
    property int offset: ( Screen.pixelDensity * 25.4 * 14 ) / 72 + 2
    property int cellWidth: ( width - offset * 2 ) / 8
    property int cellHeight: ( height - offset * 2 ) / 8

    id: board
    transform: rot

    property alias rotation: rot.angle

    Rotation {
        id: rot
        origin.x: board.width / 2
        origin.y: board.height / 2
        angle: 0
    }

    PropertyAnimation {
        id: anim
        duration: 300
        target: board
        from: ( rot.angle === 0 ? 0 : ( rot.angle === 360 ? 0 : 180 ) )
        to: ( rot.angle === 0 ? 180 : ( rot.angle === 360 ? 180 : 360 ) )
        property: "rotation"
    }

    Connections {
        target: game

        function onRotate( angle ) {
            if( angle === -1 )
                anim.start()
            else
                rot.angle = 0
        }
    }

    Connections {
        target: anim

        function onStarted() {
            rotationStarted()
        }

        function onStopped() {
            rotationDone()
        }
    }

    signal clicked( int x, int y )
    signal hovered( int x, int y )
    signal newGame()
    signal transformation( int figure, int color, int x, int y );
    signal undo()
    signal rotationDone()
    signal rotationStarted()

    Row {
        id: top
        height: offset

        // Top letters.
        Item { width: offset; height: offset; }
        Repeater {
            model: [ "A", "B", "C", "D", "E", "F", "G", "H" ]
            delegate: Text {
                width: cellWidth
                height: offset
                text: modelData
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 14
                transform: Rotation {
                    origin.x: width / 2
                    origin.y: height / 2
                    angle: rot.angle
                }
            }
        }
        Item { width: offset; height: offset; }
    }

    Column {
        y: top.y + top.height

        // Left letters.
        Repeater {
            model: 8

            delegate: Text {
                width: offset
                height: cellHeight
                text: 8 - index
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 14
                transform: Rotation {
                    origin.x: width / 2
                    origin.y: height / 2
                    angle: rot.angle
                }
           }
        }
    }

    Grid {
        id: grid
        rows: 8
        columns: 8
        x: offset
        y: top.y + top.height
        objectName: "grid"

        // Chess board.
        Repeater {
            model: chessBoard

            delegate: Cell {
                cellColor: model.CurrentPieceColor
                border.color: model.BorderColor
                chessX: index % 8
                chessY: index / 8
                onClicked: ( x, y ) => { board.clicked( x, y ) }
                objectName: "c"+ chessX + chessY
                width: cellWidth
                height: cellHeight
                source: model.CellImageSource
                blueProp: model.BluePieceColor
                redProp: model.RedPieceColor
                checkProp: model.CheckPieceColor
                transform: Rotation {
                    origin.x: width / 2
                    origin.y: height / 2
                    angle: rot.angle
                }
            }
        }
    }

    Column {
        y: grid.y
        x: grid.x + grid.width

        // Right numbers.
        Repeater {
            model: 8

            delegate: Text {
                width: offset
                height: cellHeight
                text: 8 - index
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 14
                transform: Rotation {
                    origin.x: width / 2
                    origin.y: height / 2
                    angle: rot.angle
                }
           }
        }
    }

    Row {
        id: bottom
        height: offset
        y: grid.y + grid.height

        // Bottom letters.
        Item { width: offset; height: offset; }
        Repeater {
            model: [ "A", "B", "C", "D", "E", "F", "G", "H" ]
            delegate: Text {
                width: cellWidth
                height: offset
                text: modelData
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 14
                transform: Rotation {
                    origin.x: width / 2
                    origin.y: height / 2
                    angle: rot.angle
                }
            }
        }
        Item { width: offset; height: offset; }
    }
}
