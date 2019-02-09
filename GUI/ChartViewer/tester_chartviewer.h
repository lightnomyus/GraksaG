#ifndef TESTER_CHARTVIEWER_H
#define TESTER_CHARTVIEWER_H

#include <QObject>

class Tester_ChartViewer : public QObject
{
    Q_OBJECT
public:
    explicit Tester_ChartViewer(QObject *parent = nullptr);
    Q_INVOKABLE void send_data(float x, float y);
    Q_INVOKABLE void send_1data(float x);
    Q_INVOKABLE void send_3data(float x, float y, float z);

signals:
    void incoming_Data(float angle, float x, float y);
    void incoming_Data1(float data);
    void incoming_Data3(float x, float y, float z);

public slots:
};

#endif // TESTER_CHARTVIEWER_H
