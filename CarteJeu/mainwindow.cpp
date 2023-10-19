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
    connect(Piocher, &QPushButton::clicked, this, &MainWindow::piocherCarte);

    connect(ui->ButtonQuit, &QPushButton::clicked, this, []{exit(0);});
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
            Votre_Attaque(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            Attaque_ennemie(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            break;
        case 2:
            std::cout <<"vous avez chois la carte 2" << std::endl;
            Votre_Attaque(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            Attaque_ennemie(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            break;
        case 3:
            std::cout <<"vous avez chois la carte 3" << std::endl;
            Votre_Attaque(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            Attaque_ennemie(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            break;
        case 4:
            std::cout <<"vous avez chois la carte 4" << std::endl;
            Votre_Attaque(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            Attaque_ennemie(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            break;
        case 5:
            std::cout <<"vous avez chois la carte 5" << std::endl;
            Votre_Attaque(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            Attaque_ennemie(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            break;
        case 6:
            std::cout <<"vous avez chois la carte 6" << std::endl;
            Votre_Attaque(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            Attaque_ennemie(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            break;
        case 7:
            std::cout <<"vous avez chois la carte 7" << std::endl;
            Votre_Attaque(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            Attaque_ennemie(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            break;
        case 8:
            std::cout <<"vous avez chois la carte 8" << std::endl;
            Votre_Attaque(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            Attaque_ennemie(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            break;
        case 9:
            std::cout <<"vous avez chois la carte 9" << std::endl;
            Votre_Attaque(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            Attaque_ennemie(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            break;
        case 10:
            std::cout <<"vous avez chois la carte 10" << std::endl;
            Votre_Attaque(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
            Attaque_ennemie(&number_cart, &number_ennemie_cart, identifiant, votre_main, main_ennemie);
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
        QLabel *labelPv = findChild<QLabel*>("Pv" + QString::number(i + 1)); // association des boutons
        QLabel *labelAttack = findChild<QLabel*>("Attack" + QString::number(i + 1)); // association des boutons
        label->hide();
        labelPv->hide();
        labelAttack->hide();
    }
    for (int i = 0; i < number_cart; i++){
        QLabel *label = findChild<QLabel*>("Carte" + QString::number(i + 1));// association des boutons
        QLabel *labelPv = findChild<QLabel*>("Pv" + QString::number(i + 1));// association des boutons
        QLabel *labelAttack = findChild<QLabel*>("Attack" + QString::number(i + 1));// association des boutons

        label->setText(votre_main[i+1].Name);
        labelPv->setText("Pv : " + QString::number(votre_main[i+1].Pv));
        labelAttack->setText("Attack : " + QString::number(votre_main[i+1].Attack));
        label->setProperty("identifiant", i+1); // attribue identifiant a chaque bouton
        label->show();
        labelPv->show();
        labelAttack->show();
    }
}

 void MainWindow::piocherCarte(){
    std::cout<<"bonjour"<<std::endl;
    PrintCard(PiocherCard(&number_cart),&number_cart, card, votre_main);
    PrintCard(PiocherCard(&number_ennemie_cart),&number_ennemie_cart, card, main_ennemie);
}
MainWindow::~MainWindow()
{
    delete ui;
}

