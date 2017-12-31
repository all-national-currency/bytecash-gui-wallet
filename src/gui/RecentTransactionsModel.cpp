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

#include "RecentTransactionsModel.h"
#include "SortedTransactionsModel.h"

namespace WalletGui {

RecentTransactionsModel::RecentTransactionsModel() : QSortFilterProxyModel() {
  setSourceModel(&SortedTransactionsModel::instance());
  setDynamicSortFilter(true);
  connect(sourceModel(), &QAbstractItemModel::rowsInserted, this, &RecentTransactionsModel::invalidateFilter);
}

RecentTransactionsModel::~RecentTransactionsModel() {
}

int RecentTransactionsModel::columnCount(const QModelIndex& _parent) const {
  return 1;
}

QVariant RecentTransactionsModel::data(const QModelIndex& _index, int _role) const {
  if(_role == Qt::DecorationRole) {
    return QVariant();
  }

  return QSortFilterProxyModel::data(_index, _role);
}

bool RecentTransactionsModel::filterAcceptsRow(int _sourceRow, const QModelIndex& _sourceParent) const {
  return _sourceRow < 6;
}


}
