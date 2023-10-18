#ifndef MYNEWWINDOW_H
#define MYNEWWINDOW_H

#include <QWidget>

namespace Ui{
class MyNewWindow;
}

class MyNewWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyNewWindow(QWidget *parent = nullptr);
    ~MyNewWindow();

private slots:
    void onButtonClicked();
    void nouvelleFenetre();

private:
    Ui::MyNewWindow *ui;
};


#endif // MYNEWWINDOW_H
