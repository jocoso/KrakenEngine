#include <Kraken/App/KRApplication.h>
#include <stdexcept>

using namespace kraken;

KRApplication* KRApplication::m_instance = nullptr;

kraken::KRApplication::KRApplication() {
	KRASSERT(!m_instance);
	m_instance = this;
	m_engine = kraken::CreateKrakenEngine();
}

kraken::KRApplication::~KRApplication() {
	m_engine->release();
}

void kraken::KRApplication::run() {
	onInit(); 

	while (m_isRunning) {

		onUpdate();

	}

	onStop();
}

void kraken::KRApplication::stop() {
	m_isRunning = false;
}

KRApplication* kraken::KRApplication::get() {
	KRASSERT(m_instance);
	return m_instance;
}
