#include "chat1.h"
#include "ui_chat1.h"

chat1::chat1(QTcpSocket *s,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chat1)
{
    ui->setupUi(this);
    socket=s;
}

chat1::~chat1()
{
    delete ui;
}

void chat1::on_clearButton_clicked()
{
    ui->lineEdit->clear();
}
void chat1::on_sendButton_clicked()
{
    QByteArray ba;
    ba.append(ui->lineEdit->text().toUtf8());
    socket->write(ba);
}

