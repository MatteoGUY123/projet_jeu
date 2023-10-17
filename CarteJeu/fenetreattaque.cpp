#include "fenetreattaque.h"
#include "ui_fenetreattaque.h"
//#include "mainmenu.h"

fenetreAttaque::fenetreAttaque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetreAttaque)
{
    ui->setupUi(this);

}

    //connect(this, &QDialog::showEvent, this, &fenetreAttaque::nouvelleFenetre);
fenetreAttaque::~fenetreAttaque()
{
    delete ui;
}

/*void fenetreAttaque::cacherBouton(){
    for (int i = 0; i < 10; i++) {
        QPushButton *bouton = new QPushButton("Carte" + QString::number(i + 1), this); // Remplacez "ui" par votre objet UI
        if (bouton) {
            bouton->hide();
        }
    }
}*/
