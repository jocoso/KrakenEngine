#include <iostream>
#include <SFML\Graphics.hpp>

int main(void) {
	sf::RenderWindow window(sf::VideoMode(300, 800), "yea");
	sf::Event event;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
	return 0;
}
