#include "ass2widget.h"
#include "ui_ass2widget.h"
#include "geometryrender.h"

using namespace std;

Ass2Widget::Ass2Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ass2Widget)
{
    ui->setupUi(this);
}

Ass2Widget::~Ass2Widget()
{
    delete ui;
}

//  Set projection to orthographic
void Ass2Widget::gui_set_projection_parallel()
{
    ui->btn_parallel->setChecked(true);
}

//  Set projection to perspective
void Ass2Widget::gui_set_projection_perspective()
{
    ui->btn_perspective->setChecked(true);
}

//  Set option value of top
void Ass2Widget::gui_set_option_top(double value)
{
    ui->spin_top->setValue(value);
}

//  Set option value of far
void Ass2Widget::gui_set_option_far(double value)
{
    ui->spin_pefar->setValue(value);
    ui->spin_plfar->setValue(value);
}

//  Set option value of oblique scale
void Ass2Widget::gui_set_option_oblique_scale(double value)
{
    ui->spin_oblscale->setValue(value);
}

//  Set option value of oblique angle
void Ass2Widget::gui_set_option_oblique_angle(double value)
{
    ui->spin_oblangle->setValue(value);
}

//  Set option value of field of view
void Ass2Widget::gui_set_option_fov(double value)
{
    ui->spin_fov->setValue(value);
}


// Called when parallel-button is clicked
void Ass2Widget::on_btn_parallel_clicked(){
    emit Ass2Widget::changeToParallel();
}

// Called when perspective-button is clicked
void Ass2Widget::on_btn_perspective_clicked(){
    emit Ass2Widget::changeToPerspective();
}

// Called when top value changes value
void Ass2Widget::on_spin_top_valueChanged(double top){
    emit Ass2Widget::changePlTop(top);
}

// Called when parallel far value changes value
void Ass2Widget::on_spin_plfar_valueChanged(int plfar){
    emit changePlFar(plfar);
}

// Called when oblique scale value changes value
void Ass2Widget::on_spin_oblscale_valueChanged(double scale){
    emit changeOblScale(scale);
}

// Called when oblique angle value changes value
void Ass2Widget::on_spin_oblangle_valueChanged(double angle){
    emit changeOblAngle(angle);
}

// Called when field of view value changes value
void Ass2Widget::on_spin_fov_valueChanged(int fov){
    emit Ass2Widget::changeFOV(fov);
}

// Called when perspective far value changes value
void Ass2Widget::on_spin_pefar_valueChanged(int pefar){
    emit Ass2Widget::changePFar(pefar);
}

// Terminate application if window is closed
void Ass2Widget::closeEvent(QCloseEvent *event){
    Q_UNUSED(event);
    qApp->quit();
}

// Called when open file button is clicked
void Ass2Widget::on_push_file_clicked(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open OBJ File"), QString(),
            tr("OBJ files (*.obj)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        // Get only file name (truncate path)
        QString fname = fileName.section('/', -1);
        ui->label_obj_filename->setText(fname);

        // Pass the read file name to the object render
        emit Ass2Widget::changeFile(fileName.toStdString());
        file.close();
    }
}
