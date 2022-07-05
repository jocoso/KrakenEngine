#pragma once
#include <set>
#include <Kraken/Core/KRCommon.h>

template <typename T, typename ... Args>
class CTemplateFactory;

template <typename T>
class CTemplateResource {
public:
	using FunctionType = void(T*);

	CTemplateResource() {}
	~CTemplateResource() {}
	virtual void release() = 0;
	FunctionType* ReleaseFn;
	CTemplateFactory<T>* Factory;
};

template <typename T, typename ... Args>
class CTemplateFactory {
	static_assert(std::is_base_of<CTemplateResource<T>, T>::value, "T must derive from CTemplateResource<T>");
public:
	CTemplateFactory(){}

	virtual ~CTemplateFactory() {
		auto res_track = m_resourceTracking;
		for (auto res : res_track)
			res->release();
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

	kraken::ui32 getResourcesID() {
		return (kraken::ui32)m_resourceTracking.size();
	}

protected:
	std::set<T*> m_resourceTracking;
};


template <typename T, typename ... Args>
class CTemplateFactoryEx : public CTemplateFactory<T, Args...> {
public:
	CTemplateFactoryEx() {
		my_var = 40;
	}

	virtual T* createResource(Args ... args) {
		my_var = 60;
		return CTemplateFactory<T, Args...>::createResource(args ...);
	}

	~CTemplateFactoryEx() {}

private:
	int my_var = 0;
};