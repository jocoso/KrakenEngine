#pragma once
#include <Kraken/Engine/KRScene.h>
#include "CTemplateFactory.h"

namespace kraken {
	class CScene : public KRScene, public CTemplateResource<CScene> {
	public:
		CScene();
		~CScene();
		virtual void release() override;
	};
}

