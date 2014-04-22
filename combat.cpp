#include "combat.h"

void meleeAttack(character * attacker, character * defender, std::vector<character> gameObjects, std::vector<enemy> &enemyList)
{
    //Variable Declarations
    int defenderHealth = defender -> getHealth();
    int defenderArmor = defender -> getArmor();

    //Decimal is needed to carry out proper division.
    float const DAMAGE_MITIGATION = 1.0 + (defenderArmor/70.0);
    int attackerAccuracy = attacker -> getAccuracy();
    int attackerDamage = attacker -> getBaseDamage();
    int newHealthValue;
    int actualDamage;
    int hitRoll = (rand() % 100)+1;

    //If attacker passes the accuracy test
    if (attackerAccuracy > hitRoll)
    {
        //Deals Damage to Player after armor mitigation
        //Similiar equation can be found used in MMO-Shooter Warframe
        actualDamage = (attackerDamage/DAMAGE_MITIGATION);
        newHealthValue = defenderHealth - actualDamage;
        //Sets the Enemy health value accordingly.
        defender -> setHealth(newHealthValue);
        return;
    }

    //If this occurs, the attack missed
    else
    {
        return;
    }
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
}

//Goes through the vector and finds all the dead enemies and adds their experience accordingly
void removeDead(player thePlayer, std::vector<character*> gameObjects)
{
    for (unsigned int i = 0; i < gameObjects.size(); i++)
    {

    }

    //if (thePlayer.getExperience())
}
