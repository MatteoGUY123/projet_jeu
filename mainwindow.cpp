#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <mainmenu.h>
#include "fenetreattaque.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
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
    fenetreAttaque *fenetre = new fenetreAttaque(this);
    fenetre->show();
    for (int i = 0; i < 10; i++) {
        QPushButton *bouton = findChild<QPushButton*>("Carte" + QString::number(i + 1)); // Remplacez "ui" par votre objet UI
        bouton->hide();
    }
    for (int i = 0; i < number_cart; i++){
        QPushButton *bouton = findChild<QPushButton*>("Carte" + QString::number(i + 1));// Remplacez "ui" par votre objet UI
        bouton->setText(votre_main[i+1].Name);
        bouton->show();
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
