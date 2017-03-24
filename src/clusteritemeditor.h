/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
# GNU General Public License Usage
# This file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPL included in the
# packaging of this file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl.html.
#
############################################################################
*/

#ifndef CLUSTERITEMEDITOR_H
#define CLUSTERITEMEDITOR_H


#include <QtGui>
#include <QWidget>
#include <QListWidgetItem>
#include <QPrinter>
#include "cluster/clusteritem.h"
#include "cluster/cluster.h"
#include "cluster/aspect.h"

namespace Ui {
    class ClusterItemEditor;
}

class ClusterItemEditor : public QWidget {
    Q_OBJECT

    ClusterItem* _clusterItem;
    Cluster* _clusterPtr;
    int _selectedClusterIndex;


public:
    ClusterItemEditor(QWidget *parent = 0);
    ~ClusterItemEditor();

    const ClusterItem& clusterItem() { return *_clusterItem; }
    void setClusterItem(ClusterItem *itemPtr);
    void fillClusterWithData();
    void enableConfirmButton() ;

    inline const Cluster& cluster() { return *_clusterPtr; }
    inline Cluster* clusterPtr() { return _clusterPtr; }
    void setCluster(Cluster *c);

    inline int selectedClusterIndex() { return _selectedClusterIndex; }
    void setSelectedClusterIndex(int i);
    inline ClusterItem& selectedClusterItem() {
        if (_clusterPtr != 0 && _selectedClusterIndex != -1)
            return _clusterPtr->mutableClusterItems()[_selectedClusterIndex];
    }
    inline bool validSelectedClusterItem() {
        return (_clusterPtr != 0 && _selectedClusterIndex != -1);
    }
    inline ClusterItem* clusterItemPtr() {
        if (validSelectedClusterItem())
            return &(_clusterPtr->mutableClusterItems()[_selectedClusterIndex]);
        else
            return 0;
    }

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ClusterItemEditor *ui;

signals:
    void clusterItemChanged();



private slots:
    void on_lstReachability_itemChanged(QListWidgetItem* item);
    void on_btnConfirmEditing_clicked();
    void on_spnTech_valueChanged(int );
    void on_spnRes_valueChanged(int );
    void on_spnEnv_valueChanged(int );
    void on_txtSystemDescription_textChanged();
    void on_txtAspect3_textChanged();
    void on_txtAspect2_textChanged();
    void on_txtAspect1_textChanged();
    void on_txtSystemName_textChanged(QString );
};

#endif // CLUSTERITEMEDITOR_H
