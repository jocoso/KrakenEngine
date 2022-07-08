#pragma once

namespace kraken {
	class KREntity;
	class KREntityComponentManager {
	public:
		KREntityComponentManager() {}
		virtual ~KREntityComponentManager() {}

		virtual KREntity* createEntity() = 0;
	};
}
