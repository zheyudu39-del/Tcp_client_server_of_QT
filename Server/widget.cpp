#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    server=new QTcpServer;
    server->listen(QHostAddress::AnyIPv4,8000);
    //客户端发起连接
    connect(server,&QTcpServer::newConnection,this,&Widget::newClienthander);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::newClienthander()
{
    //建立客户连接
    QTcpSocket *socket=server->nextPendingConnection();
    socket->peerAddress();//获取地址
    socket->peerPort();//获取端口号
    ui->iplineedit->setText(socket->peerAddress().toString());
    ui->portlineedit->setText(QString::number(socket->peerPort()));
    //服务器接收客服端的消息
    connect(socket,&QTcpSocket::readyRead,this,&Widget::clientInfoSlot);
}
void Widget::clientInfoSlot()
{
    QTcpSocket *s=(QTcpSocket*)sender();
    ui->lineEdit->setText(QString(s->readAll()));

}
