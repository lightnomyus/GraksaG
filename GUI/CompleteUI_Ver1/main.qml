import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle{
    id: root
    SystemPalette { id: myPalette; colorGroup: SystemPalette.Active }
    color: myPalette.window

    Rectangle{
        id: window_header
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 0.03 * parent.height
        color: myPalette.light


        Button{
            id: button_exit
            anchors.right: parent.right
            anchors.rightMargin: 1
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1
            anchors.top: parent.top
            width: 0.03 * parent.width
            text: "\u274c"
            display: AbstractButton.TextBesideIcon
            icon.color: "Red"
            onClicked: Qt.quit()

        }
    }

    Rectangle{
        id: ribbon
        width: parent.width
        anchors.top: window_header.bottom
        height: 0.15 * parent.height
        color: myPalette.alternateBase

        TabBar {
            id: tabBar
            width: parent.width * 0.3
            anchors.top: parent.top

            TabButton {
                id: tabButton1
                text: qsTr("Mission Setting")
            }

            TabButton {
                id: tabButton2
                text: qsTr("Port Setting")
            }

            TabButton {
                id: tabButton3
                text: qsTr("UI Setting")
            }

        }

        StackLayout{
            anchors.top: tabBar.bottom
            anchors.bottom: parent.bottom
            width: parent.width
            currentIndex: tabBar.currentIndex

            Item{
                id: mission_setup
                Layout.alignment: Qt.AlignCenter

                RowLayout{
                    id: ribbon_layout1
                    height: parent.height
                    width: parent.width


                    Rectangle{
                        Layout.fillHeight: true
                        Layout.preferredWidth: 0.3 * parent.width
                        Layout.margins: 5
                        color: "#00000000"

                        RowLayout{
                            width: parent.width
                            anchors.bottom: label.top
                            anchors.top: parent.top

                            Button{
                                Layout.margins: 5
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                icon.source: "images/icons/newMission.svg"
                                icon.color: "black"
                                display: AbstractButton.TextUnderIcon
                                text: qsTr("New Mission")
                            }

                            Button{
                                Layout.margins: 5
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                icon.source: "images/icons/play-button.svg"
                                icon.color: "black"
                                display: AbstractButton.TextUnderIcon
                                text: qsTr("Replay Mission")
                            }

                            Button{
                                Layout.margins: 5
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                icon.source: "images/icons/rocket-launch.svg"
                                icon.color: "black"
                                display: AbstractButton.TextUnderIcon
                                text: qsTr("Start Mission")
                            }

                            Button{
                                Layout.margins: 5
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                icon.source: "images/icons/prohibition.svg"
                                icon.color: "black"
                                display: AbstractButton.TextUnderIcon
                                text: qsTr("Stop Mission")
                            }
                        }


                        Label {
                            id: label
                            anchors.bottom: parent.bottom
                            width: parent.width
                            height: parent.height * 0.2
                            text: qsTr("Mission Control")
                            wrapMode: Text.WordWrap
                            fontSizeMode: Text.VerticalFit
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.preferredWidth: 0.3 * parent.width
                        Layout.margins: 5
                        color: "#00000000"

                        RowLayout{
                            width: parent.width
                            height: parent.height - label1.height

                            Label{
                               Layout.fillHeight: true
                               Layout.fillWidth: true
                               text: qsTr("Select Port: ")
                               fontSizeMode: Text.HorizontalFit
                               verticalAlignment: Text.AlignVCenter
                               horizontalAlignment: Text.AlignHCenter
                            }

                            ComboBox {
                                Layout.preferredHeight: 0.3 * parent.height
                                Layout.fillWidth: true
                                id: comboBox_port
                                textRole: "port"
                                model: ListModel{
                                    id: model_port
                                    dynamicRoles: true
                                }
                                //onActivated: obj_SerialHandler.set_serial(currentText.toString())
                            }

                            Button{
                                Layout.preferredHeight: 0.3 * parent.height
                                Layout.fillWidth: true
                                text: qsTr("Scan")

                            }

                            Button{
                                Layout.preferredHeight: 0.3 * parent.height
                                Layout.fillWidth: true
                                text: qsTr("Connect")
                            }

                            Button{
                                Layout.preferredHeight: 0.3 * parent.height
                                Layout.fillWidth: true
                                text: qsTr("Disconnect")

                            }
                        }

                        Label {
                            id: label1
                            anchors.bottom: parent.bottom
                            width: parent.width
                            height: parent.height * 0.2
                            text: qsTr("Serial Connection Control")
                            wrapMode: Text.WordWrap
                            fontSizeMode: Text.VerticalFit
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                    Rectangle{
                        color: "#00000000"
                        Layout.fillHeight: true
                        Layout.preferredWidth: parent.width * 0.2
                        Layout.margins: 5

                        RowLayout{
                            width: parent.width
                            anchors.bottom: label2.top
                            anchors.top: parent.top

                            Button{
                                Layout.margins: 5
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                icon.source: "images/icons/newMission.svg"
                                icon.color: "black"
                                display: AbstractButton.TextUnderIcon
                                text: qsTr("Start Data Acquisition")
                            }

                            Button{
                                Layout.margins: 5
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                icon.source: "images/icons/play-button.svg"
                                icon.color: "black"
                                display: AbstractButton.TextUnderIcon
                                text: qsTr("Stop Data Acquisition")
                            }
                        }

                        Label {
                            id: label2
                            anchors.bottom: parent.bottom
                            width: parent.width
                            height: parent.height * 0.2
                            text: qsTr("Data Acqusition Control")
                            wrapMode: Text.WordWrap
                            fontSizeMode: Text.VerticalFit
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                    Item {
                        Layout.fillWidth: true
                    }

                }

            }

            Item{
                id: serial_setup
                Layout.alignment: Qt.AlignCenter

                RowLayout{
                    id: ribbon_layout2
                    anchors.fill: parent

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.margins: 5
                        color: "#00000000"

                        RowLayout{
                            anchors.fill: parent

                            Item {
                                Layout.fillWidth: true
                            }

                            ColumnLayout{
                                Layout.fillHeight: true
                                Layout.preferredWidth: 0.45 * parent.width

                                Button{
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true
                                    text: qsTr("Scan")
                                }

                                Button{
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true
                                    text: qsTr("Connect")
                                }

                                Button{
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true
                                    text: qsTr("Disconnect")
                                }
                            }


                            ColumnLayout{
                                Layout.fillHeight: true
                                Layout.preferredWidth: 0.45 * parent.width

                                Label{
                                    Layout.fillWidth: true
                                    text: qsTr("Select Port")
                                    fontSizeMode: Text.HorizontalFit
                                    verticalAlignment: Text.AlignVCenter
                                    horizontalAlignment: Text.AlignHCenter
                                }

                                ComboBox{
                                    Layout.fillWidth: true
                                }

                                Item{
                                    Layout.fillHeight: true
                                }
                            }

                        }
                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.margins: 5
                        color: "#00000000"

                        RowLayout{
                            anchors.fill: parent

                            Item {
                                Layout.fillWidth: true
                            }

                            Label{
                                Layout.preferredWidth: 0.4 * parent.width
                                Layout.fillHeight: true
                                text: qsTr("Baud Rate")
                                fontSizeMode: Text.HorizontalFit
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                            }

                            ComboBox{
                                id: comboBox_baud
                                Layout.preferredWidth: 0.4 * parent.width
                                Layout.preferredHeight: 0.3 * parent.height
                                model: ["9600","19200","38400","57600","115200"]
                                onActivated: {
                                    if (index == 0){
                                        //obj_SerialHandler.set_baud(9600)
                                    } else if (index == 1){
                                        //obj_SerialHandler.set_baud(19200)
                                    } else if (index == 2){
                                        //obj_SerialHandler.set_baud(38400)
                                    } else if (index == 3){
                                        //obj_SerialHandler.set_baud(57600)
                                    } else if (index == 4){
                                        //obj_SerialHandler.set_baud(115200)
                                    }
                                }
                            }

                            Item {
                                Layout.fillWidth: true
                            }
                        }

                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.margins: 5
                        color: "#00000000"


                        RowLayout{
                            anchors.fill: parent

                            Item {
                                Layout.fillWidth: true
                            }

                            Label{
                                Layout.preferredWidth: 0.4 * parent.width
                                Layout.fillHeight: true
                                text: qsTr("Data Bits")
                                fontSizeMode: Text.HorizontalFit
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                            }

                            ComboBox{
                                id: ccomboBox_databits
                                Layout.preferredWidth: 0.4 * parent.width
                                Layout.preferredHeight: 0.3 * parent.height
                                model: ["5","6","7","8"]
                                onActivated: {
                                    if (index == 0){
                                        //obj_SerialHandler.set_databits(5)
                                    } else if (index == 1){
                                        //obj_SerialHandler.set_databits(6)
                                    } else if (index == 2){
                                        //obj_SerialHandler.set_databits(7)
                                    } else if (index == 3){
                                        //obj_SerialHandler.set_databits(8)
                                    }
                                }
                            }

                            Item {
                                Layout.fillWidth: true
                            }
                        }

                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.margins: 5
                        color: "#00000000"


                        RowLayout{
                            anchors.fill: parent

                            Item {
                                Layout.fillWidth: true
                            }

                            Label{
                                Layout.preferredWidth: 0.4 * parent.width
                                Layout.fillHeight: true
                                text: qsTr("Parity")
                                fontSizeMode: Text.HorizontalFit
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                            }

                            ComboBox{
                                id: comboBox_parity
                                Layout.preferredWidth: 0.4 * parent.width
                                Layout.preferredHeight: 0.3 * parent.height
                                model: ["No Parity","Odd Parity","Even Parity"]
                                onActivated: {
                                    if (index == 0){
                                        //obj_SerialHandler.set_parity(0)
                                    } else if (index == 1){
                                        //obj_SerialHandler.set_parity(1)
                                    } else if (index == 2){
                                        //obj_SerialHandler.set_parity(2)
                                    }
                                }
                            }

                            Item {
                                Layout.fillWidth: true
                            }
                        }

                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.margins: 5
                        color: "#00000000"


                        RowLayout{
                            anchors.fill: parent

                            Item {
                                Layout.fillWidth: true
                            }

                            Label{
                                Layout.preferredWidth: 0.4 * parent.width
                                Layout.fillHeight: true
                                text: qsTr("Stop Bits")
                                fontSizeMode: Text.HorizontalFit
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                            }

                            ComboBox{
                                id: comboBox_stopbits
                                Layout.preferredWidth: 0.4 * parent.width
                                Layout.preferredHeight: 0.3 * parent.height
                                model: ["1","2"]
                                onActivated: {
                                    if (index == 0){
                                        //obj_SerialHandler.set_stopbits(1)
                                    } else if (index == 1){
                                        //obj_SerialHandler.set_stopbits(2)
                                    }
                                }
                            }

                            Item {
                                Layout.fillWidth: true
                            }
                        }

                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                }
            }

            Item{
                id: ui_setup
                Layout.alignment: Qt.AlignCenter

                RowLayout{
                    id: ribbon_layout3
                    anchors.fill: parent

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.margins: 5
                        color: "#00000000"
                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.margins: 5
                        color: "#00000000"
                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.margins: 5
                        color: "#00000000"
                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.margins: 5
                        color: "#00000000"
                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.margins: 5
                        color: "#00000000"
                    }

                    ToolSeparator{
                        Layout.fillHeight: true
                    }

                }

            }

        }


    }

    Rectangle {
        id: main_content
        anchors.top: ribbon.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        color: myPalette.base

        GridLayout{
            id: content_layout
            anchors.fill: parent

            columns: 3
            rows: 5

            GroupBox{
                title: qsTr("Location and Surveillance")
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.leftMargin: 5
                Layout.topMargin: 5

            }

            GroupBox{
                title: qsTr("3D Odometri Position")
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.topMargin: 5

            }

            GroupBox{
                title: qsTr("Realtime Graph")
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.topMargin: 5
                Layout.rightMargin: 5

            }

            GroupBox{
                title: qsTr("Mission Log")
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.leftMargin: 5
                Layout.bottomMargin: 5

            }

            GroupBox{
                title: qsTr("Status and Data")
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.bottomMargin: 5

            }

            GroupBox{
                title: qsTr("3D Attitude Model")
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.bottomMargin: 5
                Layout.rightMargin: 5
            }

        }
    }
}
