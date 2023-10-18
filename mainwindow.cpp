#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    //MainWindow::afficherBoutonsSupplementaires();
}

void MainWindow::afficherBoutonsSupplementaires() {
        // Affichez les boutons supplémentaires lorsque le bouton principal est pressé
        Attaquer->show();
        Piocher->show();
        Afficher_carte->show();
        ButtonStartGame->hide();
        ButtonLoadGame->hide();
        ButtonOption->hide();
        ButtonQuit->hide();
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
