#ifndef EDITORGCONTACTDIALOG_H
#define EDITORGCONTACTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QValidator>
#include <QKeyEvent>
#include <QSqlDatabase>
#include <QTextCursor>

namespace Ui {
class EditOrgContactDialog;
}

class EditOrgContactDialog : public QDialog
{
    Q_OBJECT

signals:
    void sendData(bool update, qint32 x, qint32 y);

public slots:
    void setPos(qint32 x, qint32 y);

public:
    explicit EditOrgContactDialog(QWidget* parent = 0);
    ~EditOrgContactDialog();

    void setValues(const QString& id);
    void hideBackButton();

private slots:
    void onSave();
    void onReturn();
    void onTextChanged();
    void onCursorPosChanged();

    bool isPhone(QString* str);

    void keyPressEvent(QKeyEvent* event);

    bool eventFilter(QObject*, QEvent* event);

private:
    Ui::EditOrgContactDialog *ui;

    QSqlDatabase m_db;

    QList<QLineEdit*> m_phones;

    QStringList m_oldPhones;

    QMap<QString, QLineEdit*> m_managers;
    QMap<QString, QString> m_oldManagers;

    QString m_contactId;

    QTextCursor m_textCursor;
};

#endif // EDITORGCONTACTDIALOG_H
