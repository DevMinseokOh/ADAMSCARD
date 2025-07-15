#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(bool maximized READ isMaximized WRITE setMaximized NOTIFY maximizedChanged)

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool isMaximized() const { return m_maximized; }
    void setMaximized(bool val);

    Q_INVOKABLE void toggleMaximize();
    Q_INVOKABLE void minimizeWindow();
    Q_INVOKABLE void quitApp();

signals:
    void maximizedChanged(bool);

private:
    Ui::MainWindow *ui;
    bool m_maximized = false;
};

#endif // MAINWINDOW_H
