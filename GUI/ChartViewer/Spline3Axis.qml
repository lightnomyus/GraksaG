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
                obj_ChartViewer.clear_time2()
                id_SplineSeries1.clear()
                id_SplineSeries1.add_zero = true
                id_SplineSeries2.clear()
                id_SplineSeries2.add_zero = true
                id_SplineSeries3.clear()
                id_SplineSeries3.add_zero = true
                xAxis.min = 0
                xAxis.max = 1
                yAxis1.min = 0
                yAxis1.max = 1
//                yAxis2.min = 0
//                yAxis2.max = 1
//                yAxis3.min = 0
//                yAxis3.max = 1
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
            title: qsTr("Accelero Data")
            anchors.fill: parent
            antialiasing: true
            theme: ChartView.ChartThemeQt

            ValueAxis{
                id: xAxis
                min: 0
                max: 1
            }

            ValueAxis{
                id: yAxis1
                min: 0
                max: 1
            }

//            ValueAxis{
//                id: yAxis2
//                min: 0
//                max: 1
//            }

//            ValueAxis{
//                id: yAxis3
//                min: 0
//                max: 1
//            }

            SplineSeries{
                id: id_SplineSeries1
                name: qsTr("ax")
                property bool add_zero: true
                axisX: xAxis
                axisY: yAxis1
            }
            SplineSeries{
                id: id_SplineSeries2
                name: qsTr("ay")
                property bool add_zero: true
                axisX: xAxis
                axisY: yAxis1
            }
            SplineSeries{
                id: id_SplineSeries3
                name: qsTr("az")
                property bool add_zero: true
                axisX: xAxis
                axisY: yAxis1
            }
        }

        Connections{
            target: obj_ChartViewer
            onUpdate_UI_3Data: {
                if (id_SplineSeries1.add_zero) {
                    id_SplineSeries1.add_zero = false
                    id_SplineSeries1.append(0,0)
                }
                if (id_SplineSeries2.add_zero) {
                    id_SplineSeries2.add_zero = false
                    id_SplineSeries2.append(0,0)
                }
                if (id_SplineSeries3.add_zero) {
                    id_SplineSeries3.add_zero = false
                    id_SplineSeries3.append(0,0)
                }
                if (xAxis.max <= time) {
                    xAxis.max = time+1
                }
                if (xAxis.min > time) {
                    xAxis.min = time-1
                }
                if (xAxis.max-xAxis.min >= 11) {
                    xAxis.min = xAxis.max-10
                }
                if (yAxis1.max <= x) {
                    yAxis1.max = x+1
                }
                if (yAxis1.min > x) {
                    yAxis1.min = x-1
                }
                if (yAxis1.max <= y) {
                    yAxis1.max = y+1
                }
                if (yAxis1.min > y) {
                    yAxis1.min = y-1
                }
                if (yAxis1.max <= z) {
                    yAxis1.max = z+1
                }
                if (yAxis1.min > z) {
                    yAxis1.min = z-1
                }
                id_SplineSeries1.append(time,x)
                id_SplineSeries2.append(time,y)
                id_SplineSeries3.append(time,z)
            }
        }
    }

}
