#ifndef MAFENETRE_H
#define MAFENETRE_H
#include <QtWidgets>
#include <QtGui>
#define DECIMAL_BINAIRE 0
#define DECIMAL_HEXA 1
#define BINAIRE_DECIMAL 2
#define HEXA_DECIMAL 3
#define HEXA_BINAIRE 4
#define BINAIRE_HEXA 5

#if QT_VERSION >= 0x050000

class MaFenetre : public QDialog
{
    Q_OBJECT

    private:
    QLineEdit *valeur;
    QLineEdit *resultat;
    QLabel *unite;
    QComboBox *choixConversion;
    QPushButton *bConvertir;
    QPushButton *bQuitter;
    QDoubleValidator *doubleValidator;
    signals:
    void actualiser();


    public:
    MaFenetre( QWidget *parent = 0 );

    private slots:
    void convertir();
    void permuter();

};
#endif // MAFENETRE_H
#endif //QT_VERSION
