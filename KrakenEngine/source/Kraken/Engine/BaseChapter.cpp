#include "BaseChapter.h"

kraken::BaseChapter::BaseChapter() {}
kraken::BaseChapter::~BaseChapter() {}

void kraken::BaseChapter::release() {
	ReleaseFn(this);
}