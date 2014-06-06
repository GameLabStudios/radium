#pragma once

struct gun {
    std::string name;
    float damage;
    float spread;
    float bulletSpeed;
    float armorPen;
    float cooldown;
    bool burst;
    float burstAmount;
};