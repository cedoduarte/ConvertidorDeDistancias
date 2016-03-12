#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mMetros = 0.0;
    mCentimetros = 0.0;
    mKilometros = 0.0;
    configuraSpinner(ui->metrosDoubleSpinBox);
    configuraSpinner(ui->centimetrosDoubleSpinBox);
    configuraSpinner(ui->kilometrosDoubleSpinBox);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_quitarAplicacionPushButton_clicked()
{
    close();
}

void Widget::on_metrosDoubleSpinBox_valueChanged(double arg1)
{
    mMetros = arg1;
    mCentimetros = mMetros * 100.0;
    mKilometros = mMetros / 1000.0;
    muestraValores();
}

void Widget::on_centimetrosDoubleSpinBox_valueChanged(double arg1)
{
    mCentimetros = arg1;
    mMetros = mCentimetros / 100.0;
    mKilometros = mMetros / 1000.0;
    muestraValores();
}

void Widget::on_kilometrosDoubleSpinBox_valueChanged(double arg1)
{
    mKilometros = arg1;
    mMetros = mKilometros * 1000.0;
    mCentimetros = mMetros * 100.0;
    muestraValores();
}

void Widget::muestraValores()
{
    ui->metrosDoubleSpinBox->setValue(mMetros);
    ui->centimetrosDoubleSpinBox->setValue(mCentimetros);
    ui->kilometrosDoubleSpinBox->setValue(mKilometros);
}

void Widget::configuraSpinner(QDoubleSpinBox *spinner) const
{
    const double valor = 9999999999.999;
    spinner->setMinimum(-valor);
    spinner->setMaximum(valor);
    spinner->setDecimals(12);
}
