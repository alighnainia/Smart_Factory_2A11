#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addemployee.h"
#include "search.h"
#include <QLabel>
#include <QList>
#include <QLayout>
#include <QPushButton>
#include "addemployee.h"
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{

  ui->setupUi(this);
  QPushButton *add= ui->AddEmployee;
  QPixmap add_image("C:\\Users\\Anas\\OneDrive\\Workload\\Project 2\\Smart Factory\\MFactory\\Resources\\plus.png");
  QIcon add_icon(":/Resources/plus.png");
  add->setIcon(add_icon);
  add->setIconSize(add->size());
  QIcon deletes(":/Resources/minus.png"),
      update(":/Resources/edit.png");
  ui->DeleteEmployee->setIcon(deletes);
  ui->UpdateEmployee->setIcon(update);
  ui->DeletePosts->setIcon(deletes);
  ui->AddPosts->setIcon(add_icon);
  ui->UpdatePosts->setIcon(update);

  ui->DeleteEmployee->setIconSize(ui->DeleteEmployee->size());
  ui->UpdateEmployee->setIconSize(ui->UpdateEmployee->size());
  ui->DeletePosts->setIconSize(ui->DeletePosts->size());
  ui->AddPosts->setIconSize(ui->AddPosts->size());
  ui->UpdatePosts->setIconSize(ui->UpdatePosts->size());

  db.setDatabaseName(QString("Source_Projet2A"));
  db.setUserName("Anas");
  db.setPassword("esprit20");
  if(!db.open()) {
    qDebug() << QString("Unable to open database");
    QMessageBox::warning(this, tr("MFactory"), tr("Unable to open database"), QMessageBox::Ok);
    }
  else {
  ui->label_7->setText("Status: Connected");
    }
  ui->tableView_2->setModel(em.display_Employee());
  ui->tableViewPost->setModel(po.display_Posts());

  ui->Search_line->setPlaceholderText("Type Here");

  ui->CIN_Employee_text->setMaxLength(8);
  ui->CIN_Employee_text->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
  ui->Age_Employee_text->setMaxLength(3);
  ui->Age_Employee_text->setValidator(new QRegExpValidator(QRegExp("\\d*")));
  ui->Name_Employee_text->setValidator(new QRegExpValidator(QRegExp("(\\w|\\s)*")));
  ui->Address_Employee_text->setValidator(new QRegExpValidator(QRegExp("(\\w|\\b|\\s)*")));
  ui->Email_Employee_text->setValidator(new QRegExpValidator(QRegExp("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$")));


  /*SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
  smtp.setUser("anas.benbrahim@esprit.tn");
  smtp.setPassword("191JMT4743");
  //smtp.getSocket()->setProxy(QNetworkProxy::NoProxy);
  smtp.setAuthMethod(SmtpClient::AuthLogin);
  MimeMessage message;
  EmailAddress sender ("anasbenbrahim9@gmail.com","Anas Ben Brahim");
  message.setSender(&sender);
  EmailAddress to("mohamedamine.benbrahim@esprit.tn", "mohamed amine");
  message.addRecipient(&to);
  message.setSubject("this is a test amine0");
  if(!smtp.connectToHost())
    qDebug() << "failed to connect to the host\n";
  if (!smtp.login())
    qDebug()<< "failed to login\n";
  if (!smtp.sendMail(message))
    qDebug() << "failed to send message\n";
  smtp.quit();*/

}

void MainWindow::animation_button(QPushButton *b)
{
  int a=-20;
    {
      QPropertyAnimation *p = new QPropertyAnimation(b, "geometry");
      p->setDuration(500);
      p->start();
      p->setStartValue(b->geometry());
     // a*=-1;
      p->setEndValue(QRect(b->geometry().x()-a, b->geometry().y(), b->width(), b->height()));
      p->setLoopCount(3);
      p->deleteLater();

    }

}




MainWindow::~MainWindow()
{
  db.close();
  delete ui;
}





void MainWindow::on_search_clicked()
{
  Search s;
  s.exec();
}




void MainWindow::on_AddEmployee_clicked()
{
 // ui->tableEmployees->resizeColumnToContents(5);
  //ui->tableEmployees->sortItems(5,Qt::AscendingOrder);
  //ui->tableEmployees->insertRow(ui->tableEmployees->rowCount());
  //while (ui->tableWidget->isItemSelected(ui->tableWidget->currentItem()));
  QPushButton *a1=ui->AddEmployee, *a2=ui->DeleteEmployee, *a3=ui->UpdateEmployee;
  QRect  r[]={a1->geometry(),a2->geometry(),a3->geometry()};
  sound->play();
  if (ui->AddEmployee->isEnabled()){
    QPropertyAnimation *p1=new QPropertyAnimation(ui->AddEmployee,"geometry"),
        *p2= new QPropertyAnimation(ui->DeleteEmployee,"geometry"),*p3 =new QPropertyAnimation(ui->UpdateEmployee,"geometry");
    QParallelAnimationGroup *p = new QParallelAnimationGroup();
    p->addAnimation(p1);
    p->addAnimation(p2);
    p->addAnimation(p3);

    p1->setDuration(1500);
    p2->setDuration(1500);
    p3->setDuration(1500);


    p1->setStartValue(a1->geometry());
    p2->setStartValue(a2->geometry());
    p3->setStartValue(a3->geometry());

    ui->AddEmployee->setText("Add Employee");

    p1->setEndValue(QRect(a1->geometry().x(),a1->geometry().y(),130,a1->height()));
    p2->setEndValue(QRect(a2->geometry().x()+120,a2->geometry().y(),a2->width(),a2->height()));
    p3->setEndValue(QRect(a3->geometry().x()+120,a3->geometry().y(),a3->width(),a3->height()));
    p->start();
    }


  AddEmployee e;
  e.exec();

  ui->tableView_2->setModel(em.display_Employee());
  a1->setGeometry(r[0]);
  a2->setGeometry(r[1]);
  a3->setGeometry(r[2]);
 // QIcon add_icon("C:\\Users\\Anas\\OneDrive\\Workload\\Project 2\\Smart Factory\\MFactory\\Resources\\plus.png");
  ui->AddEmployee->setText("");
  //ui->AddEmployee->setIcon(add_icon);
 // ui->AddEmployee->setIconSize(r[0].size());

}

void MainWindow::on_DeleteEmployee_clicked()
{
  QString cin=ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0).data().toString();
  em.remove_employee(cin);
 ui->tableView_2->setModel(em.display_Employee());
}

void MainWindow::display_Employee()
{
  //m->setQuery("Select * from Employees");
  //ui->tableView->setModel(m);
}

void MainWindow::on_AddEmployeeButton_clicked()
{



}

void MainWindow::on_DeleteEmployee_button_clicked()
{
    Employees e;
    sound->play();
    e.setCin(ui->CIN_Del_Text->toPlainText());
    if (e.remove_employee()){
        QMessageBox::information(this, "Delete Employee", "The employee removed successfully", QMessageBox::Ok);
      }
    else
      QMessageBox::warning(this, "Warning", "the task failed successfully",QMessageBox::Ok);
}

void MainWindow::on_DeleteEmployee_button_2_clicked()
{

}


void MainWindow::on_UpdateEmployee_clicked()
{

}

void MainWindow::on_Search_line_editingFinished()
{
    QString s=ui->Search_line->text();
    if (s.isEmpty()) ui->tableViewPost->setModel(po.display_Posts());
    else
      {
        ui->tableViewPost->setModel(po.search(s));
      }
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
  index=3;
  QPieSeries *series= new QPieSeries();
  series->append("ffff",30);
  series->append("ghj",50);
  series->append("hyj",20);
  QPieSlice *s=series->slices().at(0);
  s->setLabelVisible();
  s->setExploded();
  s->setPen(QPen(Qt::darkBlue,2));
  QChart *ch= new QChart();
  ch->addSeries(series);
  ch->setTitle(QString("Test"));
  ch->legend()->show();
  ch->setAnimationOptions(QChart::AllAnimations);
  ch->setTheme(QChart::ChartThemeDark);
  QChartView *chart=new QChartView(ch);
  chart->setRenderHint(QPainter::Antialiasing);
  chart->setGeometry(ui->tab_2->geometry());
  chart->setBackgroundBrush(QBrush(QColor(0x202020)));
  QGridLayout q;
  q.addWidget(chart);
  this->ui->tab_2->setLayout(&q);
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString cin=ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0).data().toString();
    QString name=ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),1).data().toString();
    QString age=ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),2).data().toString();
    QString address=ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),3).data().toString();
    QString email=ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),4).data().toString();

    ui->CIN_Employee_text->setText(cin);
    ui->Name_Employee_text->setText(name);
    ui->Age_Employee_text->setText(age);
    ui->Address_Employee_text->setText(address);
    ui->Email_Employee_text->setText(email);
}

void MainWindow::on_pushButton_clicked()
{
  Employees e;
  sound->play();
  e.setCin(ui->CIN_Employee_text->text());
  e.setFull_Name(ui->Name_Employee_text->text());
  e.setAge(ui->Age_Employee_text->text().toUInt());
  e.setAddress(ui->Address_Employee_text->text());
  e.setEmail(ui->Email_Employee_text->text());
  QRegExp regex("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$");
  regex.setPatternSyntax(QRegExp::RegExp);
  bool areEmpty=e.getAddress().isEmpty() || e.getEmail().isEmpty() || e.getCin().isEmpty() || e.getCin().size()<8;
  if (areEmpty || !regex.exactMatch(e.getEmail()) || e.getAge()>=100){
      animation_button(ui->pushButton);

    }
  else if (!ui->tableView_2->currentIndex().isValid()){
      (ui->CIN_Employee_text->setText(""));
      ui->Name_Employee_text->setText("");
      ui->Age_Employee_text->setText("");
      ui->Address_Employee_text->setText("");
      (ui->Email_Employee_text->setText(""));

      if (!e.add_employee())
        QMessageBox::warning(this, "Error", "An Unknown error", QMessageBox::Ok);
    }
  else {
      if (!e.update_employee())
        QMessageBox::warning(this, "Error", "An Unknown error", QMessageBox::Ok);
    }

  ui->tableView_2->setModel(em.display_Employee());
}




void MainWindow::on_comboBox_activated(int index)
{
    ui->tableView_2->setModel(em.sort_employees(index));

}
