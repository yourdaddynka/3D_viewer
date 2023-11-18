#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <my_ogl_widget.h>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  Ui::MainWindow *ui;

  int vertices_count;
  int edges_count;

  enum display_method { NONE, CIRCLE, SQUARE };
  enum projection_type { PARALLEL, CENTRAL };
  enum edges_type { SOLID, DASHED };

  ~MainWindow();

 private slots:
  void saveSettings();
  void loadSettings();

  void edgesChangeColor();
  void setWhiteEdges();
  void edgesStdClrBtn();
  void on_edges_thickness_valueChanged(int value);
  void on_edges_type_currentIndexChanged(int index);
  void on_edges_reset_clicked();

  void verticesChangeColor();
  void setWhiteVertices();
  void verticesStdClrBtn();
  void on_vertices_thickness_valueChanged(int value);
  void on_vertices_type_currentIndexChanged(int index);
  void on_vertices_reset_clicked();

  void backgroundChangeColor();
  void setBlackBackground();
  void backgroundStdClrBtn();
  void on_background_reset_clicked();

  void on_projection_type_currentIndexChanged(int index);

  void on_move_by_x_valueChanged(int value);
  void on_move_by_y_valueChanged(int value);
  void on_move_by_z_valueChanged(int value);

  void on_scale_slider_valueChanged(int value);

  void on_rotate_by_x_valueChanged(int value);
  void on_rotate_by_y_valueChanged(int value);
  void on_rotate_by_z_valueChanged(int value);

  void setStandartAffine();

  void on_get_screenshot_clicked();
  void on_get_gif_clicked();
  void createGif(QString fileName);

  void on_open_obj_file_clicked();
  void on_render_obj_file_clicked();
  void on_close_object_clicked();

 private:
  QPoint cur_pos;
  QPoint new_pos;
  QSettings *settings;
};
#endif  // MAINWINDOW_H
