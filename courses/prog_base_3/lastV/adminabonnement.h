#ifndef ADMINABONNEMENT_H
#define ADMINABONNEMENT_H

#include <QMainWindow>

namespace Ui {
class AdminAbonnement;
}

class AdminAbonnement : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminAbonnement(QWidget *parent = 0);
    ~AdminAbonnement();

private:
    Ui::AdminAbonnement *ui;
};

#endif // ADMINABONNEMENT_H
