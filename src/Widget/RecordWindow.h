#ifndef RECORDWINDOW_H
#define RECORDWINDOW_H

#include <QWidget>
#include <QDate>
#include <QString>
#include <QVector>

using std::vector;

namespace Ui { class RecordWindow; }

struct Record {
    QDateTime date;
    QString user;
    int round;
    int score;
};

class RecordWindow : public QWidget {
    Q_OBJECT
public:
    explicit RecordWindow(QWidget *parent = nullptr);

    ~RecordWindow();

    void loadData();

    void saveData();

    void refresh();
private:
    Ui::RecordWindow *ui;
    QVector<Record> records;
};

#endif // RECORDWINDOW_H
