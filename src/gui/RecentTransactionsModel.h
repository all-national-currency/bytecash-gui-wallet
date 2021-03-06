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

#pragma once

#include <QSortFilterProxyModel>

namespace WalletGui {

class RecentTransactionsModel : public QSortFilterProxyModel {
  Q_OBJECT
  Q_DISABLE_COPY(RecentTransactionsModel)

public:
  RecentTransactionsModel();
  ~RecentTransactionsModel();

  int columnCount(const QModelIndex& _parent = QModelIndex()) const Q_DECL_OVERRIDE;
  QVariant data(const QModelIndex& _index, int _role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  bool filterAcceptsRow(int _source_row, const QModelIndex& _source_parent) const Q_DECL_OVERRIDE;
};

}
