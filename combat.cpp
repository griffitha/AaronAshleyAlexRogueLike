#include "combat.h"

void meleeAttack(character * attacker,character * defender, std::vector<enemy> &enemyList)
{
    //Variable Declarations
    int defenderHealth = defender -> getHealth();
    int defenderArmor = defender -> getArmor();

    //Decimal is needed to carry out proper division.
    float DAMAGE_MITIGATION = 1.0 + (defenderArmor/70.0);
    int attackerAccuracy = attacker -> getAccuracy();
    int attackerDamage = attacker -> getBaseDamage();
    int newHealthValue;
    int actualDamage;
    int hitRoll = (rand() % 100) + 1;

    //If attacker passes the accuracy test
    if (attackerAccuracy > hitRoll)
    {
        //Deals Damage to Player after armor mitigation
        //Similiar equation can be found used in MMO-Shooter Warframe
        actualDamage = (attackerDamage/DAMAGE_MITIGATION);
        newHealthValue = defenderHealth - actualDamage;
        if (newHealthValue <= 0)
        {
            defender -> setHealth(0);
        }
        //Sets the Enemy health value accordingly.
        defender -> setHealth(newHealthValue);
    }

    //If this occurs, the attack missed
    else
    {
        return;
    }

}

void playerMelee(player &thePlayer, enemy &defender, std::vector<enemy> &enemyList)
{
    //Variable Declarations
    int defenderHealth = defender.getHealth();
    int defenderArmor = defender.getArmor();

    //Decimal is needed to carry out proper division.
    float DAMAGE_MITIGATION = 1.0 + (defenderArmor/70.0);
    int attackerAccuracy = thePlayer.getAccuracy();
    int attackerDamage = thePlayer.getBaseDamage();
    int newHealthValue;
    int actualDamage;
    int hitRoll = (rand() % 100) + 1;

    //If attacker passes the accuracy test
    if (attackerAccuracy > hitRoll)
    {
        //Deals Damage to Player after armor mitigation
        //Similiar equation can be found used in MMO-Shooter Warframe
        actualDamage = (attackerDamage/DAMAGE_MITIGATION);
        newHealthValue = defenderHealth - actualDamage;
        if (newHealthValue <= 0)
        {
            defender.setHealth(0);
        }
        //Sets the Enemy health value accordingly.
        else
        {
            defender.setHealth(newHealthValue);
        }
    }

    return;
    //If this occurs, the attack missed
}
bool checkDead(character * target)
{
    if ((target -> getHealth()) <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkEmpty(int x, int y, std::vector<character> gameObjects,std::vector<enemy> enemyList)
{
    //Function will go through and see if spot is occupied
    if (gameObjects.size() != 0)
    {
        for (unsigned int i = 0; i < gameObjects.size(); i++)
        {
            character currentObject = gameObjects.at(i);
            int designatedX = currentObject.getXCoordinate();
            int designatedY = currentObject.getYCoordinate();
            if (designatedX == x && designatedY == y)
            {
                return false;
            }
        }
    }

    if (enemyList.size() != 0)
    {
        for (unsigned int i = 0; i < enemyList.size(); i++)
        {
            enemy currentEnemy = enemyList.at(i);
            int designatedX = currentEnemy.getXCoordinate();
            int designatedY = currentEnemy.getYCoordinate();
            if (designatedX == x && designatedY == y)
            {
                return false;
            }
        }
    }
    return true;
}

int findTarget(int x, int y, std::vector<character> gameObjects)
{
    if (gameObjects.size() != 0)
    {
        for (unsigned int i = 0; i < gameObjects.size(); i++)
        {
            character currentObject = gameObjects.at(i);
            int designatedX = currentObject.getXCoordinate();
            int designatedY = currentObject.getYCoordinate();
            if (designatedX == x && designatedY == y)
            {
                return i;
            }
        }
    }
    else
        return -1;
}

int findTarget(int x, int y, std::vector<enemy> enemyList)
{
    if (enemyList.size() != 0)
    {
        for (unsigned int i = 0; i < enemyList.size(); i++)
        {
            enemy currentObject = enemyList.at(i);
            int designatedX = currentObject.getXCoordinate();
            int designatedY = currentObject.getYCoordinate();
            if (designatedX == x && designatedY == y)
            {
                return i;
            }
        }
    }
    else
        return -1;
}

void removeEnemy(std::vector<enemy> &enemyList, player &thePlayer)
{
    for (int i = 0; i < enemyList.size(); i++)
    {
        if (enemyList.at(i).getHealth() == 0)
        {
            enemy currentEnemy = enemyList.at(i);
            int awardedEXP = currentEnemy.getXpValue();
            enemyList = removeFromVector(i,enemyList);
            thePlayer.setExperience(thePlayer.getExperience() + awardedEXP);
        }
    }
}

template <typename T>
std::vector<T> removeFromVector(int position, std::vector<T> targetVector)
{
    std::vector<T> returnedVector;

    for (int i = targetVector.size()-1; i >= 0; i--)
    {
        if (i != position)
        {
            T item = targetVector.at(i);
            targetVector.pop_back();
            targetVector.push_back(item);
        }
        else
        {
            targetVector.pop_back();
        }
    }
    return returnedVector;
}
