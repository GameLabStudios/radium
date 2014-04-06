// DEBUG #includes
#if _DEBUG
#include <iostream>
#endif

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ParticleSystem.h"

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Particle System Test");

	// Start the clock
	sf::Clock clock;

	// DEBUG Declarations
#if _DEBUG
	// Debug FPS Clock
	sf::Clock fpsClock;
	unsigned fps = 0;
#endif

	// Create the particle system.
	ParticleSystem particles(100000);
	 
	// Start the game loop
	while (window.isOpen())
	{
		// Process Events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				// Close Window : exit
				case sf::Event::Closed:
					window.close();
					break;
				
				default:

					break;
			}
		}

		// Get delta time.
		sf::Time elapsed = clock.restart();

		// DEBUG Game Loop
#if _DEBUG
		// Calculate FPS and Print to Console
		fps++;
		sf::Time fpsElapsed = fpsClock.getElapsedTime();
		if (fpsElapsed.asSeconds() >= 1.0f)
		{
			fpsClock.restart();
			std::cout << "FPS: " << fps << std::endl;
			fps = 0;
		}
#endif

		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		particles.SetEmitter(window.mapPixelToCoords(mouse));
		
		// Update Particles
		particles.Update(elapsed);

		// Clear Screen
		window.clear();

		// Draw Particles
		window.draw(particles);

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}