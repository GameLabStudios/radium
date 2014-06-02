#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Inventory
{
public:
                                            Inventory();
    void                                    addItem();
    const std::vector<std::string>          getInv() const;

private:
    std::vector<std::string>                inv;
};