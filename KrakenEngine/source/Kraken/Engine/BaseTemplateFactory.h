#pragma once
#include <set>
#include <Kraken/Core/KRCommon.h>
#include <Kraken/Core/KRBase.h>


namespace kraken {
	template <typename T, typename ... Args>
	class BaseTemplateFactory;



	template <typename T, typename ... Args>
	class BaseTemplateResource
	{
	public:
		using FunctionType = void(T*);

		BaseTemplateResource()
		{
		}
		~BaseTemplateResource()
		{
		}

		FunctionType* ReleaseFn;
		BaseTemplateFactory<T, Args ...>* Factory;
	};




	template <typename T, typename ... Args>
	class BaseTemplateFactory {
		static_assert(std::is_base_of<kraken::KRBase, T>::value, "T must derive from BaseTemplateResource<T>");
		static_assert(std::is_base_of<BaseTemplateResource<T, Args ...>, T>::value, "T must derive from BaseTemplateResource<T>");
	public:
		BaseTemplateFactory() {
		}

		~BaseTemplateFactory() {
			auto res_track = m_resourceTracking;
			for (auto res : res_track)
			{
				res->release();
			}
		}

		T* createResource(Args ... args)
		{
			T* res = new T(std::forward<Args>(args)...);
			m_resourceTracking.emplace(res);

			res->Factory = this;
			res->ReleaseFn = [](T* res)
			{
				res->Factory->m_resourceTracking.erase(res);
				delete res;
			};

			return res;
		}

		kraken::ui32 getNumResources()
		{
			return (kraken::ui32)m_resourceTracking.size();
		}

	private:
		std::set<T*> m_resourceTracking;
	};


}