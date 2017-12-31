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

#include <QLabel>
#include <QTimer>

namespace WalletGui {

class AnimatedLabel : public QLabel {
  Q_OBJECT
  Q_DISABLE_COPY(AnimatedLabel)

public:
  AnimatedLabel(QWidget* _parent);
  ~AnimatedLabel();

  void setSprite(const QPixmap& _sprite_pixmap, const QSize& _frame_size, quint32 _vertical_space, quint32 _frequency);
  void startAnimation();
  void stopAnimation();

private:
  QPixmap m_spritePixmap;
  QSize m_spriteFrameSize;
  quint32 m_spriteVerticalSpace;
  QTimer m_animationTimer;
  QRect m_frameRect;

  void timeout();
};

}
