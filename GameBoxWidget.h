#ifndef GAMEBOXWIDGET_H
#define GAMEBOXWIDGET_H

#include <QWidget>

namespace Ui {
class GameBoxWidget;
}

class GameBoxWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoxWidget(QWidget *parent = nullptr);
    ~GameBoxWidget();

private:
    Ui::GameBoxWidget *ui;
};

#endif // GAMEBOXWIDGET_H
