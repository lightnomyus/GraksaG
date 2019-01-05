import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    property alias title: label
    Rectangle{
        color: "#00000000"
        anchors.fill: parent


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
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
