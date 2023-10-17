#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>

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

private:

    Ui::MainWindow *ui;
    QPushButton *ButtonStartGame;
    QPushButton *Attaquer;
    QPushButton *Piocher;
    QPushButton *Afficher_carte;
    QPushButton *ButtonLoadGame;
    QPushButton *ButtonOption;
    QPushButton *ButtonQuit;
};

#endif // MAINWINDOW_H
