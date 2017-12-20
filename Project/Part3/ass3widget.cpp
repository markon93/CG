#include "ass3widget.h"
#include "ui_ass3widget.h"
#include "ass3widget.h"

using namespace std;

Ass3Widget::Ass3Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ass3Widget)
{
    ui->setupUi(this);
}

Ass3Widget::~Ass3Widget()
{
    delete ui;
}

// *** Projection tab ***

//  Set projection to orthographic
void Ass3Widget::gui_set_projection_parallel()
{
    ui->btn_parallel->setChecked(true);
}

//  Set projection to perspective
void Ass3Widget::gui_set_projection_perspective()
{
    ui->btn_perspective->setChecked(true);
}

//  Set option value of top
void Ass3Widget::gui_set_option_top(double value)
{
    ui->spin_top->setValue(value);
}

//  Set option value of far
void Ass3Widget::gui_set_option_far(double value)
{
    ui->spin_pefar->setValue(value);
    ui->spin_plfar->setValue(value);
}

//  Set option value of oblique scale
void Ass3Widget::gui_set_option_oblique_scale(double value)
{
    ui->spin_oblscale->setValue(value);
}

//  Set option value of oblique angle
void Ass3Widget::gui_set_option_oblique_angle(double value)
{
    ui->spin_oblangle->setValue(value);
}

//  Set option value of field of view
void Ass3Widget::gui_set_option_fov(double value)
{
    ui->spin_fov->setValue(value);
}


// Called when parallel-button is clicked
void Ass3Widget::on_btn_parallel_clicked(){
    emit Ass3Widget::changeToParallel();
}

// Called when perspective-button is clicked
void Ass3Widget::on_btn_perspective_clicked(){
    emit Ass3Widget::changeToPerspective();
}

// Called when top value changes value
void Ass3Widget::on_spin_top_valueChanged(double top){
    emit Ass3Widget::changePlTop(top);
}

// Called when parallel far value changes value
void Ass3Widget::on_spin_plfar_valueChanged(int plfar){
    emit changePlFar(plfar);
}

// Called when oblique scale value changes value
void Ass3Widget::on_spin_oblscale_valueChanged(double scale){
    emit changeOblScale(scale);
}

// Called when oblique angle value changes value
void Ass3Widget::on_spin_oblangle_valueChanged(double angle){
    emit changeOblAngle(angle);
}

// Called when field of view value changes value
void Ass3Widget::on_spin_fov_valueChanged(int fov){
    emit Ass3Widget::changeFOV(fov);
}

// Called when perspective far value changes value
void Ass3Widget::on_spin_pefar_valueChanged(int pefar){
    emit Ass3Widget::changePFar(pefar);
}

// Terminate application if window is closed
void Ass3Widget::closeEvent(QCloseEvent *event){
    Q_UNUSED(event);
    qApp->quit();
}

// Called when open file button is clicked
void Ass3Widget::on_push_file_clicked(){
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
        emit Ass3Widget::changeFile(fileName.toStdString());
        file.close();
    }
}

// *****************************************************
// *** The Slots (callback functions) below are new ****
// *****************************************************

// *** Default light tab ***
void Ass3Widget::on_sb_light_x_valueChanged(double x){
    emit changeLightX(x);
}

void Ass3Widget::on_sb_light_y_valueChanged(double y){
    emit changeLightY(y);
}

void Ass3Widget::on_sb_light_z_valueChanged(double z){
    emit changeLightZ(z);
}

void Ass3Widget::on_sb_light_r_doubleValueChanged(double v){
    if (ui->cb_light_lock->isChecked()) {
        ui->sb_light_g->setValue(v*100);
        ui->sb_light_b->setValue(v*100);
    }
    emit changeLightR(v);
}

void Ass3Widget::on_sb_light_g_doubleValueChanged(double v)
{
    if (ui->cb_light_lock->isChecked()) {
        ui->sb_light_r->setValue(v*100);
        ui->sb_light_b->setValue(v*100);
    }
    emit changeLightG(v);
}

void Ass3Widget::on_sb_light_b_doubleValueChanged(double v)
{
    if (ui->cb_light_lock->isChecked()) {
        ui->sb_light_r->setValue(v*100);
        ui->sb_light_g->setValue(v*100);
    }
    emit changeLightB(v);
}

void Ass3Widget::on_sb_ambient_r_doubleValueChanged(double v)
{
    if (ui->cb_ambient_lock->isChecked()) {
        ui->sb_ambient_g->setValue(v*100);
        ui->sb_ambient_b->setValue(v*100);
    }
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_ambient_g_doubleValueChanged(double v)
{
    if (ui->cb_ambient_lock->isChecked()) {
        ui->sb_ambient_r->setValue(v*100);
        ui->sb_ambient_b->setValue(v*100);
    }
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_ambient_b_doubleValueChanged(double v)
{
    if (ui->cb_ambient_lock->isChecked()) {
        ui->sb_ambient_r->setValue(v*100);
        ui->sb_ambient_g->setValue(v*100);
    }
    cout << "Slider value " << v << endl;
}

// *** Default material tab ***
void Ass3Widget::on_sb_ambient_c_r_doubleValueChanged(double v)
{
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_ambient_c_g_doubleValueChanged(double v)
{
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_ambient_c_b_doubleValueChanged(double v)
{
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_diffuse_r_doubleValueChanged(double v)
{
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_diffuse_g_doubleValueChanged(double v)
{
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_diffuse_b_doubleValueChanged(double v)
{
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_specular_r_doubleValueChanged(double v)
{
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_specular_g_doubleValueChanged(double v)
{
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_specular_b_doubleValueChanged(double v)
{
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_phong_valueChanged(int phong)
{
    cout << "Phong value " << phong << endl;
}

// *** Texture tab ***
void Ass3Widget::on_push_texturefile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Texture Image File"), QString(),
            tr("Texture Images (*.bmp *.dds *.hdr *.pic *.png *.psd *.jpg *.tga)"));

    if (!fileName.isEmpty()) {
        // Get only file name (truncate path)
        QString fname = fileName.section('/', -1);
        ui->label_texture_filename->setText(fname);

        cout << "Image file to open: " << fileName.toStdString() << endl;
    }
}

void Ass3Widget::on_cb_show_texture_toggled(bool checked)
{
    cout << "Show texture? " << checked << endl;
}
