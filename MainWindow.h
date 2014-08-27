#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Sender.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_startTransmissionButton_clicked();

    void on_stopTransmissionButton_clicked();

private:
    Ui::MainWindow *ui;
    Sender *m_sender;
};

#endif // MAINWINDOW_H
