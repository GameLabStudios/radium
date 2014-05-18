#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class SFMLDebugDraw : public b2Draw
{
public:
    SFMLDebugDraw(sf::RenderWindow &window);

    // Convert Box2D's OpenGL style color definition[0-1] to SFML's color definition[0-255], with optional alpha byte[Default = opaque]
    static sf::Color glColorToSFML(const b2Color &color, sf::Uint8 alpha = 255);

    // Convert Box2D's vector to SFML vector [Default = scales the vector up by m2p amount]
    static sf::Vector2f b2VecToSFVec(const b2Vec2 &vector, bool scaleToPixels = true);

    // Draw a closed polygon procided in ccw order.
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color &color);

    // Draw a solid closed polygon provicded in ccw order.
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color &color);

    // Draw a circle.
    void DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color);

    // Draw a solid circle
    void DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color);

    // Draw a line segment.
    void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color);

    // Draw a transform. Choose your own length scale.
    void DrawTransform(const b2Transform &xf);

private:
    sf::RenderWindow* mWindow;
};