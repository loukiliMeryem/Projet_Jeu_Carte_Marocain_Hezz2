#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"JeuMainWindow.h"
#include"rule.h"
#
#include<QInputDialog>
#include<QPushButton>



MainWindow::MainWindow(QWidget *parent )
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap originalImage(":/Downloads/hezz2Interface1.jpg");
    setStyleSheet("QMainWindow { background-image: url(:/Downloads/hezz2Interface1.jpg); background-repeat:no-repeat; }");
   QPixmap backgroundImage = originalImage.scaled(originalImage.width(), 600, Qt::IgnoreAspectRatio);

    setFixedSize(backgroundImage.size());

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    // Demander à l'utilisateur le nombre de tours
    bool ok;
    int nombreDeTours = QInputDialog::getInt(this, tr("عدد الجولات"),
                                             tr("Entrez le nombre de tours :"), 1, 1, 100, 1, &ok);

    if (ok) {
        // L'utilisateur a appuyé sur OK, créer JeuMainWindow avec le nombre de tours sélectionné
        JeuMainWindow *jeu = new JeuMainWindow(this, nombreDeTours);
        jeu->show();
    }

    }




void MainWindow::on_rulebtn_clicked()
{
    Rule *rule=new Rule(this);
    rule->show();
}

