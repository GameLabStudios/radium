#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;

struct Command;

enum Layer
{
    Background,
    Foreground,
    GUI,
    LayerCount
};

class SceneNode : public Transformable, public Drawable, private NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    SceneNode();
    void                    attachChild(Ptr child);
    Ptr                     detachChild(const SceneNode& node);
    void                    update(Time dt);
    Transform               getWorldTransform() const;	// If absolution position is needed over
    Vector2f                getWorldPosition() const;   //  relative posiiton use these two functions.

private:
    virtual void            draw(RenderTarget& target, RenderStates states) const;
    void                    updateChildren(Time dt);
    virtual void            drawCurrent(RenderTarget& target, RenderStates states) const;	// Must override in derived class. Replaces Drawable.draw().
    virtual void            updateCurrent(Time dt);										    // Must override in derived class. Optional update logic goes here.

private:
    std::vector<Ptr>        mChildren;
    SceneNode*              mParent;
};