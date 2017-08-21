
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

import QtQuick 2.5

Rectangle {
    property int offset: 16
    property int cellWidth: ( width - offset * 2 ) / 8
    property int cellHeight: ( height - offset * 2 ) / 8

    id: board

    signal clicked( int x, int y )
    signal hovered( int x, int y )
    signal newGame()

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
                font.pixelSize: 14
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
                font.pixelSize: 14
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
                chessX: index % 8
                chessY: index / 8
                onClicked: board.clicked( x, y )
                onHovered: board.hovered( x, y )
                objectName: "c"+ chessX + chessY
                width: cellWidth
                height: cellHeight
                source: model.CellImageSource
                blueProp: model.BluePieceColor
                redProp: model.RedPieceColor
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
                font.pixelSize: 14
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
                font.pixelSize: 14
            }
        }
        Item { width: offset; height: offset; }
    }
}
