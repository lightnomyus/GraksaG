import QtQuick 2.9
import QtQuick.Scene3D 2.0
import QtQuick.Controls 1.6

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
                        id: model_payload
                    }
                }

    }

    SpinBox {
        id: spinBox
        x: 81
        y: 346
        onValueChanged: obj_tester.send_Data(spinBox2.value,spinBox.value,spinBox1.value)
    }

    Label {
        id: label
        x: 81
        y: 327
        text: qsTr("x(pitch)")
    }

    SpinBox {
        id: spinBox1
        x: 145
        y: 346
        onValueChanged: obj_tester.send_Data(spinBox2.value,spinBox.value,spinBox1.value)
    }

    Label {
        id: label1
        x: 145
        y: 327
        text: qsTr("y(yaw)")
    }

    SpinBox {
        id: spinBox2
        x: 218
        y: 346
        onValueChanged: obj_tester.send_Data(spinBox2.value,spinBox.value,spinBox1.value)
    }

    Label {
        id: label2
        x: 218
        y: 327
        text: qsTr("z(roll)")
    }




}
