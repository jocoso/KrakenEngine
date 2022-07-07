#include "BaseFactory.h"

using namespace kraken;

BaseFactory* BaseFactory::m_instance = nullptr;

BaseFactory::BaseFactory() {}
BaseFactory::~BaseFactory() {}

void BaseFactory::release() {
	BaseFactory::destroy();
}

BaseTemplateFactory<BaseChapter>* kraken::BaseFactory::getChapterFactory() {
	return &m_chapterFactory;
}

void BaseFactory::create() {
	ASSERT(!m_instance);
	m_instance = new BaseFactory();
}

BaseFactory* BaseFactory::get() {
	ASSERT(m_instance);
	return m_instance;
}

void BaseFactory::destroy() {
	ASSERT(m_instance);
	delete m_instance;
}