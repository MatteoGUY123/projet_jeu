#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <mainmenu.h>
#include "fenetreattaque.h"
#include <iostream>
#include <string.h>
#include "fenetreaffichercarte.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fenetre = nullptr;
    fenetreCarte = nullptr;
    fenetrePrincipale = this;
    // Associer avec le bouton de Design
    ButtonStartGame = findChild<QPushButton*>("ButtonStartGame");
    ButtonLoadGame = findChild<QPushButton*>("ButtonLoadGame");
    ButtonOption = findChild<QPushButton*>("ButtonOption");
    ButtonQuit = findChild<QPushButton*>("ButtonQuit");

    Attaquer = findChild<QPushButton*>("Attaquer");
    Piocher = findChild<QPushButton*>("Piocher");
    Afficher_carte = findChild<QPushButton*>("Afficher_carte");

    Attaquer->hide();
    Piocher->hide();
    Afficher_carte->hide();
    connect(ButtonStartGame, &QPushButton::clicked, this, &MainWindow::afficherBoutonsSupplementaires);
    connect(Attaquer, &QPushButton::clicked, this, &MainWindow::nouvelleFenetre);
    connect(Afficher_carte, &QPushButton::clicked, this, &MainWindow::afficherCarte);
}

void MainWindow::afficherBoutonsSupplementaires() {
        // Affichez les boutons supplémentaires lorsque le bouton principal est pressé
    for (int i = 0; i < 3; i++)
    {
        PrintCard(PiocherCard(&number_cart),&number_cart, card, votre_main);
        printf("votre nombre de carte : %d \n", number_cart);
        PrintCard(PiocherCard(&number_ennemie_cart), &number_ennemie_cart, card, main_ennemie);
        printf("nombre de carte de l'ennemie : %d \n", number_cart);
    }
        Attaquer->show();
        Piocher->show();
        Afficher_carte->show();
        ButtonStartGame->hide();
        ButtonLoadGame->hide();
        ButtonOption->hide();
        ButtonQuit->hide();
}

void MainWindow::nouvelleFenetre(){
        if (!fenetre){
    fenetre = new fenetreAttaque(this);
        }
    fenetre->show();
    for (int i = 0; i < 10; i++) {
        QPushButton *bouton = findChild<QPushButton*>("Carte" + QString::number(i + 1)); // association des boutons
        bouton->hide();
    }
    for (int i = 0; i < number_cart; i++){
        QPushButton *bouton = findChild<QPushButton*>("Carte" + QString::number(i + 1));// association des boutons
        bouton->setText(votre_main[i+1].Name);
        bouton->setProperty("identifiant", i+1); // attribue identifiant a chaque bouton
        bouton->show();
        connect(bouton, &QPushButton::clicked, this, &MainWindow::boutonCarteClique);
    }
}

void MainWindow::boutonCarteClique() {
    QPushButton *bouton = qobject_cast<QPushButton*>(sender()); // Obtenez le bouton qui a été cliqué
    if (bouton) {
        int identifiant = bouton->property("identifiant").toInt();
        // permet de choisir la carte
        switch (identifiant) {
        case 1:
            std::cout <<"vous avez chois la carte 1" << std::endl;
            break;
        case 2:
            std::cout <<"vous avez chois la carte 2" << std::endl;
            break;
        }
        if (fenetre){
            fenetre->close();
            delete fenetre;
            fenetre = nullptr;
        }
    }
}

void MainWindow::afficherCarte(){
    if (!fenetreCarte){
        fenetreCarte = new fenetreAfficherCarte(this);
    }
    fenetreCarte->show();
    for (int i = 0; i < 10; i++) {
        QLabel *label = findChild<QLabel*>("Carte" + QString::number(i + 1)); // association des boutons
        label->hide();
    }
    for (int i = 0; i < number_cart; i++){
        QLabel *label = findChild<QLabel*>("Carte" + QString::number(i + 1));// association des boutons
        label->setText(votre_main[i+1].Name);
        label->setProperty("identifiant", i+1); // attribue identifiant a chaque bouton
        label->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
// Créez un menu
QMenu *menu = new QMenu(this);

// Ajoutez des actions au menu
QAction *action1 = menu->addAction("Option 1");
QAction *action2 = menu->addAction("Option 2");

// Connectez le bouton pour afficher le menu
connect(ButtonStartGame, &QPushButton::clicked, this, [=](){
    menu->exec(ButtonStartGame->mapToGlobal(QPoint(0, ButtonStartGame->height())));
});

// Connectez les actions à des slots
connect(action1, &QAction::triggered, this, &MainWindow::action1Clique);
connect(action2, &QAction::triggered, this, &MainWindow::action2Clique);
}
void MainWindow::action1Clique() {
cout<<"SAlut"<< endl; // Code pour l'action 1
}
void MainWindow::action2Cliquee() {
// Code pour l'action 2
}*/
