#include "combat.h"

void meleeAttack(character * attacker, character * defender)
{
    //Variable Declarations
    int defenderHealth = defender -> getHealth();
    int defenderArmor = defender -> getArmor();
    //Decimal is needed to carry out proper division.
    float const DAMAGE_MITIGATION = 1.0+(defenderArmor/70.0);
    int attackerAccuracy = attacker -> getAccuracy();
    int attackerDamage = attacker -> getBaseDamage();
    int newHealthValue;
    int actualDamage;
    int hitRoll = (rand() % 100)+1;

    //IF attacker passes the accuracy test
    if (attackerAccuracy > hitRoll)
    {
        //std::cout << defenderArmor;
        //Deals Damage to Player after armor mitigation
        //Similiar equation can be found used in MMO-Shooter Warframe
        actualDamage = (attackerDamage/DAMAGE_MITIGATION);
        newHealthValue = defenderHealth - actualDamage;
        //Sets the Enemy health value accordingly.
        defender -> setHealth(newHealthValue);
    }
    //If this occurs, the attack missed
    else
    {
        return;
    }


    return;
}
