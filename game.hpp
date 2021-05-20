#include <iostream>
using namespace std;
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define TOPLVL 10


class names{
private:
    string namesarray[200];
    string potionsarray[200];
    string weaponsarray[200];
    string armorsarray[200];
    string spellsarray[200];
    int n=0;
    int p=0;
    int w=0;
    int a=0;
    int s=0;
public:
    void readfiles();
    string get_entry(string);
};


class range{
public:
    int minimum;
    int maximum;
    range(int x, int y) {minimum=x; maximum=y;}
    void lower_range(int i, int j) {minimum=minimum-i; maximum=maximum-j;}
    int get_min() {return minimum;}
    int get_max() {return maximum;}
    void set_min(int i) {minimum=i;}
    void set_max(int i) {maximum=i;}
    int get_exact(int lvl) {return min( maximum, max( ((maximum-minimum)/TOPLVL)*(lvl+1), minimum));}
    int get_exacto(int i) {return min( maximum, max( ((maximum-minimum)/i*10)*(i), minimum));}
};


class Item{
protected:
    string cat;
    string name;
    int price;
    int min_level;
    int type;
public:
    Item() {}
    void print_name();
    string get_name() { return name;}
    void print_cat();
    int get_price() {return price;}
    int get_minlevel() {return min_level;}
    int get_type() {return type;}
    void print_price();
    void print_minlevel();
    virtual void print_1() {}
    virtual void print_2() {}
    virtual int get_submem() = 0;
};

class Weapon: public Item{
private:
    int damage;
    int hands;
public:
    Weapon(string);
    void print_1();
    void print_2();
    int get_submem() {return damage;}
};

class Armor: public Item{
private:
    int damage_decrease;

public:
    Armor(string);
    void print_1();
    void print_2() {cout<<"\033[40m                     \033[0m";}
    int get_submem() {return damage_decrease;}
};

class Potion: public Item{
private:
    int quantity;
public:
    Potion(string);
    void print_1();
    void print_2() {cout<<"\033[40m                     \033[0m";}
    int get_submem() {return quantity;}
};

class Spell{
protected:
    string cat;
    string name;
    int price;
    int min_level;
    range* damage;
    int magicPower_cost;
    int rounds_left;
    int type;
public:
    string get_name() {return name;}
    void print_cat();
    int get_price() {return price;}
    int get_minlevel() {return min_level;}
    range* get_damagerange() {return damage;}
    int get_magiccost() {return magicPower_cost;}
    int get_rounds() {return rounds_left;}
    void print_name();
    void print_price();
    void print_minlevel();
    void print_range();
    void print_magiccost();
    int get_type() {return type;}
    virtual int get_submem() = 0;
};

class FireSpell: public Spell{
private:
    int decrease_defence;
public:
    FireSpell(string);
    int get_submem() {return decrease_defence;}
};

class IceSpell: public Spell{
private:
    int decrease_damage_range;
public:
    IceSpell(string);
    int get_submem() {return decrease_damage_range;}
};

class LightningSpell: public Spell{
private:
    int decrease_dodge_chance;
public:
    LightningSpell(string);
    int get_submem() {return decrease_dodge_chance;}
};


class Living{
protected:
    string name;
    int level;
    int healthPower;
public:
    Living() {}
    int get_healthPower() {return healthPower;}
    string get_name() {return name;}
    void set_healthPower(int i) {healthPower=i;}
    void lower_healthPower(int i) {healthPower=healthPower-i;}
};


class Monster: public Living{
protected:
    range* damage;
    int defence;
    int dodge_chance;
    int spell_rounds_left;
    int mem1;
    int mem2;
    int spelltype;
public:
    Monster() {}
    virtual void defend(int,int,int,int) {}
    void displayStats();
    int attack();
};

class Dragon: public Monster{
public:
    Dragon(string);
    ~Dragon();
    void defend(int,int,int,int);
};

class Exoskeleton: public Monster{
public:
    Exoskeleton(string);
    ~Exoskeleton();
    void defend(int,int,int,int);
};

class Spirit: public Monster{
public:
    Spirit(string);
    void defend(int,int,int,int);
};

class Hero: public Living{
protected:
    Item** items;
    Spell** spells;
    int nitems;
    int nspells;
    int magicPower;
    int strength;
    int dexterity;
    int agility;
    int money;
    int experience;
    Item* gun;
    Item* armor;
public:
    Hero() {}
    void checkInventory(int);
    int isInventoryEmpty();
    void equip(int);
    int get_money() {return money;}
    int get_level() {return level;}
    int get_spells() {return nspells;}
    Spell* get_spell(int i) {return spells[i];}
    Item* get_item(int i) {return items[i];}
    void sub_money(int i) {money=money-i;}
    void add_money(int i) {money=money+i;}
    void addItemtoInventory(Item*);
    void addSpelltoInventory(Spell*);
    void rmSpellfromInventory(Spell*);
    void rmItemfromInventory(Item*);
    int dim() {return max(nitems,nspells);}
    void add_experience(int i);
    int get_experience() {return experience;}
    virtual void levelUp(int i) {}
    void castSpell(Monster*);
    void attack(Monster*);
    void use();
    void boost(int);
    void displayStats();
    void put_on(Item*);
    void defend(int);

};

class Warrior: public Hero{
private:
    int privilege=10;
    int normal=5;
public:
    Warrior(string);
    ~Warrior();
    void levelUp(int i) {
      level=level+i; strength=strength+i*privilege; agility=agility+i*privilege; dexterity=dexterity+i*normal;
      cout << "\nGood Job!! You are now level " << level << "!"<< endl;
    }
    //ευνοημένος στον τομέα της δύναμης και της ευκινησίας
};

class Sorcerer: public Hero{
private:
    int privilege=10;
    int normal=5;
public:
    Sorcerer(string);
    ~Sorcerer();
    void levelUp(int i) {
      level=level+i; strength=strength+i*normal; agility=agility+i*privilege; dexterity=dexterity+i*privilege;
      cout << "\nGood Job!! You are now level " << level << "!"<< endl;
    }
    //ευνοημένος στον τομέα της επιδεξιότητας και της ευκινησίας.
};

class Paladin: public Hero{
private:
    int privilege=10;
    int normal=5;
public:
    Paladin(string);
    ~Paladin();
    void levelUp(int i) {
      level=level+i; strength=strength+i*privilege; agility=agility+i*normal; dexterity=dexterity+i*privilege;
      cout << "\nGood Job!! You are now level " << level << "!"<< endl;
    }
    //ευνοημένος στον τομέα της δύναμης και της επιδεξιότητας.
};

class Squad{
protected:
    Hero** heroes;
    int n;
public:
    Squad(int);
    ~Squad();
    int getn() {return n;}
    Hero* get_hero(int i) {return heroes[i];}
    int isSquadHealthZero();
};


class Square{
private:
    Item** items;
    Spell** spells;
    Monster** monsters;
    int coords[2];
    int heroes;
    int access;
    int market;
    int nheroes;
    int nmonsters;
public:
    int nitems;
    int nspells;
    Square(int,int,int,int,int);
    ~Square();
    int fight(Squad*);
    void displayMarket(int);
    int heroesin() {return heroes;}
    int accessible() {return access;}
    int market_in() {return market;}
    void set_heroes() {heroes=1;}
    void set_access() {access=1;}
    void set_market() {market=1;}
    void unset_heroes() {heroes=0;}
    void unset_access() {access=0;}
    void unset_market() {market=0;}
    int dim() {return max(nitems,nspells);}
    Item* get_item(int i) {return items[i];}
    Spell* get_spell(int i) {return spells[i];}
    void displayStats(Squad*);
};

class Grid{
private:
    Square*** gridp;
    Squad* squad;
    int location[2];
    int SIZE;
    int nheroes;
public:
    Grid(int);
    ~Grid();
    void play();
    int move(string);
    int fight(Squad*);
    int buy(Hero*,string,string,string);
    int sell(Hero*,string,string,string);
    //void quitGame() {}
    void displayMap();
};
