#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<cmath>
#include<vector>
#include<QLineEdit>
#include<QDebug>

using namespace std;

int to_int(QString);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (!ui->centralwidget->layout()) {
        new QVBoxLayout(ui->centralwidget);
    }

    connect(ui->movrButton, &QPushButton::clicked, this, &MainWindow::movr);
    connect(ui->dotButton, &QPushButton::clicked, this, &MainWindow::dot);
    connect(ui->movlButton, &QPushButton::clicked, this, &MainWindow::movl);
    connect(ui->computeButton, &QPushButton::clicked, this, &MainWindow::compute);
    connect(ui->addStateButton, &QPushButton::clicked, this, &MainWindow::add);
    connect(ui->delStateButton, &QPushButton::clicked, this, &MainWindow::del);

    stateWidgets.clear();
    state = '0'; n_state = 0;
    s = ".00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    pos = 0;
    ui->nState->setText(QChar(b.unicode() + n_state));
    ui->screen->setText(s);
}

void MainWindow::add() {
    if(n_state == 10) return;
    n_state++;

    QGridLayout *newLayout = new QGridLayout();
    newLayout->setObjectName(QString("state_%1").arg(n_state));

    QLabel *head1 = new QLabel("DO");
    QLabel *head2 = new QLabel("MOV");
    QLabel *head3 = new QLabel("NEXT");
    QLineEdit *do1 = new QLineEdit();
    QLineEdit *do2 = new QLineEdit();
    QLineEdit *mov1 = new QLineEdit();
    QLineEdit *mov2 = new QLineEdit();
    QLineEdit *next1 = new QLineEdit();
    QLineEdit *next2 = new QLineEdit();

    do1->setObjectName(QString("do_1_state_%1").arg(n_state));
    do2->setObjectName(QString("do_2_state_%1").arg(n_state));
    mov1->setObjectName(QString("mov_1_state_%1").arg(n_state));
    mov2->setObjectName(QString("mov_2_state_%1").arg(n_state));
    next1->setObjectName(QString("next_1_state_%1").arg(n_state));
    next2->setObjectName(QString("next_2_state_%1").arg(n_state));

\
    newLayout->addWidget(head1, 0, 0);
    newLayout->addWidget(head2, 0, 1);
    newLayout->addWidget(head3, 0, 2);

    newLayout->addWidget(do1, 1, 0);
    newLayout->addWidget(mov1, 1, 1);
    newLayout->addWidget(next1, 1, 2);

    newLayout->addWidget(do2, 2, 0);
    newLayout->addWidget(mov2, 2, 1);
    newLayout->addWidget(next2, 2, 2);

    QWidget *container = new QWidget();
    container->setLayout(newLayout);


    if(n_state <= 5) container->setGeometry(30 + (n_state-1)*220, 220, 201, 81);
    else container->setGeometry(30 + (n_state-6)*220, 300, 201, 81);
    container->setParent(ui->centralwidget);
    container->show();

    stateWidgets.append(container);

    ui->nState->setText(QString::number(n_state));
}

void MainWindow::del() {
    if(n_state == 1) return;

    if(!stateWidgets.isEmpty()) {
        QWidget* lastWidget = stateWidgets.last();
        stateWidgets.removeLast();
        delete lastWidget;
    }

    n_state--;
    ui->nState->setText(QString::number(n_state));
}

void MainWindow::movr(){
    if(pos == s.size() - 1) return;
    std::swap(s[pos], s[pos+1]);
    pos += 1;
    ui->screen->setText(s);
}

void MainWindow::movl(){
    if(pos == 0) return;
    std::swap(s[pos], s[pos-1]);
    pos -= 1;
    ui->screen->setText(s);
}

void MainWindow::dot(){
    if(pos == s.size() - 1) return;

    if(s[pos + 1] == '1') s[pos + 1] = '0';
    else if(s[pos + 1] == '0') s[pos + 1] = '1';

    ui->screen->setText(s);
}

void MainWindow::compute() {
    while(state != '#') {
        QWidget* temp = stateWidgets[state.unicode() - b.unicode()];
        QChar idx = QChar(b.unicode() + n_state);
        QString behave, mov, next;

        if(s[pos + 1] == '0') {
            behave = temp->findChild<QLineEdit*>(QString("do_1_state_%1").arg(idx))->text(),
                mov = temp->findChild<QLineEdit*>(QString("mov_1_state_%1").arg(idx))->text(),
                next = temp->findChild<QLineEdit*>(QString("next_1_state_%1").arg(idx))->text();
        } else if(s[pos + 1] == '1') {
            behave = temp->findChild<QLineEdit*>(QString("do_2_state_%1").arg(idx))->text(),
                mov = temp->findChild<QLineEdit*>(QString("mov_2_state_%1").arg(idx))->text(),
                next = temp->findChild<QLineEdit*>(QString("next_2_state_%1").arg(idx))->text();
        }

        if(behave.length() == 1) s[pos + 1] = behave[0];

        if(mov[0] == 'L' && pos > 0) {swap(s[pos - 1], s[pos]); --pos;}
        else if(mov[0] == 'R' && pos < s.size() - 1) {swap(s[pos], s[pos + 1]); ++pos;}

        int idx_next = next[0].unicode() - b.unicode();
        if(idx_next >= 0 && idx_next <= n_state) state = next[0];

        if(next[0] == '#') state = next[0];

        ui->screen->setText(s);
    }
}

MainWindow::~MainWindow()
{
    qDeleteAll(stateWidgets);
    stateWidgets.clear();
    delete ui;
}

class InvalidIndex{};
class OutOfMemory{};