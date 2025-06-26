#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QClipboard>
#include <QGuiApplication>
#include <QDir>

QString xorEncryptDecrypt(const QString &text, const QString &key) {
    QByteArray data = text.toUtf8();
    QByteArray k = key.toUtf8();
    QByteArray result;

    for (int i = 0; i < data.size(); ++i)
        result.append(data[i] ^ k[i % k.size()]);

    return QString(result.toBase64());
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("SecureView");
    resize(400, 200);
    setFixedSize(size());

    input = new QLineEdit(this);
    input->setPlaceholderText("Password");
    input->setEchoMode(QLineEdit::Password);  // Hide input
    input->setGeometry(50, 40, 300, 30);

    button = new QPushButton("Enter", this);
    button->setGeometry(150, 90, 100, 30);

    label = new QLabel(this);
    label->setGeometry(100, 140, 200, 30);
    label->setAlignment(Qt::AlignCenter);

    connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(input, &QLineEdit::returnPressed, button, &QPushButton::click);
}

MainWindow::~MainWindow() {}

void MainWindow::onButtonClicked()
{
    QString inputText = input->text();
    QString key = "ZZZBESTGAME/";
    QString encrypted = xorEncryptDecrypt(inputText, key);

    qDebug() << "[Debug] Input:" << inputText;
    qDebug() << "[Debug] Encrypted:" << encrypted;

    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(encrypted);

    QString dataPath = QCoreApplication::applicationDirPath() + "/data";
    qDebug() << "[Debug] Data path:" << dataPath;

    QDir dir(dataPath);
    if (!dir.exists()) {
        if (dir.mkpath(".")) {
            qDebug() << "[Debug] Created directory:" << dataPath;
        } else {
            qDebug() << "[Error] Failed to create directory:" << dataPath;
        }
    }

    QFile outFile(dataPath + "/final.file");
    if (outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&outFile);
        out << encrypted;
        outFile.close();
        qDebug() << "[Success] File saved to:" << outFile.fileName();
        label->setText("Encrypted & saved to file!");
    } else {
        qDebug() << "[Error] Failed to write file:" << outFile.fileName();
        label->setText("Failed to save encrypted file.");
    }
}
