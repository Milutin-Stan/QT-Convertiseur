#include <QApplication>
#include "MaFenetre.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv); // un objet QApplication
    MaFenetre maFenetre; // un objet fenêtre
    maFenetre.show(); // affiche la fenêtre
    int ret = app.exec(); // exécute la boucle principale d’évènement
    return ret;
}

