#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "DATFile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_descricao_textChanged();

    void on_pushButton_3_clicked();
    void keyPressEvent(QKeyEvent* e);
private:
    Ui::MainWindow* ui;
    SM::DATFile* outputFile;
    QStringList fileNames;
};

#endif // MAINWINDOW_H
