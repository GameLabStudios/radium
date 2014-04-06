#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:
	ParticleSystem(unsigned int count) :
		m_particles(count),
		m_vertices(sf::Points, count),
		m_lifetime(sf::seconds(2)),
		m_emitter(0, 0)
	{

	}
	void SetEmitter(sf::Vector2f position);
	void Update(sf::Time elapsed);

private:
	struct Particle
	{
		sf::Vector2f velocity;
		sf::Time lifetime;
		sf::Color color;
	};

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void ResetParticles(std::size_t index);

	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;
};