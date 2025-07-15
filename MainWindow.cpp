#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QQmlContext>
#include <QQuickWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    QQuickWidget *qquickwidget = new QQuickWidget();
    qquickwidget->rootContext()->setContextProperty("mainWindow", this);
    qquickwidget->setSource(QUrl(QStringLiteral("qrc:/Resources/TitleBar.qml")));

    ui->TitleBarLayout->addWidget(qquickwidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMaximized(bool val)
{
    if (m_maximized != val) {
        m_maximized = val;
        emit maximizedChanged(m_maximized);
    }
}

void MainWindow::toggleMaximize()
{
    if (m_maximized) {
        showNormal();
        setMaximized(false);
    } else {
        showMaximized();
        setMaximized(true);
    }
}

void MainWindow::minimizeWindow()
{
    showMinimized();
}

void MainWindow::quitApp()
{
    close();
}
