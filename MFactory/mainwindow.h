#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSqlQueryModel>
#include "QSound"
#include "employees.h"
#include "posts.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);

  ~MainWindow();

private slots:
  void on_pushButton_clicked();
  //void on_addnew_clicked();
  void on_search_clicked();



  //void on_AddEmployee_clicked();

  void on_DeleteEmployee_clicked();
  void display_Employee();

  void on_AddEmployeeButton_clicked();

  void on_DeleteEmployee_button_clicked();

  void on_DeleteEmployee_button_2_clicked();

private:
  Ui::MainWindow *ui;
  QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
  QSqlQueryModel *m=new QSqlQueryModel;
  QSound *sound= new QSound(QString("button1.wav"));
};
#endif // MAINWINDOW_H
