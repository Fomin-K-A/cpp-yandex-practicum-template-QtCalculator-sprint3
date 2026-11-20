#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetInputText(const std::string &text)
{
    ui->l_result->setText(QString::fromStdString(text));
    ui->l_result->setStyleSheet("");
}

void MainWindow::SetErrorText(const std::string &text)
{
    ui->l_result->setText(QString::fromStdString(text));
    ui->l_result->setStyleSheet("color: red;");
}

void MainWindow::SetFormulaText(const std::string &text)
{
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string &text)
{
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetExtraKey(const std::optional<std::string> &key)
{
    if(!key.has_value()){
        ui->tb_extra->setVisible(false);
        ui->tb_extra->setEnabled(false);
        return;
    }
    ui->tb_extra->setVisible(true);
    ui->tb_extra->setEnabled(true);
    ui->tb_extra->setText(QString::fromStdString(key.value()));
}


