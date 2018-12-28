import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: root_SerialSetting
    width: placeholder.width
    height: placeholder.height

    Connections{
        target: obj_SerialHandler
        onUpdate_UI: {
            model_port.clear()
            model_port.append({port : port_name})
        }
    }

    Rectangle{
        id: placeholder
        width: 369
        height: 347

        ComboBox {
            id: comboBox_port
            x: 201
            y: 29
            textRole: "port"
            model: ListModel{
                id: model_port
                dynamicRoles: true
            }
            onActivated: obj_SerialHandler.set_serial(currentText.toString())
        }

        ComboBox {
            id: comboBox_baud
            x: 201
            y: 76
            model: ["9600","19200","38400","57600","115200"]
            onActivated: {
                console.log(index);
                if (index == 0){
                    obj_SerialHandler.set_baud(9600)
                } else if (index == 1){
                    obj_SerialHandler.set_baud(19200)
                } else if (index == 2){
                    obj_SerialHandler.set_baud(38400)
                } else if (index == 3){
                    obj_SerialHandler.set_baud(57600)
                } else if (index == 4){
                    obj_SerialHandler.set_baud(115200)
                }
            }
        }

        ComboBox {
            id: comboBox1_databits
            x: 201
            y: 123
        }

        ComboBox {
            id: comboBox2_parity
            x: 201
            y: 169
        }

        ComboBox {
            id: comboBox3_stopbits
            x: 201
            y: 215
        }

        Button {
            id: button
            x: 125
            y: 278
            text: qsTr("Connect")
            onPressed: obj_SerialHandler.open_serial()
        }

        Button {
            id: button1
            x: 241
            y: 277
            text: qsTr("Disconnect")
            onPressed: obj_SerialHandler.close_serial()
        }

        Button {
            id: button2
            x: 9
            y: 279
            text: qsTr("Scan")
            onPressed: obj_SerialHandler.scan_serial()
        }

        Label {
            id: label
            x: 44
            y: 77
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
            y: 123
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
            y: 169
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
            y: 215
            width: 109
            height: 40
            text: qsTr("Stop Bits")
            fontSizeMode: Text.FixedSize
            font.pointSize: 10
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

        Label {
            id: label4
            x: 44
            y: 29
            width: 109
            height: 40
            text: qsTr("Select Port")
            font.pointSize: 10
            fontSizeMode: Text.FixedSize
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

    }


}
