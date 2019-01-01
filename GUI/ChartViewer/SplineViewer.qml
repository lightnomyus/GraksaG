import QtQuick 2.0
import QtCharts 2.3
import QtQuick.Controls 1.4

Item {
    id: root_SplineViewer

    Rectangle{
        id: placeholder_button
        width: parent.width
        height: 0.1 * parent.height
        anchors.top: parent.top

        Button{
            id: button_clear
            height: parent.height
            width: 0.25*parent.width
            anchors.left: parent.left
            text: qsTr("Clear")
            onClicked: {
                id_SplineSeries.clear()
                id_SplineSeries.add_zero = true
            }
        }

        Button{
            id: button_theme
            height: parent.height
            width: 0.25*parent.width
            anchors.left: button_clear.right
            text: qsTr("Change Theme")
            onClicked: {
                if (id_ChartViewer.theme == ChartView.ChartThemeLight) {
                    id_ChartViewer.theme = ChartView.ChartThemeBlueCerulean
                } else if (id_ChartViewer.theme == ChartView.ChartThemeBlueCerulean) {
                    id_ChartViewer.theme = ChartView.ChartThemeDark
                } else if (id_ChartViewer.theme == ChartView.ChartThemeDark) {
                    id_ChartViewer.theme = ChartView.ChartThemeQt
                } else {
                    id_ChartViewer.theme = ChartView.ChartThemeLight
                }

            }
        }

        Button{
            id: button_zoomIn
            height: parent.height
            width: 0.25*parent.width
            anchors.left: button_theme.right
            text: qsTr("Zoom In")
            onClicked: {
                id_ChartViewer.zoomIn()
            }
        }

        Button{
            id: button_zoomOut
            height: parent.height
            width: 0.25*parent.width
            anchors.left: button_zoomIn.right
            text: qsTr("Zoom Out")
            onClicked: {
                id_ChartViewer.zoomOut()
            }
        }
    }

    Rectangle{
        id: placeholder_spline
        width: parent.width
        anchors.top: placeholder_button.bottom
        anchors.bottom: parent.bottom

        ChartView{
            id: id_ChartViewer
            title: qsTr("Range vs Altitude")
            anchors.fill: parent
            antialiasing: true
            theme: ChartView.ChartThemeQt

            SplineSeries{
                id: id_SplineSeries
                name: qsTr("degree")
                property bool add_zero: true

            }
        }

        Connections{
            target: obj_ChartViewer
            onUpdate_UI:{
                if (id_SplineSeries.add_zero) {
                    id_SplineSeries.add_zero = false
                    id_SplineSeries.append(0,0)
                }

                id_SplineSeries.append(x,y)
            }
        }
    }

}
