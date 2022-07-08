#pragma once

#include <Kraken/Engine/KREntity.h>
#include "BaseTemplateFactory.h"

namespace kraken {

	class BaseEntity: public kraken::KREntity, public BaseTemplateResource<BaseEntity, KREntityHandle> {
	public:
		BaseEntity(KREntityHandle handle);
		~BaseEntity();
		virtual KREntityHandle getHandle();
		virtual void release();

	private:
		KREntityHandle m_handle;
		
	};

}
