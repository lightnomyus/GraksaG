#ifndef API_SCATTER3D_H
#define API_SCATTER3D_H

#include <QObject>

class API_Scatter3D : public QObject
{
    Q_OBJECT
public:
    explicit API_Scatter3D(QObject *parent = nullptr);

signals:

public slots:
};

#endif // API_SCATTER3D_H