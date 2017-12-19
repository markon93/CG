#include "ass3widget.h"
#include "ui_ass3widget.h"

using namespace std;

Ass3Widget::Ass3Widget(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::Ass3Widget)
{
    ui_->setupUi(this);
}

Ass3Widget::~Ass3Widget()
{
    delete ui_;
}

// *** Projection tab ***

//  Set projection to orthographic
void Ass3Widget::gui_set_projection_parallel()
{
    ui_->btn_parallel->setChecked(true);
}

//  Set projection to perspective
void Ass3Widget::gui_set_projection_perspective()
{
    ui_->btn_perspective->setChecked(true);
}

//  Set option value of top
void Ass3Widget::gui_set_option_top(double value)
{
    ui_->spin_top->setValue(value);
}

//  Set option value of far
void Ass3Widget::gui_set_option_far(double value)
{
    ui_->spin_pefar->setValue(value);
    ui_->spin_plfar->setValue(value);
}

//  Set option value of oblique scale
void Ass3Widget::gui_set_option_oblique_scale(double value)
{
    ui_->spin_oblscale->setValue(value);
}

//  Set option value of oblique angle
void Ass3Widget::gui_set_option_oblique_angle(double value)
{
    ui_->spin_oblangle->setValue(value);
}

//  Set option value of field of view
void Ass3Widget::gui_set_option_fov(double value)
{
    ui_->spin_fov->setValue(value);
}

// Called when parallel-button is clicked
void Ass3Widget::on_btn_parallel_clicked(bool checked)
{
    cout << "Parallel projection: " << checked << endl;
}

// Called when perspective-button is clicked
void Ass3Widget::on_btn_perspective_clicked(bool checked)
{
    cout << "Perspective projection: " << checked << endl;
}

// Called when top value changes value
void Ass3Widget::on_spin_top_valueChanged(double top)
{
    cout << "Top: " << top << endl;
}

// Called when parallel far value changes value
void Ass3Widget::on_spin_plfar_valueChanged(int plfar)
{
    cout << "Far: " << plfar << endl;
}

// Called when oblique scale value changes value
void Ass3Widget::on_spin_oblscale_valueChanged(double scale)
{
    cout << "Scale: " << scale << endl;
}

// Called when oblique angle value changes value
void Ass3Widget::on_spin_oblangle_valueChanged(double angle)
{
    cout << "Angle: " << angle << endl;
}

// Called when field of view value changes value
void Ass3Widget::on_spin_fov_valueChanged(int fov)
{
    cout << "Field of view: " << fov << endl;
}

// Called when perspective far value changes value
void Ass3Widget::on_spin_pefar_valueChanged(int pefar)
{
    cout << "Far: " << pefar << endl;
}

// Terminate application if window is closed
void Ass3Widget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    qApp->quit();
}

// Called when open file button is clicked
void Ass3Widget::on_push_file_clicked()
{
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
        ui_->label_obj_filename->setText(fname);

        cout << "OBJ file to open: " << fileName.toStdString() << endl;
        //QTextStream in(&file);
        // Read the object file...
        file.close();
    }
}

// *****************************************************
// *** The Slots (callback functions) below are new ****
// *****************************************************

// *** Default light tab ***
void Ass3Widget::on_sb_light_x_valueChanged(double x)
{
    cout << "Light X: " << x << endl;
}

void Ass3Widget::on_sb_light_y_valueChanged(double y)
{
    cout << "Light Y: " << y << endl;
}

void Ass3Widget::on_sb_light_z_valueChanged(double z)
{
    cout << "Light Z: " << z << endl;
}

void Ass3Widget::on_sb_light_r_doubleValueChanged(double v)
{
    if (ui_->cb_light_lock->isChecked()) {
        ui_->sb_light_g->setValue(v*100);
        ui_->sb_light_b->setValue(v*100);
    }
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_light_g_doubleValueChanged(double v)
{
    if (ui_->cb_light_lock->isChecked()) {
        ui_->sb_light_r->setValue(v*100);
        ui_->sb_light_b->setValue(v*100);
    }
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_light_b_doubleValueChanged(double v)
{
    if (ui_->cb_light_lock->isChecked()) {
        ui_->sb_light_r->setValue(v*100);
        ui_->sb_light_g->setValue(v*100);
    }
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_ambient_r_doubleValueChanged(double v)
{
    if (ui_->cb_ambient_lock->isChecked()) {
        ui_->sb_ambient_g->setValue(v*100);
        ui_->sb_ambient_b->setValue(v*100);
    }
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_ambient_g_doubleValueChanged(double v)
{
    if (ui_->cb_ambient_lock->isChecked()) {
        ui_->sb_ambient_r->setValue(v*100);
        ui_->sb_ambient_b->setValue(v*100);
    }
    cout << "Slider value " << v << endl;
}

void Ass3Widget::on_sb_ambient_b_doubleValueChanged(double v)
{
    if (ui_->cb_ambient_lock->isChecked()) {
        ui_->sb_ambient_r->setValue(v*100);
        ui_->sb_ambient_g->setValue(v*100);
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
        ui_->label_texture_filename->setText(fname);

        cout << "Image file to open: " << fileName.toStdString() << endl;
    }
}

void Ass3Widget::on_cb_show_texture_toggled(bool checked)
{
    cout << "Show texture? " << checked << endl;
}
