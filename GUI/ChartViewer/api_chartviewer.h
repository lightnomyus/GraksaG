#ifndef API_CHARTVIEWER_H
#define API_CHARTVIEWER_H

#include <QObject>

class API_ChartViewer : public QObject
{
    Q_OBJECT
public:
    explicit API_ChartViewer(QObject *parent = nullptr);
    Q_INVOKABLE float get_launcAngle();
    Q_INVOKABLE void clear_time1();
    Q_INVOKABLE void clear_time2();

signals:
    void update_UI(float x, float y);
    void update_UI_3Data(float x, float y, float z, float time);

public slots:
    void receive_DataSpline(float angle, float x, float y);
    void receive_DataSpline_Time(float data);
    void receive_DataSpline_3Data(float x, float y, float z);

private:
    float m_launchAngle;
    float m_timeCounter1;
    float m_timeCounter2;
};

#endif // API_CHARTVIEWER_H
