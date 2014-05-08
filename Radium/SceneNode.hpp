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
                            ~SceneNode();
    void                    attachChild(Ptr child);
    Ptr                     detachChild(const SceneNode& node);
    void                    update(Time dt);
    void                    fixedUpdate(Time dt);
    void                    handleDestruction();
    Transform               getWorldTransform() const;	// If absolution position is needed over
    Vector2f                getWorldPosition() const;   //  relative posiiton use these two functions.

private:
    virtual void            draw(RenderTarget& target, RenderStates states) const;
    virtual void            drawCurrent(RenderTarget& target, RenderStates states) const;	// Must override in derived class. Replaces Drawable.draw().
    void                    updateChildren(Time dt);
    virtual void            updateCurrent(Time dt);										    // Must override in derived class. Optional update logic goes here.
    void                    fixedUpdateChildren(Time dt);
    virtual void            fixedUpdateCurrent(Time dt);
    void                    handleDestructionChildren();
    virtual void            handleDestructionCurrent();

private:
    std::vector<Ptr>        mChildren;
    SceneNode*              mParent;
};