
#include "JeuMainWindow.h"
#include <QEvent>

// ...

bool JeuMainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Show)
    {
        // Événement Show détecté, distribuer les cartes
        distribuerCartes();
    }

    // Laisser le gestionnaire d'événements de la classe de base traiter l'événement
    return QMainWindow::eventFilter(obj, event);
}
