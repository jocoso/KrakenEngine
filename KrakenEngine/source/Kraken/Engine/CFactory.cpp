#include "CFactory.h"
using namespace kraken;

CFactory* CFactory::m_instance = nullptr;

CFactory::CFactory() {}

CFactory::~CFactory() {}

void CFactory::release() {
	CFactory::destroy();
}

CTemplateFactory<CScene>* kraken::CFactory::getSceneFactory() {
	return &m_sceneFactory;
}

void CFactory::create() {
	KRASSERT(!m_instance);
	m_instance = new CFactory();
}

CFactory* CFactory::get() {
	KRASSERT(m_instance);
	return m_instance;
}

void CFactory::destroy() {
	KRASSERT(m_instance);
	delete m_instance;
}