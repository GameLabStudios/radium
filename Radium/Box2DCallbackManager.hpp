#include <Box2D/Box2D.h>

class Box2DCallbackManager : public b2ContactListener
{
public:
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
};