#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#inclde <QFocusEvent>

class myLineEdit : public QLineEdit
{
  Q_OBJECT

public:
  myLineEdit(QWidget *parent = 0);
  ~myLineEdit();

signals:
  void focussed(bool hasFocus);

protected:
  virtual void focusInEvent(QFocusEvent *e);
  virtual void focusOutEvent(QFocusEvent *e);
};
#endif // MYLINEEDIT_H
