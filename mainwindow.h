#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void movr();
    void movl();
    void dot();
    void compute();
    void add();
    void del();
    void getInput();

private:
    QVector<QWidget*> stateWidgets;
    Ui::MainWindow *ui;
    int pos, n_state; QChar state;
    QString s; QChar b = '0';
};
#endif // MAINWINDOW_H
