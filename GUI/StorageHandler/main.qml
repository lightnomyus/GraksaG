import QtQuick.Controls 2.4
import QtQuick 2.12

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
        onPressed: dialog.open()
    }

    Button {
        id: button1
        x: 159
        y: 33
        text: qsTr("Start Writing")
        onPressed: obj_Tester.command_StartWriting()
    }

    Button {
        id: button2
        x: 285
        y: 33
        text: qsTr("End Writing")
        onPressed: obj_Tester.command_EndWriting()
    }

    Button {
        id: button3
        x: 412
        y: 33
        text: qsTr("Send Data")
        onPressed: obj_Tester.send_Data(spinBox.value,spinBox1.value,spinBox2.value,
                                        spinBox3.value,spinBox4.value,spinBox5.value,
                                        spinBox6.value,spinBox7.value,spinBox8.value)
    }

    SpinBox {
        id: spinBox
        x: 35
        y: 106
    }

    Label {
        id: label
        x: 41
        y: 87
        text: qsTr("alt")
    }

    SpinBox {
        id: spinBox1
        x: 35
        y: 171
    }

    Label {
        id: label1
        x: 41
        y: 152
        text: qsTr("lon")
    }

    SpinBox {
        id: spinBox2
        x: 35
        y: 236
    }

    Label {
        id: label2
        x: 41
        y: 217
        text: qsTr("lat")
    }

    SpinBox {
        id: spinBox3
        x: 35
        y: 301
    }

    Label {
        id: label3
        x: 41
        y: 282
        text: qsTr("roll")
    }

    SpinBox {
        id: spinBox4
        x: 35
        y: 366
    }

    Label {
        id: label4
        x: 41
        y: 347
        text: qsTr("pitch")
    }

    SpinBox {
        id: spinBox5
        x: 206
        y: 106
    }

    Label {
        id: label5
        x: 212
        y: 87
        text: qsTr("yaw")
    }

    SpinBox {
        id: spinBox6
        x: 206
        y: 171
    }

    Label {
        id: label6
        x: 212
        y: 152
        text: qsTr("xpos")
    }

    SpinBox {
        id: spinBox7
        x: 206
        y: 236
    }

    Label {
        id: label7
        x: 212
        y: 217
        text: qsTr("ypos")
    }

    SpinBox {
        id: spinBox8
        x: 206
        y: 301
    }

    Label {
        id: label8
        x: 212
        y: 282
        text: qsTr("zpos")
    }


    Dialog{
        id: dialog
        modal: true
        title: qsTr("Mission's Name")
        standardButtons: Dialog.Save
        width: 300
        height: 300
        anchors.centerIn: parent
        Item {
            id: dialog_content
            anchors.fill: parent
            TextInput{
                id: text_input
                width: 0.5* parent.width
                anchors.centerIn: parent
                color: "grey"
                text: qsTr("give me name")
            }
        }

        onAccepted: obj_Tester.command_NewMission(text_input.displayText)
    }


}
