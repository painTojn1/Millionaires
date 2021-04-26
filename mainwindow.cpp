#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    points = 0;
    questionNumber = 0;
    ui->answerAButton->setEnabled(false);
    ui->answerBButton->setEnabled(false);
    ui->answerCButton->setEnabled(false);
    ui->answerDButton->setEnabled(false);

    QVector<QString> answers1;
    answers1.push_back("1785");
    answers1.push_back("false");
    answers1.push_back("1789");
    answers1.push_back("false");
    answers1.push_back("1798");
    answers1.push_back("true");
    answers1.push_back("1800");
    answers1.push_back("false");
    questions["01. W którym roku urodził się Adam Mickiewicz?"] = answers1;
    QVector<QString> answers2;
    answers2.push_back("Arce Gdynia");
    answers2.push_back("false");
    answers2.push_back("Lechii Gdańsk");
    answers2.push_back("true");
    answers2.push_back("Śląskowi Wrocław");
    answers2.push_back("false");
    answers2.push_back("Ruchowi Chorzów");
    answers2.push_back("false");
    questions["02. Któremu klubowi zagorzale kibicują Donald Tusk i Jacek Kurski?"] = answers2;
    QVector<QString> answers3;
    answers3.push_back("27 października 2009");
    answers3.push_back("true");
    answers3.push_back("27 września 2009");
    answers3.push_back("false");
    answers3.push_back("30 września 2010");
    answers3.push_back("false");
    answers3.push_back("27 października 2009");
    answers3.push_back("false");
    questions["03. Jaka jest data wydania League of Legends?"] = answers3;
    QVector<QString> answers4;
    answers4.push_back("Sód");
    answers4.push_back("false");
    answers4.push_back("Potas");
    answers4.push_back("false");
    answers4.push_back("Wapń");
    answers4.push_back("false");
    answers4.push_back("Siarka");
    answers4.push_back("true");
    questions["04. Nie jest metalem?"] = answers4;
    QVector<QString> answers5;
    answers5.push_back("auta");
    answers5.push_back("false");
    answers5.push_back("psa");
    answers5.push_back("true");
    answers5.push_back("basenu");
    answers5.push_back("false");
    answers5.push_back("chodnika");
    answers5.push_back("false");
    questions["05. Groomer zadba o wygląd twojego:"] = answers5;
    QVector<QString> answers6;
    answers6.push_back("Niechlujny strój");
    answers6.push_back("false");
    answers6.push_back("Kędzierzawa broda");
    answers6.push_back("false");
    answers6.push_back("Potężna muskulatura");
    answers6.push_back("false");
    answers6.push_back("Długie wąsy");
    answers6.push_back("true");
    questions["06. Co jest atrybutem Herkulesa Poirot ze stronic powieści Agaty Christie?"] = answers6;
    QVector<QString> answers7;
    answers7.push_back("Mojżesz");
    answers7.push_back("false");
    answers7.push_back("Judasz");
    answers7.push_back("true");
    answers7.push_back("Abel");
    answers7.push_back("false");
    answers7.push_back("Noe");
    answers7.push_back("false");
    questions["07. Która z biblijnych postaci nosi przydomek Iskariota?"] = answers7;
    QVector<QString> answers8;
    answers8.push_back("Ksiądz Robak");
    answers8.push_back("true");
    answers8.push_back("Sędzia");
    answers8.push_back("false");
    answers8.push_back("Podkomorzy");
    answers8.push_back("false");
    answers8.push_back("Gerwazy");
    answers8.push_back("false");
    questions["08. Kto był ojcem Tadeusza Soplicy w książce \"Pan Tadeusz\""] = answers8;
    QVector<QString> answers9;
    answers9.push_back("Eurysteusza");
    answers9.push_back("false");
    answers9.push_back("Orfeusza");
    answers9.push_back("true");
    answers9.push_back("Morfeusza");
    answers9.push_back("false");
    answers9.push_back("Perseusza");
    answers9.push_back("false");
    questions["09. Eurydyka to żona:"] = answers9;
    QVector<QString> answers10;
    answers10.push_back("cyfry 0 i 1");
    answers10.push_back("true");
    answers10.push_back("litery X i Y");
    answers10.push_back("false");
    answers10.push_back("kropki i kreski");
    answers10.push_back("false");
    answers10.push_back("kwadraty i kółka");
    answers10.push_back("false");
    questions["10. W systemie binarnym do zapisu liczb potrzebne są tylko:"] = answers10;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::on_playButton_clicked()
{
    ui->pointsLabel->setText("Punkty: " + QString::number(points));
    QMapIterator<QString, QVector<QString> > i(questions);
    if(ui->playButton->text() == "Graj")
    {
        i.next();
        ui->questionLabel->setText(i.key());
        QVector<QString> tmp = i.value();
        ui->answerALabel->setText(tmp[0]);
        ui->answerBLabel->setText(tmp[2]);
        ui->answerCLabel->setText(tmp[4]);
        ui->answerDLabel->setText(tmp[6]);
        ui->playButton->setText("Dalej");
        ui->answerAButton->setEnabled(true);
        ui->answerBButton->setEnabled(true);
        ui->answerCButton->setEnabled(true);
        ui->answerDButton->setEnabled(true);
        questionNumber++;
    }
    else if(ui->playButton->text() == "Dalej")
    {
        questionNumber++;
        if(questionNumber == 11)
        {
            QMessageBox::information(this, "Koniec gry!", "Odpowiedziałeś dobrze na " + QString::number(points) + " pytań.");
        }
        else
        {
            int pom = questionNumber;
            while(pom--)
            {
                i.next();
            }
            ui->questionLabel->setText(i.key());
            QVector<QString> tmp = i.value();
            ui->answerALabel->setText(tmp[0]);
            ui->answerBLabel->setText(tmp[2]);
            ui->answerCLabel->setText(tmp[4]);
            ui->answerDLabel->setText(tmp[6]);
            ui->answerAButton->setEnabled(true);
            ui->answerBButton->setEnabled(true);
            ui->answerCButton->setEnabled(true);
            ui->answerDButton->setEnabled(true);
        }
    }
}

void MainWindow::on_answerAButton_clicked()
{
    QMapIterator<QString, QVector<QString> > i(questions);
    int pom = questionNumber;
    while(pom--)
    {
        i.next();
    }
    QVector<QString> tmp = i.value();
    if(tmp[1] == "true")
    {
        points++;
        ui->pointsLabel->setText("Punkty: " + QString::number(points));
        ui->answerAButton->setEnabled(false);
        ui->answerBButton->setEnabled(false);
        ui->answerCButton->setEnabled(false);
        ui->answerDButton->setEnabled(false);
        QMessageBox::information(this, "Brawo!", "Wybrałeś poprawną odpowiedź!");
    }
    else if(tmp[1] == "false")
    {
        ui->answerAButton->setEnabled(false);
        ui->answerBButton->setEnabled(false);
        ui->answerCButton->setEnabled(false);
        ui->answerDButton->setEnabled(false);
        QMessageBox::information(this, "Niestety!", "Wybrałeś złą odpowiedź!");
    }
}

void MainWindow::on_answerBButton_clicked()
{
    QMapIterator<QString, QVector<QString> > i(questions);
    int pom = questionNumber;
    while(pom--)
    {
        i.next();
    }
    QVector<QString> tmp = i.value();
    if(tmp[3] == "true")
    {
        points++;
        ui->pointsLabel->setText("Punkty: " + QString::number(points));
        ui->answerAButton->setEnabled(false);
        ui->answerBButton->setEnabled(false);
        ui->answerCButton->setEnabled(false);
        ui->answerDButton->setEnabled(false);
        QMessageBox::information(this, "Brawo!", "Wybrałeś poprawną odpowiedź!");
    }
    else if(tmp[3] == "false")
    {
        ui->answerAButton->setEnabled(false);
        ui->answerBButton->setEnabled(false);
        ui->answerCButton->setEnabled(false);
        ui->answerDButton->setEnabled(false);
        QMessageBox::information(this, "Niestety!", "Wybrałeś złą odpowiedź!");
    }
}

void MainWindow::on_answerCButton_clicked()
{
    QMapIterator<QString, QVector<QString> > i(questions);
    int pom = questionNumber;
    while(pom--)
    {
        i.next();
    }
    QVector<QString> tmp = i.value();
    if(tmp[5] == "true")
    {
        points++;
        ui->pointsLabel->setText("Punkty: " + QString::number(points));
        ui->answerAButton->setEnabled(false);
        ui->answerBButton->setEnabled(false);
        ui->answerCButton->setEnabled(false);
        ui->answerDButton->setEnabled(false);
        QMessageBox::information(this, "Brawo!", "Wybrałeś poprawną odpowiedź!");
    }
    else if(tmp[5] == "false")
    {
        ui->answerAButton->setEnabled(false);
        ui->answerBButton->setEnabled(false);
        ui->answerCButton->setEnabled(false);
        ui->answerDButton->setEnabled(false);
        QMessageBox::information(this, "Niestety!", "Wybrałeś złą odpowiedź!");
    }
}

void MainWindow::on_answerDButton_clicked()
{
    QMapIterator<QString, QVector<QString> > i(questions);
    int pom = questionNumber;
    while(pom--)
    {
        i.next();
    }
    QVector<QString> tmp = i.value();
    if(tmp[7] == "true")
    {
        points++;
        ui->pointsLabel->setText("Punkty: " + QString::number(points));
        ui->answerAButton->setEnabled(false);
        ui->answerBButton->setEnabled(false);
        ui->answerCButton->setEnabled(false);
        ui->answerDButton->setEnabled(false);
        QMessageBox::information(this, "Brawo!", "Wybrałeś poprawną odpowiedź!");
    }
    else if(tmp[7] == "false")
    {
        ui->answerAButton->setEnabled(false);
        ui->answerBButton->setEnabled(false);
        ui->answerCButton->setEnabled(false);
        ui->answerDButton->setEnabled(false);
            QMessageBox::information(this, "Niestety!", "Wybrałeś złą odpowiedź!");
    }
}
