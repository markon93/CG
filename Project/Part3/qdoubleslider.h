#pragma once

#include <QSlider>

class QDoubleSlider : public QSlider
{
    Q_OBJECT
public:
    explicit QDoubleSlider(QWidget *parent = 0);

signals:
    void doubleValueChanged(double value);
public slots:
    void notifyValueChanged(int value);
};

