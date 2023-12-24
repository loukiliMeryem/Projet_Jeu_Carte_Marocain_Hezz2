#ifndef JEUMAINWINDOW_H
#define JEUMAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QPixmap>
#include <QtGlobal>


namespace Ui {
class JeuMainWindow;
}

class JeuMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    JeuMainWindow(QWidget *parent = nullptr, int nombreDeTours=1);
    ~JeuMainWindow();
private slots:
    void afficherProchaineCarte();
    void distribuerCarte();

private:
    Ui::JeuMainWindow *ui;
    int nombreDeTours;
    int currentCardIndex;
    QList<QPixmap> cartesImages;
    QList<QPixmap> typeCarte;


};
#endif // JEUMAINWINDOW_H
