#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "GunProperties.hpp"

class Inventory
{

public:
                                    Inventory();
    void                            addItem(std::string, float, float, float, float, float, bool, float );
    const std::vector<gun>          getInv() const;
    const gun                       getGun() const;

private:
    std::vector<gun>                mInv;
};