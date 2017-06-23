#ifndef QMODULEDESCWIDGET_H
#define QMODULEDESCWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QTableWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIntValidator>
#include <QDoubleValidator>
#include <texturebuilder/moduledescriptor.h>
#include <QSharedPointer>
#include <QDialogButtonBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QGroupBox>

class QModuleDescWidget : public QWidget
{
    Q_OBJECT

    QString _moduleType;
    QString _name;
    int _seed;
    int _oct;
    double _freq;
    double _lac;
    double _pers;
    QString _src1;
    QString _src2;
    QString _src3;
    QString _src4;
    QString _ctl;
    double _displ;
    double _lBound;
    double _uBound;
    double _exp;
    double _bias;
    double _scale;
    double _pow;
    double _rough;
    double _value;
    double _x;
    double _y;
    double _z;
    bool _invert;
    bool _enableRandom;
    bool _enableDist;
    QVector<std::tuple<double,double>> _cPoints;

    //controls
    QComboBox *c_moduleType;
    QLineEdit *c_name;
    QLineEdit *c_seed;
    QLineEdit *c_oct;
    QLineEdit *c_freq;
    QLineEdit *c_lac;
    QLineEdit *c_pers;
    QComboBox *c_src1;
    QComboBox *c_src2;
    QComboBox *c_src3;
    QComboBox *c_src4;
    QComboBox *c_ctl;
    QLineEdit *c_displ;
    QLineEdit *c_lBound;
    QLineEdit *c_uBound;
    QLineEdit *c_exp;
    QLineEdit *c_bias;
    QLineEdit *c_scale;
    QLineEdit *c_pow;
    QLineEdit *c_rough;
    QLineEdit *c_value;
    QLineEdit *c_x;
    QLineEdit *c_y;
    QLineEdit *c_z;
    QCheckBox *c_invert;
    QCheckBox *c_enableRandom;
    QCheckBox *c_enableDist;
    QTableWidget *c_cPoints;

    QDoubleSpinBox *s_x;
    QDoubleSpinBox *s_y;
    QPushButton *btnAddControlPoint;
    QWidget *w;

    //external data pointers
    ModuleDescriptor* _moduleDesc;
    QVector<QString> _moduleList;

public:
    //setters
    void setModuleType( const QString& v ) { _moduleType  = v; }
    void setName( const QString& v ) { _name  = v; }
    void setSeed( int v ) { _seed  = v; }
    void setOct( int v ) { _oct  = v; }
    void setFreq( double v ) { _freq  = v; }
    void setLac( double v ) { _lac  = v; }
    void setPers( double v ) { _pers  = v; }
    void setSrc1( const QString& v ) { _src1  = v; }
    void setSrc2( const QString& v ) { _src2  = v; }
    void setSrc3( const QString& v ) { _src3  = v; }
    void setSrc4( const QString& v ) { _src4  = v; }
    void setCtl( const QString& v ) { _ctl  = v; }
    void setDispl( double v ) { _displ  = v; }
    void setLBound( double v ) { _lBound  = v; }
    void setUBound( double v ) { _uBound  = v; }
    void setExp( double v ) { _exp  = v; }
    void setBias( double v ) { _bias  = v; }
    void setScale( double v ) { _scale  = v; }
    void setPow( double v ) { _pow  = v; }
    void setRough( double v ) { _rough  = v; }
    void setValue( double v ) { _value  = v; }
    void setX( double v ) { _x  = v; }
    void setY( double v ) { _y  = v; }
    void setZ( double v ) { _z  = v; }
    void setInvert( bool v ) { _invert  = v; }
    void setEnableRandom( bool v ) { _enableRandom  = v; }
    void setEnableDist( bool v ) { _enableDist  = v; }
    void setCPoints( const QVector<std::tuple<double,double>>& v ) { _cPoints  = v; }

    //getters
    const QString& moduleType() { return _moduleType; }
    const QString& name() { return _name; }
    int seed() { return _seed; }
    int oct() { return _oct; }
    double freq() { return _freq; }
    double lac() { return _lac; }
    double pers() { return _pers; }
    const QString& src1() { return _src1; }
    const QString& src2() { return _src2; }
    const QString& src3() { return _src3; }
    const QString& src4() { return _src4; }
    const QString& ctl() { return _ctl; }
    double displ() { return _displ; }
    double lBound() { return _lBound; }
    double uBound() { return _uBound; }
    double exp() { return _exp; }
    double bias() { return _bias; }
    double scale() { return _scale; }
    double pow() { return _pow; }
    double rough() { return _rough; }
    double value() { return _value; }
    double x() { return _x; }
    double y() { return _y; }
    double z() { return _z; }
    bool invert() { return _invert; }
    bool enableRandom() { return _enableRandom; }
    bool enableDist() { return _enableDist; }
    const QVector<std::tuple<double,double>>& cPoints() { return _cPoints; }

    explicit QModuleDescWidget(QWidget *parent = 0);

    void createWidgets();
    void layoutWidgets();

    void setModuleDesc(ModuleDescriptor* d);
    void setModuleList(QVector<QString>& m);

    void updateControlsFromDescriptor();
    void updateDescriptorFromControls();

    ModuleDescriptor* moduleDesc() { return _moduleDesc; }
    QVector<QString>&  moduleList() { return _moduleList; }

    void updateGridWithControlPoints();

    void enableForEditing() { this->c_name->setReadOnly(false); }
    void enableForAdding() { this->c_name->setReadOnly(true); }

    template<typename T> void enableControlsInGrid(const QString& prefix);


signals:

private slots:
    void on_add_tuple_clicked();
    void on_module_type_changed(QString type);

};

#endif // QMODULEDESCWIDGET_H
