import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Rectangle {
    id: root
    visible: true
    width: 640
    height: 535

    SerialSetting{
        id: hahaha
    }

    Rectangle{
        x: 8
        y: 327
        width: 624
        height: 200

        Terminal{
            anchors.fill: parent

        }
    }


}
