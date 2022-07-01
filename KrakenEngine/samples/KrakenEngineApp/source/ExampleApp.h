#pragma once


#include <KrakenEngine/App/KRApplication.h>

class ExampleApp : public kraken::KRApplication {
public:
	ExampleApp();
	~ExampleApp();

	virtual void onInit();
	virtual void onStop();
};

