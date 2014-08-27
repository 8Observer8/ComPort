
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    try {
        m_sender = new Sender( "COM1" );
    } catch ( const PortError &e ) {
        QMessageBox::information( this, "Error", QString( e.what() ) );
    } catch ( ... ) {
        QMessageBox::information( this, "Error", "Error: unknown exception" );
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete m_sender;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_startTransmissionButton_clicked()
{
    QString text = ui->valueForSendingLineEdit->text();
    QByteArray data;
    data.append( text );
    try {
        m_sender->send( data );
    } catch ( const PortError &e ) {
        QMessageBox::information( this, "Error", QString( e.what() ) );
        return;
    } catch ( ... ) {
        QMessageBox::information( this, "Error", "Error: unknown exception" );
        return;
    }
}

void MainWindow::on_stopTransmissionButton_clicked()
{

}
