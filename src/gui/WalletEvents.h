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

#include <QEvent>

namespace WalletGui
{
    enum class WalletEventType : quint32 {
        ShowMessage = QEvent::User
    };

    class ShowMessageEvent : public QEvent {
      Q_DISABLE_COPY(ShowMessageEvent)

    public:
        ShowMessageEvent(const QString &_messageText, QtMsgType _messageType) : QEvent(static_cast<QEvent::Type>(WalletEventType::ShowMessage)),
            m_messageText(_messageText), m_messgaeType(_messageType) {
        }

        QString messageText() const {
          return m_messageText;
        }

        QtMsgType messageType() const {
          return m_messgaeType;
        }

    private:
        QString m_messageText;
        QtMsgType m_messgaeType;
    };

}
