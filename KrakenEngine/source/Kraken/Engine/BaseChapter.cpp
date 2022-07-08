#include "BaseChapter.h"

using namespace kraken;

kraken::BaseChapter::BaseChapter() {}
kraken::BaseChapter::~BaseChapter() {}

void kraken::BaseChapter::release() {
	ReleaseFn(this);
}

KREntity* kraken::BaseChapter::createEntity() {
	return m_ecManager.createEntity();
}