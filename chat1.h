#ifndef CHAT1_H
#define CHAT1_H

#include <QWidget>
#include<QTcpSocket>
namespace Ui {
class chat1;
}

class chat1 : public QWidget
{
    Q_OBJECT

public:
    explicit chat1(QTcpSocket *s,QWidget *parent = nullptr);
    ~chat1();

private slots:
    void on_clearButton_clicked();

    // void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_sendButton_clicked();

private:
    Ui::chat1 *ui;
    QTcpSocket *socket;
};

#endif // CHAT1_H
