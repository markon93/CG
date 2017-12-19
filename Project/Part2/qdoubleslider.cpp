#include "qdoubleslider.h"

QDoubleSlider::QDoubleSlider(QWidget *parent) :
    QSlider(parent)
{
    connect(this, SIGNAL(valueChanged(int)),
        this, SLOT(notifyValueChanged(int)));
}

void
QDoubleSlider::notifyValueChanged(int value) {
    double doubleValue = value / 100.0;
    emit doubleValueChanged(doubleValue);
}
