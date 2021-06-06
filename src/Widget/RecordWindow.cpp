#include "RecordWindow.h"
#include "ui_RecordWindow.h"
#include <QStandardItemModel>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDir>
RecordWindow::RecordWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordWindow)
{
    ui->setupUi(this);
    loadData();
}

RecordWindow::~RecordWindow()
{
    delete ui;
}

void RecordWindow::loadData() {
    QFile file(QDir::homePath() + "/pellet.json");
    file.open(QIODevice::ReadOnly);
    QJsonArray array = QJsonDocument::fromJson(file.readAll()).array();
    for(const auto & ref : array) {
        QJsonObject object = ref.toObject();
        Record record;
        record.date = QDateTime::fromMSecsSinceEpoch(object.constFind("date")->toVariant().toLongLong());
        record.user = object.constFind("user")->toString();
        record.round = object.constFind("round")->toInt();
        record.score = object.constFind("score")->toInt();
        records.push_back(std::move(record));
    }
    file.close();
}

void RecordWindow::saveData() {
    QFile file(QDir::homePath() + "/pellet.json");
    file.open(QIODevice::ReadWrite);
    QJsonArray array;
    for(const auto & record : records) {
        QJsonObject object;
        object.insert("date", record.date.toMSecsSinceEpoch());
        object.insert("user", record.user);
        object.insert("round", record.round);
        object.insert("score", record.score);
        array.append(object);
    }
    file.write(QJsonDocument(array).toJson());
    file.close();
}

void RecordWindow::refresh() {
    QTableView* tableView = ui->tableView;
    auto model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({"时间", "玩家", "关卡", "分数"});
    model->setSortRole(Qt::EditRole);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    int index=0;
    for(auto iter=records.begin();iter != records.cend();iter++) {
        auto dateItem = new QStandardItem(iter->date.toString("yyyy-MM-dd HH:mm"));
        dateItem->setData(iter->date, Qt::EditRole);
        dateItem->setEditable(false);
        model->setItem(index, 0, dateItem);

        auto user = new QStandardItem(iter->user);
        user->setEditable(false);
        model->setItem(index, 1, user);

        auto round = new QStandardItem(QString::number(iter->round));
        round->setData(iter->round, Qt::EditRole);
        round->setEditable(false);
        model->setItem(index, 2, round);

        auto scene = new QStandardItem(QString::number(iter->score));
        scene->setData(iter->score, Qt::EditRole);
        scene->setEditable(false);
        model->setItem(index, 3, scene);

        index++;

    }
    tableView->setModel(model);
}

void RecordWindow::addRecord(const Record &record) {
    records.push_back(record);
}
