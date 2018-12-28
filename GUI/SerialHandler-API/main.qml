import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Rectangle {
    id: root
    visible: true
    width: 640
    height: 480

    SerialSetting{
        id: hahaha
    }

    Rectangle{
        anchors.left: hahaha.right
        width: 271
        height: 316
        color: "#e7afaf"
        Terminal{
            anchors.fill: parent
        }
    }


}
