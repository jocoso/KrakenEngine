#pragma once

#include <Kraken/Core/KRBase.h>
#include <Kraken/Engine/KREntityComponentManager.h>

namespace kraken {
	typedef size_t KREntityHandle;

	class KREntity : public KRBase {
	public:
		KREntity() {}
		virtual ~KREntity() {}

		virtual KREntityHandle getHandle() = 0;

		template<typename Component>
		Component* addComponent() {
			return m_ecManager->createComponent<Component>(this, this);
		}

		template <typename Component>
		Component* getComponent() {
			return m_ecManager->getComponent<Component>(this);
		}

		template <typename Component>
		void removeComponent() {
			m_ecManager->removeComponent<Component>(this);
		}

	protected:
		KREntityComponentManager* m_ecManager = nullptr;
	};
}