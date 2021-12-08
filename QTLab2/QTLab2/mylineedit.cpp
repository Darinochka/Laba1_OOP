#include "myLineEdit.h"

myLineEdit::myLineEdit(QWidget *parent)
 : QLineEdit(parent)
{}

myLineEdit::~myLineEdit()
{}

void myLineEdit::focusInEvent(QFocusEvent *e)
{
  QLineEdit::focusInEvent(e);
  emit(focussed(true));
}

void myLineEdit::focusOutEvent(QFocusEvent *e)
{
  QLineEdit::focusOutEvent(e);
  emit(focussed(false));
}
