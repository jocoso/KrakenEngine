#pragma once
#include <typeinfo>

namespace kraken {
	class KREntity;
	class KREntityComponentManager {
	public:
		KREntityComponentManager() {}
		virtual ~KREntityComponentManager() {}

		virtual KREntity* createEntity() = 0;

		template <typename Component, typename... Args>
		Component* createComponent(KREntity* entity, Args ... args) {
			size_t id = typeid(Component).hash_code();
			auto mem = createComponentConcrete(entity, id, sizeof(Component));
			Component* comp = nullptr;

			if (mem)
				comp = new (mem) Component(args...);

			return comp;
		}

		template <typename Component>
		Component* getComponent(KREntity* entity) {
			size_t id = typeid(Component).hash_code();
			return (Component*)getComponentConcrete(entity, id);
		}

		template <typename Component>
		void removeComponent(KREntity* entity) {
			size_t id = typeid(Component).hash_code();
			removeComponentConcrete(entity, id);
		}

	protected:
		virtual void* createComponentConcrete(KREntity* entity, size_t idComponent, size_t sizeComponent) = 0;
		virtual void* getComponentConcrete(KREntity* entity, size_t idComponent) = 0;
		virtual void removeComponentConcrete(KREntity* entity, size_t idComponent) = 0;
	};
}