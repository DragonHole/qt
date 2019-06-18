#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include "usermodel.h"
#include "logindialog.h"

#include <QWidget>
#include <QCryptographicHash>

class CreateAccountWizard;
class QLabel;
class QStackedWidget;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;

class CentralWidget : public QWidget
{
    Q_OBJECT

public:
    CentralWidget(QWidget *parent = 0);
    virtual ~CentralWidget();

    QString genAccountID() const;
    QByteArray toHash(QString stringToHash, QCryptographicHash::Algorithm) const;   // hash the password

public slots:
    void createAccountButtonClicked();
    void bookingButtonClicked();

    void addAccount(User &user);
    void loginRequested(QString username, QString passwordInPlainText);

//    void editAccount();
//    void removeAccount();

private:
    QLabel *_welcomeLabel;
    QPushButton *_bookingButton;
    QPushButton *_createAccountButton;
    QPushButton *_loginAccountButton;

    QLayout *_mainLayout;
    QStackedWidget *_stackedWindows;
    QWidget *_introPageObject;
    QWidget *_bookingPageObject;

    QHBoxLayout *_introLayout;
    QGridLayout *_bookingLayout;

    CreateAccountWizard *_createAccountWizard;
    loginDialog *_loginDialog;

    UserModel *_userModel;
    QString *_currentSessionUserID; // 6 digits ID
};

#endif // CENTRALWIDGET_H
