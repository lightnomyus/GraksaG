import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Rectangle {
    id: root
    visible: true
    width: 640
    height: 480

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 640
        height: 393
        color: "#ffffff"

        SplineViewer{
            anchors.fill: parent
        }
    }

    SpinBox {
        id: spinBox
        x: 49
        y: 414
    }

    SpinBox {
        id: spinBox1
        x: 250
        y: 414
    }

    Button {
        id: button
        x: 470
        y: 414
        text: qsTr("Send")
        onClicked: {
            obj_TesterChartViewer.send_data(spinBox.value,spinBox1.value)
        }
    }


}
