#include "SceneNode.hpp"
#include <cassert>
#include <iostream>

SceneNode::SceneNode()
{
    mParent = nullptr;
}

void SceneNode::attachChild(Ptr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
    // Fancy lamba expression that checks each element in mChildren is equal to target node.
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) -> bool { return p.get() == &node; });
    // Santiy check for above lambda.
    assert(found != mChildren.end());

    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void SceneNode::draw(RenderTarget& target, RenderStates states) const
{
    states.transform *= getTransform();
    drawCurrent(target, states);
    for (const Ptr& child : mChildren)
    {
        child->draw(target, states);
    }
}

// Must be override in derived class. Should be remain empty here.
void SceneNode::drawCurrent(RenderTarget& target, RenderStates states) const
{
    // This function intentionally left blank.
}

void SceneNode::update(Time dt)
{
    updateCurrent(dt);
    updateChildren(dt);
}

// Must be override in derived class. Should be remain empty here.
void SceneNode::updateCurrent(Time dt)
{
    // This function intentionally left blank.
}

void SceneNode::updateChildren(Time dt)
{
    for (Ptr& child : mChildren)
    {
        child->update(dt);
    }
}

void SceneNode::fixedUpdate(Time dt)
{
    fixedUpdateCurrent(dt);
    fixedUpdateChildren(dt);
}

void SceneNode::fixedUpdateCurrent(Time dT)
{
    // This function intentionally left blank.
}

void SceneNode::fixedUpdateChildren(Time dt)
{
    for (Ptr& child : mChildren)
    {
        child->fixedUpdate(dt);
    }
}

void SceneNode::handleDestruction()
{
    handleDestructionChildren();
    handleDestructionCurrent();
}

void SceneNode::handleDestructionChildren()
{
    for (unsigned i = 0; i < mChildren.size(); i++)
    {
        unsigned currentSize = mChildren.size();
        mChildren[i]->handleDestruction();
        if (mChildren.size() != currentSize)
        {
            i--;
        }
    }
}

void SceneNode::handleDestructionCurrent()
{

}

Transform SceneNode::getWorldTransform() const
{
    Transform transform = Transform::Identity;
    for (const SceneNode* node = this; node != nullptr; node = node->mParent)
    {
        transform = node->getTransform() * transform;
    }
    return transform;
}

Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform() * Vector2f();
}

SceneNode* SceneNode::getParent()
{
    return mParent;
}

void SceneNode::removeFromScene()
{
    // Delete all children
    for (Ptr& child : mChildren)
    {
        child->removeFromScene();
    }

    // Detach self from parent
    mParent->detachChild(*this);
}