#pragma once

#include <Kraken/Engine/KRChapter.h>
#include "BaseTemplateFactory.h"
#include "BaseEntityComponentManager.h"

namespace kraken {
	class BaseChapter : public KRChapter, public BaseTemplateResource<BaseChapter> {
	public:
		BaseChapter();
		~BaseChapter();
		virtual void release() override;

		virtual KREntity* createEntity() override;

	private:
		BaseEntityComponentManager m_ecManager;
	};
}

