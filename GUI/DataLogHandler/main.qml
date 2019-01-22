import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Rectangle {
    visible: true
    width: 640
    height: 480

    CheckBox {
        id: checkBox
        x: 14
        y: 8
        text: qsTr("Altitude")
        onCheckStateChanged: obj_DataLogHandler.set_activeAltitude(checked)
    }

    CheckBox {
        id: checkBox1
        x: 14
        y: 54
        text: qsTr("Attitude")
        onCheckStateChanged: obj_DataLogHandler.set_activeAttitude(checked)
    }

    CheckBox {
        id: checkBox2
        x: 14
        y: 100
        text: qsTr("3DPos")
        onCheckStateChanged: obj_DataLogHandler.set_active3DPosition(checked)
    }

    CheckBox {
        id: checkBox3
        x: 14
        y: 146
        text: qsTr("Coordinate")
        onCheckStateChanged: obj_DataLogHandler.set_activeCoordinate(checked)
    }


}
