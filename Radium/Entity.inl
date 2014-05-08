template<typename T>
T* Entity::addComponent()
{
    // Check if component already exists
    for (Component* component : components)
    {
        T* pointer = dynamic_cast<T*>(component);
        if (pointer != nullptr)
        {
            std::cerr << typeid(T).name() << " is already a component in this Entity.\n";
            return pointer;
        }
    }

    // If component is not found, return a new component
    T* component = new T();
    components.push_back(component);
    return component;
}

template<typename T>
T* Entity::getComponent()
{
    // Search for matching component type
    for (Component* component : components)
    {
        // Try and cast the pointer to desired type
        T* pointer = dynamic_cast<T*>(component);
        if (pointer != nullptr)
        {
            // If the cast is successful then return the casted pointer
            return pointer;
        }
    }
    // Return nullptr if not found
    return nullptr;
}

// Performs a similar search as getComponent<T> but returns
// a vector containing all matching results
template<typename T>
std::vector<T*> Entity::getComponents()
{
    std::vector<T*> results;
    for (Component* component : components)
    {
        T* pointer = dynamic_cast<T*>(component);
        if (pointer != nullptr)
        {
            results.push_back(pointer);
        }
    }
    return results;
}