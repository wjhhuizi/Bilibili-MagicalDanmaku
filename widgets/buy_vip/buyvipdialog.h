#ifndef BUYVIPDIALOG_H
#define BUYVIPDIALOG_H

#include <QDialog>
#include "netinterface.h"

namespace Ui {
class BuyVIPDialog;
}

#define VIP_TYPE_RR 1
#define VIP_TYPE_ROOM 2
#define VIP_TYPE_ROBOT 3

class BuyVIPDialog : public QDialog, public NetInterface
{
    Q_OBJECT

public:
    explicit BuyVIPDialog(QString roomId, QString upId, QString userId, QString roomTitle, QString upName, QString username, QWidget *parent = nullptr);
    ~BuyVIPDialog() override;

    void updatePrice();

protected:
    void resizeEvent(QResizeEvent* e) override;
    void showEvent(QShowEvent *e) override;
    void closeEvent(QCloseEvent *e) override;

private slots:
    void on_payButton_clicked();

    void on_couponButton_clicked();

signals:
    void refreshVIP();

private:
    Ui::BuyVIPDialog *ui;

    QString roomId;
    QString upId;
    QString userId;
    QString roomTitle;
    QString upName;
    QString username;

    int vipLevel = 1;
    int vipType = VIP_TYPE_RR;
    int vipMonth = 1;
    QString couponCode;
    double couponDiscount = 1; // 优惠券折扣

    bool firstShow = true;
    bool mayPayed = false;
    const QString serverPath = "http://iwxyi.com:8102/server/";

    double unit1 = 49;
    double unit2 = 69;
    double unit3 = 99;
};

#endif // BUYVIPDIALOG_H
