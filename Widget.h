#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QDoubleSpinBox;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_quitarAplicacionPushButton_clicked();
    void on_metrosDoubleSpinBox_valueChanged(double arg1);
    void on_centimetrosDoubleSpinBox_valueChanged(double arg1);
    void on_kilometrosDoubleSpinBox_valueChanged(double arg1);
    void muestraValores();
private:
    void configuraSpinner(QDoubleSpinBox *spinner) const;

    Ui::Widget *ui;
    double mMetros;
    double mCentimetros;
    double mKilometros;
};

#endif // WIDGET_H
