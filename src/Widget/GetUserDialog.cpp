#include "GetUserDialog.h"
#include "ui_GetUserDialog.h"

GetUserDialog::GetUserDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::GetUserDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    connect(ui->button_save, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->button_cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->button_quit, SIGNAL(clicked()), this, SLOT(quit()));
    QString envUser = qgetenv("USER");
    if (envUser.isEmpty())
        envUser = qgetenv("USERNAME");
    if (envUser.isEmpty())
        envUser = "PelletUser";
    ui->user_text->insert(envUser);
}

GetUserDialog::~GetUserDialog()
{
    delete ui;
}

void GetUserDialog::cancel() {
    this->reject(); // 0
}

void GetUserDialog::save() {
    record = true;
    user = ui->user_text->text();
    this->accept(); // 1

}

void GetUserDialog::quit() {
    this->accept(); // 1
}
