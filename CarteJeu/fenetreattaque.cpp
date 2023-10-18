#include "fenetreattaque.h"
#include "ui_fenetreattaque.h"

fenetreAttaque::fenetreAttaque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetreAttaque)
{
    ui->setupUi(this);
}
fenetreAttaque::~fenetreAttaque()
{
    delete ui;
}
