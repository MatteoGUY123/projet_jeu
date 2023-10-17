#ifndef FENETREATTAQUE_H
#define FENETREATTAQUE_H

#include <QDialog>

namespace Ui {
class fenetreAttaque;
}

class fenetreAttaque : public QDialog
{
    Q_OBJECT

public:
    explicit fenetreAttaque(QWidget *parent = nullptr);
    ~fenetreAttaque();
public slots:
    //void nouvelleFenetre();
    //void cacherBouton();


private:
    Ui::fenetreAttaque *ui;
};

#endif // FENETREATTAQUE_H
