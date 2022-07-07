#pragma once

#include <Kraken/Engine/KREntity.h>
#include "CTemplateFactory.h"

namespace kraken {

	class CEntity : public kraken::KREntity, 
		public CTemplateResource<CEntity, KREntityHandle> {
		
	public:
		CEntity(KREntityHandle handle);
		~CEntity();
		virtual KREntityHandle getHandle();
		virtual void release();
	private:
		KREntityHandle m_handle;
	};

}