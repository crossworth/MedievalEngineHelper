#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
    outputFile = new ME::DATFile;
}

MainWindow::~MainWindow() {
    delete outputFile;
    outputFile = nullptr;
    delete ui;
}

void MainWindow::on_pushButton_2_clicked() {
    QFileDialog files(this);
    files.setDirectory(QDir::currentPath());
    files.setFileMode(QFileDialog::ExistingFiles);
    files.setNameFilter(trUtf8("Qualquer arquivo (*)"));

    if (files.exec()) {
        if (!outputFile) {
            outputFile = new ME::DATFile;
        }

        fileNames = files.selectedFiles();
        ui->listWidget->addItems(fileNames);

        for (int i = 0; i < fileNames.size(); i++) {
            std::string fileNameClean;
            int posLast = fileNames[i].toStdString().find_last_of("/");

            fileNameClean = fileNames[i].toStdString().substr(posLast + 1);

            outputFile->addFileEntry(fileNames[i].toStdString(), fileNameClean);
        }

        if (fileNames.size() > 0) {
            ui->pushButton->setEnabled(true);
        }
    }
}

void MainWindow::on_pushButton_clicked() {
    QString fileName  = QFileDialog::getSaveFileName(this, "Salvar Arquivo MedievalEngine", QDir::currentPath(), "MedievalEngine DATA (*.dat)");

    std::string fileNameTmp  = ui->nome->text().toStdString();
    std::string descricaoTmp = ui->descricao->toPlainText().toStdString();

    if (fileNameTmp.length() <= 0) {
        fileNameTmp = "Medieval Engine Data File";
    }

    if (descricaoTmp.length() <= 0) {
        descricaoTmp = "None";
    }

    if (fileName.length() > 0) {
        outputFile->createFile(fileName.toStdString(), fileNameTmp, descricaoTmp);

        QMessageBox msgBox;
        msgBox.setText("Arquivo criado com sucesso");
        msgBox.exec();

        fileName.clear();
        ui->pushButton->setEnabled(false);
        ui->listWidget->clear();
        ui->nome->clear();
        ui->descricao->clear();

        delete outputFile;
        outputFile = nullptr;
    }
}

void MainWindow::on_descricao_textChanged() {
    if (ui->descricao->toPlainText().length() > 512) {
        ui->descricao->textCursor().deletePreviousChar();
    }
}

void MainWindow::on_pushButton_3_clicked() {
    QFileDialog file(this);
    file.setDirectory(QDir::currentPath());
    file.setFileMode(QFileDialog::ExistingFile);
    file.setNameFilter(trUtf8("MedievalEngine DATA (*.dat)"));

    if (file.exec()) {
        QString fileIn = file.selectedFiles()[0];

        if (!outputFile) {
            outputFile = new ME::DATFile;
        }

        outputFile->openFile(fileIn.toStdString());

        std::vector<std::string> fileEntries = outputFile->getFileList();
        for(unsigned int i = 0; i < fileEntries.size(); i++) {
            fileNames.push_back(QString(fileEntries[i].c_str()));
        }

        ui->listWidget->addItems(fileNames);
        ui->descricao->setPlainText(QString(outputFile->getDescription().c_str()));
        ui->nome->setText(QString(outputFile->getName().c_str()));

        if (fileNames.size() > 0) {
            ui->pushButton->setEnabled(true);
        }
    }


}

void MainWindow::keyPressEvent(QKeyEvent* e) {
    if (e->key() == Qt::Key_Delete || e->key() == Qt::Key_Backspace) {
        QListWidgetItem* item = ui->listWidget->selectedItems().first();

         for(int i = 0; i < ui->listWidget->count(); i++) {
             if(ui->listWidget->item(i)->text() == item->text()) {
                 outputFile->removeFile(item->text().toStdString());
                 delete ui->listWidget->item(i);
                 break;
             }
         }
    }
}
