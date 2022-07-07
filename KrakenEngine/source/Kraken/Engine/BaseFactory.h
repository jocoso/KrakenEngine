#pragma once

#include <Kraken/Core/KRCommon.h>
#include <set>
#include "BaseTemplateFactory.h"
#include "BaseChapter.h"


namespace kraken {
	
	class BaseFactory {
	public:
		BaseFactory();
		~BaseFactory();
		void release();
		BaseTemplateFactory<BaseChapter>* getChapterFactory();

	public:
		static void create();
		static BaseFactory* get();
	private:
		static void destroy();
	private:
		static BaseFactory* m_instance;

		BaseTemplateFactoryEx<BaseChapter> m_chapterFactory;
	};

}
