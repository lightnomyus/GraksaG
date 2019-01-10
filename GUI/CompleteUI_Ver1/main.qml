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
                                height: parent.height
                                Layout.preferredWidth: 0.45 * parent.width

                                Item{
                                    Layout.preferredHeight: 0.075 * parent.height
                                }

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

                        Label{
                            id: label_map
                            text: "Map Control"
                            fontSizeMode: Text.HorizontalFit
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            anchors.bottom: parent.bottom
                            anchors.left: parent.left
                            anchors.right: parent.right
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

                        Label{
                            id: label_odo
                            text: "3D Odometry Control"
                            fontSizeMode: Text.HorizontalFit
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            anchors.bottom: parent.bottom
                            anchors.left: parent.left
                            anchors.right: parent.right
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

                        Label{
                            id: label_log
                            text: "Log Control"
                            fontSizeMode: Text.HorizontalFit
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            anchors.bottom: parent.bottom
                            anchors.left: parent.left
                            anchors.right: parent.right
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

                        Label{
                            id: label_2d
                            text: "2D Graph Control"
                            fontSizeMode: Text.HorizontalFit
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            anchors.bottom: parent.bottom
                            anchors.left: parent.left
                            anchors.right: parent.right
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

                        Label{
                            id: label_model3d
                            text: "3D model Control"
                            fontSizeMode: Text.HorizontalFit
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            anchors.bottom: parent.bottom
                            anchors.left: parent.left
                            anchors.right: parent.right
                        }
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

            columns: 4
            rows: 2

            GroupBox{
                title: qsTr("Location and Surveillance")
                Layout.preferredWidth: 0.32 * parent.width
                Layout.preferredHeight: 0.48 * parent.height
                Layout.margins: 5
                Layout.columnSpan: 1
                Layout.rowSpan: 1
                Layout.alignment: Qt.AlignLeft

                TabBar {
                    id: tabBar_locsur
                    width: parent.width * 0.4
                    anchors.bottom: parent.bottom
                    position: TabBar.Footer

                    TabButton {
                        id: tabButton_map
                        text: qsTr("Map")
                    }

                    TabButton {
                        id: tabButton_image
                        text: qsTr("Image")
                    }

                }

                StackLayout{
                    anchors.top: parent.top
                    anchors.bottom: tabBar_locsur.top
                    width: parent.width
                    currentIndex: tabBar_locsur.currentIndex

                    Item {
                        id: map_viewer

                        Rectangle{
                            anchors.fill: parent

                            MapViewer{
                                anchors.fill: parent
                            }
                        }
                    }

                    Item {
                        id: image_viewer

                        Rectangle{
                            anchors.fill: parent
                        }
                    }
                }

            }


            Rectangle{
                Layout.preferredWidth: 0.32 * parent.width
                Layout.preferredHeight: 0.48 * parent.height
                Layout.margins: 5
                Layout.columnSpan: 2
                Layout.rowSpan: 1
                Layout.alignment: Qt.AlignCenter

                ColumnLayout{
                    anchors.fill: parent

                    Item {
                        Layout.fillHeight: true
                    }

                    GroupBox{
                        title: qsTr("Status and Data")
                        Layout.preferredHeight: 0.43 * parent.height
                        Layout.fillWidth: true
                        Layout.margins: 4

                    }

                    GroupBox{
                        title: qsTr("Mission Log")
                        Layout.preferredHeight: 0.43 * parent.height
                        Layout.fillWidth: true
                        Layout.margins: 4

                        TabBar {
                            id: tabBar_log
                            width: parent.width * 0.4
                            anchors.bottom: parent.bottom
                            position: TabBar.Footer

                            TabButton {
                                id: tabButton_mission
                                text: qsTr("Mission Log")
                            }

                            TabButton {
                                id: tabButton_data
                                text: qsTr("Data Log")
                            }

                        }

                        StackLayout{
                            anchors.top: parent.top
                            anchors.bottom: tabBar_log.top
                            width: parent.width
                            currentIndex: tabBar_log.currentIndex

                            Item {
                                id: log_mission

                                Rectangle{
                                    anchors.fill: parent

                                    Terminal{
                                        anchors.fill: parent
                                    }
                                }
                            }

                            Item {
                                id: log_data

                                Rectangle{
                                    anchors.fill: parent

                                    Terminal{
                                        anchors.fill: parent
                                    }
                                }
                            }
                        }


                    }

                    Item {
                        Layout.fillHeight: true
                    }
                }

            }

            GroupBox{
                title: qsTr("3D Attitude Model")
                Layout.preferredWidth: 0.32 * parent.width
                Layout.preferredHeight: 0.48 * parent.height
                Layout.margins: 5
                Layout.columnSpan: 1
                Layout.rowSpan: 1
                Layout.alignment: Qt.AlignRight
            }

            GroupBox{
                title: qsTr("3D Odometri Position")
                Layout.preferredWidth: 0.48 * parent.width
                Layout.preferredHeight: 0.48 * parent.height
                Layout.margins: 5
                Layout.columnSpan: 2
                Layout.rowSpan: 1
                Layout.alignment: Qt.AlignLeft

            }

            GroupBox{
                title: qsTr("Realtime Graph")
                Layout.preferredWidth: 0.48 * parent.width
                Layout.preferredHeight: 0.48 * parent.height
                Layout.margins: 5
                Layout.columnSpan: 2
                Layout.rowSpan: 1
                Layout.alignment: Qt.AlignRight

            }

        }
    }
}











/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
