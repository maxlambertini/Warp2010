#ifndef DIASPORACLUSTERFORM_H
#define DIASPORACLUSTERFORM_H

#include <QWidget>

namespace Ui {
    class DiasporaClusterForm;
}

class DiasporaClusterForm : public QWidget {
    Q_OBJECT
public:
    DiasporaClusterForm(QWidget *parent = 0);
    ~DiasporaClusterForm();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DiasporaClusterForm *ui;
};

#endif // DIASPORACLUSTERFORM_H
