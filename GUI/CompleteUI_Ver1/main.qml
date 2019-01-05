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

                    GroupBox {
                        id: groupBox
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.bottomMargin: 5
                        Layout.topMargin: 5
                        Layout.leftMargin: 5
                        Layout.rightMargin: 5
                        title: qsTr("Start")
                    }

                    ToolSeparator {
                        id: toolSeparator
                        Layout.fillHeight: true
                    }

                    GroupBox {
                        id: groupBox1
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.bottomMargin: 5
                        Layout.topMargin: 5
                        Layout.leftMargin: 5
                        Layout.rightMargin: 5
                        title: qsTr("In Progress")
                    }

                    ToolSeparator {
                        id: toolSeparator1
                        Layout.fillHeight: true
                    }

                    GroupBox {
                        id: groupBox3
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.bottomMargin: 5
                        Layout.topMargin: 5
                        Layout.leftMargin: 5
                        Layout.rightMargin: 5
                        title: qsTr("Finish")
                    }

                }

            }

            Item{
                Layout.alignment: Qt.AlignCenter
            }

            Item{
                Layout.alignment: Qt.AlignCenter

            }

        }


    }
}





























/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
