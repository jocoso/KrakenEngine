#pragma once
#include <Kraken/Engine/KrakenEngine.h>
#include "BaseChapter.h"
#include "BaseWindow.h"

namespace kraken {

	class BaseEngine : public kraken::KrakenEngine {
	public:
		BaseEngine();
		~BaseEngine();

		virtual void release() override;

		virtual KRChapter* createChapter() override;
		virtual ui32 getNumChapters() override;
		
		virtual KRWindow* createWindow() override;
		virtual ui32 getNumWindows() override;

	public:
		static BaseEngine* create();

	private:
		static void destroy();

	private:
		static BaseEngine* m_instance;

		BaseTemplateFactory<BaseChapter> m_chapterFactory;
		BaseTemplateFactory<BaseWindow> m_windowFactory;
	};

}