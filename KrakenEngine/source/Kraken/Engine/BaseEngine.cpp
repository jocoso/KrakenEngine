#pragma once

#include "BaseEngine.h"
#include "BaseFactory.h"
using namespace kraken;


BaseEngine* BaseEngine::m_instance = nullptr;

BaseEngine::BaseEngine() {
	ASSERT(!m_instance);
	m_instance = this;
	BaseFactory::create();
}

BaseEngine::~BaseEngine() {}

void BaseEngine::create() {
	ASSERT(!m_instance);
	m_instance = new BaseEngine();
}

BaseEngine* BaseEngine::get() {
	ASSERT(m_instance);
	return m_instance;
}

void BaseEngine::destroy() {
	ASSERT(m_instance);
	delete m_instance;
}

void BaseEngine::release() {
	ASSERT(m_instance);
	BaseFactory::get()->release();
	delete m_instance;
}

KRChapter* kraken::BaseEngine::createChapter() {
	return BaseFactory::get()->getChapterFactory()->createResource();
}

ui32 kraken::BaseEngine::getNumChapters() {
	return BaseFactory::get()->getChapterFactory()->getNumResources();
}

KrakenEngine* kraken::CreateKrakenEngine() {
	BaseEngine::create();
	return BaseEngine::get();
}