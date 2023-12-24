#ifndef RULE_H
#define RULE_H

#include <QWizard>

namespace Ui {
class Rule;
}

class Rule : public QWizard
{
    Q_OBJECT

public:
    explicit Rule(QWidget *parent = nullptr);
    ~Rule();

private:
    Ui::Rule *ui;
};

#endif // RULE_H
