#include "utility.h"

using namespace std;

//constructor--Location
Location::Location(int x, int y)
{
    this -> x = x;
    this -> y = y;
}

//setX
void Location::setX(int newX)
{
    x = newX;
}

//setY
void Location::setY(int newY)
{
    y = newY;
}

//getX
int Location::getX()
{
    return x;
}

//getY
int Location::getY()
{
    return y;
}

//decontructor
Location::~Location()
{
}

//constructor-Item
Item::Item()
{
}

//set X
void Item::setX(int x)
{
    this -> x = x;
    return;
}


//setY
void Item::setY(int y)
{
    this -> y = y;

    return;
}

//set name
void Item::setName(string name)
{
    this -> name = name;
}

//set description
void Item::setDescription(string description)
{
    this -> description = description;
}

//set type
void Item::setType(string type)
{
    this -> type = type;
}

//get X
int Item::getX()
{
    return x;
}

//get Y
int Item::getY()
{
    return y;
}

//get name
string Item::getName()
{
    return name;
}

//get description
string Item::getDescription()
{
    return description;
}

//get type
string Item::getType()
{
    return type;
}

//deconstructor
Item::~Item()
{
}

//constructor--Consumable
Consumable::Consumable()
{
    healthValue = 0;
    magicValue = 0;
}

//setHealthValue
void Consumable::setHealthValue(int value)
{
    healthValue = value;
}

//set magicValue
void Consumable::setMagicValue(int value)
{
    magicValue = value;
}

//set magicAffects
void Consumable::setMagicAffect(string magicAffect)
{
    this -> magicAffect = magicAffect;
}

//get healthValue
int Consumable::getHealthValue()
{
    return healthValue;
}

//get magicValue
int Consumable::getMagicValue()
{
    return magicValue;
}

//get mmagicValue
string Consumable::getMagicAffect()
{
    return magicAffect;
}

//deconstructor--Consumable
Consumable::~Consumable()
{
}

/*
//constructor--consumable pack
consumablePack::consumablePack(Consumable potion1,Consumable potion2,Consumable potion3, Consumable potion4, Consumable potion5)
{
    this -> potion1 = potion1;
    this -> potion2 = potion2;
    this -> potion3 = potion3;
    this -> potion4 = potion4;
    this -> potion5 = potion5;
}

//setPotion1
void consumablePack::setPotion1(Consumable potion)
{
    potion1 = potion;
}
//setPotion2
void consumablePack::setPotion2(Consumable potion)
{
    potion2 = potion;
}

//setPotion3
void consumablePack::setPotion3(Consumable potion)
{
    potion3 = potion;
}

//setPotion4
void consumablePack::setPotion4(Consumable potion)
{
    potion4 = potion;
}

//setPotion5
void consumablePack::setPotion5(Consumable potion)
{
    potion5 = potion;
}

//getPotion1
Consumable consumablePack::getPotion1()
{
    return potion1;
}

//getPotion2
Consumable consumablePack::getPotion2()
{
    return potion2;
}

//getPotion3
Consumable consumablePack::getPotion3()
{
    return potion3;
}

//getPotion4
Consumable consumablePack::getPotion4()
{
    return potion4;
}

//getPotion5
Consumable consumablePack::getPotion5()
{
    return potion5;
}

//deconstructor--consumable pack
consumablePack::~consumablePack()
{
}
*/

//constructor--Weapon
Weapon::Weapon()
{
    minDamage = 0;
}

//set weaponType
void Weapon::setWeaponType(string type)
{
    this -> weaponType = type;
}

//set minDamage
void Weapon::setMinDamage(int damage)
{
    this -> minDamage = damage;
}

//set maxDamage
void Weapon::setMaxDamage(int damage)
{
    this -> maxDamage = damage;
}

//set twoHanded
void Weapon::setTwoHanded(bool twoHanded)
{
    this -> twoHanded = twoHanded;
}

//get weaponType
string Weapon::getWeaponType()
{
    return weaponType;
}

//get minDamage
int Weapon::getMinDamage()
{
    return minDamage;
}

//get maxDamage
int Weapon::getMaxDamage()
{
    return maxDamage;
}

//getTwoHanded
bool Weapon::getTwoHanded()
{
    return twoHanded;
}

//deconstructor--Weapon
Weapon::~Weapon()
{
    weaponType = "";
    minDamage = 0;
    maxDamage = 0;
}

/*
//constructon--packOfArrows
packOfArrows::packOfArrows()
{
    numOfArrows = 0;
    setMinDamage(0);
    setMaxDamage(0);
}

//setNumOfArrows
void packOfArrows::setNumOfArrows(int maxValue)
{
 //   srand(time(NULL));

    numOfArrows = rand() % maxValue + 1;
}

//getNumOfArrows
int packOfArrows::getNumOfArrows()
{
    return numOfArrows;
}

//deconstructor--packOfArrows
packOfArrows::~packOfArrows()
{
    numOfArrows = 0;
}*/

//constructor--Armor
Armor::Armor()
{
    strength = 0;
    setType("Armor");
}

//setStrength
void Armor::setStrength(int strength)
{
    this ->strength = strength;
}

//setType
void Armor::setCategory(string type)
{
    this -> category = type;
}

//get Strength
int Armor::getStrength()
{
    return strength;
}

//getType
string Armor::getCategory()
{
    return category;
}

//deconstructor--Armor
Armor::~Armor()
{
    strength = 0;
    setType("");
}


//constructor--Helmet
Helmet::Helmet(string type,int strength)
{
    setType(type);
    setStrength(strength);
}
//deconstructor--helmet
Helmet::~Helmet()
{
    setStrength(0);
    setType(" ");
}

//constructor--Breastplate
Breastplate::Breastplate(string type, int strength)
{
    setType(type);
    setStrength(strength);
}

//deconstructor--breastplate
Breastplate::~Breastplate()
{
    setStrength(0);
    setType(" ");
}

//constructor--Gloves
Gloves::Gloves(string type,int strength)
{
    setType(type);
    setStrength(strength);
}

//deconstructor--gloves
Gloves::~Gloves()
{
    setStrength(0);
    setType(" ");
}

//constructor--Shoes
Shoes::Shoes(string type,int strength)
{
    setType(type);
    setStrength(strength);
}

//deconstructor-shoes
Shoes::~Shoes()
{
    setStrength(0);
    setType(" ");
}

//constructor--Shield
Shield::Shield(string type,int strength)
{
    setType(type);
    setStrength(strength);
}

//deconstructor--shield
Shield::~Shield()
{
    setStrength(0);
    setType(" ");
}

//constructor--inventory
Inventory::Inventory()
{
    inventoryFull = false;
    maxInventorySize = 20;
    lineCounter = 1;
    counter = 1;
}

//when player finds/picks up item
void Inventory::addToInventoryCArray(Consumable itemToAdd,WINDOW * messageWindow,char symbolArray[500][500])
{
    inventoryCArray.push_back(itemToAdd);
    sizeOfInventory++;
    printInventoryArrays(messageWindow);

    if(sizeOfInventory == maxInventorySize)
    {
        setInventoryFull(true);
    }

    return;

}

//when player finds/picks up item
void Inventory::addToInventoryAArray(Armor itemToAdd,WINDOW * messageWindow,char symbolArray[500][500])
{

    inventoryAArray.push_back(itemToAdd);
    sizeOfInventory++;
    printInventoryArrays(messageWindow);

    if(sizeOfInventory == maxInventorySize)
    {
        setInventoryFull(true);
    }

    return;
}

//when player finds/picks up item
void Inventory::addToInventoryWArray(Weapon itemToAdd,WINDOW * messageWindow,char symbolArray[500][500])
{

    inventoryWArray.push_back(itemToAdd);
    sizeOfInventory++;
    printInventoryArrays(messageWindow);

    if(sizeOfInventory == maxInventorySize)
    {
        setInventoryFull(true);
    }

    return;
}

//when player chooses to replace item in array
void Inventory::setPositionInInventoryCArray(int arrayPosition,Consumable itemToAdd)
{
    inventoryCArray[arrayPosition] = itemToAdd;

    return;
}

//when player chooses to replace item in array
void Inventory::setPositionInInventoryAArray(int arrayPosition,Armor itemToAdd)
{
    inventoryAArray[arrayPosition] = itemToAdd;

    return;
}

//when player chooses to replace item in array
void Inventory::setPositionInInventoryWArray(int arrayPosition,Weapon itemToAdd)
{
    inventoryWArray[arrayPosition] = itemToAdd;

    return;
}

//when player uses/replaces something in array
void Inventory::removeFromCInventory(Consumable itemToRemove)
{
    for(int i = 0; i < signed(inventoryCArray.size());i++)
    {
        if(inventoryCArray[i].getName() == itemToRemove.getName())
        {
            inventoryCArray[i] = fillerC;
            sizeOfInventory--;
        }
    }

    return;
}

//when player uses/replaces something in array
void Inventory::removeFromAInventory(Armor itemToRemove)
{
    for(int i = 0; i < signed(inventoryAArray.size());i++)
    {
        if(inventoryAArray[i].getName() == itemToRemove.getName())
        {
            inventoryAArray[i] = fillerA;
            sizeOfInventory--;
        }
    }

    return;
}

//when player uses/replaces something in array
void Inventory::removeFromWInventory(Weapon itemToRemove)
{
    for(int i = 0; i < signed(inventoryWArray.size());i++)
    {
        if(inventoryWArray[i].getName() == itemToRemove.getName())
        {
            inventoryWArray[i] = fillerW;
            sizeOfInventory--;
        }
    }

    return;
}

//setInventoryFull
void Inventory::setInventoryFull(bool inventoryFull)
{
    this -> inventoryFull = inventoryFull;
}

//get consumable
Consumable Inventory::getConsumable(int position)
{
    return inventoryCArray[position];
}

//get armor
Armor Inventory::getArmorPiece(int position)
{
    return inventoryAArray[position];
}

//get weapon
Weapon Inventory::getWeapon(int position)
{
    return inventoryWArray[position];
}

//show consumables
void Inventory::printConsumables(WINDOW * messageWindow)
{
    string currentString = "";

    for(int i = 0;i < signed(inventoryCArray.size());i++)
    {
        if(counter == 21)
                break;
        currentString = ". " + inventoryCArray[i].getName();
        char * characterPtr = &currentString.at(0);
        if(counter < 11)
        {
            mvwprintw(messageWindow,lineCounter,1,"%d",counter);
            mvwprintw(messageWindow,lineCounter,2,characterPtr);
            counter++;
            lineCounter++;
        }
        else if(counter == 11)
        {
            lineCounter = 0;
            mvwprintw(messageWindow,lineCounter,25,"%d",counter);
            mvwprintw(messageWindow,lineCounter,28,characterPtr);
            counter++;
            lineCounter++;
        }
        else
        {
            mvwprintw(messageWindow,lineCounter,25,"%d",counter);
            mvwprintw(messageWindow,lineCounter,28,characterPtr);
            counter++;
            lineCounter++;
        }
    }
}

//print armor
void Inventory::printArmor(WINDOW * messageWindow)
{
    string currentString = "";

     for(int x = 0; x < signed(inventoryAArray.size());x++)
    {
        if(counter == 21)
            break;
        currentString = ". " + inventoryAArray[x].getName();
        char * characterPtr = &currentString.at(0);
        mvwprintw(messageWindow,counter,1,"%d",counter);
        mvwprintw(messageWindow,counter,2,characterPtr);
        if(counter < 11)
        {
            mvwprintw(messageWindow,lineCounter,1,"%d",counter);
            mvwprintw(messageWindow,lineCounter,2,characterPtr);
            counter++;
            lineCounter++;
        }
        else if(counter == 11)
        {
            lineCounter = 0;
            mvwprintw(messageWindow,lineCounter,22,"%d",counter);
            mvwprintw(messageWindow,lineCounter,25,characterPtr);
            counter++;
            lineCounter++;
        }
        else
        {
            mvwprintw(messageWindow,lineCounter,22,"%d",counter);
            mvwprintw(messageWindow,lineCounter,25,characterPtr);
            counter++;
            lineCounter++;
        }
    }
}

//show weapons
void Inventory::printWeapons(WINDOW * messageWindow)
{
    string currentString = "";

    for(int y = 0; y < signed(inventoryWArray.size());y++)
    {
        if(counter == 21)
            break;
        currentString = ". " + inventoryWArray[y].getName();
        char * characterPtr = &currentString.at(0);
        mvwprintw(messageWindow,counter,1,"%d",counter);
        mvwprintw(messageWindow,counter,2,characterPtr);
        if(counter < 11)
        {
            mvwprintw(messageWindow,lineCounter,1,"%d",counter);
            mvwprintw(messageWindow,lineCounter,2,characterPtr);
            counter++;
            lineCounter++;
        }
        else if(counter == 11)
        {
            lineCounter = 0;
            mvwprintw(messageWindow,lineCounter,25,"%d",counter);
            mvwprintw(messageWindow,lineCounter,28,characterPtr);
            counter++;
            lineCounter++;
        }
        else
        {
            mvwprintw(messageWindow,lineCounter,25,"%d",counter);
            mvwprintw(messageWindow,lineCounter,28,characterPtr);
            counter++;
            lineCounter++;
        }
    }
}


//show inventory
void Inventory::printInventoryArrays(WINDOW * messageWindow)
{
    string currentString = "Inventory: ";
    char * charPtr = &currentString.at(0);
    mvwprintw(messageWindow,0,1,charPtr);

    counter = 1;
    lineCounter = 1;

    printConsumables(messageWindow);
    printArmor(messageWindow);
    printWeapons(messageWindow);


    return;
}

//returns true if inventory is full
bool Inventory::getInventoryFull()
{
    return inventoryFull;
}

//returns current size of inventory
int Inventory::getSizeOfInventory()
{
    return sizeOfInventory;
}

//deconstructor-inventory
Inventory::~Inventory()
{

}



//creates health potions and pushes onto healthPotionVector
void initializeHealthPotionVector(vector <Consumable> &healthPotionVector)
{
    Consumable firstHPotion;
    firstHPotion.setName("Increase health by 5");
    firstHPotion.setMagicValue(0);
    firstHPotion.setHealthValue(5);

    Consumable secondHPotion;
    secondHPotion.setName("Increase health by 10");
    secondHPotion.setMagicValue(0);
    secondHPotion.setHealthValue(10);

    Consumable thirdHPotion;
    thirdHPotion.setName("Increase health by 15");
    thirdHPotion.setMagicValue(0);
    thirdHPotion.setHealthValue(15);

    Consumable fourthHPotion;
    fourthHPotion.setName("Increase health by 20");
    fourthHPotion.setMagicValue(0);
    fourthHPotion.setHealthValue(20);

    for(int i = 0; i < 30; i++)
    {
        healthPotionVector.push_back(firstHPotion);
    }

    healthPotionVector.push_back(secondHPotion);
    healthPotionVector.push_back(thirdHPotion);
    healthPotionVector.push_back(fourthHPotion);

    return;
}

//creates magic potions and pushes onto magicPotionVector
void initializeMagicPotionVector(vector <Consumable> &magicPotionVector)
{
    Consumable firstMPotion;
    firstMPotion.setName("Strengthen Armor by 5");
    firstMPotion.setMagicValue(5);
    firstMPotion.setHealthValue(0);
    firstMPotion.setMagicAffect("Strengthen Armor");

    Consumable secondMPotion;
    secondMPotion.setName("Strengthen Armor by 10");
    secondMPotion.setMagicValue(10);
    secondMPotion.setHealthValue(0);
    secondMPotion.setMagicAffect("Strengthen Armor");

    Consumable thirdMPotion;
    thirdMPotion.setName("Strengthen Armor by 15");
    thirdMPotion.setMagicValue(15);
    thirdMPotion.setHealthValue(0);
    thirdMPotion.setMagicAffect("Strengthen Armor");

    Consumable fourthMPotion;
    fourthMPotion.setName("Strengthen Armor by 20");
    fourthMPotion.setMagicValue(20);
    fourthMPotion.setHealthValue(0);
    fourthMPotion.setMagicAffect("Strengthen Armor");

    Consumable fifthMPotion;
    fifthMPotion.setName("Strengthen Weapon by 5");
    fifthMPotion.setMagicValue(5);
    fifthMPotion.setHealthValue(0);
    fifthMPotion.setMagicAffect("Strengthen Weapon");

    Consumable sixthMPotion;
    sixthMPotion.setName("Strengthen Weapon by 10");
    sixthMPotion.setMagicValue(10);
    sixthMPotion.setHealthValue(0);
    sixthMPotion.setMagicAffect("Strengthen Weapon");

    Consumable seventhMPotion;
    seventhMPotion.setName("Strengthen Weapon by 15");
    seventhMPotion.setMagicValue(15);
    seventhMPotion.setHealthValue(0);
    seventhMPotion.setMagicAffect("Strengthen Weapon");

    Consumable eighthMPotion;
    eighthMPotion.setName("Strengthen Weapon by 20");
    eighthMPotion.setMagicValue(20);
    eighthMPotion.setHealthValue(0);
    eighthMPotion.setMagicAffect("Strengthen Weapon");

    for(int i = 0; i < 30; i++)
    {
        magicPotionVector.push_back(firstMPotion);
        magicPotionVector.push_back(fifthMPotion);
    }


    magicPotionVector.push_back(secondMPotion);
    magicPotionVector.push_back(thirdMPotion);
    magicPotionVector.push_back(fourthMPotion);
    magicPotionVector.push_back(sixthMPotion);
    magicPotionVector.push_back(seventhMPotion);
    magicPotionVector.push_back(eighthMPotion);

    return;
}


//creatss armor and pushes onto armorVector
void initializeArmorVector(vector <Armor> &leatherArmorVector, vector <Armor> &metalArmorVector, vector <Armor> &crystalArmorVector)
{
    Helmet leatherHelmet("leather", 2);
    leatherHelmet.setName("Leather Helmet");

    Breastplate leatherBreastplate("leather", 2);
    leatherBreastplate.setName("Leather Breastplate");

    Gloves leatherGloves("leather",2);
    leatherGloves.setName("Leather Gloves");

    Shoes leatherShoes("leather",2);
    leatherShoes.setName("Leather Shoes");

    Shield leatherShield("leather",2);
    leatherShield.setName("Leather Shield");

    Helmet metalHelmet("metal", 3);
    metalHelmet.setName("Metal Helmet");

    Breastplate metalBreastplate("metal",3);
    metalBreastplate.setName("Metal Breastplate");

    Gloves metalGloves("metal",3);
    metalGloves.setName("Metal Gloves");

    Shoes metalShoes("metal", 3);
    metalShoes.setName("Metal Shoes");

    Shield metalShield("metal", 3);
    metalShield.setName("Metal Shield");

    Helmet crystalHelmet("crystal",5);
    crystalHelmet.setName("Crystal Helmet");

    Breastplate crystalBreastplate("crystal",5);
    crystalBreastplate.setName("Crystal Breastplate");

    Gloves crystalGloves("crystal",5);
    crystalGloves.setName("Crystal Gloves");

    Shoes crystalShoes("crystal",5);
    crystalShoes.setName("Crystal Shoes");

    Shield crystalShield("crystal",5);
    crystalShield.setName("Crystal Shield");

    leatherArmorVector.push_back(leatherHelmet);
    leatherArmorVector.push_back(leatherBreastplate);
    leatherArmorVector.push_back(leatherGloves);
    leatherArmorVector.push_back(leatherShoes);
    leatherArmorVector.push_back(leatherShield);

    metalArmorVector.push_back(metalHelmet);
    metalArmorVector.push_back(metalBreastplate);
    metalArmorVector.push_back(metalGloves);
    metalArmorVector.push_back(metalShoes);
    metalArmorVector.push_back(metalShield);

    crystalArmorVector.push_back(crystalHelmet);
    crystalArmorVector.push_back(crystalBreastplate);
    crystalArmorVector.push_back(crystalGloves);
    crystalArmorVector.push_back(crystalShoes);
    crystalArmorVector.push_back(crystalShield);

    return;
}

//calculates difference between weapon's minDamage and maxDamage and pushes it on that many times
//makes weapons with minDamage of 1 more likely than weapons with minDamage of 8
void pushBackWeaponOntoVector(Weapon itemToPush, vector <Weapon> &weaponVector)
{
    int numOfTimesToPush = (itemToPush.getMaxDamage() - itemToPush.getMinDamage()) + 1;

    for(int i = 0; i < numOfTimesToPush; i++)
    {
        weaponVector.push_back(itemToPush);
    }

    return;
}


//creates weapons and pushes onto weaponsVector
void initializeDaggerVector(vector <Weapon> &daggerVector)
{
    Weapon dagger1a;
    dagger1a.setName("Common Dagger");
    dagger1a.setDescription("");
    dagger1a.setType("Weapon");
    dagger1a.setWeaponType("Small Dagger");
    dagger1a.setMinDamage(1);
    dagger1a.setMaxDamage(3);
    dagger1a.setTwoHanded(false);

    Weapon dagger1b;
    dagger1b.setName("Lucky Dagger");
    dagger1b.setDescription("");
    dagger1b.setType("Weapon");
    dagger1b.setWeaponType("Small Dagger");
    dagger1b.setMinDamage(2);
    dagger1b.setMaxDamage(3);
    dagger1b.setTwoHanded(false);

    Weapon dagger1c;
    dagger1c.setName("Magic Dagger");
    dagger1c.setDescription("");
    dagger1c.setType("Weapon");
    dagger1c.setWeaponType("Small Dagger");
    dagger1c.setMinDamage(3);
    dagger1c.setMaxDamage(3);
    dagger1c.setTwoHanded(false);

    Weapon dagger2a;
    dagger2a.setName("Common Dagger");
    dagger2a.setDescription("");
    dagger2a.setType("Weapon");
    dagger2a.setWeaponType("Dagger");
    dagger2a.setMinDamage(1);
    dagger2a.setMaxDamage(4);
    dagger2a.setTwoHanded(false);

    Weapon dagger2b;
    dagger2b.setName("Reliable Dagger");
    dagger2b.setDescription("");
    dagger2b.setType("Weapon");
    dagger2b.setWeaponType("Dagger");
    dagger2b.setMinDamage(2);
    dagger2b.setMaxDamage(4);
    dagger2b.setTwoHanded(false);

    Weapon dagger2c;
    dagger2c.setName("Lucky Dagger");
    dagger2c.setDescription("");
    dagger2c.setType("Weapon");
    dagger2c.setWeaponType("Dagger");
    dagger2c.setMinDamage(3);
    dagger2c.setMaxDamage(4);
    dagger2c.setTwoHanded(false);

    Weapon dagger2d;
    dagger2d.setName("Magic Dagger");
    dagger2d.setDescription("");
    dagger2d.setType("Weapon");
    dagger2d.setWeaponType("Dagger");
    dagger2d.setMinDamage(4);
    dagger2d.setMaxDamage(4);
    dagger2d.setTwoHanded(false);

    pushBackWeaponOntoVector(dagger1a,daggerVector);
    pushBackWeaponOntoVector(dagger1b,daggerVector);
    pushBackWeaponOntoVector(dagger1c,daggerVector);
    pushBackWeaponOntoVector(dagger2a,daggerVector);
    pushBackWeaponOntoVector(dagger2b,daggerVector);
    pushBackWeaponOntoVector(dagger2c,daggerVector);
    pushBackWeaponOntoVector(dagger2d,daggerVector);

    return;
}

//creates clubs and pushes onto clubsVector
void initializeClubVector(vector <Weapon> &clubVector)
{
    Weapon club1a;
    club1a.setName("Common Club");
    club1a.setDescription("");
    club1a.setType("Weapon");
    club1a.setWeaponType("Small Club");
    club1a.setMinDamage(1);
    club1a.setMaxDamage(6);
    club1a.setTwoHanded(false);

    Weapon club1b;
    club1b.setName("Club");
    club1b.setDescription("");
    club1b.setType("Weapon");
    club1b.setWeaponType("Club");
    club1b.setMinDamage(2);
    club1b.setMaxDamage(6);
    club1b.setTwoHanded(false);

    Weapon club1c;
    club1c.setName("Reliable Club");
    club1c.setDescription("");
    club1c.setType("Weapon");
    club1c.setWeaponType("Club");
    club1c.setMinDamage(3);
    club1c.setMaxDamage(6);
    club1c.setTwoHanded(false);

    Weapon club1d;
    club1d.setName("Lucky Club");
    club1d.setDescription("");
    club1d.setType("Weapon");
    club1d.setWeaponType("Club");
    club1d.setMinDamage(4);
    club1d.setMaxDamage(6);
    club1d.setTwoHanded(false);

    Weapon club1e;
    club1e.setName("Lucky Club");
    club1e.setDescription("");
    club1e.setType("Weapon");
    club1e.setWeaponType("Club");
    club1e.setMinDamage(5);
    club1e.setMaxDamage(6);
    club1e.setTwoHanded(false);

    Weapon club1f;
    club1f.setName("Magic Club");
    club1f.setDescription("");
    club1f.setType("Weapon");
    club1f.setWeaponType("Club");
    club1f.setMinDamage(6);
    club1f.setMaxDamage(6);
    club1f.setTwoHanded(false);

    Weapon club2a;
    club2a.setName("Common Club");
    club2a.setDescription("");
    club2a.setType("Weapon");
    club2a.setWeaponType("Small Club");
    club2a.setMinDamage(1);
    club2a.setMaxDamage(4);
    club2a.setTwoHanded(false);

    Weapon club2b;
    club2b.setName("Reliable Club");
    club2b.setDescription("");
    club2b.setType("Weapon");
    club2b.setWeaponType("Small Club");
    club2b.setMinDamage(2);
    club2b.setMaxDamage(4);
    club2b.setTwoHanded(false);

    Weapon club2c;
    club2c.setName("Lucky Club");
    club2c.setDescription("");
    club2c.setType("Weapon");
    club2c.setWeaponType("Small Club");
    club2c.setMinDamage(3);
    club2c.setMaxDamage(4);
    club2c.setTwoHanded(false);

    Weapon club2d;
    club2d.setName("Magic Club");
    club2d.setDescription("");
    club2d.setType("Weapon");
    club2d.setWeaponType("Small Club");
    club2d.setMinDamage(4);
    club2d.setMaxDamage(4);
    club2d.setTwoHanded(false);

    pushBackWeaponOntoVector(club1a,clubVector);
    pushBackWeaponOntoVector(club1b,clubVector);
    pushBackWeaponOntoVector(club1c,clubVector);
    pushBackWeaponOntoVector(club1d,clubVector);
    pushBackWeaponOntoVector(club1e,clubVector);
    pushBackWeaponOntoVector(club1f,clubVector);
    pushBackWeaponOntoVector(club2a,clubVector);
    pushBackWeaponOntoVector(club2b,clubVector);
    pushBackWeaponOntoVector(club2c,clubVector);
    pushBackWeaponOntoVector(club2d,clubVector);

    return;
}

//creates heavy maces and pushes onto heavyMaceVector
void initializeHeavyMaceVector(vector <Weapon> &heavyMaceVector)
{
    Weapon HMace1a;
    HMace1a.setName("Common Heavy Mace");
    HMace1a.setDescription("");
    HMace1a.setType("Weapon");
    HMace1a.setWeaponType("Small Heavy Mace");
    HMace1a.setMinDamage(1);
    HMace1a.setMaxDamage(6);
    HMace1a.setTwoHanded(false);

    Weapon HMace1b;
    HMace1b.setName("Common Heavy Mace");
    HMace1b.setDescription("");
    HMace1b.setType("Weapon");
    HMace1b.setWeaponType("Small Heavy Mace");
    HMace1b.setMinDamage(2);
    HMace1b.setMaxDamage(6);
    HMace1b.setTwoHanded(false);

    Weapon HMace1c;
    HMace1c.setName("Reliable Heavy Mace");
    HMace1c.setDescription("");
    HMace1c.setType("Weapon");
    HMace1c.setWeaponType("Small Heavy Mace");
    HMace1c.setMinDamage(3);
    HMace1c.setMaxDamage(6);
    HMace1c.setTwoHanded(false);

    Weapon HMace1d;
    HMace1d.setName("Lucky Heavy Mace");
    HMace1d.setDescription("");
    HMace1d.setType("Weapon");
    HMace1d.setWeaponType("Small Heavy Mace");
    HMace1d.setMinDamage(4);
    HMace1d.setMaxDamage(6);
    HMace1d.setTwoHanded(false);

    Weapon HMace1e;
    HMace1e.setName("Lucky Heavy Mace");
    HMace1e.setDescription("");
    HMace1e.setType("Weapon");
    HMace1e.setWeaponType("Small Heavy Mace");
    HMace1e.setMinDamage(5);
    HMace1e.setMaxDamage(6);
    HMace1e.setTwoHanded(false);

    Weapon HMace2a;
    HMace2a.setName("Magic Heavy Mace");
    HMace2a.setDescription("");
    HMace2a.setType("Weapon");
    HMace2a.setWeaponType("Small Heavy Mace");
    HMace2a.setMinDamage(1);
    HMace2a.setMaxDamage(8);
    HMace2a.setTwoHanded(false);

    Weapon HMace2b;
    HMace2b.setName("Common Heavy Mace");
    HMace2b.setDescription("");
    HMace2b.setType("Weapon");
    HMace2b.setWeaponType("Heavy Mace");
    HMace2b.setMinDamage(1);
    HMace2b.setMaxDamage(8);
    HMace2b.setTwoHanded(false);

    Weapon HMace2c;
    HMace2c.setName("Common Heavy Mace");
    HMace2c.setDescription("");
    HMace2c.setType("Weapon");
    HMace2c.setWeaponType("Heavy Mace");
    HMace2c.setMinDamage(2);
    HMace2c.setMaxDamage(8);
    HMace2c.setTwoHanded(false);

    Weapon HMace2d;
    HMace2d.setName("Common Heavy Mace");
    HMace2d.setDescription("");
    HMace2d.setType("Weapon");
    HMace2d.setWeaponType("Heavy Mace");
    HMace2d.setMinDamage(3);
    HMace2d.setMaxDamage(8);
    HMace2d.setTwoHanded(false);

    Weapon HMace2e;
    HMace2e.setName("Reliable Heavy Mace");
    HMace2e.setDescription("");
    HMace2e.setType("Weapon");
    HMace2e.setWeaponType("Heavy Mace");
    HMace2e.setMinDamage(4);
    HMace2e.setMaxDamage(8);
    HMace2e.setTwoHanded(false);

    Weapon HMace2f;
    HMace2f.setName("Lucky Heavy Mace");
    HMace2f.setDescription("");
    HMace2f.setType("Weapon");
    HMace2f.setWeaponType("Heavy Mace");
    HMace2f.setMinDamage(5);
    HMace2f.setMaxDamage(8);
    HMace2f.setTwoHanded(false);

    Weapon HMace2g;
    HMace2g.setName("Lucky Heavy Mace");
    HMace2g.setDescription("");
    HMace2g.setType("Weapon");
    HMace2g.setWeaponType("Heavy Mace");
    HMace2g.setMinDamage(6);
    HMace2g.setMaxDamage(8);
    HMace2g.setTwoHanded(false);

    Weapon HMace2h;
    HMace2h.setName("Magic Heavy Mace");
    HMace2h.setDescription("");
    HMace2h.setType("Weapon");
    HMace2h.setWeaponType("Heavy Mace");
    HMace2h.setMinDamage(7);
    HMace2h.setMaxDamage(8);
    HMace2h.setTwoHanded(false);

    Weapon HMace2i;
    HMace2i.setName("Magic Heavy Mace");
    HMace2i.setDescription("");
    HMace2i.setType("Weapon");
    HMace2i.setWeaponType("Heavy Mace");
    HMace2i.setMinDamage(8);
    HMace2i.setMaxDamage(8);
    HMace2i.setTwoHanded(false);

    pushBackWeaponOntoVector(HMace1a,heavyMaceVector);
    pushBackWeaponOntoVector(HMace1b,heavyMaceVector);
    pushBackWeaponOntoVector(HMace1c,heavyMaceVector);
    pushBackWeaponOntoVector(HMace1d,heavyMaceVector);
    pushBackWeaponOntoVector(HMace1e,heavyMaceVector);
    pushBackWeaponOntoVector(HMace2a,heavyMaceVector);
    pushBackWeaponOntoVector(HMace2b,heavyMaceVector);
    pushBackWeaponOntoVector(HMace2c,heavyMaceVector);
    pushBackWeaponOntoVector(HMace2d,heavyMaceVector);
    pushBackWeaponOntoVector(HMace2e,heavyMaceVector);
    pushBackWeaponOntoVector(HMace2f,heavyMaceVector);
    pushBackWeaponOntoVector(HMace2g,heavyMaceVector);
    pushBackWeaponOntoVector(HMace2h,heavyMaceVector);
    pushBackWeaponOntoVector(HMace2i,heavyMaceVector);
}

//creates spears and pushes onto spearVector
void initializeSpearVector(vector <Weapon> &spearVector)
{
    Weapon spear1a;
    spear1a.setName("Common Spear");
    spear1a.setDescription("");
    spear1a.setType("Weapon");
    spear1a.setWeaponType("Small Spear");
    spear1a.setMinDamage(1);
    spear1a.setMaxDamage(6);
    spear1a.setTwoHanded(true);

    Weapon spear1b;
    spear1b.setName("Common Spear");
    spear1b.setDescription("");
    spear1b.setType("Weapon");
    spear1b.setWeaponType("Small Spear");
    spear1b.setMinDamage(2);
    spear1b.setMaxDamage(6);
    spear1b.setTwoHanded(true);

    Weapon spear1c;
    spear1c.setName("Reliable Spear");
    spear1c.setDescription("");
    spear1c.setType("Weapon");
    spear1c.setWeaponType("Small Spear");
    spear1c.setMinDamage(3);
    spear1c.setMaxDamage(6);
    spear1c.setTwoHanded(true);

    Weapon spear1d;
    spear1d.setName("Lucky Spear");
    spear1d.setDescription("");
    spear1d.setType("Weapon");
    spear1d.setWeaponType("Small Spear");
    spear1d.setMinDamage(4);
    spear1d.setMaxDamage(6);
    spear1d.setTwoHanded(true);

    Weapon spear1e;
    spear1e.setName("Lucky Spear");
    spear1e.setDescription("");
    spear1e.setType("Weapon");
    spear1e.setWeaponType("Small Spear");
    spear1e.setMinDamage(5);
    spear1e.setMaxDamage(6);
    spear1e.setTwoHanded(true);

    Weapon spear1f;
    spear1f.setName("Magic Spear");
    spear1f.setDescription("");
    spear1f.setType("Weapon");
    spear1f.setWeaponType("Small Spear");
    spear1f.setMinDamage(6);
    spear1f.setMaxDamage(6);
    spear1f.setTwoHanded(true);

    Weapon spear2a;
    spear2a.setName("Common Spear");
    spear2a.setDescription("");
    spear2a.setType("Weapon");
    spear2a.setWeaponType("Spear");
    spear2a.setMinDamage(1);
    spear2a.setMaxDamage(8);
    spear2a.setTwoHanded(true);

    Weapon spear2b;
    spear2b.setName("Common Spear");
    spear2b.setDescription("");
    spear2b.setType("Weapon");
    spear2b.setWeaponType("Spear");
    spear2b.setMinDamage(2);
    spear2b.setMaxDamage(8);
    spear2b.setTwoHanded(true);

    Weapon spear2c;
    spear2c.setName("Common Spear");
    spear2c.setDescription("");
    spear2c.setType("Weapon");
    spear2c.setWeaponType("Spear");
    spear2c.setMinDamage(3);
    spear2c.setMaxDamage(8);
    spear2c.setTwoHanded(true);

    Weapon spear2d;
    spear2d.setName("Reliable Spear");
    spear2d.setDescription("");
    spear2d.setType("Weapon");
    spear2d.setWeaponType("Spear");
    spear2d.setMinDamage(4);
    spear2d.setMaxDamage(8);
    spear2d.setTwoHanded(true);

    Weapon spear2e;
    spear2e.setName("Reliable Spear");
    spear2e.setDescription("");
    spear2e.setType("Weapon");
    spear2e.setWeaponType("Spear");
    spear2e.setMinDamage(5);
    spear2e.setMaxDamage(8);
    spear2e.setTwoHanded(true);

    Weapon spear2f;
    spear2f.setName("Lucky Spear");
    spear2f.setDescription("");
    spear2f.setType("Weapon");
    spear2f.setWeaponType("Spear");
    spear2f.setMinDamage(6);
    spear2f.setMaxDamage(8);
    spear2f.setTwoHanded(true);

    Weapon spear2g;
    spear2g.setName("Lucky Spear");
    spear2g.setDescription("");
    spear2g.setType("Weapon");
    spear2g.setWeaponType("Spear");
    spear2g.setMinDamage(7);
    spear2g.setMaxDamage(8);
    spear2g.setTwoHanded(true);

    Weapon spear2h;
    spear2h.setName("Magic Spear");
    spear2h.setDescription("");
    spear2h.setType("Weapon");
    spear2h.setWeaponType("Spear");
    spear2h.setMinDamage(8);
    spear2h.setMaxDamage(8);
    spear2h.setTwoHanded(true);

    pushBackWeaponOntoVector(spear1a,spearVector);
    pushBackWeaponOntoVector(spear1b,spearVector);
    pushBackWeaponOntoVector(spear1c,spearVector);
    pushBackWeaponOntoVector(spear1d,spearVector);
    pushBackWeaponOntoVector(spear1e,spearVector);
    pushBackWeaponOntoVector(spear1f,spearVector);

    pushBackWeaponOntoVector(spear2a,spearVector);
    pushBackWeaponOntoVector(spear2b,spearVector);
    pushBackWeaponOntoVector(spear2c,spearVector);
    pushBackWeaponOntoVector(spear2d,spearVector);
    pushBackWeaponOntoVector(spear2e,spearVector);
    pushBackWeaponOntoVector(spear2f,spearVector);
    pushBackWeaponOntoVector(spear2g,spearVector);
    pushBackWeaponOntoVector(spear2h,spearVector);

    return;
}

//creates heavy crossbows and pushes onto heacyCrossBowsVector
void initializeHCrossBowVector(vector <Weapon> &heavyCrossBowVector)
{
    Weapon crossBow1a;
    crossBow1a.setName("Common Heavy CrossBow");
    crossBow1a.setDescription("");
    crossBow1a.setType("Weapon");
    crossBow1a.setWeaponType("Small Heavy CrossBow");
    crossBow1a.setMinDamage(1);
    crossBow1a.setMaxDamage(8);
    crossBow1a.setTwoHanded(true);

    Weapon crossBow1b;
    crossBow1b.setName("Common Heavy CrossBow");
    crossBow1b.setDescription("");
    crossBow1b.setType("Weapon");
    crossBow1b.setWeaponType("Small Heavy CrossBow");
    crossBow1b.setMinDamage(2);
    crossBow1b.setMaxDamage(8);
    crossBow1b.setTwoHanded(true);

    Weapon crossBow1c;
    crossBow1c.setName("Common Heavy CrossBow");
    crossBow1c.setDescription("");
    crossBow1c.setType("Weapon");
    crossBow1c.setWeaponType("Small Heavy CrossBow");
    crossBow1c.setMinDamage(3);
    crossBow1c.setMaxDamage(8);
    crossBow1c.setTwoHanded(true);

    Weapon crossBow1d;
    crossBow1d.setName("Reliable Heavy CrossBow");
    crossBow1d.setDescription("");
    crossBow1d.setType("Weapon");
    crossBow1d.setWeaponType("Small Heavy CrossBow");
    crossBow1d.setMinDamage(4);
    crossBow1d.setMaxDamage(8);
    crossBow1d.setTwoHanded(true);

    Weapon crossBow1e;
    crossBow1e.setName("Reliable Heavy CrossBow");
    crossBow1e.setDescription("");
    crossBow1e.setType("Weapon");
    crossBow1e.setWeaponType("Small Heavy CrossBow");
    crossBow1e.setMinDamage(5);
    crossBow1e.setMaxDamage(8);
    crossBow1e.setTwoHanded(true);

    Weapon crossBow1f;
    crossBow1f.setName("Lucky Heavy CrossBow");
    crossBow1f.setDescription("");
    crossBow1f.setType("Weapon");
    crossBow1f.setWeaponType("Small Heavy CrossBow");
    crossBow1f.setMinDamage(6);
    crossBow1f.setMaxDamage(8);
    crossBow1f.setTwoHanded(true);

    Weapon crossBow1g;
    crossBow1g.setName("Lucky Heavy CrossBow");
    crossBow1g.setDescription("");
    crossBow1g.setType("Weapon");
    crossBow1g.setWeaponType("Small Heavy CrossBow");
    crossBow1g.setMinDamage(7);
    crossBow1g.setMaxDamage(8);
    crossBow1g.setTwoHanded(true);

    Weapon crossBow1h;
    crossBow1h.setName("Magic Heavy CrossBow");
    crossBow1h.setDescription("");
    crossBow1h.setType("Weapon");
    crossBow1h.setWeaponType("Small Heavy CrossBow");
    crossBow1h.setMinDamage(8);
    crossBow1h.setMaxDamage(8);
    crossBow1h.setTwoHanded(true);

    Weapon crossBow2a;
    crossBow2a.setName("Common Heavy CrossBow");
    crossBow2a.setDescription("");
    crossBow2a.setType("Weapon");
    crossBow2a.setWeaponType("Heavy CrossBow");
    crossBow2a.setMinDamage(1);
    crossBow2a.setMaxDamage(10);
    crossBow2a.setTwoHanded(true);

    Weapon crossBow2b;
    crossBow2b.setName("Common Heavy CrossBow");
    crossBow2b.setDescription("");
    crossBow2b.setType("Weapon");
    crossBow2b.setWeaponType("Heavy CrossBow");
    crossBow2b.setMinDamage(2);
    crossBow2b.setMaxDamage(10);
    crossBow2b.setTwoHanded(true);

    Weapon crossBow2c;
    crossBow2c.setName("Common Heavy CrossBow");
    crossBow2c.setDescription("");
    crossBow2c.setType("Weapon");
    crossBow2c.setWeaponType("Heavy CrossBow");
    crossBow2c.setMinDamage(3);
    crossBow2c.setMaxDamage(10);
    crossBow2c.setTwoHanded(true);

    Weapon crossBow2d;
    crossBow2d.setName("Common Heavy CrossBow");
    crossBow2d.setDescription("");
    crossBow2d.setType("Weapon");
    crossBow2d.setWeaponType("Heavy CrossBow");
    crossBow2d.setMinDamage(4);
    crossBow2d.setMaxDamage(10);
    crossBow2d.setTwoHanded(true);

    Weapon crossBow2e;
    crossBow2e.setName("Reliable Heavy CrossBow");
    crossBow2e.setDescription("");
    crossBow2e.setType("Weapon");
    crossBow2e.setWeaponType("Heavy CrossBow");
    crossBow2e.setMinDamage(5);
    crossBow2e.setMaxDamage(10);
    crossBow2e.setTwoHanded(true);

    Weapon crossBow2f;
    crossBow2f.setName("Lucky Heavy CrossBow");
    crossBow2f.setDescription("");
    crossBow2f.setType("Weapon");
    crossBow2f.setWeaponType("Heavy CrossBow");
    crossBow2f.setMinDamage(6);
    crossBow2f.setMaxDamage(10);
    crossBow2f.setTwoHanded(true);

    Weapon crossBow2g;
    crossBow2g.setName("Lucky Heavy CrossBow");
    crossBow2g.setDescription("");
    crossBow2g.setType("Weapon");
    crossBow2g.setWeaponType("Heavy CrossBow");
    crossBow2g.setMinDamage(7);
    crossBow2g.setMaxDamage(10);
    crossBow2g.setTwoHanded(true);

    Weapon crossBow2h;
    crossBow2h.setName("Lucky Heavy CrossBow");
    crossBow2h.setDescription("");
    crossBow2h.setType("Weapon");
    crossBow2h.setWeaponType("Heavy CrossBow");
    crossBow2h.setMinDamage(8);
    crossBow2h.setMaxDamage(10);
    crossBow2h.setTwoHanded(true);

    Weapon crossBow2i;
    crossBow2i.setName("Magic Heavy CrossBow");
    crossBow2i.setDescription("");
    crossBow2i.setType("Weapon");
    crossBow2i.setWeaponType("Heavy CrossBow");
    crossBow2i.setMinDamage(9);
    crossBow2i.setMaxDamage(10);
    crossBow2i.setTwoHanded(true);

    Weapon crossBow2j;
    crossBow2j.setName("Magic Heavy CrossBow");
    crossBow2j.setDescription("");
    crossBow2j.setType("Weapon");
    crossBow2j.setWeaponType("Heavy CrossBow");
    crossBow2j.setMinDamage(10);
    crossBow2j.setMaxDamage(10);
    crossBow2j.setTwoHanded(true);

    pushBackWeaponOntoVector(crossBow1a,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow1b,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow1c,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow1d,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow1e,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow1f,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow1g,heavyCrossBowVector);

    pushBackWeaponOntoVector(crossBow2a,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow2b,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow2c,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow2d,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow2e,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow2f,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow2g,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow2h,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow2i,heavyCrossBowVector);
    pushBackWeaponOntoVector(crossBow2j,heavyCrossBowVector);

    return;
}


//creates light crossbows and pushes onto lightCrossBowVector
void initializeLightCrossBowVector(vector <Weapon> &lightCrossBowVector)
{

    Weapon crossBow1a;
    crossBow1a.setName("Common Light CrossBow");
    crossBow1a.setDescription("");
    crossBow1a.setType("Weapon");
    crossBow1a.setWeaponType("Small Light CrossBow");
    crossBow1a.setMinDamage(1);
    crossBow1a.setMaxDamage(6);
    crossBow1a.setTwoHanded(true);

    Weapon crossBow1b;
    crossBow1b.setName("Common Light CrossBow");
    crossBow1b.setDescription("");
    crossBow1b.setType("Weapon");
    crossBow1b.setWeaponType("Small Light CrossBow");
    crossBow1b.setMinDamage(2);
    crossBow1b.setMaxDamage(6);
    crossBow1b.setTwoHanded(true);

    Weapon crossBow1c;
    crossBow1c.setName("Reliable Light CrossBow");
    crossBow1c.setDescription("");
    crossBow1c.setType("Weapon");
    crossBow1c.setWeaponType("Small Light CrossBow");
    crossBow1c.setMinDamage(3);
    crossBow1c.setMaxDamage(6);
    crossBow1c.setTwoHanded(true);

    Weapon crossBow1d;
    crossBow1d.setName("Lucky Light CrossBow");
    crossBow1d.setDescription("");
    crossBow1d.setType("Weapon");
    crossBow1d.setWeaponType("Small Light CrossBow");
    crossBow1d.setMinDamage(4);
    crossBow1d.setMaxDamage(6);
    crossBow1d.setTwoHanded(true);

    Weapon crossBow1e;
    crossBow1e.setName("Lucky Light CrossBow");
    crossBow1e.setDescription("");
    crossBow1e.setType("Weapon");
    crossBow1e.setWeaponType("Small Light CrossBow");
    crossBow1e.setMinDamage(5);
    crossBow1e.setMaxDamage(6);
    crossBow1e.setTwoHanded(true);

    Weapon crossBow1f;
    crossBow1f.setName("Magic Light CrossBow");
    crossBow1f.setDescription("");
    crossBow1f.setType("Weapon");
    crossBow1f.setWeaponType("Small Light CrossBow");
    crossBow1f.setMinDamage(6);
    crossBow1f.setMaxDamage(6);
    crossBow1f.setTwoHanded(true);

    Weapon crossBow2a;
    crossBow2a.setName("Common Light CrossBow");
    crossBow2a.setDescription("");
    crossBow2a.setType("Weapon");
    crossBow2a.setWeaponType("Small Light CrossBow");
    crossBow2a.setMinDamage(1);
    crossBow2a.setMaxDamage(8);
    crossBow2a.setTwoHanded(true);

    Weapon crossBow2b;
    crossBow2b.setName("Common Light CrossBow");
    crossBow2b.setDescription("");
    crossBow2b.setType("Weapon");
    crossBow2b.setWeaponType("Small Light CrossBow");
    crossBow2b.setMinDamage(2);
    crossBow2b.setMaxDamage(8);
    crossBow2b.setTwoHanded(true);

    Weapon crossBow2c;
    crossBow2c.setName("Common Light CrossBow");
    crossBow2c.setDescription("");
    crossBow2c.setType("Weapon");
    crossBow2c.setWeaponType("Small Light CrossBow");
    crossBow2c.setMinDamage(3);
    crossBow2c.setMaxDamage(8);
    crossBow2c.setTwoHanded(true);

    Weapon crossBow2d;
    crossBow2d.setName("Reliable Light CrossBow");
    crossBow2d.setDescription("");
    crossBow2d.setType("Weapon");
    crossBow2d.setWeaponType("Small Light CrossBow");
    crossBow2d.setMinDamage(4);
    crossBow2d.setMaxDamage(8);
    crossBow2d.setTwoHanded(true);

    Weapon crossBow2e;
    crossBow2e.setName("Reliable Light CrossBow");
    crossBow2e.setDescription("");
    crossBow2e.setType("Weapon");
    crossBow2e.setWeaponType("Small Light CrossBow");
    crossBow2e.setMinDamage(5);
    crossBow2e.setMaxDamage(8);
    crossBow2e.setTwoHanded(true);

    Weapon crossBow2f;
    crossBow2f.setName("Lucky Light CrossBow");
    crossBow2f.setDescription("");
    crossBow2f.setType("Weapon");
    crossBow2f.setWeaponType("Small Light CrossBow");
    crossBow2f.setMinDamage(6);
    crossBow2f.setMaxDamage(8);
    crossBow2f.setTwoHanded(true);

    Weapon crossBow2g;
    crossBow2g.setName("Lucky Light CrossBow");
    crossBow2g.setDescription("");
    crossBow2g.setType("Weapon");
    crossBow2g.setWeaponType("Small Light CrossBow");
    crossBow2g.setMinDamage(7);
    crossBow2g.setMaxDamage(8);
    crossBow2g.setTwoHanded(true);

    Weapon crossBow2h;
    crossBow2h.setName("Magic Light CrossBow");
    crossBow2h.setDescription("");
    crossBow2h.setType("Weapon");
    crossBow2h.setWeaponType("Light CrossBow");
    crossBow2h.setMinDamage(8);
    crossBow2h.setMaxDamage(8);
    crossBow2h.setTwoHanded(true);

    pushBackWeaponOntoVector(crossBow1a,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow1b,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow1c,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow1d,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow1e,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow1f,lightCrossBowVector);

    pushBackWeaponOntoVector(crossBow2a,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow2b,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow2c,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow2d,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow2e,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow2f,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow2g,lightCrossBowVector);
    pushBackWeaponOntoVector(crossBow2h,lightCrossBowVector);

}

//creates battleaxes and pushes onto battleaxeVector
void initializeBattleaxeVector(vector <Weapon> &battleaxeVector)
{
    Weapon battleaxe1a;
    battleaxe1a.setName("Common Battleaxe");
    battleaxe1a.setDescription("");
    battleaxe1a.setType("Weapon");
    battleaxe1a.setWeaponType("Small Battleaxe");
    battleaxe1a.setMinDamage(1);
    battleaxe1a.setMaxDamage(6);
    battleaxe1a.setTwoHanded(false);

    Weapon battleaxe1b;
    battleaxe1b.setName("Common Battleaxe");
    battleaxe1b.setDescription("");
    battleaxe1b.setType("Weapon");
    battleaxe1b.setWeaponType("Small Battleaxe");
    battleaxe1b.setMinDamage(2);
    battleaxe1b.setMaxDamage(6);
    battleaxe1b.setTwoHanded(false);

    Weapon battleaxe1c;
    battleaxe1c.setName("Reliable Battleaxe");
    battleaxe1c.setDescription("");
    battleaxe1c.setType("Weapon");
    battleaxe1c.setWeaponType("Small Battleaxe");
    battleaxe1c.setMinDamage(3);
    battleaxe1c.setMaxDamage(6);
    battleaxe1c.setTwoHanded(false);

    Weapon battleaxe1d;
    battleaxe1d.setName("Lucky Battleaxe");
    battleaxe1d.setDescription("");
    battleaxe1d.setType("Weapon");
    battleaxe1d.setWeaponType("Small Battleaxe");
    battleaxe1d.setMinDamage(4);
    battleaxe1d.setMaxDamage(6);
    battleaxe1d.setTwoHanded(false);

    Weapon battleaxe1e;
    battleaxe1e.setName("Lucky Battleaxe");
    battleaxe1e.setDescription("");
    battleaxe1e.setType("Weapon");
    battleaxe1e.setWeaponType("Small Battleaxe");
    battleaxe1e.setMinDamage(5);
    battleaxe1e.setMaxDamage(6);
    battleaxe1e.setTwoHanded(false);

    Weapon battleaxe1f;
    battleaxe1f.setName("Magic Battleaxe");
    battleaxe1f.setDescription("");
    battleaxe1f.setType("Weapon");
    battleaxe1f.setWeaponType("Small Battleaxe");
    battleaxe1f.setMinDamage(6);
    battleaxe1f.setMaxDamage(6);
    battleaxe1f.setTwoHanded(false);

    Weapon battleaxe2a;
    battleaxe2a.setName("Common Battleaxe");
    battleaxe2a.setDescription("");
    battleaxe2a.setType("Weapon");
    battleaxe2a.setWeaponType("Battleaxe");
    battleaxe2a.setMinDamage(1);
    battleaxe2a.setMaxDamage(8);
    battleaxe2a.setTwoHanded(false);

    Weapon battleaxe2b;
    battleaxe2b.setName("Common Battleaxe");
    battleaxe2b.setDescription("");
    battleaxe2b.setType("Weapon");
    battleaxe2b.setWeaponType("Battleaxe");
    battleaxe2b.setMinDamage(2);
    battleaxe2b.setMaxDamage(8);
    battleaxe2b.setTwoHanded(false);

    Weapon battleaxe2c;
    battleaxe2c.setName("Common Battleaxe");
    battleaxe2c.setDescription("");
    battleaxe2c.setType("Weapon");
    battleaxe2c.setWeaponType("Battleaxe");
    battleaxe2c.setMinDamage(3);
    battleaxe2c.setMaxDamage(8);
    battleaxe2c.setTwoHanded(false);

    Weapon battleaxe2d;
    battleaxe2d.setName("Reliable Battleaxe");
    battleaxe2d.setDescription("");
    battleaxe2d.setType("Weapon");
    battleaxe2d.setWeaponType("Battleaxe");
    battleaxe2d.setMinDamage(4);
    battleaxe2d.setMaxDamage(8);
    battleaxe2d.setTwoHanded(false);

    Weapon battleaxe2e;
    battleaxe2e.setName("Lucky Battleaxe");
    battleaxe2e.setDescription("");
    battleaxe2e.setType("Weapon");
    battleaxe2e.setWeaponType("Battleaxe");
    battleaxe2e.setMinDamage(5);
    battleaxe2e.setMaxDamage(8);
    battleaxe2e.setTwoHanded(false);

    Weapon battleaxe2f;
    battleaxe2f.setName("Lucky Battleaxe");
    battleaxe2f.setDescription("");
    battleaxe2f.setType("Weapon");
    battleaxe2f.setWeaponType("Battleaxe");
    battleaxe2f.setMinDamage(6);
    battleaxe2f.setMaxDamage(8);
    battleaxe2f.setTwoHanded(false);

    Weapon battleaxe2g;
    battleaxe2g.setName("Lucky Battleaxe");
    battleaxe2g.setDescription("");
    battleaxe2g.setType("Weapon");
    battleaxe2g.setWeaponType("Battleaxe");
    battleaxe2g.setMinDamage(7);
    battleaxe2g.setMaxDamage(8);
    battleaxe2g.setTwoHanded(false);

    Weapon battleaxe2h;
    battleaxe2h.setName("Magic Battleaxe");
    battleaxe2h.setDescription("");
    battleaxe2h.setType("Weapon");
    battleaxe2h.setWeaponType("Battleaxe");
    battleaxe2h.setMinDamage(8);
    battleaxe2h.setMaxDamage(8);
    battleaxe2h.setTwoHanded(false);

    pushBackWeaponOntoVector(battleaxe1a,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe1b,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe1c,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe1d,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe1e,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe1f,battleaxeVector);

    pushBackWeaponOntoVector(battleaxe2a,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe2b,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe2c,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe2d,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe2e,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe2f,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe2g,battleaxeVector);
    pushBackWeaponOntoVector(battleaxe2h,battleaxeVector);

    return;
}

//creates longbows and pushes onto longBowsVector
void initializeLongBowVector(vector <Weapon> &longBowVector)
{
    Weapon longBow1a;
    longBow1a.setName("Common Longbow");
    longBow1a.setDescription("");
    longBow1a.setType("Weapon");
    longBow1a.setWeaponType("Small Longbow");
    longBow1a.setMinDamage(1);
    longBow1a.setMaxDamage(6);
    longBow1a.setTwoHanded(true);

    Weapon longBow1b;
    longBow1b.setName("Common Longbow");
    longBow1b.setDescription("");
    longBow1b.setType("Weapon");
    longBow1b.setWeaponType("Small Longbow");
    longBow1b.setMinDamage(2);
    longBow1b.setMaxDamage(6);
    longBow1b.setTwoHanded(true);

    Weapon longBow1c;
    longBow1c.setName("Reliable Longbow");
    longBow1c.setDescription("");
    longBow1c.setType("Weapon");
    longBow1c.setWeaponType("Small Longbow");
    longBow1c.setMinDamage(3);
    longBow1c.setMaxDamage(6);
    longBow1c.setTwoHanded(true);

    Weapon longBow1d;
    longBow1d.setName("Lucky Longbow");
    longBow1d.setDescription("");
    longBow1d.setType("Weapon");
    longBow1d.setWeaponType("Small Longbow");
    longBow1d.setMinDamage(4);
    longBow1d.setMaxDamage(6);
    longBow1d.setTwoHanded(true);

    Weapon longBow1e;
    longBow1e.setName("Lucky Longbow");
    longBow1e.setDescription("");
    longBow1e.setType("Weapon");
    longBow1e.setWeaponType("Small Longbow");
    longBow1e.setMinDamage(5);
    longBow1e.setMaxDamage(6);
    longBow1e.setTwoHanded(true);

    Weapon longBow1f;
    longBow1f.setName("Magic Longbow");
    longBow1f.setDescription("");
    longBow1f.setType("Weapon");
    longBow1f.setWeaponType("Small Longbow");
    longBow1f.setMinDamage(6);
    longBow1f.setMaxDamage(6);
    longBow1f.setTwoHanded(true);

    Weapon longBow2a;
    longBow2a.setName("Common Longbow");
    longBow2a.setDescription("");
    longBow2a.setType("Weapon");
    longBow2a.setWeaponType("Longbow");
    longBow2a.setMinDamage(1);
    longBow2a.setMaxDamage(8);
    longBow2a.setTwoHanded(true);

    Weapon longBow2b;
    longBow2b.setName("Common Longbow");
    longBow2b.setDescription("");
    longBow2b.setType("Weapon");
    longBow2b.setWeaponType("Longbow");
    longBow2b.setMinDamage(2);
    longBow2b.setMaxDamage(8);
    longBow2b.setTwoHanded(true);

    Weapon longBow2c;
    longBow2c.setName("Common Longbow");
    longBow2c.setDescription("");
    longBow2c.setType("Weapon");
    longBow2c.setWeaponType("Longbow");
    longBow2c.setMinDamage(3);
    longBow2c.setMaxDamage(8);
    longBow2c.setTwoHanded(true);

    Weapon longBow2d;
    longBow2d.setName("Reliable Longbow");
    longBow2d.setDescription("");
    longBow2d.setType("Weapon");
    longBow2d.setWeaponType("Longbow");
    longBow2d.setMinDamage(4);
    longBow2d.setMaxDamage(8);
    longBow2d.setTwoHanded(true);

    Weapon longBow2e;
    longBow2e.setName("Lucky Longbow");
    longBow2e.setDescription("");
    longBow2e.setType("Weapon");
    longBow2e.setWeaponType("Longbow");
    longBow2e.setMinDamage(5);
    longBow2e.setMaxDamage(8);
    longBow2e.setTwoHanded(true);

    Weapon longBow2f;
    longBow2f.setName("Lucky Longbow");
    longBow2f.setDescription("");
    longBow2f.setType("Weapon");
    longBow2f.setWeaponType("Longbow");
    longBow2f.setMinDamage(6);
    longBow2f.setMaxDamage(8);
    longBow2f.setTwoHanded(true);

    Weapon longBow2g;
    longBow2g.setName("Lucky Longbow");
    longBow2g.setDescription("");
    longBow2g.setType("Weapon");
    longBow2g.setWeaponType("Longbow");
    longBow2g.setMinDamage(7);
    longBow2g.setMaxDamage(8);
    longBow2g.setTwoHanded(true);

    Weapon longBow2h;
    longBow2h.setName("Magic Longbow");
    longBow2h.setDescription("");
    longBow2h.setType("Weapon");
    longBow2h.setWeaponType("Longbow");
    longBow2h.setMinDamage(8);
    longBow2h.setMaxDamage(8);
    longBow2h.setTwoHanded(true);

    pushBackWeaponOntoVector(longBow1a,longBowVector);
    pushBackWeaponOntoVector(longBow1b,longBowVector);
    pushBackWeaponOntoVector(longBow1c,longBowVector);
    pushBackWeaponOntoVector(longBow1d,longBowVector);
    pushBackWeaponOntoVector(longBow1e,longBowVector);
    pushBackWeaponOntoVector(longBow1f,longBowVector);

    pushBackWeaponOntoVector(longBow2a,longBowVector);
    pushBackWeaponOntoVector(longBow2b,longBowVector);
    pushBackWeaponOntoVector(longBow2c,longBowVector);
    pushBackWeaponOntoVector(longBow2d,longBowVector);
    pushBackWeaponOntoVector(longBow2e,longBowVector);
    pushBackWeaponOntoVector(longBow2f,longBowVector);
    pushBackWeaponOntoVector(longBow2g,longBowVector);
    pushBackWeaponOntoVector(longBow2h,longBowVector);

    return;
}

//chooses potion
Consumable chooseConsumable(vector <Consumable> potionVector)
{
    Consumable potionToReturn;
    int positionOfPotion = 0;

    positionOfPotion = rand() % potionVector.size();
    potionToReturn = potionVector[positionOfPotion];

    return potionToReturn;
}

Armor chooseArmor(vector <Armor> armorVector)
{
    Armor armorToReturn;
    int positionOfArmor = 0;

    positionOfArmor = rand() % armorVector.size();
    armorToReturn = armorVector[positionOfArmor];

    return armorToReturn;
}

Weapon chooseWeapon(vector <Weapon> weaponVector)
{
    Weapon weaponToReturn;
    int positionOfWeapon = 0;

    positionOfWeapon = rand() % weaponVector.size();
    weaponToReturn = weaponVector[positionOfWeapon];

    return weaponToReturn;
}

//Picks a random number of items to place in a room once the room is entered
int numOfItems(char symbolArray[500][500],vector <Location> &possiblePositions)
{
    int spaceCounter = 0;
    int itemsToCreate = 0;
    int numOfSpacesPerItem = 15;

    for(int x = 0; x < 500; x++)
    {
        for(int y = 0; y < 500; y++)
        {
            if(symbolArray[x][y] == ' ')
            {
                if(symbolArray[x][y+1] == ' ' && symbolArray[x][y-1] == ' ')
                {
                    spaceCounter++;

                    Location newLocation(x,y);
                    possiblePositions.push_back(newLocation);
                }
                if(symbolArray[x+1][y] == ' ' && symbolArray[x-1][y] == ' ')
                {
                    spaceCounter++;

                    Location newLocation(x,y);
                    possiblePositions.push_back(newLocation);
                }
            }
        }
    }

    //1 item for every 15 spaces
    itemsToCreate = spaceCounter/numOfSpacesPerItem;

    return itemsToCreate;
}

//chooses which item to place based on item rarity
void itemChoice(character player, vector <Consumable> &consumableVector,vector <Armor> &armorVector,
                vector <Weapon> &weaponVector, vector <Consumable> healthPotionVector,
                vector <Consumable> magicPotionVector, vector <Armor> leatherArmorVector,
                vector <Armor> metalArmorVector,vector <Armor> crystalArmorVector,
                vector <Weapon> daggerVector,vector <Weapon> clubVector,vector <Weapon> heavyMaceVector,
                vector <Weapon> spearVector, vector <Weapon> heavyCrossBowVector,
                vector <Weapon> lightCrossBowVector,vector <Weapon> battleaxeVector, vector <Weapon> longBowVector)
{

    int min5pack = 1;
    int max5pack = 3;
    int min4pack = 4;
    int max4pack = 8;
    int min3pack = 9;
    int max3pack = 15;
    int min2pack = 16;
    int max2pack = 25;
    int min1potion = 26;
    int max1potion = 40;
    int minArmor = 41;
    int maxArmor = 70;
    int minLeather = 0;
    int maxLeather = 0;
    int minMetal = 0;
    int maxMetal = 0;
    int minCrystal = 0;
    int maxCrystal = 0;
    int minWeapons = 71;
    int maxWeapons = 100;
    int minDagger = 0;
    int maxDagger = 0;
    int minClub = 0;
    int maxClub = 0;
    int minHeavyMace = 0;
    int maxHeavyMace = 0;
    int minSpear = 0;
    int maxSpear = 0;
    int minHCrossbow = 0;
    int maxHCrossbow = 0;
    int minLCrossbow = 0;
    int maxLCrossbow = 0;
    int minArrows = 0;
    int maxArrows = 0;
    int minBattleaxe = 0;
    int maxBattleaxe = 0;
    int minLongBow = 0;
    int maxLongBow = 0;

    int maxPercent = 100;
    int minPercent = 1;
    int roll = rand() % maxPercent + minPercent;

    int decidingMax = 0;
    int decidingMin = 1;
    int decidingRoll = 0;

    int quantityMax = 0;
    int quantityMin = 1;
    int quantity = 0;

    if(roll >= min5pack && roll <= max5pack)//consumable pack-5
    {
        decidingMax = 2;
        decidingRoll = rand() % decidingMax + decidingMin;
       if(decidingRoll == 1)//health
        {
            Consumable Consumable1;
            Consumable1 = chooseConsumable(healthPotionVector);

            Consumable Consumable2;
            Consumable2 = chooseConsumable(healthPotionVector);

            Consumable Consumable3;
            Consumable3 = chooseConsumable(healthPotionVector);

            Consumable Consumable4;
            Consumable4 = chooseConsumable(healthPotionVector);

            Consumable Consumable5;
            Consumable5 = chooseConsumable(healthPotionVector);

            consumableVector.push_back(Consumable1);
            consumableVector.push_back(Consumable2);
            consumableVector.push_back(Consumable3);
            consumableVector.push_back(Consumable4);
            consumableVector.push_back(Consumable5);
        }
        else//magic
        {
            Consumable Consumable1;
            Consumable1 = chooseConsumable(magicPotionVector);

            Consumable Consumable2;
            Consumable2 = chooseConsumable(magicPotionVector);

            Consumable Consumable3;
            Consumable3 = chooseConsumable(magicPotionVector);

            Consumable Consumable4;
            Consumable4 = chooseConsumable(magicPotionVector);

            Consumable Consumable5;
            Consumable5 = chooseConsumable(magicPotionVector);

            consumableVector.push_back(Consumable1);
            consumableVector.push_back(Consumable2);
            consumableVector.push_back(Consumable3);
            consumableVector.push_back(Consumable4);
            consumableVector.push_back(Consumable5);
        }

    }//end of 5 pack(1-3)
    else if(roll >= min4pack && roll <= max4pack)//consumable pack of 4
    {
        decidingMax = 2;
        decidingRoll = rand() % decidingMax + decidingMin;
        if(decidingRoll == 1)//health
        {
            Consumable Consumable1;
            Consumable1 = chooseConsumable(healthPotionVector);

            Consumable Consumable2;
            Consumable2 = chooseConsumable(healthPotionVector);

            Consumable Consumable3;
            Consumable3 = chooseConsumable(healthPotionVector);

            Consumable Consumable4;
            Consumable4 = chooseConsumable(healthPotionVector);

            consumableVector.push_back(Consumable1);
            consumableVector.push_back(Consumable2);
            consumableVector.push_back(Consumable3);
            consumableVector.push_back(Consumable4);
        }
        else//magic
        {
            Consumable Consumable1;
            Consumable1 = chooseConsumable(magicPotionVector);

            Consumable Consumable2;
            Consumable2 = chooseConsumable(magicPotionVector);

            Consumable Consumable3;
            Consumable3 = chooseConsumable(magicPotionVector);

            Consumable Consumable4;
            Consumable4 = chooseConsumable(magicPotionVector);

            consumableVector.push_back(Consumable1);
            consumableVector.push_back(Consumable2);
            consumableVector.push_back(Consumable3);
            consumableVector.push_back(Consumable4);
        }//end of magic(4-8)

    }//end of 4 pack(4-8)
    else if(roll >= min3pack && roll <= max3pack)//consumable pack3
    {
        decidingMax = 2;
        decidingRoll = rand() % decidingMax + decidingMin;
        if(decidingRoll == 1)//health
        {
            Consumable Consumable1;
            Consumable1 = chooseConsumable(healthPotionVector);

            Consumable Consumable2;
            Consumable2 = chooseConsumable(healthPotionVector);

            Consumable Consumable3;
            Consumable3 = chooseConsumable(healthPotionVector);

            consumableVector.push_back(Consumable1);
            consumableVector.push_back(Consumable2);
            consumableVector.push_back(Consumable3);
        }
        else//magic
        {
            Consumable Consumable1;
            Consumable1 = chooseConsumable(magicPotionVector);

            Consumable Consumable2;
            Consumable2 = chooseConsumable(magicPotionVector);

            Consumable Consumable3;
            Consumable3 = chooseConsumable(magicPotionVector);

            consumableVector.push_back(Consumable1);
            consumableVector.push_back(Consumable2);
            consumableVector.push_back(Consumable3);
        }//end of magic(9-15)

    }//end of 3 pack(9-15)
    else if(roll >= min2pack && roll <= max2pack)//consumable pack 2
    {
        decidingMax = 2;
        decidingRoll = rand() % decidingMax + decidingMin;
       if(decidingRoll == 1)//health
        {
            Consumable Consumable1;
            Consumable1 = chooseConsumable(healthPotionVector);

            Consumable Consumable2;
            Consumable2 = chooseConsumable(healthPotionVector);

            consumableVector.push_back(Consumable1);
            consumableVector.push_back(Consumable2);
        }
        else//magic
        {
            Consumable Consumable1;
            Consumable1 = chooseConsumable(magicPotionVector);

            Consumable Consumable2;
            Consumable2 = chooseConsumable(magicPotionVector);

            consumableVector.push_back(Consumable1);
            consumableVector.push_back(Consumable2);

        }//end of magic(16-15)

    }//end of 2 pack(16-15)
    else if(roll >= min1potion && roll <= max1potion)//1 potion
    {
        decidingMax = 2;
        decidingRoll = rand() % decidingMax + decidingMin;
        if(decidingRoll == 1)//health
        {
            Consumable newConsumable;
            newConsumable = chooseConsumable(healthPotionVector);

            consumableVector.push_back(newConsumable);
        }//end of health(26-40)
        else//magic
        {
            Consumable newConsumable;
            newConsumable = chooseConsumable(magicPotionVector);

            consumableVector.push_back(newConsumable);
        }//end of magic(26-40)
    }//end of 1 potion(26-40)
    else if(roll >= minArmor && roll <= maxArmor)//armor
    {
        Armor newArmor;
        if(player.getLevel() >= 0 && player.getLevel() <= 19)//15% leather,10%metal,5%crystal
        {
            minLeather = 41;
            maxLeather = 55;
            minMetal = 56;
            maxMetal = 65;
            minCrystal = 66;
            maxCrystal = 70;
        }//end of level 1-19
        else if(player.getLevel() >= 20 && player.getLevel() <= 29)//10%leather,15%metal,5%crystal
        {
            minLeather = 41;
            maxLeather = 50;
            minMetal = 51;
            maxMetal = 65;
            minCrystal = 66;
            maxCrystal = 70;
        }//end of level 20-29
        else if(player.getLevel() >= 30 && player.getLevel() <= 39)//5%leather,15%metal,5%crystal
        {
            minLeather = 41;
            maxLeather = 45;
            minMetal = 46;
            maxMetal = 60;
            minCrystal = 61;
            maxCrystal = 70;
        }//end of level 30-39
        else//5%leather,10%metal,15%crystal
        {
            minLeather = 41;
            maxLeather = 45;
            minMetal = 46;
            maxMetal = 55;
            minCrystal = 56;
            maxCrystal = 70;
        }

        if(roll >= minLeather && roll <= maxLeather)
        {
            newArmor = chooseArmor(leatherArmorVector);//0-first leather item in armorVector; 4 = last leather item

            armorVector.push_back(newArmor);
        }
        else if (roll >= minMetal && roll <= maxMetal)
        {
            newArmor = chooseArmor(metalArmorVector);

            armorVector.push_back(newArmor);
        }
        else if (roll >= minCrystal && roll <= maxCrystal)
        {
            newArmor = chooseArmor(crystalArmorVector);

            armorVector.push_back(newArmor);
        }
    }//end of armor(41-70)
    else if(roll >= minWeapons && roll <= maxWeapons)//weapons
    {
        Weapon newWeapon;
        if(player.getLevel() >= 0 && player.getLevel() <= 5)
        {
            minDagger = 71;//15&
            maxDagger = 85;
            minClub = 86;//10%
            maxClub = 95;
            minHeavyMace = 96;//1%
            maxHeavyMace = 96;
            minSpear = 97;//1%
            maxSpear = 97;
            minLCrossbow = 98;//1%
            maxLCrossbow = 98;
            minLongBow = 99;//1%
            maxLongBow = 99;
            minBattleaxe = 100;//1%
            maxBattleaxe = 100;
        }
        else if(player.getLevel() >= 6 && player.getLevel() <= 9)
        {
            minDagger = 71;//10&
            maxDagger = 80;
            minClub = 81;//10%
            maxClub = 90;
            minHeavyMace = 91;//2%
            maxHeavyMace = 92;
            minSpear = 93;//2%
            maxSpear = 94;
            minArrows = 95;//2%
            maxArrows = 96;
            minLCrossbow = 97;//1%
            maxLCrossbow = 97;
            minLongBow = 98;//1%
            maxLongBow = 98;
            minBattleaxe = 99;//1%
            maxBattleaxe = 99;
            minHCrossbow = 100;//1%
            maxHCrossbow = 100;
        }
        else if(player.getLevel() >= 10 && player.getLevel() <= 19)
        {
            minDagger = 71;//5&
            maxDagger = 75;
            minClub = 76;//10%
            maxClub = 85;
            minHeavyMace = 86;//4%
            maxHeavyMace = 89;
            minSpear = 90;//3%
            maxSpear = 92;
            minArrows = 93;//2%
            maxArrows = 94;
            minLCrossbow = 95;//3%
            maxLCrossbow = 97;
            minLongBow = 98;//1%
            maxLongBow = 98;
            minBattleaxe = 99;//1%
            maxBattleaxe = 99;
            minHCrossbow = 100;//1%
            maxHCrossbow = 100;
        }
        else if(player.getLevel() >=20 && player.getLevel() <=29)
        {
            minDagger = 71;//4%
            maxDagger = 74;
            minClub = 75;//5%
            maxClub = 79;
            minHeavyMace = 80;//4%
            maxHeavyMace = 83;
            minSpear = 84;//4%
            maxSpear = 87;
            minArrows = 88;//4%
            maxArrows = 91;
            minLCrossbow = 92;//3%
            maxLCrossbow = 94;
            minLongBow = 95;//2%
            maxLongBow = 96;
            minBattleaxe = 97;//2%
            maxBattleaxe = 98;
            minHCrossbow = 99;//2%
            maxHCrossbow = 100;
        }
        else if(player.getLevel() >= 30 && player.getLevel() <= 39)
        {
            minDagger = 71;//4%
            maxDagger = 74;
            minClub = 75;//4%
            maxClub = 78;
            minHeavyMace = 79;//3%
            maxHeavyMace = 81;
            minSpear = 82;//3%
            maxSpear = 84;
            minArrows = 85;//4%
            maxArrows = 88;
            minLCrossbow = 89;//3%
            maxLCrossbow = 91;
            minLongBow = 92;//3%
            maxLongBow = 94;
            minBattleaxe = 95;//3%
            maxBattleaxe = 97;
            minHCrossbow = 98;//3%
            maxHCrossbow = 100;
        }
        else if(player.getLevel() >= 40 && player.getLevel() <= 49)
        {
            minDagger = 71;//1%
            maxDagger = 71;
            minClub = 72;//1%
            maxClub = 72;
            minHeavyMace = 73;//2%
            maxHeavyMace = 74;
            minSpear = 75;//4%
            maxSpear = 78;
            minArrows = 79;//5%
            maxArrows = 83;
            minLCrossbow = 84;//4%
            maxLCrossbow = 87;
            minLongBow = 88;//4%
            maxLongBow = 91;
            minBattleaxe = 92;//4%
            maxBattleaxe = 95;
            minHCrossbow = 96;//5%
            maxHCrossbow = 100;

        }
        else
        {
            minClub = 71;//1%
            maxClub = 71;
            minHeavyMace = 72;//1%
            maxHeavyMace = 72;
            minSpear = 73;//1%
            maxSpear = 73;
            minArrows = 74;//5%
            maxArrows = 78;
            minLCrossbow = 79;//3%
            maxLCrossbow = 81;
            minLongBow = 82;//4%
            maxLongBow = 85;
            minBattleaxe = 86;//5%
            maxBattleaxe = 90;
            minHCrossbow = 91;//10%
            maxHCrossbow = 100;
        }

        if(roll >= minDagger && roll <= maxDagger)
        {
            newWeapon = chooseWeapon(daggerVector);

            weaponVector.push_back(newWeapon);
        }
        else if(roll >= minClub && roll <= maxClub)
        {
            newWeapon = chooseWeapon(clubVector);

            weaponVector.push_back(newWeapon);
        }
        else if(roll >= minHeavyMace && roll <= maxHeavyMace)
        {
            newWeapon = chooseWeapon(heavyMaceVector);

            weaponVector.push_back(newWeapon);
        }
        else if(roll >= minSpear && roll <= maxSpear)
        {
            newWeapon = chooseWeapon(spearVector);

            weaponVector.push_back(newWeapon);
        }
        else if(roll >= minArrows && roll <= maxArrows)
        {
            quantityMin = 1;
            quantityMax = 20;
            quantity = rand() % quantityMax + quantityMin;

            Weapon arrows;
            if(quantity == 1)
                arrows.setName("1 Arrow");
            else if(quantity == 2)
                arrows.setName("2 Arrows");
            else if(quantity == 3)
                arrows.setName("3 Arrows");
            else if(quantity == 4)
                arrows.setName("4 Arrows");
            else if(quantity == 5)
                arrows.setName("5 Arrows");
            else if(quantity == 6)
                arrows.setName("6 Arrows");
            else if(quantity == 7)
                arrows.setName("7 Arrows");
            else if(quantity == 8)
                arrows.setName("8 Arrows");
            else if(quantity == 9)
                arrows.setName("9 Arrows");
            else if(quantity == 10)
                arrows.setName("10 Arrows");
            else if(quantity == 11)
                arrows.setName("11 Arrows");
            else if(quantity == 12)
                arrows.setName("12 Arrows");
            else if(quantity == 13)
                arrows.setName("13 Arrows");
            else if(quantity == 14)
                arrows.setName("14 Arrows");
            else if(quantity == 15)
                arrows.setName("15 Arrows");
            else if(quantity == 16)
                arrows.setName("16 Arrows");
            else if(quantity == 17)
                arrows.setName("17 Arrows");
            else if(quantity == 18)
                arrows.setName("18 Arrows");
            else if(quantity == 19)
                arrows.setName("19 Arrows");

            weaponVector.push_back(arrows);
        }
        else if(roll >= minLCrossbow && roll <= maxLCrossbow)
        {
            newWeapon = chooseWeapon(lightCrossBowVector);

            weaponVector.push_back(newWeapon);
        }
        else if(roll >= minLongBow && roll <= maxLongBow)
        {
            newWeapon = chooseWeapon(longBowVector);

            weaponVector.push_back(newWeapon);
        }
        else if(roll >= minBattleaxe && roll <= maxBattleaxe)
        {
            newWeapon = chooseWeapon(battleaxeVector);

            weaponVector.push_back(newWeapon);
        }
        else if(roll >= minHCrossbow && roll <= maxHCrossbow)
        {
            newWeapon = chooseWeapon(heavyCrossBowVector);

            weaponVector.push_back(newWeapon);
        }

    }//end of weapons(71-100)

    return;
}

//removes position from vector
void removePosition(vector <Location> &possiblePositions,int XtoClear, int YtoClear)
{
    for(int i = 0; i < signed(possiblePositions.size()); i++)
    {
        if(possiblePositions[i].getX() == XtoClear && possiblePositions[i].getY() == YtoClear)
        {
            possiblePositions[i].setX(0);
            possiblePositions[i].setY(0);
        }
    }
}

//Chooses the starting x and y coordinates for each item
void positions(char symbolArray[500][500], vector <Consumable> consumableVector,vector <Armor> armorVector,
               vector <Weapon> weaponVector,vector <Location> &possiblePositions)
{

    int numOfLocationsNeeded = consumableVector.size() + armorVector.size() + weaponVector.size();
    int chooseVector = 0;
    int position = 0;
    int itemX;
    int itemY;

    for(int i = 0; i < numOfLocationsNeeded; i++)
    {
        chooseVector = rand() % 3 + 1;
        if(chooseVector == 1)
        {
            position = rand() % consumableVector.size();
            itemX = consumableVector[position].getX();
            itemY = consumableVector[position].getY();
            symbolArray[itemX][itemY] = 'c';
        }
        else if (chooseVector == 2)
        {
            position = rand() % armorVector.size();
            itemX = armorVector[position].getX();
            itemY = armorVector[position].getY();
            symbolArray[itemX][itemY] = 'a';
        }
        else if(chooseVector == 3)
        {
            position = rand() % weaponVector.size();
            itemX = weaponVector[position].getX();
            itemY = weaponVector[position].getY();
            symbolArray[itemX][itemY] = 'w';
        }
    }

    return;
}

//sets items' x and y to positions taken from array
void matchItemWithPosition(char symbolArray[500][500],vector <Location> &possiblePositions, vector <Consumable> &consumableVector, vector <Armor> &armorVector, vector <Weapon> &weaponsVector)
{
    int itemX = 0;
    int itemY = 0;
    int randPosition = 0;

    for(int i = 0; i < signed(consumableVector.size()); i++)
    {
        randPosition = rand() % possiblePositions.size();
        while(possiblePositions[randPosition].getX() == 0 && possiblePositions[randPosition].getY() == 0)
        {
            randPosition = rand() % possiblePositions.size();
        }

        itemX = possiblePositions[randPosition].getX();
        itemY = possiblePositions[randPosition].getY();

        consumableVector[i].setX(itemX);
        consumableVector[i].setY(itemY);

        possiblePositions[randPosition].setX(0);
        possiblePositions[randPosition].setY(0);
    }
    for(int a = 0; a < signed(armorVector.size()); a++)
    {
        randPosition = rand() % possiblePositions.size();
        while(possiblePositions[randPosition].getX() == 0 && possiblePositions[randPosition].getY() == 0)
        {
            randPosition = rand() % possiblePositions.size();
        }

        itemX = possiblePositions[randPosition].getX();
        itemY = possiblePositions[randPosition].getY();

        armorVector[a].setX(itemX);
        armorVector[a].setY(itemY);

        possiblePositions[randPosition].setX(0);
        possiblePositions[randPosition].setY(0);
    }
    for(int b = 0; b < signed(weaponsVector.size()); b++)
    {
        randPosition = rand() % possiblePositions.size();
        while(possiblePositions[randPosition].getX() == 0 && possiblePositions[randPosition].getY() == 0)
        {
            randPosition = rand() % possiblePositions.size();
        }

        itemX = possiblePositions[randPosition].getX();
        itemY = possiblePositions[randPosition].getY();

        weaponsVector[b].setX(itemX);
        weaponsVector[b].setY(itemY);

        possiblePositions[randPosition].setX(0);
        possiblePositions[randPosition].setY(0);
    }

    return;
}

//finds consumable with Xposition and Yposition
Consumable findConsumable(vector<Consumable> consumabeVector,int Xposition, int Yposition)
{
    for(int i = 0; i < signed(consumabeVector.size()); i++)
    {
        if(consumabeVector[i].getX() == Xposition && consumabeVector[i].getY() == Yposition)
        {
            return consumabeVector[i];
        }
    }
}


//find armor with xPosition and yPosition
Armor findArmor(vector <Armor> armorVector,int xPosition, int yPosition)
{
    for(int i = 0; i < signed(armorVector.size());i++)
    {
        if(armorVector[i].getX() == xPosition && armorVector[i].getY() == yPosition)
        {
            return armorVector[i];
        }
    }
}

//find weapon with xPosition and yPosition
Weapon findWeapon(vector <Weapon> weaponVector, int xPosition, int yPosition)
{
    for(int i = 0; i < signed(weaponVector.size());i++)
    {
        if(weaponVector[i].getX() == xPosition && weaponVector[i].getY() == yPosition)
        {
            return weaponVector[i];
        }
    }
}

//checks if player is standind on item
void checkForItem(character player,char symbolArray[500][500],vector <Consumable> consumableVector,
                  vector <Armor> armorVector,vector <Weapon> weaponVector, WINDOW * workingWindow,
                  Inventory &playerInventory,vector <Location> possiblePositions)
{
    wclear(workingWindow);

    int currentX = player.getXCoordinate();
    int currentY = player.getYCoordinate();

    string currentString = "";

    if(symbolArray[currentX][currentY] == 'c')
    {
        Consumable itemToUse = findConsumable(consumableVector,currentX,currentY);

        if(itemToUse.getName()[itemToUse.getName().length()] == 's')
        {
            currentString = "You found: ";
        }
        else
        {
           if(itemToUse.getName()[0] == 'a' || itemToUse.getName()[0] == 'e' ||
           itemToUse.getName()[0] == 'u' || itemToUse.getName()[0] == 'i' ||
           itemToUse.getName()[0] == 'o')//a or an
            {
                currentString = "You have found an: ";
            }
            else
            {
                currentString = "You have found a: ";
            }
        }


        currentString = currentString + itemToUse.getName();
        char * characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,0,3,characterPointer);

        currentString = "Would you like to use item,";
        characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,4,3,characterPointer);
        currentString = " place item in your inventory or";
        characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,5,3,characterPointer);
        currentString = "move along?(Y/U/M)";
        characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,6,3,characterPointer);

        int ch = getch();

        if(ch == 'y')
        {
            playerInventory.addToInventoryCArray(itemToUse,workingWindow,symbolArray);
            symbolArray[itemToUse.getX()][itemToUse.getY()] = ' ';
            itemToUse.setX(0);
            itemToUse.setY(0);
            wclear(workingWindow);
            playerInventory.printInventoryArrays(workingWindow);
            return;
        }

     //   printConsumableWindow(itemToUse,workingWindow,symbolArray,player,playerInventory);
    }
    else if(symbolArray[currentX][currentY] == 'a')
    {
        Armor itemToUse = findArmor(armorVector,currentX,currentY);

        if(itemToUse.getName()[itemToUse.getName().length()] == 's')
        {
            currentString = "You found: ";
        }
        else
        {
           if(itemToUse.getName()[0] == 'a' || itemToUse.getName()[0] == 'e' ||
           itemToUse.getName()[0] == 'u' || itemToUse.getName()[0] == 'i' ||
           itemToUse.getName()[0] == 'o')//a or an
            {
                currentString = "You have found an: ";
            }
            else
            {
                currentString = "You have found a: ";
            }
        }

        currentString = currentString + itemToUse.getName();
        char * characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,0,3,characterPointer);

        string currentString = "Strength: ";
        int strength = itemToUse.getStrength();
        characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,1,3,characterPointer);
        mvwprintw(workingWindow,1,12,"%d",strength);

        currentString = "Would you like to place item in your";
        characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,4,3,characterPointer);
        currentString = "inventory?(Enter for yes)";
        characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,5,3,characterPointer);

        int ch = getch();

        if(ch == 'y')
        {
            playerInventory.addToInventoryAArray(itemToUse,workingWindow,symbolArray);
            symbolArray[itemToUse.getX()][itemToUse.getY()] = ' ';
            itemToUse.setX(0);
            itemToUse.setY(0);
            wclear(workingWindow);
            playerInventory.printInventoryArrays(workingWindow);
            return;
        }

       // printArmorWindow(itemToUse,workingWindow,symbolArray,player,playerInventory);
    }
    else if(symbolArray[currentX][currentY] == 'w')
    {
        Weapon itemToUse = findWeapon(weaponVector,currentX,currentY);

        if(itemToUse.getName()[itemToUse.getName().length()] == 's')
        {
            currentString = "You found: ";
        }
        else
        {
           if(itemToUse.getName()[0] == 'a' || itemToUse.getName()[0] == 'e' ||
           itemToUse.getName()[0] == 'u' || itemToUse.getName()[0] == 'i' ||
           itemToUse.getName()[0] == 'o')//a or an
            {
                currentString = "You have found an: ";
            }
            else
            {
                currentString = "You have found a: ";
            }
        }
        currentString = currentString + itemToUse.getName();
        char * characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,0,3,characterPointer);

        string currentString = "Minimum Damage: ";
        int minDamage = itemToUse.getMinDamage();
        characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,1,3,characterPointer);
        mvwprintw(workingWindow,1,18,"%d",minDamage);

        currentString = "Maximum Damage: ";
        int maxDamage = itemToUse.getMaxDamage();
        characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,2,3,characterPointer);
        mvwprintw(workingWindow,2,18,"%d",maxDamage);

        currentString = "Would you like to place item in your";
        characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,4,3,characterPointer);
        currentString = "inventory?(Enter for yes)";
        characterPointer = &currentString.at(0);
        mvwprintw(workingWindow,5,3,characterPointer);

        int ch = getch();

        if(ch == 'y')
        {
            playerInventory.addToInventoryWArray(itemToUse,workingWindow,symbolArray);
            symbolArray[itemToUse.getX()][itemToUse.getY()] = ' ';
            itemToUse.setX(0);
            itemToUse.setY(0);
            wclear(workingWindow);
            playerInventory.printInventoryArrays(workingWindow);
            return;
        }

       // printWeaponWindow(itemToUse,workingWindow,symbolArray,player,playerInventory);
    }
    else
    {
        return;
    }
}

//prints consumable stats
void printConsumableWindow(Consumable consumableToUse, WINDOW * messageWindow,
                           char symbolArray[500][500],character player,Inventory &playerInventory)
{
    string currentString = "Would you like to use item,";
    char * characterPointer = &currentString.at(0);
    mvwprintw(messageWindow,4,3,characterPointer);
    currentString = " place item in your inventory or";
    characterPointer = &currentString.at(0);
    mvwprintw(messageWindow,5,3,characterPointer);
    currentString = "move along?(Y/U/M)";
    characterPointer = &currentString.at(0);
    mvwprintw(messageWindow,6,3,characterPointer);

    int ch = getchar();
    bool checkFull = false;

    if(ch == 'Y' || ch == 'y')
    {
        checkFull = playerInventory.getInventoryFull();
        if(checkFull == false)
        {
            wclear(messageWindow);
            playerInventory.addToInventoryCArray(consumableToUse,messageWindow,symbolArray);
            symbolArray[player.getXCoordinate()][player.getYCoordinate()] = ' ';
            return;
        }
    }
    /*else if(ch == 'U' || ch == 'u')
    {
        if(consumableToUse.getHealthValue() != 0)
        {
            player.setHealth(player.getHealth() + consumableToUse.getHealthValue());
            return;
        }
        else
        {
            if(consumableToUse.getMagicAffect() == "Strengthen Armor")
            {
                currentString = "Which piece of armor would you like to strengthen?";
                characterPointer = &currentString.at(0);
                mvwprintw(messageWindow,0,1,characterPointer);

                playerInventory.printArmor(messageWindow);

                ch = getchar();
                ch = ch - 1;

                Armor armorToStrengthen = playerInventory.getArmorPiece(ch);
                armorToStrengthen.setStrength(armorToStrengthen.getStrength() + consumableToUse.getMagicValue());
                playerInventory.removeFromAInventory(playerInventory.getArmorPiece(ch));
                playerInventory.addToInventoryAArray(armorToStrengthen,messageWindow,symbolArray);
            }
            else if(consumableToUse.getMagicAffect() == "Strengthen Weapon")
            {
                currentString = "Which weapon would you like to stregthen?";
                characterPointer = &currentString.at(0);
                mvwprintw(messageWindow,0,1,characterPointer);

                playerInventory.printWeapons(messageWindow);

                ch = getchar();
                ch = ch - 1;

                Weapon weaponToStrengthen = playerInventory.getWeapon(ch);
                weaponToStrengthen.setMaxDamage(weaponToStrengthen.getMaxDamage() + consumableToUse.getMagicValue());
                playerInventory.removeFromWInventory(playerInventory.getWeapon(ch));
                playerInventory.addToInventoryWArray(weaponToStrengthen,messageWindow,symbolArray);
            }
        }
    }*/
    return;

}

//prints armor stats
void printArmorWindow(Armor armorToUse, WINDOW * messageWindow,
                      char symbolArray[500][500], character player,Inventory &playerInventory)
{
    string currentString = "Strength: ";
    int strength = armorToUse.getStrength();
    char * characterPointer = &currentString.at(0);
    mvwprintw(messageWindow,1,3,characterPointer);
    mvwprintw(messageWindow,1,12,"%d",strength);

    currentString = "Would you like to place item in your";
    characterPointer = &currentString.at(0);
    mvwprintw(messageWindow,4,3,characterPointer);
    currentString = "inventory?(Enter for yes)";
    characterPointer = &currentString.at(0);
    mvwprintw(messageWindow,5,3,characterPointer);
/*
    int ch = getchar();
    bool checkFull = false;

    if(ch == 'Y' || ch == 'y')
    {
        checkFull = playerInventory.getInventoryFull();
        if(checkFull == false)
        {
            wclear(messageWindow);
            playerInventory.addToInventoryAArray(armorToUse,messageWindow,symbolArray);
            symbolArray[player.getXCoordinate()][player.getYCoordinate()] = ' ';
            return;
        }
        else
        {
            currentString = "Your inventory is full. Would you like to drop something?(Y for yes)";
            characterPointer = &currentString.at(0);
            mvwprintw(messageWindow,0,1,characterPointer);
            return;
        }
    }
*/
    return;
}

//prints weapon stats
void printWeaponWindow(Weapon weaponToUse, WINDOW * messageWindow,
                       char symbolArray[500][500], character player,Inventory &playerInventory)
{
    string currentString = "Minimum Damage: ";
    int minDamage = weaponToUse.getMinDamage();
    char * characterPointer = &currentString.at(0);
    mvwprintw(messageWindow,1,3,characterPointer);
    mvwprintw(messageWindow,1,18,"%d",minDamage);

    currentString = "Maximum Damage: ";
    int maxDamage = weaponToUse.getMaxDamage();
    characterPointer = &currentString.at(0);
    mvwprintw(messageWindow,2,3,characterPointer);
    mvwprintw(messageWindow,2,18,"%d",maxDamage);

    currentString = "Would you like to place item in your";
    characterPointer = &currentString.at(0);
    mvwprintw(messageWindow,4,3,characterPointer);
    currentString = "inventory?(Enter for yes)";
    characterPointer = &currentString.at(0);
    mvwprintw(messageWindow,5,3,characterPointer);
/*
    int ch = getchar();
    bool checkFull = false;

    if(ch == 'Y' || ch == 'y')
    {
        checkFull = playerInventory.getInventoryFull();
        if(checkFull == false)
        {
            wclear(messageWindow);
            playerInventory.addToInventoryWArray(weaponToUse,messageWindow,symbolArray);
            symbolArray[player.getXCoordinate()][player.getYCoordinate()] = ' ';
            playerInventory.printInventoryArrays(messageWindow);
            return;
        }
        else
        {
            currentString = "Your inventory is full. Would you like to drop something?(Y for yes)";
            characterPointer = &currentString.at(0);
            mvwprintw(messageWindow,0,1,characterPointer);
            return;
        }
    }
*/
    return;
}

//write tests out to file
void writeTests(vector <Consumable> consumableVector,vector <Armor> armorVector,
                vector <Weapon> weaponVector, vector <Location> positionVector,vector <Consumable> healthPotionVector,
                vector <Consumable> magicPotionVector, vector <Armor> leatherArmorVector, vector <Armor> metalArmorVector,
                vector <Armor> crystalArmorVector, vector <Weapon> daggerVector,
                vector <Weapon> clubVector, vector <Weapon> heavyMaceVector,vector <Weapon> spearVector,
                vector <Weapon> heavyCrossBowVector, vector <Weapon> lightCrossBowVector,
                vector <Weapon> battleaxeVector, vector <Weapon> longBowVector,Inventory playerInventory)
{
    ofstream oFile("test.txt");

    oFile << "Test Consumable Vector:" << endl;

    for(int a = 0; a < signed(consumableVector.size()); a++)
    {
        oFile << a << ". " << consumableVector[a].getName() << endl
              << "    " << consumableVector[a].getType() << endl
              << "X: " << consumableVector[a].getX() << endl
              << "Y: " << consumableVector[a].getY() << endl;
    }

    oFile << endl << endl;

    oFile << "Test Armor Vector:" << endl;

    for(int b = 0; b < signed(armorVector.size()); b++)
    {
        oFile << b << ". " << armorVector[b].getName() << endl
              << "    " << armorVector[b].getType() << endl
              << "X: " << armorVector[b].getX() << endl
              << "Y: " << armorVector[b].getY() << endl;
    }

    oFile << endl << endl;

    oFile << "Test Weapon Vector:" << endl;

    for(int c = 0; c < signed(weaponVector.size()); c++)
    {
        oFile << c << ". " << weaponVector[c].getName() << endl
              << "    " << weaponVector[c].getType() << endl
              << "X: " << weaponVector[c].getX() << endl
              << "Y: " << weaponVector[c].getY() << endl;
    }

    oFile << endl << endl;

    oFile << "Test Position Vector:" << endl;

    for(int b = 0; b < signed(positionVector.size());b++)
    {
        oFile << b << ". X: " << positionVector[b].getX() << endl
              << "    Y: " << positionVector[b].getY() << endl;
    }

    oFile << endl << endl;

    //test healthPotionVection
    oFile << "Test Health Potion Vector: " << endl;

    for(int c = 0; c < signed(healthPotionVector.size()); c++)
    {
        oFile << c << ". " << healthPotionVector[c].getName() << endl
              << "    " << healthPotionVector[c].getType() << endl
              << "    " << healthPotionVector[c].getHealthValue() << endl;
    }

    oFile << endl << endl;

    //test magicPotionVector
    oFile << "Test Magic Potion Vector: " << endl;

    for(int d = 0; d < signed(healthPotionVector.size()); d++)
    {
        oFile << d << ". " << magicPotionVector[d].getName() << endl
              << "    " << magicPotionVector[d].getType() << endl
              << "    " << magicPotionVector[d].getMagicValue() << endl;
    }

    oFile << endl << endl;

    //test leatherArmorVector
    oFile << "Test leatherArmorVector: " << endl;

    for(int e = 0; e < signed(leatherArmorVector.size()); e++)
    {
        oFile << e << ". " << leatherArmorVector[e].getName() << endl
              << "    " << leatherArmorVector[e].getType() << endl;
    }

    oFile << endl << endl;

    //test metalArmorVector
    oFile << "Test metalArmorVector: " << endl;

    for(int f = 0; f < signed(metalArmorVector.size()); f++)
    {
        oFile << f << ". " << metalArmorVector[f].getName() << endl
              << "    " << metalArmorVector[f].getType() << endl;
    }

    oFile << endl << endl;

    //test crystalArmorVector
    oFile << "Test crystalArmorVector: " << endl;

    for(int g = 0; g < signed(metalArmorVector.size()); g++)
    {
        oFile << g << ". " << metalArmorVector[g].getName() << endl
              << "    " << metalArmorVector[g].getType() << endl;
    }

    oFile << endl << endl;

    oFile << "Test daggerVector: " << endl;
    for(int h = 0; h < signed(daggerVector.size());h++)
    {
        oFile << h << ". " << daggerVector[h].getName()
              << "   MinDamage: " << daggerVector[h].getMinDamage()
              << "   MaxDamage: " << daggerVector[h].getMinDamage() << endl;
    }

    oFile << endl << endl;

    oFile << "Test clubVector: " << endl;
    for(int i = 0; i < signed(clubVector.size()); i++)
    {
        oFile << i << ". " << clubVector[i].getName()
              << "   MinDamage: " << daggerVector[i].getMinDamage()
              << "   MaxDamage: " << daggerVector[i].getMinDamage() << endl;
    }

    oFile << endl << endl;

    oFile << "Test heavyMaceVector: " << endl;
    for(int j = 0; j < signed(heavyMaceVector.size()); j++)
    {
        oFile << j << ". " << heavyMaceVector[j].getName()
              << "   MinDamage: " << heavyMaceVector[j].getMinDamage()
              << "   MaxDamage: " << heavyMaceVector[j].getMinDamage() << endl;
    }

    oFile << endl << endl;

    oFile << "Test spearVector: " << endl;
    for(int k = 0; k < signed(spearVector.size()); k++)
    {
        oFile << k << ". " << spearVector[k].getName()
              << "   MinDamage: " << spearVector[k].getMinDamage()
              << "   MaxDamage: " << spearVector[k].getMinDamage() << endl;
    }

    oFile << endl << endl;

    oFile << "Test heavyCrossBowVector: " << endl;
    for(int l = 0; l < signed(heavyCrossBowVector.size()); l++)
    {
        oFile << l << ". " << heavyCrossBowVector[l].getName()
              << "   MinDamage: " << heavyCrossBowVector[l].getMinDamage()
              << "   MaxDamage: " << heavyCrossBowVector[l].getMinDamage() << endl;
    }

    oFile << endl << endl;

    oFile << "Test lightCrossBowVector: " << endl;
    for(int m = 0; m < signed(lightCrossBowVector.size()); m++)
    {
        oFile << m << ". " << lightCrossBowVector[m].getName()
              << "   MinDamage: " << lightCrossBowVector[m].getMinDamage()
              << "   MaxDamage: " << lightCrossBowVector[m].getMinDamage() << endl;
    }

    oFile << endl << endl;

    oFile << "Test battleaxeVector: " << endl;
    for(int n = 0; n < signed(battleaxeVector.size()); n++)
    {
        oFile << n << ". " << battleaxeVector[n].getName()
              << "   MinDamage: " << battleaxeVector[n].getMinDamage()
              << "   MaxDamage: " << battleaxeVector[n].getMinDamage() << endl;
    }

    oFile << endl << endl;

    oFile << "Test longBowVector: " << endl;
    for(int o = 0; o < signed(longBowVector.size()); o++)
    {
        oFile << o << ". " << longBowVector[o].getName()
              << "   MinDamage: " << longBowVector[o].getMinDamage()
              << "   MaxDamage: " << longBowVector[o].getMinDamage() << endl;
    }

    oFile << endl << endl;

}
