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
            width: parent.width
            anchors.top: parent.top
            currentIndex: 0

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
                    anchors.fill: parent

                    Rectangle{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.leftMargin: 5
                        Layout.topMargin: 5
                        Layout.bottomMargin: 5
                        color: "#00000000"

                        RowLayout{
                            width: parent.width
                            anchors.bottom: label.bottom
                            anchors.top: parent.top

                            Button{
                                Layout.margins: 5
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }

                            Button{
                                Layout.margins: 5
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }

                            Button{
                                Layout.margins: 5
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }

                            Button{
                                Layout.margins: 5
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }
                        }


                        Label {
                            id: label
                            anchors.bottom: parent.bottom
                            width: parent.width
                            height: parent.height * 0.2
                            text: qsTr("Label")
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
                        Layout.fillWidth: true
                        Layout.rightMargin: 5
                        Layout.topMargin: 5
                        Layout.bottomMargin: 5

                        RowLayout{
                            width: parent.width
                            anchors.bottom: label1.bottom
                            anchors.top: parent.top
                        }

                        Label {
                            id: label1
                            anchors.bottom: parent.bottom
                            width: parent.width
                            height: parent.height * 0.2
                            text: qsTr("Label")
                            wrapMode: Text.WordWrap
                            fontSizeMode: Text.VerticalFit
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }



                }

            }

            Item{
                Layout.alignment: Qt.AlignCenter

                RowLayout{
                    id: ribbon_layout2
                    anchors.fill: parent

                }
            }

            Item{
                Layout.alignment: Qt.AlignCenter

                RowLayout{
                    id: ribbon_layout3
                    anchors.fill: parent

                }

            }

        }


    }

    Rectangle {
        id: main_content
        anchors.top: ribbon.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        color: myPalette.dark

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















/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
