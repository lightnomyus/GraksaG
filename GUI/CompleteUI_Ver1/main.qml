import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle{
    id: root

    Rectangle{
        id: window_header
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 0.03 * parent.height

        Button{
            id: button_exit
            anchors.right: parent.right
            anchors.rightMargin: 1
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1
            anchors.top: parent.top
            width: 0.05 * parent.width
            text: "\u274c"
            display: AbstractButton.TextBesideIcon
            onClicked: Qt.quit()

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
