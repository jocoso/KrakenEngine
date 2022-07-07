#pragma once

#include "CEngine.h"

using namespace kraken;
CEngine* CEngine::m_instance = nullptr;

CEngine::CEngine() {}

CEngine::~CEngine() {}

CEngine* CEngine::create() {
	KRASSERT(!m_instance);
	m_instance = new CEngine();
	return m_instance;
}

void CEngine::destroy() {
	KRASSERT(m_instance);
	delete m_instance;
}

void CEngine::release() {
	CEngine::destroy();
}

KRScene* kraken::CEngine::createScene() {
	return m_sceneFactory.createResource();
}

ui32 kraken::CEngine::getScenesID() {
	return m_sceneFactory.getResourcesID();
}

KrakenEngine* kraken::CreateKrakenEngine() {
	return CEngine::create();
}