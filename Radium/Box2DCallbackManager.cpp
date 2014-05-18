#include "Box2DCallbackManager.hpp"
#include "Entity.hpp"

void Box2DCallbackManager::BeginContact(b2Contact* contact)
{
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();
    Entity* entityA = static_cast<Entity*>(fixtureA->GetBody()->GetUserData());
    Entity* entityB = static_cast<Entity*>(fixtureB->GetBody()->GetUserData());
    entityA->receiveBeginContact(fixtureB, contact);
    entityB->receiveBeginContact(fixtureA, contact);
}

void Box2DCallbackManager::EndContact(b2Contact* contact)
{
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();
    Entity* entityA = static_cast<Entity*>(fixtureA->GetBody()->GetUserData());
    Entity* entityB = static_cast<Entity*>(fixtureB->GetBody()->GetUserData());
    entityA->receiveEndContact(fixtureA, contact);
    entityB->receiveEndContact(fixtureB, contact);
}