#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setColumnWidth(0,100);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Result"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    ui->tableWidget_2->setColumnCount(1);
    ui->tableWidget_2->setColumnWidth(0,100);
    ui->tableWidget_2->setHorizontalHeaderItem(0, new QTableWidgetItem("Log"));
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString FileName;
    FileName = QFileDialog::getOpenFileName(this, tr("Open Driver File"), "", tr("DLL file (*.dll)"));
    if (FileName != "")
    {
        ui->lineEdit->setText(FileName);
        m_drivertester.SetDriverFile(FileName.toStdString());
        m_drivertester.OpenDriver();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QString FileName;
    FileName = QFileDialog::getOpenFileName(this, tr("Open Log File"), "", tr("csvfile (*.csv)"));
    if (FileName != "")
    {
        ui->lineEdit_2->setText(FileName);
        m_drivertester.SetLogFile(FileName.toStdString());
        m_drivertester.OpenLogFile();
    }
}

void MainWindow::on_pushButton_3_clicked()  // обработчик кнопки моделировать
{
    int i, j = 0, Row;
    QString str, str_2;
    std::vector<std::vector<unsigned char>> log;
    m_drivertester.SimulateExchange();
    log = m_drivertester.GetFileLog();
    for(i = 0; i < log.size(); i++)
    {
        Row = ui -> tableWidget_2 -> rowCount();
        ui ->tableWidget_2->setRowCount(Row+1);
        str.clear();
        for (j = 0; j < log[i].size(); j++)
            str = str + QString::number(log[i][j], 16).rightJustified(2, '0') + " ";
        str = str.toUpper();
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(str));
    }

    log = m_drivertester.GetDriverLog();
    for(i = 0; i < log.size(); i++)
    {
        Row = ui -> tableWidget -> rowCount();
        ui ->tableWidget->setRowCount(Row+1);
        str.clear();
        for (j = 0; j < log[i].size(); j++)
            str = str + QString::number(log[i][j], 16).rightJustified(2, '0') + " ";
        str = str.toUpper();
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(str));
    }

// Выделение строк, различающихся в получившихся таблицах
    for(i = 0; i < log.size(); i++)
    {
            str = ui->tableWidget->item(i, 0)->text();
            str_2 = ui->tableWidget_2->item(i, 0)->text();
            if (str != str_2)
            {
                ui->tableWidget->item(i, 0)->setBackground(Qt::red);
                ui->tableWidget->item(i, 0)->setData(Qt::TextColorRole, QColorConstants::White);
                ui->tableWidget_2->item(i, 0)->setBackground(Qt::red);
                ui->tableWidget_2->item(i, 0)->setData(Qt::TextColorRole, QColorConstants::White);
            }
    }

}

