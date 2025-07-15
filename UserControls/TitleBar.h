#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TitleBar;
}
QT_END_NAMESPACE

class TitleBar : public QMainWindow
{
    Q_OBJECT

public:
    TitleBar(QWidget *parent = nullptr);
    ~TitleBar();

private:
};
#endif // TITLEBAR_H
