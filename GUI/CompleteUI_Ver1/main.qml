import QtQuick 2.12
import QtQuick.Controls 2.12

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
        color: myPalette.dark


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

    ToolBar {
        id: toolBar
        anchors.top: window_header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 0.15 * parent.height

        GroupBox {
            id: groupBox
            x: 0
            y: 0
            width: 216
            height: 72
            title: qsTr("Group Box")
        }

        ToolSeparator {
            id: toolSeparator
            x: 222
            y: 0
            width: 13
            height: 72
        }

        GroupBox {
            id: groupBox1
            x: 241
            y: 0
            width: 264
            height: 72
            title: qsTr("Group Box")
        }

        ToolSeparator {
            id: toolSeparator1
            x: 511
            y: 0
            width: 13
            height: 72
        }

    }

//    MenuBar{
//        Menu {
//            title: qsTr("&File")
//            Action { text: qsTr("&New...") }
//            Action { text: qsTr("&Open...") }
//            Action { text: qsTr("&Save") }
//            Action { text: qsTr("Save &As...") }
//            MenuSeparator { }
//            Action { text: qsTr("&Quit") }
//        }
//        Menu {
//            title: qsTr("&Edit")
//            Action { text: qsTr("Cu&t") }
//            Action { text: qsTr("&Copy") }
//            Action { text: qsTr("&Paste") }
//        }
//        Menu {
//            title: qsTr("&Help")
//            Action { text: qsTr("&About") }
//        }

//    }
}













/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
