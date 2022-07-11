#pragma once
#include <Kraken/Core/KRCommon.h>
#include <Kraken/Engine/KRWindow.h>
#include "BaseTemplateFactory.h"

namespace kraken {
	class BaseWindow : public kraken::KRWindow, public BaseTemplateResource<BaseWindow> {
	public:
		BaseWindow();
		~BaseWindow();

		virtual void onCreate();
		virtual void onDestroy();
		virtual void onFocus();
		virtual void onKillFocus();
		virtual void onSize();
		virtual void release();

	protected:
		void* m_handle = nullptr;
	};
}

