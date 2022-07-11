#include <exception>
#include <Kraken/Engine/BaseWindow.h>

using namespace kraken;

BaseWindow::~BaseWindow() {}
void BaseWindow::onCreate() {}

void BaseWindow::onDestroy() {
	ReleaseFn(this);
}

void BaseWindow::onFocus() {}
void BaseWindow::onKillFocus() {}
void BaseWindow::onSize() {}