#include "MyNewWindow.h"

MyNewWindow::MyNewWindow(QWidget *parent) : QMainWindow(parent)
{
    connect(this, &QMainWindow::showEvent, this, &MyNewWindow::nouvelleFenetre);
}
