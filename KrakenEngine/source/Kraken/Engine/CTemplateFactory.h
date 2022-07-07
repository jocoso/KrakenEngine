#pragma once
#include <set>
#include <Kraken/Core/KRCommon.h>
#include <Kraken/Core/KRBase.h>

namespace kraken {
	template <typename T, typename ... Args>
	class CTemplateFactory;



	template <typename T, typename ... Args>
	class CTemplateResource {

	public:
		using FunctionType = void(T*);

		CTemplateResource() {}
		~CTemplateResource() {}
		FunctionType* ReleaseFn;
		CTemplateFactory<T, Args ...>* Factory;

	};

	template <typename T, typename ... Args>
	class CTemplateFactory {

		static_assert(std::is_base_of<CTemplateResource<T>, T>::value, "T must derive from CTemplateResource<T>");
		static_assert(std::is_base_of<CTemplateResource<T, Args ...>, T>::value, "T must derive from CTemplateResource<T>");
	public:
		CTemplateFactory() {}

		~CTemplateFactory() {
			auto res_track = m_resourceTracking;
			for (auto res : res_track)
				res->release();
		}

		T* createResource(Args ... args) {
			T* res = new T(std::forward<Args>(args)...);
			m_resourceTracking.emplace(res);

			res->Factory = this;

			res->ReleaseFn = [](T* res) {

				res->Factory->m_resourceTracking.erase(res);
				delete res;

			};

			return res;
		}

		kraken::ui32 getResourcesID() {
			return (kraken::ui32)m_resourceTracking.size();
		}

	private:
		std::set<T*> m_resourceTracking;
	};

}