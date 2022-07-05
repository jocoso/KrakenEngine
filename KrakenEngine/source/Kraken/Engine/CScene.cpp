#include "CScene.h"


kraken::CScene::CScene() {}
kraken::CScene::~CScene() {}
void kraken::CScene::release() {
	ReleaseFn(this);
}