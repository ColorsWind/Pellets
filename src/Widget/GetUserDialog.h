#ifndef GETUSERDIALOG_H
#define GETUSERDIALOG_H

#include <QDialog>
#include <Board.h>
#include "RecordWindow.h"

namespace Ui { class GetUserDialog; }

/**
 * 获取玩家昵称的对话框
 */
class GetUserDialog : public QDialog {
Q_OBJECT
public slots:

    void cancel();

    void save();

    void quit();

public:
    bool record = false;
    QString user = "PelletUser";

    explicit GetUserDialog(QWidget *parent = nullptr);

    ~GetUserDialog();


private:
    Ui::GetUserDialog *ui;
};

#endif // GETUSERDIALOG_H
