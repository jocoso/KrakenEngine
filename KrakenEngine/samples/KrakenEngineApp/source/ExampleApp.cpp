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

	auto entity = scene->createEntity();
	auto entity2 = scene->createEntity();

	entity->release();
	entity2->release();

	scene->release();

	this->stop();
}

