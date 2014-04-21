#include "utility.h"
#include "AlexRogue.h"
#include "combat.h"

//Test CPP file for all test in relation to Aaron Martin

int main()
{
    srand(time(NULL));
    //Create Player
    character player(0,0);
    player.setCharacterName("Tim the Viking");
    player.setLevel(1);
    player.setHealth(100);
    player.setMaxHealth(100);
    player.setBaseDamage(10);
    player.setMapRep('X');

    character enemy(0,1);
    enemy.setHealth(10);
    enemy.setMaxHealth(100);
    enemy.setBaseDamage(10);
    enemy.setArmor(30);


    character * attacker = &player;
    character * defender = &enemy;
    meleeAttack(attacker,defender);
    std::cout << enemy.getHealth();
    meleeAttack(attacker,defender);
    meleeAttack(attacker,defender);
    meleeAttack(attacker,defender);
    std::cout << enemy.getHealth();
    std::cout << checkDead(defender);

    delete attacker;
    delete defender;
    return 0;
}
