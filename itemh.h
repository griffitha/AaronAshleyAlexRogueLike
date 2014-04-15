#ifndef itemh_H
#define itemh_H

#include "AlexRogue.h"

#include "utility.h"

using namespace std;


class Location
{
public:
    Location(int x,int y);
    void setX(int newX);
    void setY(int newY);
    int getX();
    int getY();
    ~Location();
private:
    int x;
    int y;
};


class Item
{
public:
    Item();
    void setX(int height, int width, int xOfWindow);
    void setY(int height, int width, int yOfWindow);
    void setName(string name);
    void setDescription(string description);
    int getX();
    int getY();
    string getName();
    string getDescription();
    ~Item();
private:
    int x;
    int y;
    string name;
    string description;
    int randomNumber;//picks which item
    int howManyItemsPerRoom;//how many numbers per room; called when player gets into room
};

class Consumable: public Item
{
public:
    Consumable();
    void setHealthValue(int value);
    void setMagicValue(int value);
    int getHealthValue();
    int getMagicValue();
    ~Consumable();
private:
    int healthValue;//adds health
    int magicValue;//adds to strength
};

class consumablePack: public Consumable
{
public:
    consumablePack(Consumable potion1,Consumable potion2,Consumable potion3,Consumable potion4,Consumable potion5);
    void setPotion1(Consumable potion);
    void setPotion2(Consumable potion);
    void setPotion3(Consumable potion);
    void setPotion4(Consumable potion);
    void setPotion5(Consumable potion);
    Consumable getPotion1();
    Consumable getPotion2();
    Consumable getPotion3();
    Consumable getPotion4();
    Consumable getPotion5();
    ~consumablePack();
private:
    Consumable potion1;
    Consumable potion2;
    Consumable potion3;
    Consumable potion4;
    Consumable potion5;
};

class Weapon: public Item
{
public:
    Weapon();
    void setDamage(int damage);
    int getDamage();
    ~Weapon();
private:
    int damage;
};


class packOfArrows: public Weapon
{
public:
    packOfArrows();
    void setNumOfArrows(int maxValue);
    int getNumOfArrows();
    ~packOfArrows();
private:
    int numOfArrows;
};

class Armor: public Item
{
public:
    Armor();
    void setStrength(int strength);
    void setType(string type);
    int getStrength();
    string getType();
    ~Armor();
private:
    int strength;
    string type;
};

class Helmet: public Armor
{
public:
    Helmet(string type,int strength);
    ~Helmet();
private:
};

class Breastplate: public Armor
{
public:
    Breastplate(string type,int strength);
    ~Breastplate();
private:
};

class Gloves: public Armor
{
public:
    Gloves(string type,int strength);
    ~Gloves();
private:
};

class Shoes: public Armor
{
public:
    Shoes(string type,int strength);
    ~Shoes();
private:
};

class Shield: public Armor
{
public:
    Shield(string type,int strength);
    ~Shield();
private:
};



//creates health potions and pushes onto healthPotionVector
void initializeHealthPotionVector(vector <Consumable> &healthPotionVector);

//creates magic potions and pushes onto magicPotionVector
void initializeMagicPotionVector(vector <Consumable> &magicPotionVector);

//creatss armor and pushes onto armorVector
void initializeArmorVector(vector <Armor> &armorVector);

//creates weapons and pushes onto weaponsVector
void initializeWeaponsVector(vector <Weapon> &weaponsVector);

//chooses consumable to
Consumable chooseConsumbale(int quantity, vector <Consumable> potionVector);


//Picks a random number of items to place in a room once the room is entered
int numOfItems(char symbolArray[500][500],vector <Location> &possiblePositions);


//Chooses the starting x and y coordinates for each item
void positions(char symbolArray[500][500], vector <Item> itemVector,vector <Location> &possiblePositions);


//chooses which item to place based on item rarity
void itemChoice(character player,vector <Item> &itemVector,vector <Consumable> healthPotionVector, vector <Consumable> magicPotionVector);

#endif
