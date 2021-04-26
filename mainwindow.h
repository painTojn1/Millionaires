#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QVector>
#include <QMapIterator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exitButton_clicked();

    void on_playButton_clicked();

    void on_answerAButton_clicked();

    void on_answerBButton_clicked();

    void on_answerCButton_clicked();

    void on_answerDButton_clicked();

private:
    Ui::MainWindow *ui;
    QMap<QString, QVector<QString>> questions;
    int points;
    int questionNumber;

};
#endif // MAINWINDOW_H
