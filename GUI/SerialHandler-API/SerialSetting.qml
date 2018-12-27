import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: root_SerialSetting
    anchors.fill: parent


    Rectangle{
        id: placeholder
        anchors.fill: parent

        ComboBox {
            id: comboBox_baud
            x: 201
            y: 38

            Connections{
                target: obj_SerialHandler
                onUpdate_UI: comboBox_baud.model = list
            }
        }

        ComboBox {
            id: comboBox1_databits
            x: 201
            y: 84
        }

        ComboBox {
            id: comboBox2_parity
            x: 201
            y: 130
        }

        ComboBox {
            id: comboBox3_stopbits
            x: 201
            y: 176
        }

        Button {
            id: button
            x: 125
            y: 239
            text: qsTr("Connect")
            onPressed: obj_SerialHandler.open_serial()
        }

        Button {
            id: button1
            x: 241
            y: 238
            text: qsTr("Disconnect")
        }

        Button {
            id: button2
            x: 9
            y: 240
            text: qsTr("Scan")
        }

        Label {
            id: label
            x: 44
            y: 38
            width: 109
            height: 40
            text: qsTr("Baud Rate")
            font.pointSize: 10
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            fontSizeMode: Text.FixedSize
        }

        Label {
            id: label1
            x: 44
            y: 84
            width: 109
            height: 40
            text: qsTr("Data Bits")
            fontSizeMode: Text.FixedSize
            horizontalAlignment: Text.AlignLeft
            font.pointSize: 10
            verticalAlignment: Text.AlignVCenter
        }

        Label {
            id: label2
            x: 44
            y: 130
            width: 109
            height: 40
            text: qsTr("Parity")
            fontSizeMode: Text.FixedSize
            horizontalAlignment: Text.AlignLeft
            font.pointSize: 10
            verticalAlignment: Text.AlignVCenter
        }

        Label {
            id: label3
            x: 44
            y: 176
            width: 109
            height: 40
            text: qsTr("Stop Bits")
            fontSizeMode: Text.FixedSize
            font.pointSize: 10
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

    }


}
