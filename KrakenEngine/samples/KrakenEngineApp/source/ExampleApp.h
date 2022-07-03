#pragma once

#include <Kraken/App/KRApplication.h>

class ExampleApp : public kraken::KRApplication {
public:
	ExampleApp();
	~ExampleApp();

	virtual void onInit();
	virtual void onStop();
	virtual void onUpdate();
};

