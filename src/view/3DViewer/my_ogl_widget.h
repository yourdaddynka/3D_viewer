#ifndef MY_OGL_WIDGET_H
#define MY_OGL_WIDGET_H
#define GL_SILENCE_DEPRECATION

#include <OpenGL/gl.h>

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QOpenGLWidget>
#include <QSettings>
#include <QWheelEvent>
#include <QWidget>
#include <QtOpenGL>
#include <iostream>
extern "C" {
#include "../../modules/header/modules.h"
}

class my_ogl_widget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
 public:
  explicit my_ogl_widget(QWidget *parent = nullptr);
  model_data data = {0, NULL, 0, NULL};
  /*APP_SETTING*/
  double scale_val = 50;
  double rotate_x, rotate_y, rotate_z;
  double translate_x, translate_y, translate_z;
  double v_size = 1;
  double l_thickness = 1;
  int projection_type = 0;
  int v_type = 0;
  int l_type = 0;
  double v_r = 1, v_g = 1, v_b = 1;
  double l_r = 1, l_g = 100, l_b = 1;
  double bg_r = 0, bg_g = 0, bg_b = 0;
  GLfloat normalize_coef;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;
  void parse_file(char *filename);
  void closeObject();
  void initializeGL() override;
  void paintGL() override;

 private:
  ~my_ogl_widget() override;
  QPoint current_pos;
  QPoint new_pos;
  void set_normalize_coef();
  void render_ui_stats();
  void build_lines();
  void build_points();
};

#endif  // MY_OGL_WIDGET_H
