#ifndef CLIENTFORM_H
#define CLIENTFORM_H

#include <QMainWindow>

namespace Ui {
class clientForm;
}

class clientForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientForm(QWidget *parent = 0);

    ~clientForm();

private:
    Ui::clientForm *ui;
};

#endif // CLIENTFORM_H
