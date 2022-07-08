#include "ExampleApp.h"
#include <Kraken/Engine/KRChapter.h>
#include <Kraken/Engine/KREntity.h>

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
	
	auto entity = chapter->createEntity();
	auto entity2 = chapter->createEntity();

	entity->release();
	entity2->release();

	chapter->release();

	this->stop();
}

