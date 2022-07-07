#include "ExampleApp.h"
#include <Kraken/Engine/KRChapter.h>

ExampleApp::ExampleApp()
{
}

ExampleApp::~ExampleApp()
{
}

void ExampleApp::onInit()
{
}

void ExampleApp::onStop()
{
}

void ExampleApp::onUpdate() {
	auto chapter = getEngine()->createChapter();
	chapter->release();

	this->stop();
}

