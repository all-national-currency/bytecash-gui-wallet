// Copyright (c) 2018, The CryptoNote developers, The BYTECash developers
//
// This file is part of BYTECash.
//
// BYTECash is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// BYTECash is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with BYTECash. If not, see <https://opensource.org/licenses/lgpl-3.0/>.

#include <QMovie>

#include "CurrencyAdapter.h"
#include "ExitWidget.h"

#include "ui_exitwidget.h"

namespace WalletGui {

ExitWidget::ExitWidget(QWidget* _parent) : QWidget(_parent, Qt::Window), m_ui(new Ui::ExitWidget),
  m_clockMovie(new QMovie(this)) {
  m_ui->setupUi(this);
  QString text = m_ui->m_label->text();
  m_ui->m_label->setText(text.arg(CurrencyAdapter::instance().getCurrencyDisplayName()));
  m_clockMovie->setFileName(":images/clock");
  m_clockMovie->setScaledSize(QSize(48, 48));
  m_ui->m_clockLabel->setMovie(m_clockMovie);
  m_clockMovie->start();
}

ExitWidget::~ExitWidget() {
}

}
