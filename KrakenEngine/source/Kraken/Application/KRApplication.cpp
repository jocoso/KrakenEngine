#include <Kraken/Application/KRApplication.h>
#include <stdexcept>
#include <chrono>
#include <thread>

using namespace kraken;

KRApplication* KRApplication::m_instance = nullptr;

kraken::KRApplication::KRApplication() {
	ASSERT(!m_instance);
	m_instance = this;
	m_engine = CreateKrakenEngine();
}

kraken::KRApplication::~KRApplication() {
	m_engine->release(); // Delete Engine
}

void kraken::KRApplication::stop() {
	m_isRunning = false;
}

KrakenEngine* kraken::KRApplication::getEngine() {
	return m_engine;
}

KRApplication* kraken::KRApplication::get() {
	ASSERT(m_instance);
	return m_instance;
}