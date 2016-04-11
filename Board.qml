
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

Rectangle {
    property int offset: 16
    property int cellWidth: ( width - offset * 2 ) / 8
    property int cellHeight: ( height - offset * 2 ) / 8

    id: board

    signal clicked( int x, int y )
    signal hovered( int x, int y )

    function clearColor() {
        c00.clearColor();
        c01.clearColor();
        c02.clearColor();
        c03.clearColor();
        c04.clearColor();
        c05.clearColor();
        c06.clearColor();
        c07.clearColor();

        c10.clearColor();
        c11.clearColor();
        c12.clearColor();
        c13.clearColor();
        c14.clearColor();
        c15.clearColor();
        c16.clearColor();
        c17.clearColor();

        c20.clearColor();
        c21.clearColor();
        c22.clearColor();
        c23.clearColor();
        c24.clearColor();
        c25.clearColor();
        c26.clearColor();
        c27.clearColor();

        c30.clearColor();
        c31.clearColor();
        c32.clearColor();
        c33.clearColor();
        c34.clearColor();
        c35.clearColor();
        c36.clearColor();
        c37.clearColor();

        c40.clearColor();
        c41.clearColor();
        c42.clearColor();
        c43.clearColor();
        c44.clearColor();
        c45.clearColor();
        c46.clearColor();
        c47.clearColor();

        c50.clearColor();
        c51.clearColor();
        c52.clearColor();
        c53.clearColor();
        c54.clearColor();
        c55.clearColor();
        c56.clearColor();
        c57.clearColor();

        c60.clearColor();
        c61.clearColor();
        c62.clearColor();
        c63.clearColor();
        c64.clearColor();
        c65.clearColor();
        c66.clearColor();
        c67.clearColor();

        c70.clearColor();
        c71.clearColor();
        c72.clearColor();
        c73.clearColor();
        c74.clearColor();
        c75.clearColor();
        c76.clearColor();
        c77.clearColor();
    }

    Cell { id: c00; x: offset; y: offset;
        cellColor: "white"; chessX: 0; chessY: 0;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c00";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c10; x: offset + cellWidth; y: offset;
        cellColor: "lightgray"; chessX: 1; chessY: 0;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c10";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c20; x: offset + cellWidth * 2; y: offset;
        cellColor: "white"; chessX: 2; chessY: 0;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c20";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c30; x: offset + cellWidth * 3; y: offset;
        cellColor: "lightgray"; chessX: 3; chessY: 0;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c30";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c40; x: offset + cellWidth * 4; y: offset;
        cellColor: "white"; chessX: 4; chessY: 0;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c40";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c50; x: offset + cellWidth * 5; y: offset;
        cellColor: "lightgray"; chessX: 5; chessY: 0;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c50";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c60; x: offset + cellWidth * 6; y: offset;
        cellColor: "white"; chessX: 6; chessY: 0;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c60";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c70; x: offset + cellWidth * 7; y: offset;
        cellColor: "lightgray"; chessX: 7; chessY: 0;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c70";
        width: cellWidth;
        height: cellHeight; }

    Cell { id: c01; x: offset; y: offset + cellHeight;
        cellColor: "lightgray"; chessX: 0; chessY: 1;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c01";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c11; x: offset + cellWidth; y: offset + cellHeight;
        cellColor: "white"; chessX: 1; chessY: 1;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c11";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c21; x: offset + cellWidth * 2; y: offset + cellHeight;
        cellColor: "lightgray"; chessX: 2; chessY: 1;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c21";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c31; x: offset + cellWidth * 3; y: offset + cellHeight;
        cellColor: "white"; chessX: 3; chessY: 1;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c31";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c41; x: offset + cellWidth * 4; y: offset + cellHeight;
        cellColor: "lightgray"; chessX: 4; chessY: 1;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c41";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c51; x: offset + cellWidth * 5; y: offset + cellHeight;
        cellColor: "white"; chessX: 5; chessY: 1;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c51";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c61; x: offset + cellWidth * 6; y: offset + cellHeight;
        cellColor: "lightgray"; chessX: 6; chessY: 1;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c61";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c71; x: offset + cellWidth * 7; y: offset + cellHeight;
        cellColor: "white"; chessX: 7; chessY: 1;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c71";
        width: cellWidth;
        height: cellHeight; }

    Cell { id: c02; x: offset; y: offset + cellHeight * 2;
        cellColor: "white"; chessX: 0; chessY: 2;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c02";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c12; x: offset + cellWidth; y: offset + cellHeight * 2;
        cellColor: "lightgray"; chessX: 1; chessY: 2;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c12";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c22; x: offset + cellWidth * 2; y: offset + cellHeight * 2;
        cellColor: "white"; chessX: 2; chessY: 2;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c22";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c32; x: offset + cellWidth * 3; y: offset + cellHeight * 2;
        cellColor: "lightgray"; chessX: 3; chessY: 2;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c32";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c42; x: offset + cellWidth * 4; y: offset + cellHeight * 2;
        cellColor: "white"; chessX: 4; chessY: 2;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c42";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c52; x: offset + cellWidth * 5; y: offset + cellHeight * 2;
        cellColor: "lightgray"; chessX: 5; chessY: 2;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c52";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c62; x: offset + cellWidth * 6; y: offset + cellHeight * 2;
        cellColor: "white"; chessX: 6; chessY: 2;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c62";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c72; x: offset + cellWidth * 7; y: offset + cellHeight * 2;
        cellColor: "lightgray"; chessX: 7; chessY: 2;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c72";
        width: cellWidth;
        height: cellHeight; }

    Cell { id: c03; x: offset; y: offset + cellHeight * 3;
        cellColor: "lightgray"; chessX: 0; chessY: 3;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c03";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c13; x: offset + cellWidth; y: offset + cellHeight * 3;
        cellColor: "white"; chessX: 1; chessY: 3;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c13";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c23; x: offset + cellWidth * 2; y: offset + cellHeight * 3;
        cellColor: "lightgray"; chessX: 2; chessY: 3;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c23";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c33; x: offset + cellWidth * 3; y: offset + cellHeight * 3;
        cellColor: "white"; chessX: 3; chessY: 3;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c33";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c43; x: offset + cellWidth * 4; y: offset + cellHeight * 3;
        cellColor: "lightgray"; chessX: 4; chessY: 3;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c43";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c53; x: offset + cellWidth * 5; y: offset + cellHeight * 3;
        cellColor: "white"; chessX: 5; chessY: 3;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c53";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c63; x: offset + cellWidth * 6; y: offset + cellHeight * 3;
        cellColor: "lightgray"; chessX: 6; chessY: 3;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c63";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c73; x: offset + cellWidth * 7; y: offset + cellHeight * 3;
        cellColor: "white"; chessX: 7; chessY: 3;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c73";
        width: cellWidth;
        height: cellHeight; }

    Cell { id: c04; x: offset; y: offset + cellHeight * 4;
        cellColor: "white"; chessX: 0; chessY: 4;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c04";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c14; x: offset + cellWidth; y: offset + cellHeight * 4;
        cellColor: "lightgray"; chessX: 1; chessY: 4;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c14";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c24; x: offset + cellWidth * 2; y: offset + cellHeight * 4;
        cellColor: "white"; chessX: 2; chessY: 4;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c24";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c34; x: offset + cellWidth * 3; y: offset + cellHeight * 4;
        cellColor: "lightgray"; chessX: 3; chessY: 4;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c34";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c44; x: offset + cellWidth * 4; y: offset + cellHeight * 4;
        cellColor: "white"; chessX: 4; chessY: 4;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c44";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c54; x: offset + cellWidth * 5; y: offset + cellHeight * 4;
        cellColor: "lightgray"; chessX: 5; chessY: 4;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c54";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c64; x: offset + cellWidth * 6; y: offset + cellHeight * 4;
        cellColor: "white"; chessX: 6; chessY: 4;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c64";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c74; x: offset + cellWidth * 7; y: offset + cellHeight * 4;
        cellColor: "lightgray"; chessX: 7; chessY: 4;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c74";
        width: cellWidth;
        height: cellHeight; }

    Cell { id: c05; x: offset; y: offset + cellHeight * 5;
        cellColor: "lightgray"; chessX: 0; chessY: 5;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c05";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c15; x: offset + cellWidth; y: offset + cellHeight * 5;
        cellColor: "white"; chessX: 1; chessY: 5;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c15";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c25; x: offset + cellWidth * 2; y: offset + cellHeight * 5;
        cellColor: "lightgray"; chessX: 2; chessY: 5;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c25";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c35; x: offset + cellWidth * 3; y: offset + cellHeight * 5;
        cellColor: "white"; chessX: 3; chessY: 5;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c35";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c45; x: offset + cellWidth * 4; y: offset + cellHeight * 5;
        cellColor: "lightgray"; chessX: 4; chessY: 5;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c45";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c55; x: offset + cellWidth * 5; y: offset + cellHeight * 5;
        cellColor: "white"; chessX: 5; chessY: 5;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c55";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c65; x: offset + cellWidth * 6; y: offset + cellHeight * 5;
        cellColor: "lightgray"; chessX: 6; chessY: 5;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c65";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c75; x: offset + cellWidth * 7; y: offset + cellHeight * 5;
        cellColor: "white"; chessX: 7; chessY: 5;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c75";
        width: cellWidth;
        height: cellHeight; }

    Cell { id: c06; x: offset; y: offset + cellHeight * 6;
        cellColor: "white"; chessX: 0; chessY: 6;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c06";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c16; x: offset + cellWidth; y: offset + cellHeight * 6;
        cellColor: "lightgray"; chessX: 1; chessY: 6;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c16";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c26; x: offset + cellWidth * 2; y: offset + cellHeight * 6;
        cellColor: "white"; chessX: 2; chessY: 6;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c26";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c36; x: offset + cellWidth * 3; y: offset + cellHeight * 6;
        cellColor: "lightgray"; chessX: 3; chessY: 6;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c36";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c46; x: offset + cellWidth * 4; y: offset + cellHeight * 6;
        cellColor: "white"; chessX: 4; chessY: 6;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c46";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c56; x: offset + cellWidth * 5; y: offset + cellHeight * 6;
        cellColor: "lightgray"; chessX: 5; chessY: 6;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c56";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c66; x: offset + cellWidth * 6; y: offset + cellHeight * 6;
        cellColor: "white"; chessX: 6; chessY: 6;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c66";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c76; x: offset + cellWidth * 7; y: offset + cellHeight * 6;
        cellColor: "lightgray"; chessX: 7; chessY: 6;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c76";
        width: cellWidth;
        height: cellHeight; }

    Cell { id: c07; x: offset; y: offset + cellHeight * 7;
        cellColor: "lightgray"; chessX: 0; chessY: 7;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c07";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c17; x: offset + cellWidth; y: offset + cellHeight * 7;
        cellColor: "white"; chessX: 1; chessY: 7;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c17";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c27; x: offset + cellWidth * 2; y: offset + cellHeight * 7;
        cellColor: "lightgray"; chessX: 2; chessY: 7;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c27";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c37; x: offset + cellWidth * 3; y: offset + cellHeight * 7;
        cellColor: "white"; chessX: 3; chessY: 7;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c37";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c47; x: offset + cellWidth * 4; y: offset + cellHeight * 7;
        cellColor: "lightgray"; chessX: 4; chessY: 7;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c47";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c57; x: offset + cellWidth * 5; y: offset + cellHeight * 7;
        cellColor: "white"; chessX: 5; chessY: 7;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c57";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c67; x: offset + cellWidth * 6; y: offset + cellHeight * 7;
        cellColor: "lightgray"; chessX: 6; chessY: 7;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c67";
        width: cellWidth;
        height: cellHeight; }
    Cell { id: c77; x: offset + cellWidth * 7; y: offset + cellHeight * 7;
        cellColor: "white"; chessX: 7; chessY: 7;
        onClicked: board.clicked( x, y );
        onHovered: board.hovered( x, y );
        objectName: "c77";
        width: cellWidth;
        height: cellHeight; }

    // Left side.

    Item {
        id: leftLine
        x: offset / 2
        y: 0
        width: 1
        height: 1
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "8"
        anchors.verticalCenter: c00.verticalCenter
        anchors.horizontalCenter: leftLine.horizontalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "7"
        anchors.verticalCenter: c01.verticalCenter
        anchors.horizontalCenter: leftLine.horizontalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "6"
        anchors.verticalCenter: c02.verticalCenter
        anchors.horizontalCenter: leftLine.horizontalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "5"
        anchors.verticalCenter: c03.verticalCenter
        anchors.horizontalCenter: leftLine.horizontalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "4"
        anchors.verticalCenter: c04.verticalCenter
        anchors.horizontalCenter: leftLine.horizontalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "3"
        anchors.verticalCenter: c05.verticalCenter
        anchors.horizontalCenter: leftLine.horizontalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "2"
        anchors.verticalCenter: c06.verticalCenter
        anchors.horizontalCenter: leftLine.horizontalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "1"
        anchors.verticalCenter: c07.verticalCenter
        anchors.horizontalCenter: leftLine.horizontalCenter
    }

    // Bottom side.

    Item {
        id: bottomLine
        x: 0
        y: offset + cellWidth * 8 + offset / 2
        width: 1
        height: 1
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "A"
        anchors.horizontalCenter: c07.horizontalCenter
        anchors.verticalCenter: bottomLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "B"
        anchors.horizontalCenter: c17.horizontalCenter
        anchors.verticalCenter: bottomLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "C"
        anchors.horizontalCenter: c27.horizontalCenter
        anchors.verticalCenter: bottomLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "D"
        anchors.horizontalCenter: c37.horizontalCenter
        anchors.verticalCenter: bottomLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "E"
        anchors.horizontalCenter: c47.horizontalCenter
        anchors.verticalCenter: bottomLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "F"
        anchors.horizontalCenter: c57.horizontalCenter
        anchors.verticalCenter: bottomLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "G"
        anchors.horizontalCenter: c67.horizontalCenter
        anchors.verticalCenter: bottomLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "H"
        anchors.horizontalCenter: c77.horizontalCenter
        anchors.verticalCenter: bottomLine.verticalCenter
    }

    // Top side.

    Item {
        id: topLine
        x: 0
        y: offset / 2
        width: 1
        height: 1
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "A"
        anchors.horizontalCenter: c00.horizontalCenter
        anchors.verticalCenter: topLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "B"
        anchors.horizontalCenter: c10.horizontalCenter
        anchors.verticalCenter: topLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "C"
        anchors.horizontalCenter: c20.horizontalCenter
        anchors.verticalCenter: topLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "D"
        anchors.horizontalCenter: c30.horizontalCenter
        anchors.verticalCenter: topLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "E"
        anchors.horizontalCenter: c40.horizontalCenter
        anchors.verticalCenter: topLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "F"
        anchors.horizontalCenter: c50.horizontalCenter
        anchors.verticalCenter: topLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "G"
        anchors.horizontalCenter: c60.horizontalCenter
        anchors.verticalCenter: topLine.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "H"
        anchors.horizontalCenter: c70.horizontalCenter
        anchors.verticalCenter: topLine.verticalCenter
    }

    // Right side.

    Item {
        id: rightLine
        x: offset + cellWidth * 8 + 8
        y: 0
        width: 1
        height: 1
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "8"
        anchors.horizontalCenter: rightLine.horizontalCenter
        anchors.verticalCenter: c70.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "7"
        anchors.horizontalCenter: rightLine.horizontalCenter
        anchors.verticalCenter: c71.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "6"
        anchors.horizontalCenter: rightLine.horizontalCenter
        anchors.verticalCenter: c72.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "5"
        anchors.horizontalCenter: rightLine.horizontalCenter
        anchors.verticalCenter: c73.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "4"
        anchors.horizontalCenter: rightLine.horizontalCenter
        anchors.verticalCenter: c74.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "3"
        anchors.horizontalCenter: rightLine.horizontalCenter
        anchors.verticalCenter: c75.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "2"
        anchors.horizontalCenter: rightLine.horizontalCenter
        anchors.verticalCenter: c76.verticalCenter
    }

    Text {
        font.pixelSize: 14; font.bold: true
        text: "1"
        anchors.horizontalCenter: rightLine.horizontalCenter
        anchors.verticalCenter: c77.verticalCenter
    }

    // White.

    Figure {
        source: "qrc:/img/pawn-white.png"
        x: c06.x
        y: c06.y
        objectName: "pawn-white-1"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-white.png"
        x: c16.x
        y: c16.y
        objectName: "pawn-white-2"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-white.png"
        x: c26.x
        y: c26.y
        objectName: "pawn-white-3"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-white.png"
        x: c36.x
        y: c36.y
        objectName: "pawn-white-4"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-white.png"
        x: c46.x
        y: c46.y
        objectName: "pawn-white-5"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-white.png"
        x: c56.x
        y: c56.y
        objectName: "pawn-white-6"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-white.png"
        x: c66.x
        y: c66.y
        objectName: "pawn-white-7"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-white.png"
        x: c76.x
        y: c76.y
        objectName: "pawn-white-8"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/castle-white.png"
        x: c07.x
        y: c07.y
        objectName: "castle-white-1"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/knight-white.png"
        x: c17.x
        y: c17.y
        objectName: "knight-white-1"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/bishop-white.png"
        x: c27.x
        y: c27.y
        objectName: "bishop-white-1"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/queen-white.png"
        x: c37.x
        y: c37.y
        objectName: "queen-white"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/king-white.png"
        x: c47.x
        y: c47.y
        objectName: "king-white"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/bishop-white.png"
        x: c57.x
        y: c57.y
        objectName: "bishop-white-2"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/knight-white.png"
        x: c67.x
        y: c67.y
        objectName: "knight-white-2"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/castle-white.png"
        x: c77.x
        y: c77.y
        objectName: "castle-white-2"
        width: cellWidth
        height: cellHeight
    }

    // Black.

    Figure {
        source: "qrc:/img/pawn-black.png"
        x: c01.x
        y: c01.y
        objectName: "pawn-black-1"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-black.png"
        x: c11.x
        y: c11.y
        objectName: "pawn-black-2"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-black.png"
        x: c21.x
        y: c21.y
        objectName: "pawn-black-3"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-black.png"
        x: c31.x
        y: c31.y
        objectName: "pawn-black-4"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-black.png"
        x: c41.x
        y: c41.y
        objectName: "pawn-black-5"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-black.png"
        x: c51.x
        y: c51.y
        objectName: "pawn-black-6"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-black.png"
        x: c61.x
        y: c61.y
        objectName: "pawn-black-7"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/pawn-black.png"
        x: c71.x
        y: c71.y
        objectName: "pawn-black-8"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/castle-black.png"
        x: c00.x
        y: c00.y
        objectName: "castle-black-1"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/knight-black.png"
        x: c10.x
        y: c10.y
        objectName: "knight-black-1"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/bishop-black.png"
        x: c20.x
        y: c20.y
        objectName: "bishop-black-1"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/queen-black.png"
        x: c30.x
        y: c30.y
        objectName: "queen-black"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/king-black.png"
        x: c40.x
        y: c40.y
        objectName: "king-black"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/bishop-black.png"
        x: c50.x
        y: c50.y
        objectName: "bishop-black-2"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/knight-black.png"
        x: c60.x
        y: c60.y
        objectName: "knight-black-2"
        width: cellWidth
        height: cellHeight
    }

    Figure {
        source: "qrc:/img/castle-black.png"
        x: c70.x
        y: c70.y
        objectName: "castle-black-2"
        width: cellWidth
        height: cellHeight
    }
}
