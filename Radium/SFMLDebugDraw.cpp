#include <cmath>
#include "SFMLDebugDraw.hpp"
#include "Game.hpp"
#include <iostream>

SFMLDebugDraw::SFMLDebugDraw(sf::RenderWindow &window) : mWindow(&window)
{

}

sf::Color SFMLDebugDraw::glColorToSFML(const b2Color &color, sf::Uint8 alpha)
{
    return sf::Color(static_cast<sf::Uint8>(color.r * 255), static_cast<sf::Uint8>(color.g * 255), static_cast<sf::Uint8>(color.b), alpha);
}

sf::Vector2f SFMLDebugDraw::b2VecToSFVec(const b2Vec2 &vector, bool scaleToPixels)
{
    return sf::Vector2f(vector.x * (scaleToPixels ? Game::m2p : 1.0f), vector.y * (scaleToPixels ? Game::m2p : 1.0f));
}

void SFMLDebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color &color)
{
    sf::ConvexShape polygon(vertexCount);
    sf::Vector2f center;
    for (int i = 0; i < vertexCount; i++)
    {
        sf::Vector2f transformedVec = b2VecToSFVec(vertices[i]);
        polygon.setPoint(i, sf::Vector2f(std::floor(transformedVec.x), std::floor(transformedVec.y)));
    }
    polygon.setOutlineThickness(-1.0f);
    polygon.setFillColor(sf::Color::Transparent);
    polygon.setOutlineColor(glColorToSFML(color));
    mWindow->draw(polygon);
}

void SFMLDebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color &color)
{
    sf::ConvexShape polygon(vertexCount);
    sf::Vector2f center;
    for (int i = 0; i < vertexCount; i++)
    {
        sf::Vector2f transformedVec = b2VecToSFVec(vertices[i]);
        polygon.setPoint(i, sf::Vector2f(std::floor(transformedVec.x), std::floor(transformedVec.y)));
    }
    polygon.setOutlineThickness(-1.0f);
    polygon.setFillColor(glColorToSFML(color, 60));
    polygon.setOutlineColor(glColorToSFML(color));
    mWindow->draw(polygon);
}

void SFMLDebugDraw::DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color)
{
    sf::CircleShape circle(radius * Game::m2p);
    circle.setOrigin(radius * Game::m2p, radius * Game::m2p);
    circle.setPosition(b2VecToSFVec(center));
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(-1.0f);
    circle.setOutlineColor(glColorToSFML(color));
    mWindow->draw(circle);
}

void SFMLDebugDraw::DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color)
{
    sf::CircleShape circle(radius * Game::m2p);
    circle.setOrigin(radius * Game::m2p, radius * Game::m2p);
    circle.setPosition(b2VecToSFVec(center));
    circle.setFillColor(glColorToSFML(color, 60));
    circle.setOutlineThickness(-1.0f);
    circle.setOutlineColor(glColorToSFML(color));

    b2Vec2 endPoint = center + radius * axis;
    sf::Vertex line[2] = 
    {
        sf::Vertex(b2VecToSFVec(center), glColorToSFML(color)),
        sf::Vertex(b2VecToSFVec(endPoint), glColorToSFML(color))
    };

    mWindow->draw(circle);
    mWindow->draw(line, 2, sf::Lines);
}

void SFMLDebugDraw::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color)
{;
    sf::Vertex line[] =
    {
        sf::Vertex(b2VecToSFVec(p1), glColorToSFML(color)),
        sf::Vertex(b2VecToSFVec(p2), glColorToSFML(color))
    };

    mWindow->draw(line, 2, sf::Lines);
}

void SFMLDebugDraw::DrawTransform(const b2Transform &xf)
{
    float lineLength = 0.4f;

    b2Vec2 xAxis = xf.p + lineLength * xf.q.GetXAxis();
    sf::Vertex redLine[] =
    {
        sf::Vertex(b2VecToSFVec(xf.p), sf::Color::Red),
        sf::Vertex(b2VecToSFVec(xAxis), sf::Color::Red)
    };

    b2Vec2 yAxis = xf.p + lineLength * xf.q.GetYAxis();
    sf::Vertex greenLine[] =
    {
        sf::Vertex(b2VecToSFVec(xf.p), sf::Color::Green),
        sf::Vertex(b2VecToSFVec(yAxis), sf::Color::Green)
    };

    mWindow->draw(redLine, 2, sf::Lines);
    mWindow->draw(greenLine, 2, sf::Lines);
}