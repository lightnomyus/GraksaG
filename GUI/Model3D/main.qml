import QtQuick 2.9
import QtQuick.Scene3D 2.0

Rectangle {
    visible: true
    width: 640
    height: 480

    Rectangle {
        id: rectangle
        x: 76
        y: 29
        width: 271
        height: 259
        color: "#ffffff"

        Scene3D{
            anchors.fill: parent
        }

    }


}
