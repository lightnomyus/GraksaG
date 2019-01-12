import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick 2.9

Rectangle {
    id: root
    visible: true
    width: 640
    height: 480

    Button {
        id: button
        x: 35
        y: 33
        text: qsTr("New Mission")
    }

    Button {
        id: button1
        x: 159
        y: 33
        text: qsTr("Start Writing")
    }

    Button {
        id: button2
        x: 285
        y: 33
        text: qsTr("End Writing")
    }

    Button {
        id: button3
        x: 412
        y: 33
        text: qsTr("Send Data")
    }

    SpinBox {
        id: spinBox
        x: 35
        y: 171
    }

    Label {
        id: label
        x: 41
        y: 152
        text: qsTr("alt")
    }

    SpinBox {
        id: spinBox1
        x: 88
        y: 171
    }

    Label {
        id: label1
        x: 94
        y: 152
        text: qsTr("lon")
    }

    SpinBox {
        id: spinBox2
        x: 143
        y: 171
    }

    Label {
        id: label2
        x: 149
        y: 152
        text: qsTr("lat")
    }

    SpinBox {
        id: spinBox3
        x: 194
        y: 171
    }

    Label {
        id: label3
        x: 200
        y: 152
        text: qsTr("roll")
    }

    SpinBox {
        id: spinBox4
        x: 247
        y: 171
    }

    Label {
        id: label4
        x: 253
        y: 152
        text: qsTr("pitch")
    }

    SpinBox {
        id: spinBox5
        x: 302
        y: 171
    }

    Label {
        id: label5
        x: 308
        y: 152
        text: qsTr("yaw")
    }

    SpinBox {
        id: spinBox6
        x: 354
        y: 171
    }

    Label {
        id: label6
        x: 360
        y: 152
        text: qsTr("xpos")
    }

    SpinBox {
        id: spinBox7
        x: 407
        y: 171
    }

    Label {
        id: label7
        x: 413
        y: 152
        text: qsTr("ypos")
    }

    SpinBox {
        id: spinBox8
        x: 462
        y: 171
    }

    Label {
        id: label8
        x: 468
        y: 152
        text: qsTr("zpos")
    }

//    SpinBox {
//        id: spinBox
//        x: 35
//        y: 157
//    }
}
