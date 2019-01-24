import QtQuick 2.12
import QtQuick.Controls 2.5
import Qt.labs.platform 1.1

Rectangle {
    id: root
    visible: true
    width: 640
    height: 480

    Button {
        id: button
        x: 37
        y: 32
        text: qsTr("New Mission")
        onPressed: popup_NewMission.open()
    }

    Button {
        id: button1
        x: 172
        y: 32
        text: qsTr("Replay Mission")
        onPressed: fileDialog.open()
    }

    Popup{
        id: popup_NewMission
        anchors.centerIn: parent
        width: parent.width/3
        height: parent.height/3
        modal: true
        closePolicy: Popup.NoAutoClose

        Rectangle{
            id: popup_rectangle
            anchors.centerIn: parent
            width: root.width/3
            height: root.height/3
            color: "yellow"

            Button {
                id: button2
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 15
                text: qsTr("Save")
                onPressed: {
                    obj_MissionHandler.new_mission(textField.text)
                    popup_NewMission.close()
                }
            }

            Label {
                id: label
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 10
                text: qsTr("Enter mission name")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            TextField {
                id: textField
                anchors.bottom: button2.top
                anchors.bottomMargin: 20
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width/2
                placeholderText: qsTr("Give a name")

            }

        }
    }

    FileDialog{
        id: fileDialog
        onAccepted: {
            obj_MissionHandler.get_fileName(fileDialog.file)
        }
    }
}
