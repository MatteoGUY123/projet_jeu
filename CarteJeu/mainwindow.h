#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include "fenetreattaque.h"
#include "fenetreaffichercarte.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
   //oid on_insertButton_clicked();
    void afficherBoutonsSupplementaires();
    void nouvelleFenetre();
    void boutonCarteClique();
    void afficherCarte();

private:

    Ui::MainWindow *ui;
    QPushButton *ButtonStartGame;
    QPushButton *Attaquer;
    QPushButton *Piocher;
    QPushButton *Afficher_carte;
    QPushButton *ButtonLoadGame;
    QPushButton *ButtonOption;
    QPushButton *ButtonQuit;
    fenetreAttaque *fenetre;
    MainWindow *fenetrePrincipale;
    fenetreAfficherCarte *fenetreCarte;
};

#endif // MAINWINDOW_H
