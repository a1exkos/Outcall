#ifndef VIEWCONTACTDIALOG_H
#define VIEWCONTACTDIALOG_H

#include <QDialog>
#include <QValidator>
#include <QSqlQuery>

namespace Ui {
class ViewContactDialog;
}

class ViewContactDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewContactDialog(QWidget *parent = 0);
    void setValuesContacts(QString &);
    void setValuesCallHistory(QString &);
    void loadCalls(QString &);

    enum Calls
    {
        MISSED = 0,
        RECIEVED = 1,
        PLACED = 2
    };
    void addCall(const QMap<QString, QVariant> &call, Calls calls, QString stateDB);
    ~ViewContactDialog();

private:
    QSqlQuery *query;
    Ui::ViewContactDialog *ui;
    QValidator *validator;
    QString updateID;
    QString firstNumber;
    QString secondNumber;
    QString thirdNumber;
    QString fourthNumber;
    QString fifthNumber;
};

#endif // VIEWCONTACTDIALOG_H


