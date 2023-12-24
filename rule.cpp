#include "rule.h"
#include <QWizard>
#include "ui_rule.h"

Rule::Rule(QWidget *parent)
    : QWizard(parent)
    , ui(new Ui::Rule)
{
    ui->setupUi(this);
}

Rule::~Rule()
{
    delete ui;
}
