#ifndef itemh_H
#define itemh_H

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
    void setX(int x);
    void setY(int y);
    void setName(string name);
    void setDescription(string description);
    void setType(string type);
    int getX();
    int getY();
    string getName();
    string getDescription();
    string getType();
    ~Item();
private:
    int x;
    int y;
    string name;
    string description;
    string type;
};

class Consumable: public Item
{
public:
    Consumable();
    void setHealthValue(int value);
    void setMagicValue(int value);
    void setMagicAffect(string magicAffect);
    int getHealthValue();
    int getMagicValue();
    string getMagicAffect();
    ~Consumable();
private:
    int healthValue;//adds health
    int magicValue;//adds to strength
    string magicAffect;
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
    void setWeaponType(string type);
    void setMinDamage(int damage);
    void setMaxDamage(int damage);
    void setTwoHanded(bool twoHanded);
    string getWeaponType();
    int getMinDamage();
    int getMaxDamage();
    bool getTwoHanded();
    ~Weapon();
private:
    string weaponType;
    int minDamage;
    int maxDamage;
    bool twoHanded;
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
    void setCategory(string type);
    int getStrength();
    string getCategory();
    ~Armor();
private:
    int strength;
    string category;
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

class Inventory
{
public:
    Inventory();
    void addToInventoryCArray(Consumable itemToAdd,WINDOW * messageWindow,char symbolArray[500][500]);//when player finds/picks up item
    void addToInventoryAArray(Armor itemToAdd,WINDOW * messageWindow,char symbolArray[500][500]);
    void addToInventoryWArray(Weapon itemToAdd,WINDOW * messageWindow,char symbolArray[500][500]);
    void setPositionInInventoryCArray(int arrayPosition,Consumable itemToAdd);//when player chooses to replace item in array
    void setPositionInInventoryAArray(int arrayPosition,Armor itemToAdd);
    void setPositionInInventoryWArray(int arrayPosition,Weapon itemToAdd);
    void removeFromCInventory(Consumable itemToRemove);//when player uses/replaces something in array
    void removeFromAInventory(Armor itemToRemove);
    void removeFromWInventory(Weapon itemToRemove);
    void setInventoryFull(bool inventoryFull);
    void printInventoryArrays(WINDOW * messageWindow);
    bool getInventoryFull();
    int getSizeOfInventory();
    ~Inventory();
private:
    Consumable fillerC;
    Armor fillerA;
    Weapon fillerW;
    int maxInventorySize;
    int sizeOfInventory;
    vector <Consumable> inventoryCArray;
    vector <Armor> inventoryAArray;
    vector <Weapon> inventoryWArray;
    bool inventoryFull;
};


//creates health potions and pushes onto healthPotionVector
void initializeHealthPotionVector(vector <Consumable> &healthPotionVector);

//creates magic potions and pushes onto magicPotionVector
void initializeMagicPotionVector(vector <Consumable> &magicPotionVector);

//creatss armor and pushes onto armorVector
void initializeArmorVector(vector <Armor> &leatherArmorVector, vector <Armor> &metalArmorVector, vector <Armor> &crystalArmorVector);

//calculates difference between weapon's minDamage and maxDamage and pushes it on that many times
//makes weapons with minDamage of 1 more likely than weapons with minDamage of 8
void pushBackWeaponOntoVector(Weapon itemToPush, vector <Weapon> &weaponVector);

//creates daggers and pushes onto daggerVector
void initializeDaggerVector(vector <Weapon> &daggerVector);

//creates clubs and pushes onto clubsVector
void initializeClubVector(vector <Weapon> &clubVector);

//creates heavy maces and pushes onto heavyMaceVector
void initializeHeavyMaceVector(vector <Weapon> &heavyMaceVector);

//creates spears and pushes onto spearVector
void initializeSpearVector(vector <Weapon> &spearVector);

//creates heavy crossbows and pushes onto heacyCrossBowsVector
void initializeHCrossBowVector(vector <Weapon> &heavyCrossBowVector);

//creates light crossbows and pushes onto lightCrossBowVector
void initializeLightCrossBowVector(vector <Weapon> &lightCrossBowVector);

//creates battleaxes and pushes onto battleaxeVector
void initializeBattleaxeVector(vector <Weapon> &battleaxeVector);

//creates longbows and pushes onto longBowsVector
void initializeLongBowVector(vector <Weapon> &longBowVector);

//chooses consumable to return
Consumable chooseConsumbale(int quantity, vector <Consumable> potionVector);

//chooses armor to return
Armor chooseArmor(vector <Armor> armorVector);

//chooses weapon to return
Weapon chooseWeapon(vector <Weapon> daggerVector, vector <Weapon> clubVector, vector <Weapon> heavyMaceVector,
                    vector <Weapon> spearVector, vector <Weapon> heavyCrossBowVector,
                    vector <Weapon> lightCrossBowVector, vector <Weapon> battleaxeVector,
                    vector <Weapon> longBowVector);

//Picks a random number of items to place in a room once the room is entered
int numOfItems(char symbolArray[500][500],vector <Location> &possiblePositions);


//Chooses the starting x and y coordinates for each item
void positions(char symbolArray[500][500],vector <Consumable> consumableVector,vector <Armor> &armorVector,
                vector <Weapon> weaponVector,vector <Location> &possiblePositions);


//chooses which item to place based on item rarity
void itemChoice(character player,vector <Consumable> &consumableVector,vector <Armor> &armorVector,
                vector <Weapon> &weaponVector,vector <Consumable> healthPotionVector, vector <Consumable> magicPotionVector,
                vector <Armor> leatherArmorVector, vector <Armor> metalArmorVector, vector <Armor> crystalArmorVector, vector <Weapon> daggerVector,
                vector <Weapon> clubVector, vector <Weapon> heavyMaceVector,vector <Weapon> spearVector, vector <Weapon> heavyCrossBowVector,
                vector <Weapon> lightCrossBowVector, vector <Weapon> battleaxeVector, vector <Weapon> longBowVector);

//checks if item is in current position
void checkForItem(character player,char symbolArray[500][500],vector <Consumable> consumableVector,
                  vector <Armor> &armorVector,vector <Weapon> weaponVector, WINDOW * workingWindow,
                  Inventory playerInventory);

//prints consumable stats
void printConsumableWindow(Consumable consumableToUse, WINDOW * messageWindow,
                           char symbolArray[500][500],character player,Inventory playerInventory);

//prints armor stats
void printArmorWindow(Armor armorToUse, WINDOW * messageWindow,
                      char symbolArray[500][500],character player,Inventory playerInventory);

//prints weapon stats
void printWeaponWindow(Weapon weaponToUse, WINDOW * messageWindow,
                       char symbolArray[500][500],character player,Inventory playerInventory);

//writes test to file
void writeTests(vector <Consumable> consumableVector,vector <Armor> armorVector,
                vector <Weapon> weaponVector, vector <Location> positionVector,vector <Consumable> healthPotionVector,
                vector <Consumable> magicPotionVector, vector <Armor> leatherArmorVector, vector <Armor> metalArmorVector,
                vector <Armor> crystalArmorVector, vector <Weapon> daggerVector,
                vector <Weapon> clubVector, vector <Weapon> heavyMaceVector,vector <Weapon> spearVector,
                vector <Weapon> heavyCrossBowVector, vector <Weapon> lightCrossBowVector,
                vector <Weapon> battleaxeVector, vector <Weapon> longBowVector);



#endif
