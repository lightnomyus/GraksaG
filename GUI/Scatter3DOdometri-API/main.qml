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
        x: 8
        y: 8
        width: 624
        height: 368
        color: "#ffffff"

        ScatterGraph{
            id: scatter_graph
            anchors.fill: parent
        }

    }

    Label {
        id: label
        x: 21
        y: 382
        width: 116
        height: 38
        text: qsTr("add new point")
        font.pointSize: 12
        wrapMode: Text.NoWrap
        fontSizeMode: Text.FixedSize
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Label {
        id: label1
        x: 32
        y: 426
        width: 20
        height: 17
        text: qsTr("x:")
        font.pointSize: 10
    }

    Label {
        id: label2
        x: 165
        y: 426
        width: 20
        height: 17
        text: qsTr("y:")
        font.pointSize: 10
    }

    Label {
        id: label3
        x: 295
        y: 426
        width: 20
        height: 17
        text: qsTr("z:")
        font.pointSize: 10
    }

    SpinBox {
        id: spinBox
        x: 53
        y: 422
        width: 106
        height: 26
    }

    SpinBox {
        id: spinBox1
        x: 183
        y: 422
        width: 106
        height: 26
    }

    SpinBox {
        id: spinBox2
        x: 310
        y: 422
        width: 106
        height: 26
    }

    Button {
        id: button
        x: 422
        y: 415
        text: qsTr("ADD")
        onPressed: obj_testerScatter3D.send_Data(spinBox.value,spinBox1.value,spinBox2.value) //scatter_graph.scatter_element.append({xPos: spinBox.value, yPos: spinBox1.value, zPos: spinBox2.value})
    }

    Button {
        id: button1
        x: 528
        y: 415
        text: qsTr("CLEAR")
        onPressed: scatter_graph.scatter_element.clear()
    }
}
