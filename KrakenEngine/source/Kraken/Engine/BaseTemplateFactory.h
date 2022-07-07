#pragma once

#include <set>
#include <Kraken/Core/KRCommon.h>

template <typename T, typename ... Args>
class BaseTemplateFactory;



// Template Resources

template <typename T>
class BaseTemplateResource {
public:
	using FunctionType = void(T*);

	BaseTemplateResource() {}
	~BaseTemplateResource() {}

	virtual void release() = 0;
	FunctionType* ReleaseFn;
	BaseTemplateFactory<T>* Factory;
};





// Template Factory

template <typename T, typename ... Args>
class BaseTemplateFactory {
	static_assert(std::is_base_of<BaseTemplateResource<T>, T>::value, "T must derive from BaseTemplateResource<T>");

public:
	BaseTemplateFactory() {}

	virtual ~BaseTemplateFactory() {
		auto res_track = m_resourceTracking;
		for (auto res : res_track) {
			res->release();
		}
	}

	virtual T* createResource(Args ... args) {
		
		T* res = new T(std::forward<Args>(args)...);
		m_resourceTracking.emplace(res);

		res->Factory = this;
		res->ReleaseFn = [](T* res) {
			res->Factory->m_resourceTracking.erase(res);
			delete res;
		};

		return res;

	}

	kraken::ui32 getNumResources() {
		return (kraken::ui32)m_resourceTracking.size();
	}

protected:
	std::set<T*> m_resourceTracking;
};



// TMP Factory
template <typename T, typename ... Args>
class BaseTemplateFactoryEx : public BaseTemplateFactory<T, Args...> {
public:
	BaseTemplateFactoryEx() {
		my_var = 3;
	}

	virtual T* createResource(Args ... args) {
		my_var = 6;
		return BaseTemplateFactory<T, Args...>::createResource(args ...);
	}

	~BaseTemplateFactoryEx() {}

private:
	int my_var = 0;
};

