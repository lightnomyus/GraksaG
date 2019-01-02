#ifndef API_CHARTVIEWER_H
#define API_CHARTVIEWER_H

#include <QObject>

class API_ChartViewer : public QObject
{
    Q_OBJECT
public:
    explicit API_ChartViewer(QObject *parent = nullptr);

signals:
    void update_UI(float x, float y);

public slots:
    void receive_DataSpline(float x, float y);
};

#endif // API_CHARTVIEWER_H
