#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
   //oid on_insertButton_clicked();
    void afficherBoutonsSupplementaires();

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
