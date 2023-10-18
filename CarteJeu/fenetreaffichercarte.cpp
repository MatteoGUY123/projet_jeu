#include "fenetreaffichercarte.h"
#include "ui_fenetreaffichercarte.h"

fenetreAfficherCarte::fenetreAfficherCarte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetreAfficherCarte)
{
    ui->setupUi(this);
}
fenetreAfficherCarte::~fenetreAfficherCarte()
{
    delete ui;
}
