#include "ExampleApp.h"
#include <Kraken/Engine/KRChapter.h>
#include <Kraken/Engine/KREntity.h>
#include <Kraken/Engine/KRComponent.h>

ExampleApp::ExampleApp()
{
}

ExampleApp::~ExampleApp()
{
}

void ExampleApp::onInit() {
	auto window = getEngine()->createWindow();
	auto chapter = getEngine()->createChapter();

	// Entity
	auto entity = chapter->createEntity();
	entity->addComponent<kraken::KRComponent>();
	auto entity2 = chapter->createEntity();
	entity2->addComponent<kraken::KRComponent>();
}

void ExampleApp::onStop()
{
}

void ExampleApp::onUpdate() {

	this->stop();
}

