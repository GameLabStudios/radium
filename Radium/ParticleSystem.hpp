#pragma once
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
using namespace sf;

class ParticleSystem : public Drawable, public Transformable
{
public:
	ParticleSystem(unsigned int count) :
		m_particles(count),
		m_vertices(Points, count),
		m_lifetime(seconds(2)),
		m_emitter(0, 0)
	{

	}
	void SetEmitter(Vector2f position);
	void Update(Time elapsed);

private:
	struct Particle
	{
		Vector2f velocity;
		Time lifetime;
		Color color;
	};

	virtual void draw(RenderTarget &target, RenderStates states) const;
	void ResetParticles(std::size_t index);

	std::vector<Particle> m_particles;
	VertexArray m_vertices;
	Time m_lifetime;
	Vector2f m_emitter;
};
