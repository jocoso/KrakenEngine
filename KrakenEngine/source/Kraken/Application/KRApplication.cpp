#include <Kraken/Application/KRApplication.h>
#include <stdexcept>
using namespace kraken;

KRApplication* KRApplication::m_instance = nullptr;

kraken::KRApplication::KRApplication() {
	ASSERT(!m_instance);
	m_instance = this;
}

kraken::KRApplication::~KRApplication() {}

// Main Loop
void kraken::KRApplication::run() {

	m_engine = CreateKrakenEngine();

	onInit();

	while (m_isRunning) {

		onUpdate();

	}

	onStop();

	m_engine->release(); // Deleting the engine

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