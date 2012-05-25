#ifndef DIASPORACLUSTERDIALOG_H
#define DIASPORACLUSTERDIALOG_H

#include <QDialog>
#include "cluster/cluster.h"
#include "cluster/diasporaclusterscene.h"
#include "cluster/aspectlist.h"

namespace Ui {
    class DiasporaClusterDialog;
}

class DiasporaClusterDialog : public QWidget {
    Q_OBJECT
public:
    DiasporaClusterDialog(QWidget *parent = 0);
    ~DiasporaClusterDialog();

    inline Cluster& cluster() { return _cluster; }
    inline void setCluster (const Cluster& cluster) {
        _cluster = cluster;
        doFillClusterControls();
        doDrawCluster();
    }
    inline DiasporaClusterScene& clusterScene() { return _scene; }
    inline AspectList& aspectList() {return _aspectList;}
    inline void setAspectList (AspectList& al) { _aspectList = al; _cluster.setAspectList(al);}

    void generateNewCluster();
    void saveCluster();
    void loadCluster();
    void exportClusterToSvg();
    void exportClusterToGraphViz();
    void exportClusterToPDF();
    void printCluster();
    void exportClusterToHtml();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DiasporaClusterDialog *ui;
    Cluster _cluster;
    QStringList _clusterNames;
    QStringListModel _clusterNameModel;
    DiasporaClusterScene _scene;
    AspectList _aspectList;

    int _selectedRow;

    void doFillListBox();
    void doFillClusterControls();
    void doDrawCluster();
    void doGenerateCluster();
    void doProcessClusterListModelItem(QModelIndex index);
    void showClusterItemInfo(int ciIdx);

    void performSliderZoomRotation();


private slots:
    void on_lblClusterName_returnPressed();
    void on_lblClusterName_textChanged(QString );
    void on_btnRotateRight_clicked();
    void on_btnRotateLeft_clicked();
    void on_btnZoomOut_clicked();
    void on_btnZoomIn_clicked();
    void on_sliderZoom_valueChanged(int value);
    void on_sliderRotate_valueChanged(int value);
    void on_spinNumSolSys_valueChanged(int );
    void on_lstCluster_entered(QModelIndex index);
    void on_lstCluster_clicked(QModelIndex index);
    void on_btnExit_clicked();
    void on_btnSaveCluster_clicked();
    void on_btnAddAspect_clicked();
    void on_btnRandomizeAspects_clicked();
    void on_btnGenerate_clicked();

    void on_clusterItemChanged();

    void on_clusterItemClicked(const ClusterItem& cli2, int idx);
};

#endif // DIASPORACLUSTERDIALOG_H
