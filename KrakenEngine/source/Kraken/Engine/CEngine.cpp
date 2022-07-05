#pragma once

#include "CEngine.h"
#include "CFactory.h"

using namespace kraken;
CEngine* CEngine::m_instance = nullptr;

CEngine::CEngine() {
	KRASSERT(!m_instance);
	m_instance = this;
	CFactory::create();
}

CEngine::~CEngine()
{
}

void CEngine::create() {
	KRASSERT(!m_instance);
	m_instance = new CEngine();
}

CEngine* CEngine::get() {
	KRASSERT(m_instance);
	return m_instance;
}

void CEngine::destroy() {
	KRASSERT(m_instance);
	delete m_instance;
}

void CEngine::release() {
	KRASSERT(m_instance);
	CFactory::get()->release();
	delete m_instance;
}

KRScene* kraken::CEngine::createScene() {
	return CFactory::get()->getSceneFactory()->createResource();
}

ui32 kraken::CEngine::getScenesID() {
	return CFactory::get()->getSceneFactory()->getResourcesID();
}

KrakenEngine* kraken::CreateKrakenEngine() {
	CEngine::create();
	return CEngine::get();
}