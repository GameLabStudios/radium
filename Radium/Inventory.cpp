#include "Inventory.hpp"

Inventory::Inventory()
{
    /// default constructor
}

void Inventory::addItem(std::string name, float dmg, float sprd, float btSpd, float amrPen, float cd, bool burst, float burstAmt)
{
    gun addGun = gun();
    addGun.name = name;
    addGun.damage = dmg;
    addGun.spread = sprd;
    addGun.bulletSpeed = btSpd;
    addGun.armorPen = amrPen;
    addGun.cooldown = cd;
    addGun.burst = burst;
    addGun.burstAmount = burstAmt;

    mInv.push_back(addGun);
}

const std::vector<gun> Inventory::getInv() const
{
    return mInv;
}

const gun Inventory::getGun() const
{
    return mInv[mInv.size() - 1];
}