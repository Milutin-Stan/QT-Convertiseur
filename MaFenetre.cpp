#include "MaFenetre.h"
#include <QCoreApplication>
#include <QDebug>
#include <QString>

MaFenetre::MaFenetre( QWidget *parent ) : QDialog( parent )
{
// 1. Instancier les widgets
    valeur = new QLineEdit(this);
    resultat = new QLineEdit(this);
    unite = new QLabel(this);
    choixConversion = new QComboBox(this);
    bConvertir = new QPushButton(QString::fromUtf8("Convertir"), this);
    bQuitter = new QPushButton(QString::fromUtf8("Quitter"), this);


// 2. Personnaliser les widgets
    valeur->setStyleSheet("color: #0a214c; background-color: #D7D7D7;");
    valeur->clear();
    QFont font("Liberation Sans", 12, QFont::Bold);
    choixConversion->setFont(font);
    choixConversion->addItem(QString::fromUtf8("Décimal -> Binaire"));
    choixConversion->addItem(QString::fromUtf8("Décimal -> Hexadécimal"));
    choixConversion->addItem(QString::fromUtf8("Binaire -> Décimal"));
    choixConversion->addItem(QString::fromUtf8("Héxadécimal -> Décimal"));
    choixConversion->addItem(QString::fromUtf8("Héxadécimal -> Binaire"));
    choixConversion->addItem(QString::fromUtf8("Binaire -> Héxadécimal"));
    resultat->setStyleSheet("color: #0a214c;");
    unite->setStyleSheet("color: #0a214c;");


// 3. Instancier les layouts
    QHBoxLayout *hLayout1 = new QHBoxLayout;
    QHBoxLayout *hLayout2 = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;

// 4. Positionner les widgets dans les layouts
    hLayout1->addWidget(valeur);
    hLayout1->addWidget(choixConversion); hLayout1->addWidget(resultat); hLayout1->addWidget(unite);
    hLayout2->addWidget(bConvertir); hLayout2->addWidget(bQuitter); mainLayout->addLayout(hLayout1); mainLayout->addLayout(hLayout2); setLayout(mainLayout);


// 5. Connecter les signaux et slots
    connect(bConvertir, SIGNAL(clicked()), this, SLOT(convertir()));
    connect(this, SIGNAL(actualiser()), this, SLOT(convertir()));
    connect(choixConversion, SIGNAL(currentIndexChanged(int)), this,SLOT(permuter()));
    connect(bQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    // bonus : conversion automatique
    connect(valeur, SIGNAL(textChanged(const QString &)), this, SLOT(convertir()));

// 6. Personnaliser la fenêtre
    setWindowTitle(QString::fromUtf8("Convertisseur de chiffres décimals en binaires")); adjustSize();
    // on lance une conversion
    //convertir();
    // ou :
    emit actualiser();
}

// 7. Définir les slots
void MaFenetre::convertir()
{
    bool ok;
    QString  decimal  = valeur->text();
    if ( decimal.isEmpty())
        {
            resultat->setText(QString::fromUtf8(" "));
            return;
        }
    switch (choixConversion->currentIndex())
    {
    case DECIMAL_BINAIRE:

        resultat->setText(QString::fromUtf8("%1").arg(decimal.setNum(decimal.toInt(), 2)));
        break;

    case DECIMAL_HEXA:

        resultat->setText(QString::fromUtf8("%1").arg(decimal.setNum(decimal.toInt(),16 )));
        break;

    case BINAIRE_DECIMAL:

        resultat->setText(QString::fromUtf8("%1").arg(decimal.setNum(decimal.toInt(&ok,2) )));
        break;

    case HEXA_DECIMAL:

        resultat->setText(QString::fromUtf8("%1").arg(decimal.setNum(decimal.toInt(&ok,16) )));
        break;

    case HEXA_BINAIRE:
        resultat->setText(QString::fromUtf8("%1").arg(decimal.setNum(decimal.toInt(&ok,16),2 )));
        break;

    case BINAIRE_HEXA:
        resultat->setText(QString::fromUtf8("%1").arg(decimal.setNum(decimal.toInt(&ok,2),16 )));
        break;


    }


}

void MaFenetre::permuter()
{
    if(resultat->text() != " ")
    {
        valeur->setText(resultat->text()); emit actualiser();
    }
}











