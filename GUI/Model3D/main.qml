import QtQuick 2.9
import QtQuick.Scene3D 2.0

Rectangle {
    visible: true
    width: 640
    height: 480

    Rectangle {
        id: rectangle
        x: 8
        y: 8
        width: 624
        height: 280
        color: "#ffffff"

        Scene3D{
            anchors.fill: parent
            Model3D{

            }
        }

    }


}
