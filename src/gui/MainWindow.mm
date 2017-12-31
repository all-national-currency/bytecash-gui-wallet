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

#import <objc/runtime.h>
#import <Cocoa/Cocoa.h>

#include "mainwindow.h"

namespace WalletGui {

namespace {

void dockClickHandler(id self, SEL _cmd) {
  Q_UNUSED(self)
  Q_UNUSED(_cmd)
  MainWindow::instance().restoreFromDock();
}

}

void MainWindow::installDockHandler() {
    Class cls = [[[NSApplication sharedApplication] delegate] class];
    if (!class_replaceMethod(cls, @selector(applicationShouldHandleReopen:hasVisibleWindows:), (IMP) dockClickHandler, "v@:")) {
      NSLog(@"MainWindow::installDockHandler() : class_addMethod failed!");
    }
}

}
