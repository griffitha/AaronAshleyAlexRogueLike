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
void Item::setX(int height, int width, int xOfWindow)
{
    int maxX = xOfWindow + width;

    this -> x = rand() % maxX + xOfWindow;

    return;
}


//setY
void Item::setY(int height, int width, int yOfWindow)
{
    int maxY = yOfWindow + height;

    this -> x = rand() % maxY + yOfWindow;

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

//get healthValue
int Consumable::getHealthValue()
{
    return healthValue;
}

//get maficValue
int Consumable::getMagicValue()
{
    return magicValue;
}

//deconstructor--Consumable
Consumable::~Consumable()
{
}

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


//constructor--Weapon
Weapon::Weapon()
{
    damage = 0;
}

//set damage
void Weapon::setDamage(int damage)
{
    this -> damage = damage;
}

//get damage
int Weapon::getDamage()
{
    return damage;
}

//deconstructor--Weapon
Weapon::~Weapon()
{
    damage = 0;
}

//constructon--packOfArrows
packOfArrows::packOfArrows()
{
    numOfArrows = 0;
}

//setNumOfArrows
void packOfArrows::setNumOfArrows(int maxValue)
{
    srand(time(NULL));

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
}

//constructor--Armor
Armor::Armor()
{
    strength = 0;
    type = " ";
}

//setStrength
void Armor::setStrength(int strength)
{
    this ->strength = strength;
}

//setType
void Armor::setType(string type)
{
    this -> type = type;
}

//get Strength
int Armor::getStrength()
{
    return strength;
}

//getType
string Armor::getType()
{
    return type;
}

//deconstructor--Armor
Armor::~Armor()
{
    strength = 0;
    type = " ";
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

//creates health potions and pushes onto healthPotionVector
void initializeHealthPotionVector(vector <Consumable> &healthPotionVector)
{
    Consumable firstHPotion;
    firstHPotion.setMagicValue(0);
    firstHPotion.setHealthValue(5);

    Consumable secondHPotion;
    secondHPotion.setMagicValue(0);
    secondHPotion.setHealthValue(10);

    Consumable thirdHPotion;
    thirdHPotion.setMagicValue(0);
    thirdHPotion.setHealthValue(15);

    Consumable fourthHPotion;
    fourthHPotion.setMagicValue(0);
    fourthHPotion.setHealthValue(20);

    Consumable fifthHPotion;
    fifthHPotion.setMagicValue(0);
    fifthHPotion.setHealthValue(25);

    Consumable sixthHPotion;
    sixthHPotion.setMagicValue(0);
    sixthHPotion.setHealthValue(30);

    Consumable seventhHPotion;
    seventhHPotion.setMagicValue(0);
    seventhHPotion.setHealthValue(35);

    Consumable eighthHPotion;
    eighthHPotion.setMagicValue(0);
    eighthHPotion.setHealthValue(40);

    Consumable ninthHPotion;
    ninthHPotion.setMagicValue(0);
    ninthHPotion.setHealthValue(45);

    Consumable tenthHPotion;
    tenthHPotion.setMagicValue(0);
    tenthHPotion.setHealthValue(50);

    healthPotionVector.push_back(firstHPotion);
    healthPotionVector.push_back(secondHPotion);
    healthPotionVector.push_back(thirdHPotion);
    healthPotionVector.push_back(fourthHPotion);
    healthPotionVector.push_back(fifthHPotion);
    healthPotionVector.push_back(sixthHPotion);
    healthPotionVector.push_back(seventhHPotion);
    healthPotionVector.push_back(eighthHPotion);
    healthPotionVector.push_back(ninthHPotion);
    healthPotionVector.push_back(tenthHPotion);

    return;
}

//creates magic potions and pushes onto magicPotionVector
void initializeMagicPotionVector(vector <Consumable> &magicPotionVector)
{
    Consumable firstMPotion;
    firstMPotion.setMagicValue(5);
    firstMPotion.setHealthValue(0);

    Consumable secondMPotion;
    secondMPotion.setMagicValue(10);
    secondMPotion.setHealthValue(0);

    Consumable thirdMPotion;
    thirdMPotion.setMagicValue(15);
    thirdMPotion.setHealthValue(0);

    Consumable fourthMPotion;
    fourthMPotion.setMagicValue(20);
    fourthMPotion.setHealthValue(0);

    Consumable fifthMPotion;
    fifthMPotion.setMagicValue(25);
    fifthMPotion.setHealthValue(0);

    Consumable sixthMPotion;
    sixthMPotion.setMagicValue(30);
    sixthMPotion.setHealthValue(0);

    Consumable seventhMPotion;
    seventhMPotion.setMagicValue(35);
    seventhMPotion.setHealthValue(0);

    Consumable eighthMPotion;
    eighthMPotion.setMagicValue(40);
    eighthMPotion.setHealthValue(0);

    Consumable ninthMPotion;
    ninthMPotion.setMagicValue(45);
    ninthMPotion.setHealthValue(0);

    Consumable tenthMPotion;
    tenthMPotion.setMagicValue(50);
    tenthMPotion.setHealthValue(0);

    magicPotionVector.push_back(firstMPotion);
    magicPotionVector.push_back(secondMPotion);
    magicPotionVector.push_back(thirdMPotion);
    magicPotionVector.push_back(fourthMPotion);
    magicPotionVector.push_back(fifthMPotion);
    magicPotionVector.push_back(sixthMPotion);
    magicPotionVector.push_back(seventhMPotion);
    magicPotionVector.push_back(eighthMPotion);
    magicPotionVector.push_back(ninthMPotion);
    magicPotionVector.push_back(tenthMPotion);

    return;
}


//creatss armor and pushes onto armorVector
void initializeArmorVector(vector <Armor> &armorVector)
{
    Helmet leatherHelmet("leather", 0);
    Breastplate leatherBreastplate("leather", 0);
    Gloves leatherGloves("leather",0);
    Shoes leatherShoes("leather",0);
    Shield leatherShield("leather",0);

    Helmet metalHelmet("metal", 0);
    Breastplate metalBreastplate("metal",0);
    Gloves metalGloves("metal",0);
    Shoes metalShoes("metal", 0);
    Shield metalShield("metal", 0);

    Helmet crystalHelmet("crystal",0);
    Breastplate crystalBreastplate("crystal",0);
    Gloves crystalGloves("crystal",0);
    Shoes crystalShoes("crystal",0);
    Shield crystalShield("crystal",0);

    armorVector.push_back(leatherHelmet);
    armorVector.push_back(leatherBreastplate);
    armorVector.push_back(leatherGloves);
    armorVector.push_back(leatherShoes);
    armorVector.push_back(leatherShield);

    armorVector.push_back(metalHelmet);
    armorVector.push_back(metalBreastplate);
    armorVector.push_back(metalGloves);
    armorVector.push_back(metalShoes);
    armorVector.push_back(metalShield);

    armorVector.push_back(crystalHelmet);
    armorVector.push_back(crystalBreastplate);
    armorVector.push_back(crystalGloves);
    armorVector.push_back(crystalShoes);
    armorVector.push_back(crystalShield);

    return;
}

//creates weapons and pushes onto weaponsVector
/*void initializeWeaponsVector(vector <Weapon> &weaponsVector)
{
    Weapon

    return;
}*/

Consumable chooseConsumable(vector <Consumable> potionVector)
{
    Consumable potionToReturn;
    int positionOfPotion;

    positionOfPotion = rand() % potionVector.size();
    potionToReturn = potionVector[positionOfPotion];

    return potionToReturn;
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
void itemChoice(character player,vector <Item> &itemVector,
                vector <Consumable> healthPotionVector, vector <Consumable> magicPotionVector)
{
    srand(time(NULL));

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
    int minCyrstal = 0;
    int maxCyrstal = 0;
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

            consumablePack newConsumablePack(Consumable1,Consumable2,Consumable3,Consumable4,Consumable5);

            itemVector.push_back(newConsumablePack);
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

            consumablePack newConsumablePack(Consumable1,Consumable2,Consumable3,Consumable4,Consumable5);

            itemVector.push_back(newConsumablePack);
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

            Consumable Consumable5;

            consumablePack newConsumablePack(Consumable1,Consumable2,Consumable3,Consumable4,Consumable5);

            itemVector.push_back(newConsumablePack);
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

            consumablePack newConsumablePack(Consumable1,Consumable2,Consumable3,Consumable4,Consumable5);

            itemVector.push_back(newConsumablePack);
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

            Consumable Consumable4;

            Consumable Consumable5;

            consumablePack newConsumablePack(Consumable1,Consumable2,Consumable3,Consumable4,Consumable5);

            itemVector.push_back(newConsumablePack);
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

            Consumable Consumable5;

            consumablePack newConsumablePack(Consumable1,Consumable2,Consumable3,Consumable4,Consumable5);

            itemVector.push_back(newConsumablePack);
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

            Consumable Consumable3;

            Consumable Consumable4;

            Consumable Consumable5;

            consumablePack newConsumablePack(Consumable1,Consumable2,Consumable3,Consumable4,Consumable5);

            itemVector.push_back(newConsumablePack);
        }
        else//magic
        {
            Consumable Consumable1;
            Consumable1 = chooseConsumable(magicPotionVector);

            Consumable Consumable2;
            Consumable2 = chooseConsumable(magicPotionVector);

            Consumable Consumable3;

            Consumable Consumable4;

            Consumable Consumable5;

            consumablePack newConsumablePack(Consumable1,Consumable2,Consumable3,Consumable4,Consumable5);

            itemVector.push_back(newConsumablePack);

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

            itemVector.push_back(newConsumable);
        }//end of health(26-40)
        else//magic
        {
            Consumable newConsumable;
            newConsumable = chooseConsumable(magicPotionVector);

            itemVector.push_back(newConsumable);
        }//end of magic(26-40)
    }//end of 1 potion(26-40)
    else if(roll >= minArmor && roll <= maxArmor)//armor
    {
        if(player.getLevel() == 1)
        {

        }


    }//end of armor(41-70)
    else if(roll >= minWeapons && roll <= maxWeapons)//weapons
    {

    }//end of weapons(71-100)

    return;
}

//Chooses the starting x and y coordinates for each item
void positions(char symbolArray[500][500], vector <Item> itemVector,vector <Location> &possiblePositions)
{
    ofstream oFile("test.txt");

   /* oFile << "possiblePositionsVector: " << endl;
    for(int x = 0; x < possiblePositions.size(); x++)
    {

        oFile << x << ".  (" << possiblePositions[x].getX() << "," << possiblePositions[x].getY() << ")" << endl;
    }

    oFile << endl << endl;*/

    for(int y = 0; y < 500; y++)
    {
        for(int x = 0; x < 500; x++)
        {
            oFile << symbolArray[x][y] << endl;
        }
    }

    srand(time(NULL));

    int numOfLocationsNeeded = itemVector.size();
    int maxPercent = possiblePositions.size() - 1;
    int possiblePositionsLocation = 0;
    int itemX;
    int itemY;

    for(int i = 0; i < numOfLocationsNeeded; i++)
    {
        possiblePositionsLocation = rand() % maxPercent;
        itemX = possiblePositions[possiblePositionsLocation].getX();
        itemY = possiblePositions[possiblePositionsLocation].getY();
        symbolArray[itemX][itemY] = '*';
    }

    for(int y = 0; y < 500; y++)
    {
        for(int x = 0; x < 500; x++)
        {
            oFile << symbolArray[x][y] << endl;
        }
    }
}
