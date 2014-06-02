#pragma once
#include "Component.hpp"

class TextComponent : public Component
{
public:
                TextComponent(Entity* entity);
                ~TextComponent();
void            setText(String txt);
void            setSize(Vector2f size);
virtual void    onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
virtual void    onUpdate(sf::Time dt);
virtual void    onFixedUpdate(sf::Time dt);
    
private:
    Text        text;
    Rect<float> textBox;
    bool        showText;
};