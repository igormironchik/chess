
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

import QtQuick 2.0

Item {
    id: cell

    property alias cellColor: rectangle.color
    property int chessX
    property int chessY

    signal clicked( int x, int y )
    signal hovered( int x, int y )

    function clearColor() {
        blue.visible = false
        red.visible = false
    }

    function markBlue() {
        blue.visible = true
    }

    function markRed() {
        red.visible = true
    }

    Rectangle {
        id: rectangle
        anchors.fill: parent
    }

    Rectangle {
        id: blue
        visible: false
        anchors.fill: parent
        color: "#880000FF"
    }

    Rectangle {
        id: red
        visible: false
        anchors.fill: parent
        color: "#88FF0000"
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onClicked: cell.clicked( chessX, chessY )
        onEntered: cell.hovered( chessX, chessY )
    }
}
