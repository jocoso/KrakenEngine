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
	return m_chapterFactory.createResource();
}

ui32 kraken::BaseEngine::getNumChapters() {
	return m_chapterFactory.getNumResources();
}

KRWindow* kraken::BaseEngine::createWindow() {
	return m_windowFactory.createResource();
}

ui32 kraken::BaseEngine::getNumWindows() {
	return m_windowFactory.getNumResources();
}

KrakenEngine* kraken::CreateKrakenEngine() {
	return BaseEngine::create();
}