#ifndef SECTOREXPORTOPTIONSDIALOG_H
#define SECTOREXPORTOPTIONSDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QCheckBox>
#include <QDialogButtonBox>

class SectorExportOptionsDialog : public QDialog
{
    QCheckBox *chkDirectRoutesOnly;
    QCheckBox *chkGardenRoutesOnly;
public:
    SectorExportOptionsDialog(QWidget *parent = 0);

    bool directRoutesOnly() { return chkDirectRoutesOnly->isChecked(); }
    bool gardenRoutesOnly() { return chkGardenRoutesOnly->isChecked(); }
};

#endif // SECTOREXPORTOPTIONSDIALOG_H
