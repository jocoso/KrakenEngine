#include "KrakenEngine/App/KRApplication.h"
#include <stdexcept>

using namespace kraken;

KRApplication* KRApplication::m_instance = nullptr;

kraken::KRApplication::KRApplication() {
	if (!m_instance) 
		m_instance = this;
	else 
		throw std::runtime_error("A Kraken Application was already created.");
}

kraken::KRApplication::~KRApplication()
{
}

void kraken::KRApplication::run() {
	onInit(); 

	while (m_isRunning) {



	}

	onStop();
}

void kraken::KRApplication::stop() {
	m_isRunning = false;
}

KRApplication* kraken::KRApplication::get()
{
	return m_instance;
}
