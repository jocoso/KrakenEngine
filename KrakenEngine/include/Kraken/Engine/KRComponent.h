#pragma once
#include <Kraken/Core/KRCommon.h>

namespace kraken {
	class KREntity;
	class KR_API KRComponent {
	public:
		KRComponent(kraken::KREntity* entity);
		virtual ~KRComponent();
		virtual KREntity* getEntity();

	protected:
		KREntity* m_entity = nullptr;
	};
}