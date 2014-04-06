#include "ParticleSystem.h"

void ParticleSystem::SetEmitter(sf::Vector2f position)
{
	m_emitter = position;
}

void ParticleSystem::Update(sf::Time elapsed)
{
	for (std::size_t i = 0; i < m_particles.size(); ++i)
	{
		// Update the particles lifetime
		Particle& p = m_particles[i];
		p.lifetime -= elapsed;

		// If the particle is dead, respawn it
		if (p.lifetime <= sf::Time::Zero)
			ResetParticles(i);

		//float angle = atan2(360 - m_vertices[i].position.y, 640 - m_vertices[i].position.x);
		//float speed = 7.0f;
		//p.velocity.x += std::cos(angle) * speed;
		//p.velocity.y += std::sin(angle) * speed;

		// Update the position of the corresponding vertex
		m_vertices[i].position += p.velocity * elapsed.asSeconds();

		// Update the alpha (transparency of the particle accoring to its lifetime
		//float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
		//m_vertices[i].color = p.color;
		//m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
	}
}

void ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	 // Apply the transform
	states.transform *= getTransform();

	// Out particles don't use a texture
	states.texture = NULL;

	// Draw the vertex array
	target.draw(m_vertices, states);
}

void ParticleSystem::ResetParticles(std::size_t index)
{
	// Give a random velocity and lifetime to the particle
	float angle = (std::rand() % 360) * 3.14f / 180.0f;
	float speed = (std::rand() % 50) + 50.0f;
	m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);
	
	// Random Color
	//sf::Uint8 red = static_cast<sf::Uint8>(std::rand() % 127) + 128;
	//sf::Uint8 green = 0;
	//sf::Uint8 blue = 0;
	//sf::Uint8 alpha = static_cast<sf::Uint8>(255);
	//m_particles[index].color = sf::Color(red, green, blue);

	// Reset the position of the corresponding vertex
	m_vertices[index].position = m_emitter;
}