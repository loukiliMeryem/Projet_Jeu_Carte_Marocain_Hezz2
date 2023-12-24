

// JeuMainWindow.cpp
#include "JeuMainWindow.h"
#include "ui_jeumainwindow.h"
#include <QRandomGenerator>
#include<QPixmap>
#include<QTimer>
JeuMainWindow::JeuMainWindow(QWidget *parent,int nombreDeTours) :
    QMainWindow(parent),
    ui(new Ui::JeuMainWindow),
    nombreDeTours(nombreDeTours),
    currentCardIndex(0),
    cartesImages(  { QPixmap(":Bureau/CARTES/carte1Argent.png"),
                  QPixmap(":Bureau/CARTES/carte1Baton.png"),
                  QPixmap(":Bureau/CARTES/carte1Cup.png"),
                  QPixmap(":Bureau/CARTES/carte1Epee.png"),
                  QPixmap(":Bureau/CARTES/carte2Argent.png"),
                  QPixmap(":Bureau/CARTES/carte2Baton.png"),
                  QPixmap(":Bureau/CARTES/carte2Cup.png"),
                  QPixmap(":Bureau/CARTES/carte2Epee.png"),
                  QPixmap(":Bureau/CARTES/carte3Argent.png"),
                  QPixmap (":Bureau/CARTES/carte3Baton.png"),
                  QPixmap (":Bureau/CARTES/carte3Cup.png"),
                  QPixmap(":Bureau/CARTES/carte3Epee.png"),
                  QPixmap(":Bureau/CARTES/carte4Argent.png"),
                  QPixmap(":Bureau/CARTES/carte4Baton.png"),
                  QPixmap (":Bureau/CARTES/carte4Cup.png"),
                  QPixmap(":Bureau/CARTES/carte4Epee.png"),
                  QPixmap(":Bureau/CARTES/carte5Argent.png"),
                  QPixmap(":Bureau/CARTES/carte5Baton.png"),
                  QPixmap(":Bureau/CARTES/carte5Cup.png"),
                  QPixmap(":Bureau/CARTES/carte5Epee.png"),
                  QPixmap(":Bureau/CARTES/carte6Argent.png"),
                  QPixmap(":Bureau/CARTES/carte6Baton.png"),
                  QPixmap(":Bureau/CARTES/carte6Cup.png"),
                  QPixmap(":Bureau/CARTES/carte6Epee.png"),
                  QPixmap(":Bureau/CARTES/carte7Argent.png"),
                  QPixmap(":Bureau/CARTES/carte7Baton.png"),
                  QPixmap(":Bureau/CARTES/carte7Cup.png"),
                  QPixmap(":Bureau/CARTES/carte7Epee.png"),
                  QPixmap(":Bureau/CARTES/carte10Argent.png"),
                  QPixmap(":Bureau/CARTES/carte10Baton.png"),
                  QPixmap(":Bureau/CARTES/carte10Cup.png"),
                  QPixmap(":Bureau/CARTES/carte10Epee.png"),
                  QPixmap(":Bureau/CARTES/carte11Argent.png"),
                  QPixmap(":Bureau/CARTES/carte11Baton.png"),
                  QPixmap(":Bureau/CARTES/carte11Cup.png"),
                  QPixmap(":Bureau/CARTES/carte11Epee.png"),
                  QPixmap(":Bureau/CARTES/carte12Argent.png"),
                  QPixmap(":Bureau/CARTES/carte12Baton.png"),
                  QPixmap(":Bureau/CARTES/carte12Cup.png"),
                  QPixmap(":Bureau/CARTES/carte12Epee.png")}),
    typeCarte({QPixmap(":/Downloads/cup.jpg"),
               QPixmap(":/Downloads/stick.jpg"),
               QPixmap(":/Downloads/sword.jpg"),
               QPixmap(":/Downloads/gold.jpg"),

               })


{
    ui->setupUi(this);

    ui->gridLayout->addWidget(ui->carteLabel,1,0);


    // Créer un QTimer pour introduire un délai entre chaque distribution
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &JeuMainWindow::distribuerCarte);
    timer->start(100);
}



JeuMainWindow::~JeuMainWindow()
{
    delete ui;
}
void JeuMainWindow::afficherProchaineCarte()
{
    // Vérifier si toutes les cartes ont été affichées
    if (currentCardIndex < cartesImages.size()) {
        // Afficher la prochaine carte
        ui->carteLabel->setPixmap(cartesImages[currentCardIndex]);
        currentCardIndex++;
    }
}




void JeuMainWindow::distribuerCarte()
{
    QLabel* cartesLabelRobot[4] = {
        ui->card1Robot, ui->card2Robot, ui->card3Robot, ui->card4Robot
    };
    QLabel *carteLabelPlayer[4] ={
        ui->card1, ui->card2, ui->card3, ui->card4,
    };
    QSize labelSize(100, 150);
    QSize typesize(100,100);
    if (cartesImages.size() >= 8)
    {

        for (int i = 0; i < 8; ++i)
        {
            int index = rand() % cartesImages.size(); // Utilisation de rand()

            QPixmap carte(cartesImages[index]);

            // Redimensionner si nécessaire
            QPixmap carteRedimensionnee = carte.scaled(labelSize, Qt::KeepAspectRatio);

            // Distribuer la carte au robot ou au joueur en fonction de la parité
            if (i % 2 == 0) {
                cartesLabelRobot[i / 2]->setPixmap(carteRedimensionnee);
            } else {
                carteLabelPlayer[i / 2]->setPixmap(carteRedimensionnee);
            }

            // Si une carte est distribuée au milieu
            if (i == 4) {
                QPixmap typeImage(typeCarte[2]);  // Choisir l'image de type pour le milieu
                QPixmap typeImageRedimensionnee = typeImage.scaled(typesize, Qt::KeepAspectRatio);
                ui->typeCard->setPixmap(typeImageRedimensionnee);  // Mettre à jour le typeLabel
            }
            // Retirer l'image utilisée pour éviter la duplication
            cartesImages.removeAt(index);
        }


        if (!cartesImages.isEmpty())
        {
            int index = rand() % cartesImages.size();
            QPixmap carte(cartesImages[index]);
            QPixmap carteRedimensionnee = carte.scaled(labelSize, Qt::KeepAspectRatio);
            ui->cardMilieu->setPixmap(carteRedimensionnee);
            cartesImages.removeAt(index);

        }

    }
    else
    {
        // Arrêter le QTimer une fois toutes les cartes distribuées
        QObject::sender()->disconnect();
    }
    afficherProchaineCarte();
}













