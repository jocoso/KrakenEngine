#include "ExampleApp.h"
#include <Kraken/Engine/KRScene.h>

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
	auto scene = getEngine()->createScene();
	scene->release();

	this->stop();
}

