# KRAKEN
## A text adventure engine

| Name | Master | Stable |
|------|--------|--------|
| SeaMonster VS 0.01 |[![Build Status](https://build.kde.org/job/Extragear/job/krita/job/kf5-qt5%20SUSEQt5.15/badge/icon)](https://build.kde.org/job/Extragear/job/krita/job/kf5-qt5%20SUSEQt5.15/) |[![Build Status](https://build.kde.org/job/Extragear/job/krita/job/kf5-qt5%20SUSEQt5.15/badge/icon)](https://build.kde.org/job/Extragear/job/krita/job/kf5-qt5%20SUSEQt5.15/)|

** Installation **
-------------------
::

	git clone git@github.com:jocoso/Kraken.git



```
	#include "theater.h"

	int main() {

		krk::Theater main_loop( 800, 800, "Kraken" );
		main_loop.display();

		return 0;

	}

```