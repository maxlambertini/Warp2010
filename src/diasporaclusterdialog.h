/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA#
############################################################################
*/

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
    void exportCluster();
    void exportClusterToHtml(QString expFilename = "");
    void exportClusterToSvg(QString expFilename = "");
    void exportClusterToGraphViz(QString expFilename = "");
    void exportClusterToPDF(QString expFilename = "");
    void printCluster();

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
