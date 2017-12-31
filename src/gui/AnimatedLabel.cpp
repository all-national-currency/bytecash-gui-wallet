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

#include "AnimatedLabel.h"

namespace WalletGui {

AnimatedLabel::AnimatedLabel(QWidget* _parent) : QLabel(_parent), m_spriteVerticalSpace(0) {
  connect(&m_animationTimer, &QTimer::timeout, this, &AnimatedLabel::timeout);
}

AnimatedLabel::~AnimatedLabel() {
}

void AnimatedLabel::setSprite(const QPixmap& _spritePixmap, const QSize& _frameSize, quint32 _verticalSpace, quint32 _frequency) {
  m_spritePixmap = _spritePixmap;
  m_spriteFrameSize = _frameSize;
  m_spriteVerticalSpace = _verticalSpace;
  m_animationTimer.setInterval(1000 / _frequency);
  m_frameRect.setTopLeft(QPoint(0, 0));
  m_frameRect.setBottomRight(m_frameRect.topLeft() += QPoint(_frameSize.width(), _frameSize.height()));
}

void AnimatedLabel::startAnimation() {
  if (m_animationTimer.isActive()) {
    return;
  }

  m_animationTimer.start();
}

void AnimatedLabel::stopAnimation() {
  m_animationTimer.stop();
}

void AnimatedLabel::timeout() {
  setPixmap(m_spritePixmap.copy(m_frameRect));
  m_frameRect.translate(QPoint(0, m_spriteVerticalSpace + m_spriteFrameSize.height()));
  if (m_frameRect.bottom() >= m_spritePixmap.height()) {
    m_frameRect.moveTop(0);
  }
}

}
