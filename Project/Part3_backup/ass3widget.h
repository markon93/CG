#pragma once

#include <iostream>
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class Ass3Widget;
}

class Ass3Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Ass3Widget(QWidget *parent = 0);
    ~Ass3Widget();

    void gui_set_projection_parallel();
    void gui_set_projection_perspective();

    void gui_set_option_top(double value);
    void gui_set_option_far(double value);
    void gui_set_option_fov(double value);
    void gui_set_option_oblique_angle(double value);
    void gui_set_option_oblique_scale(double value);

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_btn_parallel_clicked();

    void on_btn_perspective_clicked();

    void on_spin_top_valueChanged(double top);

    void on_spin_plfar_valueChanged(int plfar);

    void on_spin_oblscale_valueChanged(double scale);

    void on_spin_oblangle_valueChanged(double angle);

    void on_spin_fov_valueChanged(int fov);

    void on_spin_pefar_valueChanged(int pefar);

    void on_push_file_clicked();

    void on_sb_light_x_valueChanged(double x);

    void on_sb_light_y_valueChanged(double y);

    void on_sb_light_z_valueChanged(double z);

    void on_sb_light_r_doubleValueChanged(double v);

    void on_sb_light_g_doubleValueChanged(double v);

    void on_sb_light_b_doubleValueChanged(double v);

    void on_sb_ambient_r_doubleValueChanged(double v);

    void on_sb_ambient_g_doubleValueChanged(double v);

    void on_sb_ambient_b_doubleValueChanged(double v);

    void on_sb_ambient_c_r_doubleValueChanged(double v);

    void on_sb_ambient_c_g_doubleValueChanged(double v);

    void on_sb_ambient_c_b_doubleValueChanged(double v);

    void on_sb_diffuse_r_doubleValueChanged(double v);

    void on_sb_diffuse_g_doubleValueChanged(double v);

    void on_sb_diffuse_b_doubleValueChanged(double v);

    void on_sb_specular_r_doubleValueChanged(double v);

    void on_sb_specular_g_doubleValueChanged(double v);

    void on_sb_specular_b_doubleValueChanged(double v);

    void on_sb_phong_valueChanged(int phong);

    void on_push_texturefile_clicked();

    void on_cb_show_texture_toggled(bool checked);

private:
    Ui::Ass3Widget *ui;

signals:

    // Object file
    void changeFile(std::string filename);

    // Projection
    void changeFOV(int fov);
    void changePFar(int d);
    void changeToPerspective();
    void changeToParallel();
    void changeOblScale(double scale);
    void changeOblAngle(double angle);
    void changePlTop(double top);
    void changePlFar(int plFar);

    // Light
    void changeLightX(float x);
    void changeLightY(float y);
    void changeLightZ(float z);

    void changeLightLuminanceR(double r);
    void changeLightLuminanceG(double g);
    void changeLightLuminanceB(double b);

    void changeAmbientLightR(double r);
    void changeAmbientLightG(double g);
    void changeAmbientLightB(double b);

    // Material
    void changeK_A_R(double r);
    void changeK_A_G(double g);
    void changeK_A_B(double b);

    void changeK_D_R(double r);
    void changeK_D_G(double g);
    void changeK_D_B(double b);

    void changeK_S_R(double r);
    void changeK_S_G(double g);
    void changeK_S_B(double b);

    void changeAlpha(int phong);
};

