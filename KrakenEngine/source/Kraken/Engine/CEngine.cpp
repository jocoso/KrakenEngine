#include "CEngine.h"
#include <Kraken/Core/KRCommon.h>
#pragma once

using namespace kraken;

CEngine* CEngine::m_instance = nullptr;

KrakenEngine* kraken::CreateKrakenEngine() {
	return CEngine::create();
}

kraken::CEngine::CEngine()
{
}

kraken::CEngine::~CEngine()
{
}

void kraken::CEngine::release() {
	CEngine::destroy();
}

CEngine * kraken::CEngine::create() {
	KRASSERT(!m_instance);
	m_instance = new CEngine();
	return m_instance;
}

void kraken::CEngine::destroy() {
	KRASSERT(m_instance);
	delete m_instance;
	m_instance = nullptr;
}

