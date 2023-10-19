#ifndef FENETREAFFICHERCARTE_H
#define FENETREAFFICHERCARTE_H

#include <QDialog>

namespace Ui {
class fenetreAfficherCarte;
}

class fenetreAfficherCarte : public QDialog
{
    Q_OBJECT

public:
    explicit fenetreAfficherCarte(QWidget *parent = nullptr);
    ~fenetreAfficherCarte();

private:
    Ui::fenetreAfficherCarte *ui;
};

#endif // FENETREAFFICHERCARTE_H
