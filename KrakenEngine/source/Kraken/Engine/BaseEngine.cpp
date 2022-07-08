#pragma once

#include "BaseEngine.h"

using namespace kraken;


BaseEngine* BaseEngine::m_instance = nullptr;

BaseEngine::BaseEngine() {}
BaseEngine::~BaseEngine() {}

BaseEngine* BaseEngine::create() {
	ASSERT(!m_instance);
	m_instance = new BaseEngine();
	return m_instance;
}

void BaseEngine::destroy() {
	ASSERT(m_instance);
	delete m_instance;
}

void BaseEngine::release() {
	BaseEngine::destroy();
}

KRChapter* kraken::BaseEngine::createChapter() {
	return m_sceneFactory.createResource();
}

ui32 kraken::BaseEngine::getNumChapters() {
	return m_sceneFactory.getNumResources();
}

KrakenEngine* kraken::CreateKrakenEngine() {
	return BaseEngine::create();
}