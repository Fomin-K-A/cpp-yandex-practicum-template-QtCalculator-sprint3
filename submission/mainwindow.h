#pragma once

#include "calculator.h"
#include "enums.h"

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private slots:
    void SetInputText(const std::string& text);
    void SetErrorText(const std::string& text)
private:
    Ui::MainWindow* ui;
};

