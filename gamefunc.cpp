#include <iostream>
using namespace std;
#include "game.hpp"
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include<ios>
#include<limits>
#include<cmath>
#define RESET "\033[0m"
names* entry;

void names::readfiles()
{
    string line;
    int i=0;
    ifstream iFile("names.txt");
    while (true) {
        //iFile >> x;
        getline (iFile,line);
        namesarray[i]=line;
        i++;
        if( iFile.eof() ) break;
        //cout << namesarray[i-1] << endl;
    }
    iFile.close();
    i=0;
    ifstream iFile1("potions.txt");
    while (true) {
        //iFile >> x;
        getline (iFile1,line);
        potionsarray[i]=line;
        i++;
        if( iFile1.eof() ) break;
        //cout << potionsarray[i-1] << endl;
    }
    iFile1.close();
    i=0;
    ifstream iFile2("weapons.txt");
    while (true) {
        //iFile >> x;
        getline (iFile2,line);
        weaponsarray[i]=line;
        i++;
        if( iFile2.eof() ) break;
        //cout << weaponsarray[i-1] << endl;
    }
    iFile2.close();
    i=0;
    ifstream iFile3("armors.txt");
    while (true) {
        //iFile >> x;
        getline (iFile3,line);
        armorsarray[i]=line;
        i++;
        if( iFile3.eof() ) break;
        //cout << armorsarray[i-1] << endl;
    }
    iFile3.close();
    i=0;
    ifstream iFile4("spells.txt");
    while (true) {
        //iFile >> x;
        getline (iFile4,line);
        spellsarray[i]=line;
        i++;
        if( iFile4.eof() ) break;
        //cout << armorsarray[i-1] << endl;
    }
    iFile4.close();

}

string names::get_entry(string i)
{
    if(i=="name")
    {
        if(n>=96)
            n=0;
        n++;
        return namesarray[n-1];
    }
    else if(i=="potion")
    {
        if(p>=64)
            p=0;
        p++;
        return potionsarray[p-1];
    }
    else if(i=="weapon")
    {
        if(w>=118)
            w=0;
        w++;
        return weaponsarray[w-1];
    }
    else if(i=="armor")
    {
        if(a>=79)
            a=0;
        a++;
        return armorsarray[a-1];
    }
    else if(i=="spell")
    {
        //cout << s << endl;
        if(s>=90)
            s=0;
        s++;
        return spellsarray[s-1];
    }
    else
    {
        return "\0";
    }
}
////////////////////////////////////////////////////////////////////////////////
void Item::print_cat()
{
    cout << cat;
    for(int i=0;i<21-cat.length();i++)
        cout << " ";
}

void Item::print_name()
{
    cout << name;
    for(int i=0;i<21-name.length();i++)
        cout << " ";
}

void Item::print_price()
{
    stringstream ss;
    ss << "Price: " << price;
    string str = ss.str();
    cout << str;
    for(int i=0;i<21-str.length();i++)
        cout << " ";
}

void Item::print_minlevel()
{
    stringstream ss;
    ss  << "Minimum level: " << min_level;
    string str = ss.str();
    cout << str;
    for(int i=0;i<21-str.length();i++)
        cout << " ";
}

void Weapon::print_1()
{
    stringstream ss;
    ss  << "Damage: " << damage;
    string str = ss.str();
    cout << str;
    for(int i=0;i<21-str.length();i++)
        cout << " ";
}

void Weapon::print_2()
{
    if(hands==1)
        cout << "Requires both hands! ";
    else
        cout << "Requires one hand    ";
}

void Armor::print_1()
{
    stringstream ss;
    ss  << "Damage decrease: " << damage_decrease;
    string str = ss.str();
    cout << str;
    for(int i=0;i<21-str.length();i++)
        cout << " ";
}

void Potion::print_1()
{
    stringstream ss;
    ss  << "Boost: " << quantity;
    string str = ss.str();
    cout << str;
    for(int i=0;i<21-str.length();i++)
        cout << " ";
}
////////////////////////////////////////////////////////////////////////////////
void Spell::print_cat()
{
    cout << cat;
    for(int i=0;i<21-cat.length();i++)
        cout << " ";
}

void Spell::print_name()
{
    cout << name;
    for(int i=0;i<21-name.length();i++)
        cout << " ";
}

void Spell::print_price()
{
    stringstream ss;
    ss << "Price: " << price;
    string str = ss.str();
    cout << str;
    for(int i=0;i<21-str.length();i++)
        cout << " ";
}

void Spell::print_minlevel()
{
    stringstream ss;
    ss  << "Minimum level: " << min_level;
    string str = ss.str();
    cout << str;
    for(int i=0;i<21-str.length();i++)
        cout << " ";
}

void Spell::print_range()
{
    stringstream ss;
    ss << "Damage range: " << damage->minimum << " - " << damage->maximum;
    string str = ss.str();
    cout << str;
    for(int i=0;i<21-str.length();i++)
        cout << " ";
}

void Spell::print_magiccost()
{
    stringstream ss;
    ss  << "Magic power cost: " << magicPower_cost;
    string str = ss.str();
    cout << str;
    for(int i=0;i<21-str.length();i++)
        cout << " ";
}
////////////////////////////////////////////////////////////////////////////////
IceSpell::IceSpell(string nam)
{
    cat="IceSpell";
    name=nam;
    type=1;
    price=rand() % 7+2;
    min_level=rand()%2;
    int i=rand()%5;
    if(i>2)
        min_level=0;
    damage=new range( rand() % 5 + 25 , rand() % 5 + 35 );
    magicPower_cost=rand() % 7+2;;
    rounds_left=rand() %3 +1;
    decrease_damage_range=rand()%3+5;
    //cout << "An IceSpell has been created!" << ", named " << name << endl;
    //εκτός από τη ζημιά που προκαλεί, μειώνει και το εύρος ζημιάς τουαντιπάλου για κάποιους γύρους.
}
////////////////////////////////////////////////////////////////////////////////
LightningSpell::LightningSpell(string nam)
{
    cat="LightningSpell";
    name=nam;
    type=2;
    price=rand() % 7+2;
    min_level=rand()%2;
    int i=rand()%5;
    if(i>2)
        min_level=0;
    damage=new range( rand() % 5 + 25 , rand() % 5 + 35 );
    magicPower_cost=rand() % 7+2;
    rounds_left=rand() %3 +1;
    decrease_dodge_chance=rand()%30+20;
    //cout << "A LightningSpell has been created!" << ", named " << name << endl;
    //εκτός από τη ζημιά που προκαλεί, μειώνει καιτην πιθανότητα να αποφύγει μια επίθεση ο αντίπαλος για κάποιους γύρους.
}
////////////////////////////////////////////////////////////////////////////////
FireSpell::FireSpell(string nam)
{
    cat="FireSpell";
    name=nam;
    type=0;
    price=rand() % 7+2;
    min_level=rand()%2;
    int i=rand()%5;
    if(i>2)
        min_level=0;
    damage=new range( rand() % 5 + 25 , rand() % 5 + 35 );
    magicPower_cost=rand() % 7+2;
    rounds_left=rand() %3 +1;
    decrease_defence=rand() %3 +1;
    //cout << "A FireSpell has been created!" << ", named " << name << endl;
    //εκτός απότη ζημιά που προκαλεί, μειώνει και το ποσό άμυνας του αντιπάλου για κάποιους γύρους.
}
////////////////////////////////////////////////////////////////////////////////
Potion::Potion(string nam)
{
    cat="Potion";
    type=3;
    name=nam;
    price=rand()%5+2;
    min_level=rand()%2;
    quantity=rand()%5+20;
    //cout << "A Potion has been created!" << ", named " << name << endl;
    //αυξάνει κάποιο στατιστικό του  κατά  κάποιο  ποσό.
}
////////////////////////////////////////////////////////////////////////////////
Armor::Armor(string nam)
{
    cat="Armor";
    type=4;
    name=nam;
    price=rand()%10+5;
    min_level=rand()%2;
    damage_decrease=rand()%10+7;
    //cout << "A Armor has been created!" << ", named " << name << endl;
    //μειώνει την ζημία που δέχεται από μία επίθεση του αντιπάλου του.
}
////////////////////////////////////////////////////////////////////////////////
Weapon::Weapon(string nam)
{
    cat="Weapon";
    type=5;
    name=nam;
    price=rand()%20+5;
    min_level=rand()%2;
    damage=rand()%10+10;
    hands=rand()%2;
    //cout << "A Weapon has been created!" << ", named " << name << endl;
    //έχει ένα συγκεκριμένο ποσό ζημιάς που προκαλεί στον αντίπαλο του
    //και μπορεί να απαιτεί το ένα ή και τα δύο χέρια του ήρωα για να το χρησιμοποιεί.
}
////////////////////////////////////////////////////////////////////////////////
void Monster::displayStats()
{
    cout << "\033[0m\n\n" << get_name() << "'s stats are: " << endl << endl;
    cout << "level        ";
    float timh=level;
    int barWidth = 100;
    cout << "\u001b[33;1m\u2503";
    int pos = 1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 "  << RESET <<level << endl;

    cout << endl;
    cout << "healthPower  ";
    timh=healthPower;
    barWidth = 100;
    cout << "\u001b[33;1m\u2503";
    pos =1.25*1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 " << RESET << healthPower << endl;
    cout << endl;

    cout << "Defence     ";
    timh=defence;
    cout << "\u001b[33;1m\u2503";
    pos = 15*1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 " << RESET << defence << endl;
    cout << endl;

}


int Monster::attack()
{
    cout << "\u001b[31m\nMonster " << get_name() << " is attacking you " << RESET << endl;
    return damage->get_exact(level);
}
////////////////////////////////////////////////////////////////////////////////
Dragon::Dragon(string nam)
{
    name=nam;
    level=0;
    healthPower=50;
    damage=new range( rand() % 5 + 15 , rand() % 5 + 25 );
    defence=rand()%2;
    dodge_chance=rand()%100;
    spell_rounds_left=0;
    spelltype=4;
    //cout << "A Dragon has been created!" << ", named " << name << endl;
    //ευνοημένο στο εύρος ζημιάς που μπορεί να προκαλέσει.
}

void Dragon::defend(int type, int i, int rounds_left, int j)
{
    if(spell_rounds_left>0){
        spell_rounds_left=spell_rounds_left-1;
        if((spell_rounds_left==0)&&(spelltype<=2))
        {
            cout << "\u001b[31mThe effect of the spell on " << get_name() << " has worn out. His stats shall go back to normal "  << endl;
            if(spelltype==0)
            {
                defence=mem1;
            }
            else if(spelltype==1)
            {
                damage->set_min(mem1);
                damage->set_max(mem2);
            }
            else if(spelltype==2)
            {
                dodge_chance=mem1;
            }
            spelltype=4;
        }
    }
    if(spelltype!=2)
        dodge_chance=rand()%100;
    if(dodge_chance<75)
    {
        int old=healthPower;
        //cout<<"i="<<i<<", defence="<<defence<<endl;
        i=i-defence;
        if(i<0) i=0;
        healthPower=healthPower-i;
        if(healthPower<=0){
            healthPower=0;
            cout << "\u001b[32m" << get_name() << " was killed."<< RESET << endl;
        }
        else if(old-healthPower>0)
            cout << "\u001b[32m" << get_name() << "'s healthPower was brought down from " << old << " to " << healthPower << "."<< RESET << endl;
        else if(old-healthPower<=0)
            cout << "\u001b[31m" << get_name() << " didn't lose an ounce of HP." << RESET << endl;
        if(type==0)
        {
           spelltype=0;
           mem1=defence;
           defence=defence-j;
           spell_rounds_left=rounds_left;
           cout << "\u001b[32m" << get_name() << "'s defence was brought down from " << mem1 << " to " << defence << " for " << spell_rounds_left << " rounds." << RESET << endl;
        }
        else if(type==1)
        {
            spelltype=1;
            mem1=damage->get_min();
            mem2=damage->get_max();
            cout << "\u001b[32m" << get_name() << "'s damage range was brought down from [" << damage->get_min() << "," << damage->get_max();
            damage->lower_range(j,j);
            spell_rounds_left=rounds_left;
            cout << "\u001b[32m" << "] to [" << damage->get_min() << "," <<  damage->get_max() << "] for " << spell_rounds_left << " rounds." << RESET << endl;
        }
        else if(type==2)
        {
            spelltype=2;
            mem1=dodge_chance;
            dodge_chance=dodge_chance-j;
            spell_rounds_left=rounds_left;
            cout << "\u001b[32m" << get_name() << "'s dodge chance was brought down for " << spell_rounds_left << " rounds."<< RESET << endl;
        }
    }
    else
        cout << "\u001b[31m" <<  get_name() << " dodged your attack. "<< RESET << endl;
}
////////////////////////////////////////////////////////////////////////////////
Exoskeleton::Exoskeleton(string nam)
{
    name=nam;
    level=0;
    healthPower=50;
    damage=new range( rand() % 5 + 5 , rand() % 5 + 15 );
    defence=rand()%2+2;
    dodge_chance=rand()%100;
    spell_rounds_left=0;
    spelltype=4;
    //cout << "An Exoskeleton has been created!" << ", named " << name << endl;
    //ευνοημένο  στο  ποσό  άμυνας  που  διαθέτει.
}

void Exoskeleton::defend(int type, int i, int rounds_left, int j)
{
    if(spell_rounds_left>0){
        spell_rounds_left=spell_rounds_left-1;
        if((spell_rounds_left==0)&&(spelltype<=2))
        {
            cout << "\u001b[31mThe effect of the spell on " << get_name() << " has worn out. His stats shall go back to normal "  << endl;
            if(spelltype==0)
            {
                defence=mem1;
            }
            else if(spelltype==1)
            {
                damage->set_min(mem1);
                damage->set_max(mem2);
            }
            else if(spelltype==2)
            {
                dodge_chance=mem1;
            }
            spelltype=4;
        }
    }
    if(spelltype!=2)
        dodge_chance=rand()%100;
    if(dodge_chance<75)
    {
        int old=healthPower;
        //cout<<"i="<<i<<", defence="<<defence<<endl;
        i=i-defence;
        if(i<0) i=0;
        healthPower=healthPower-i;
        if(healthPower<=0){
            healthPower=0;
            cout << "\u001b[32m" << get_name() << " was killed."<< RESET << endl;
        }
        else if(old-healthPower>0)
            cout << "\u001b[32m" << get_name() << "'s healthPower was brought down from " << old << " to " << healthPower << "."<< RESET << endl;
        else if(old-healthPower<=0)
            cout << "\u001b[31m" << get_name() << " didn't lose an ounce of HP." << RESET << endl;
        if(type==0)
        {
           spelltype=0;
           mem1=defence;
           defence=defence-j;
           spell_rounds_left=rounds_left;
           cout << "\u001b[32m" << get_name() << "'s defence was brought down from " << mem1 << " to " << defence << " for " << spell_rounds_left << " rounds." << RESET << endl;
        }
        else if(type==1)
        {
            spelltype=1;
            mem1=damage->get_min();
            mem2=damage->get_max();
            cout << "\u001b[32m" << get_name() << "'s damage range was brought down from [" << damage->get_min() << "," << damage->get_max();
            damage->lower_range(j,j);
            spell_rounds_left=rounds_left;
            cout << "\u001b[32m" << "] to [" << damage->get_min() << "," <<  damage->get_max() << "] for " << spell_rounds_left << " rounds." << RESET << endl;
        }
        else if(type==2)
        {
            spelltype=2;
            mem1=dodge_chance;
            dodge_chance=dodge_chance-j;
            spell_rounds_left=rounds_left;
            cout << "\u001b[32m" << get_name() << "'s dodge chance was brought down for " << spell_rounds_left << " rounds."<< RESET << endl;
        }
    }
    else
        cout << "\u001b[31m" <<  get_name() << " dodged your attack. "<< RESET << endl;
}
////////////////////////////////////////////////////////////////////////////////
Spirit::Spirit(string nam)
{
    name=nam;
    level=0;
    healthPower=50;
    damage=new range( rand() % 5 + 5 , rand() % 5 + 15 );
    defence=rand()%2;
    dodge_chance=rand()%120;
    spell_rounds_left=0;
    spelltype=4;
    //cout << "A Spirit has been created!" << ", named " << name << endl;
    //ευνοημένο  στο  πόσο  συχνά  αποφεύγει  επιθέσεις  του αντιπάλου του.
}

void Spirit::defend(int type, int i, int rounds_left, int j)
{
    if(spell_rounds_left>0){
        spell_rounds_left=spell_rounds_left-1;
        if((spell_rounds_left==0)&&(spelltype<=2))
        {
            cout << "\u001b[31mThe effect of the spell on " << get_name() << " has worn out. His stats shall go back to normal "  << endl;
            if(spelltype==0)
            {
                defence=mem1;
            }
            else if(spelltype==1)
            {
                damage->set_min(mem1);
                damage->set_max(mem2);
            }
            else if(spelltype==2)
            {
                dodge_chance=mem1;
            }
            spelltype=4;
        }
    }
    if(spelltype!=2)
        dodge_chance=rand()%100;
    if(dodge_chance<75)
    {
        int old=healthPower;
        //cout<<"i="<<i<<", defence="<<defence<<endl;
        i=i-defence;
        if(i<0) i=0;
        healthPower=healthPower-i;
        if(healthPower<=0){
            healthPower=0;
            cout << "\u001b[32m" << get_name() << " was killed."<< RESET << endl;
        }
        else if(old-healthPower>0)
            cout << "\u001b[32m" << get_name() << "'s healthPower was brought down from " << old << " to " << healthPower << "."<< RESET << endl;
        else if(old-healthPower<=0)
            cout << "\u001b[31m" << get_name() << " didn't lose an ounce of HP." << RESET << endl;
        if(type==0)
        {
           spelltype=0;
           mem1=defence;
           defence=defence-j;
           spell_rounds_left=rounds_left;
           cout << "\u001b[32m" << get_name() << "'s defence was brought down from " << mem1 << " to " << defence << " for " << spell_rounds_left << " rounds." << RESET << endl;
        }
        else if(type==1)
        {
            spelltype=1;
            mem1=damage->get_min();
            mem2=damage->get_max();
            cout << "\u001b[32m" << get_name() << "'s damage range was brought down from [" << damage->get_min() << "," << damage->get_max();
            damage->lower_range(j,j);
            spell_rounds_left=rounds_left;
            cout << "\u001b[32m" << "] to [" << damage->get_min() << "," <<  damage->get_max() << "] for " << spell_rounds_left << " rounds." << RESET << endl;
        }
        else if(type==2)
        {
            spelltype=2;
            mem1=dodge_chance;
            dodge_chance=dodge_chance-j;
            spell_rounds_left=rounds_left;
            cout << "\u001b[32m" << get_name() << "'s dodge chance was brought down for " << spell_rounds_left << " rounds."<< RESET << endl;
        }
    }
    else
        cout << "\u001b[31m" <<  get_name() << " dodged your attack. "<< RESET << endl;
}
////////////////////////////////////////////////////////////////////////////////
void Hero::addItemtoInventory(Item* temp)
{
    items[nitems]=temp;
    nitems++;
}

void Hero::addSpelltoInventory(Spell* temp)
{
    spells[nspells]=temp;
    nspells++;
}

void Hero::rmItemfromInventory(Item* temp)
{
    string name=temp->get_name();
    int pos=nitems+1;
    for(int i=0; i<nitems; i++)
        if(name==items[i]->get_name())
            pos=i;
    if((pos!=nitems+1)&&(nitems>=2))
    {
        items[pos]=items[nitems-1];
        items[nitems-1]=NULL;
        nitems--;
    }
    else if(nitems==1)
    {
        items[0]=NULL;
        nitems=0;
    }
}

void Hero::put_on(Item* temp)
{
    if(temp->get_type()==5){
        gun=temp;
        cout << get_name() << " was succesfully equipped with the " << temp->get_name() << " weapon!" << endl;
    }
    if(temp->get_type()==4){
        armor=temp;
        cout << get_name() << " was succesfully equipped with the " << temp->get_name() << " armor!" << endl;
    }
}

void Hero::defend(int i)
{
    int j=0;
    if(armor!=NULL)
        j=armor->get_submem();
    if(i-j>0)
    {
        if(healthPower-(i-j)<=0){
            cout << "\u001b[31m" << get_name() << " was killed" << RESET << endl;
            healthPower=0;
        }
        else{
            cout << "\u001b[31m" << get_name() << "'s healthPower was lowered from " << healthPower;
            healthPower=healthPower-(i-j);
            cout << "\u001b[31m" << " to " << healthPower << RESET << endl;
        }
    }
    else
        cout << "\u001b[32m" << get_name() << " succesfully defended himself and the Squad!"  << RESET << endl;
}

void Hero::equip(int my)
{
  cout << RESET << endl;
  int eqcounter=0, mytype=0;
  Item** myitems;
  Item* temp;
  if(my==0)
      mytype=5;
  else
      mytype=4;
  for(int r=0; r<nitems; r++)
  {
      temp=get_item(r);
      if(temp->get_type()==mytype){
        eqcounter++;
      }
  }
  if(my==0)
  {
      if(eqcounter==0)
      {
          cout << "Sorry, you don't own no weapons" << endl;
          return;
      }
      else
          cout << "Here is the weapons you own. " << endl;
  }
  else
  {
      if(eqcounter==0)
      {
          cout << "Sorry, you don't own no armors" << endl;
          return;
      }
      else
          cout << "Here is the armors you own. " << endl;
  }
  myitems=new Item*[eqcounter];
  int c=0;
  for(int r=0; r<nitems; r++)
  {
      temp=get_item(r);
      if(temp->get_type()==mytype){
          myitems[c]=temp;
          c++;
      }
  }
  cout<<endl;
  cout<<" ";
  int i=1,j;
  int k=0;
  int l=0;
  int p=0;
  for(j = 0,i = 0; j <= 16*eqcounter; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
  for(i = 0; i <= 10; i++){
    if(i%10!=0){
      if((i%10)==2){
          cout << "  ";
          //cout<<(char)(i/4 +'A');
          //if(i/10<10)
          //    cout << i/10<<" ";
          //else
          //    cout << i/10;
      }
      else
          cout<<"  ";
    }
    //cout << "\033[31mbold red text\033[0m\n";
    for(j = 0; j <= 8*eqcounter; j++){
      if(i%10==0)
      {
        if(j==0)
            cout<<"  ";
        if(j%8==0)
            cout<<" ";
        else
            cout<<"---";
      }
      else{
        if(j%8==0)
            cout<<"|";
        else {
                if((i%10)==1){
                    if(j%8==1){
                        if (p<eqcounter)
                            myitems[p]->print_name();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<eqcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==2){
                   if(j%8==1){
                        if (p<eqcounter)
                            myitems[p]->print_price();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<eqcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==3){
                    if(j%8==1){
                        if (p<eqcounter)
                            myitems[p]->print_minlevel();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<eqcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==4){
                    if(j%8==1){
                        if (p<eqcounter)
                            myitems[p]->print_1();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<eqcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==5){
                    if(j%8==1){
                        if (p<eqcounter)
                            myitems[p]->print_2();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<eqcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==6){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else if((i%10)==7){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else{
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
        }
      }
    }
    if(i%10!=0){
      cout<<" ";
    }
    cout<<endl;
  }
  cout<<" ";
  for(j = 0,i = 0; j <= 16*eqcounter; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
  string choice;
  int eureka=0;
  int d;
  int number=eqcounter+1;
  while(!eureka)
  {
      if(my==0)
          cout<<"Choose the weapon thou shall equip thyself with" << endl;
      else
          cout<<"Choose the armor thou shall equip thyself with" << endl;
      getline(cin,choice);
      //cout << endl;
      for(int r=0; r<eqcounter; r++)
      {
          if(choice==myitems[r]->get_name()){
            eureka=1;
            number=r;
            break;
          }
          if(choice=="q")
              break;
      }
      if((eureka==0)&&(choice!="q")){
          if(my==0)
              cout<< "No weapon named '" << choice << "' in your inventory"<< endl;
          else
              cout<< "No armor named '" << choice << "' in your inventory"<< endl;
          cout << "Try again...  {";
          for(int j=0;j<eqcounter;j++)
          {
              cout << "'"<<myitems[j]->get_name()<< "'";
              if(j<eqcounter-1)
                  cout << ", ";
          }
          cout << "}\n"<<endl;
          cout << "If you want quit equipping type 'q' next time you 're asked" << endl;
      }
  }
  if(eureka==1)
      put_on(myitems[number]);
}

void Hero::rmSpellfromInventory(Spell* temp)
{
    string name=temp->get_name();
    int pos=nspells+1;
    for(int i=0; i<nspells; i++)
        if(name==spells[i]->get_name())
            pos=i;
    if((pos!=nspells+1)&&(nspells>=2))
    {
        spells[pos]=spells[nspells-1];
        spells[nspells-1]=NULL;
        nspells--;
    }
    else if(nspells==1)
    {
        spells[0]=NULL;
        nspells=0;
    }
}

int Hero::isInventoryEmpty()
{
    if((nitems==0)&&(nspells==0))
        return 1;
    else
        return 0;
}

void Hero::add_experience(int i)
{
    int currentlvl=level;
    experience=experience+i;
    if(level<5)
        level=abs(experience/7);
    else
        level=abs(experience/11);
    if(level-currentlvl>0)
        levelUp(level-currentlvl);
}

void Hero::checkInventory(int size)
{
  if((nitems==0)&&(nspells==0))
  {
      cout << "\nSorry pal, your inventory is empty. Head to the nearest market" << endl;
      return;
  }
  cout << RESET << endl;
  cout<<" ";
  int i=1,j;
  int k=0;
  int l=0;
  int p=0;
  int pi=0;
  for(j = 0,i = 0; j <= 16*size; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
  for(i = 0; i <= 10*2; i++){
    if(i%10!=0){
      cout<<"  ";
    }
    //cout << "\033[31mbold red text\033[0m\n";
    for(j = 0; j <= 8*size; j++){
      if(i%10==0)
      {
        if(j==0)
            cout<<"  ";
        if(j%8==0)
            cout<<" ";
        else
            cout<<"---";
      }
      else{
        if(j%8==0)
            cout<<"|";
        else {

            if(i<10)
            {
                if((i%10)==1){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_name();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==2){
                   if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_price();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==3){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_minlevel();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==4){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_range();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==5){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_magiccost();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==6){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else if((i%10)==7){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else{
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
            }
            else
            {
              if((i%10)==1){
                  if(j%8==1){
                      if(pi<nitems)
                          items[pi]->print_name();
                      else
                          cout<<"\033[40m                     \033[0m";
                      if(pi<nitems-1)
                          pi++;
                      else
                          pi=0;
                  }
              }
              else if((i%10)==2){
                 if(j%8==1){
                      if(pi<nitems)
                          items[pi]->print_price();
                      else
                          cout<<"\033[40m                     \033[0m";
                      if(pi<nitems-1)
                          pi++;
                      else
                          pi=0;
                  }
              }
              else if((i%10)==3){
                  if(j%8==1){
                      if(pi<nitems)
                          items[pi]->print_minlevel();
                      else
                          cout<<"\033[40m                     \033[0m";
                      if(pi<nitems-1)
                          pi++;
                      else
                          pi=0;
                  }
              }
              else if((i%10)==4){
                  if(j%8==1){
                      if(pi<nitems)
                          items[pi]->print_1();
                      else
                          cout<<"\033[40m                     \033[0m";
                      if(pi<nitems-1)
                          pi++;
                      else
                          pi=0;
                  }
              }
              else if((i%10)==5){
                  if(j%8==1){
                      if(pi<nitems)
                          items[pi]->print_2();
                      else
                          cout<<"\033[40m                     \033[0m";
                      if(pi<nitems-1)
                          pi++;
                      else
                          pi=0;
                  }
              }
              else if((i%10)==6){
                  if(j%8==1)
                      cout<<"\033[40m                     \033[0m";
              }
              else if((i%10)==7){
                  if(j%8==1)
                      cout<<"\033[40m                     \033[0m";
              }
              else
                  if(j%8==1)
                      cout<<"\033[40m                     \033[0m";
            }
        }
      }
    }
    if(i%10!=0){
      cout<<" ";
    }
    cout<<endl;
  }
  cout<<" ";
  for(j = 0,i = 0; j <= 16*size; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
}

void Hero::attack(Monster* monstertemp)
{
  cout << RESET << endl;
  int wcounter=0;
  Item** myweapons;
  Item* temp;
  for(int r=0; r<nitems; r++)
  {
      temp=get_item(r);
      if(temp->get_type()==5){
        wcounter++;
      }
  }

  if(wcounter==0)
  {
      cout << "Sorry, you don't own no weapons" << endl;
      return;
  }
  else
      cout << "Here is the weapons you own. " << endl;
  myweapons=new Item*[wcounter];
  int c=0;
  for(int r=0; r<nitems; r++)
  {
      temp=get_item(r);
      if(temp->get_type()==5){
          myweapons[c]=temp;
          c++;
      }
  }
  cout<<endl;
  cout<<" ";
  int i=1,j;
  int k=0;
  int l=0;
  int p=0;
  for(j = 0,i = 0; j <= 16*wcounter; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
  for(i = 0; i <= 10; i++){
    if(i%10!=0){
      cout<<"  ";
    }
    //cout << "\033[31mbold red text\033[0m\n";
    for(j = 0; j <= 8*wcounter; j++){
      if(i%10==0)
      {
        if(j==0)
            cout<<"  ";
        if(j%8==0)
            cout<<" ";
        else
            cout<<"---";
      }
      else{
        if(j%8==0)
            cout<<"|";
        else {
                if((i%10)==1){
                    if(j%8==1){
                        if (p<wcounter)
                            myweapons[p]->print_name();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<wcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==2){
                   if(j%8==1){
                        if (p<wcounter)
                            myweapons[p]->print_price();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<wcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==3){
                    if(j%8==1){
                        if (p<wcounter)
                            myweapons[p]->print_minlevel();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<wcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==4){
                    if(j%8==1){
                        if (p<wcounter)
                            myweapons[p]->print_1();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<wcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==5){
                    if(j%8==1){
                        if (p<wcounter)
                            myweapons[p]->print_2();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<wcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==6){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else if((i%10)==7){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else{
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
        }
      }
    }
    if(i%10!=0){
      cout<<" ";
    }
    cout<<endl;
  }
  cout<<" ";
  for(j = 0,i = 0; j <= 16*wcounter; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
  string choice;
  int eureka=0;
  int d;
  int number=wcounter+1;
  while(!eureka)
  {
      cout<<"Choose the weapon thou shall use" << endl;
      getline(cin,choice);
      cout << endl;
      for(int r=0; r<wcounter; r++)
      {
          if(choice==myweapons[r]->get_name()){
            eureka=1;
            number=r;
            break;
          }
      }
      if(eureka==0){
          cout<< "No weapon named '" << choice << "' in your inventory"<< endl;
          cout << "Try again...  {";
          for(int j=0;j<wcounter;j++)
          {
              cout << "'"<<myweapons[j]->get_name()<< "'";
              if(j<wcounter-1)
                  cout << ", ";
          }
          cout << "}\n"<<endl;
      }
  }
  if(eureka==1){
      d=myweapons[number]->get_submem();
      monstertemp->defend(myweapons[number]->get_type(), d, 0,myweapons[number]->get_submem());
  }
}

void Hero::castSpell(Monster* monstertemp)
{
  cout << RESET << endl;
  if(nspells==0)
  {
      cout << "Sorry, you don't own no spells to cast." << endl;
      return;
  }
  else
      cout << "Here is the spells you own. " << endl;
  cout<<endl;
  cout<<" ";
  int i=1,j;
  int k=0;
  int l=0;
  int p=0;
  int pi=0;
  for(j = 0,i = 0; j <= 16*nspells; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
  for(i = 0; i <= 10; i++){
    if(i%10!=0){
      cout<<"  ";
    }
    //cout << "\033[31mbold red text\033[0m\n";
    for(j = 0; j <= 8*nspells; j++){
      if(i%10==0)
      {
        if(j==0)
            cout<<"  ";
        if(j%8==0)
            cout<<" ";
        else
            cout<<"---";
      }
      else{
        if(j%8==0)
            cout<<"|";
        else {
                if((i%10)==1){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_name();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==2){
                   if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_price();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==3){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_minlevel();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==4){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_range();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==5){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_magiccost();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==6){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else if((i%10)==7){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else{
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
        }
      }
    }
    if(i%10!=0){
      cout<<" ";
    }
    cout<<endl;
  }
  cout<<" ";
  for(j = 0,i = 0; j <= 16*nspells; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
  Spell* temp;
  string choice;
  int eureka=0;
  range* r;
  int d;
  while(1)
  {
      cout<<"Choose a spell to cast" << endl;
      getline(cin,choice);
      cout << endl;
      for(int r=0; r<nspells; r++)
      {
          temp=get_spell(r);
          if(choice==temp->get_name()){
            eureka=1;
            break;
          }
      }
      if(eureka==1){
          if(temp->get_magiccost()>magicPower){
              cout << "You need " << temp->get_magiccost() - magicPower << " more Magic Power to cast this spell.\n Try again." << endl;
              eureka=0;
          }
          else{
              cout << "Successfully casted the spell towards thy enemies" << endl;
              break;
          }
      }
  }
  if(eureka==1){
      r=temp->get_damagerange();
      d=r->get_exacto(dexterity);
      monstertemp->defend(temp->get_type(), d, temp->get_rounds(),temp->get_submem());
  }
}


void Hero::use()
{
  cout << RESET << endl;
  int pcounter=0;
  Item** mypotions;
  Item* temp;
  for(int r=0; r<nitems; r++)
  {
      temp=get_item(r);
      if(temp->get_type()==3){
        pcounter++;
      }
  }

  if(pcounter==0)
  {
      cout << "Sorry, you don't own no potions" << endl;
      return;
  }
  else
      cout << "Here is the potions you own. " << endl;
  mypotions=new Item*[pcounter];
  int c=0;
  for(int r=0; r<nitems; r++)
  {
      temp=get_item(r);
      if(temp->get_type()==5){
          mypotions[c]=temp;
          c++;
      }
  }
  cout<<endl;
  cout<<" ";
  int i=1,j;
  int k=0;
  int l=0;
  int p=0;
  for(j = 0,i = 0; j <= 16*pcounter; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
  for(i = 0; i <= 10; i++){
    if(i%10!=0){
      cout<<"  ";
    }
    //cout << "\033[31mbold red text\033[0m\n";
    for(j = 0; j <= 8*pcounter; j++){
      if(i%10==0)
      {
        if(j==0)
            cout<<"  ";
        if(j%8==0)
            cout<<" ";
        else
            cout<<"---";
      }
      else{
        if(j%8==0)
            cout<<"|";
        else {
                if((i%10)==1){
                    if(j%8==1){
                        if (p<pcounter)
                            mypotions[p]->print_name();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<pcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==2){
                   if(j%8==1){
                        if (p<pcounter)
                            mypotions[p]->print_price();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<pcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==3){
                    if(j%8==1){
                        if (p<pcounter)
                            mypotions[p]->print_minlevel();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<pcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==4){
                    if(j%8==1){
                        if (p<pcounter)
                            mypotions[p]->print_1();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<pcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==5){
                    if(j%8==1){
                        if (p<pcounter)
                            mypotions[p]->print_2();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<pcounter-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==6){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else if((i%10)==7){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else{
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
        }
      }
    }
    if(i%10!=0){
      cout<<" ";
    }
    cout<<endl;
  }
  cout<<" ";
  for(j = 0,i = 0; j <= 16*pcounter; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
  string choice;
  int eureka=0;
  int d;
  int number=pcounter+1;
  while(!eureka)
  {
      cout<<"Choose the potion thou shall use" << endl;
      getline(cin,choice);
      cout << endl;
      for(int r=0; r<pcounter; r++)
      {
          if(choice==mypotions[r]->get_name()){
            eureka=1;
            number=r;
            break;
          }
      }
      if(eureka==0){
          cout<< "No potion named '" << choice << "' in your inventory"<< endl;
          cout << "Try again...  {";
          for(int j=0;j<pcounter;j++)
          {
              cout << "'"<<mypotions[j]->get_name()<< "'";
              if(j<pcounter-1)
                  cout << ", ";
          }
          cout << "}\n"<<endl;
      }
  }
  if(eureka==1){
      d=mypotions[number]->get_submem();
      boost(d);
  }
}

void Hero::boost(int i)
{
    int stat=rand()%6;
    if(stat==0)
    {
      cout << get_name() << "'s healthPower was boosted from " << healthPower;
      healthPower=healthPower+i;
      cout << " to " << healthPower <<endl;
    }
    else if(stat==1)
    {
      cout << get_name() << "'s magicPower was boosted from " << magicPower;
      magicPower=magicPower+i;
      cout << " to " << magicPower <<endl;
    }
    else if(stat==2)
    {
      cout << get_name() << "'s strength was boosted from " << strength;
      strength=strength+i;
      cout << " to " << strength <<endl;
    }
    else if(stat==3)
    {
      cout << get_name() << "'s dexterity was boosted from " << dexterity;
      dexterity=dexterity+i;
      cout << " to " << dexterity <<endl;
    }
    else if(stat==4)
    {
      cout << get_name() << "'s agility was boosted from " << agility;
      agility=agility+i;
      cout << " to " << agility <<endl;
    }
    else if(stat==5)
    {
      cout << get_name() << "'s experience was boosted from " << experience;
      experience=experience+i;
      cout << " to " << experience <<endl;
    }
}

void Hero::displayStats()
{
    cout << "\033[0m\n\n" << get_name() << "'s stats are: " << endl << endl;
    cout << "level        ";
    float timh=level;
    int barWidth = 100;
    cout << "\u001b[33;1m\u2503";
    int pos = 1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 "  << RESET <<level << endl;

    cout << endl;
    cout << "healthPower  ";
    timh=healthPower;
    barWidth = 100;
    cout << "\u001b[33;1m\u2503";
    pos =1.25*1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 " << RESET << healthPower << endl;
    cout << endl;

    cout << "magicPower   ";
    timh=magicPower;
    barWidth = 100;
    cout << "\u001b[33;1m\u2503";
    pos =1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 " << RESET << magicPower << endl;
    cout << endl;

    cout << "strength     " ;
    timh=strength;
    barWidth = 100;
    cout << "\u001b[33;1m\u2503";
    pos =1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 " << RESET  << strength<< endl;
    cout << endl;

    cout << "dexterity    ";
    timh=dexterity;
    cout << "\u001b[33;1m\u2503";
    pos =1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 " << RESET << dexterity << endl;
    cout << endl;

    cout << "agility      ";
    timh=agility;
    cout << "\u001b[33;1m\u2503";
    pos =1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 " << RESET << agility<< endl;
    cout << endl;

    cout << "money        ";
    timh=money;
    cout << "\u001b[33;1m\u2503";
    pos =1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 " << RESET << money<< endl;
    cout << endl;

    cout << "experience   ";
    timh=experience;
    cout << "\u001b[33;1m\u2503";
    pos = 1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 " << RESET << experience<< endl;
    cout << endl;

    cout << "Owned spells ";
    timh=nspells;
    cout << "\u001b[33;1m\u2503";
    pos = 10*1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 " << RESET << nspells << endl;
    cout << endl;

    cout << "Owned items  ";
    timh=nitems;
    cout << "\u001b[33;1m\u2503";
    pos =10* 1.01*timh;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "\u001b[33;1m\u258A";
        else cout << "\u001b[33;1m\u2500";
    }
    cout << "\u001b[33;1m\u2503 " << RESET << nitems << endl;
}
////////////////////////////////////////////////////////////////////////////////

Warrior::Warrior(string nam)
{
    name=nam;
    level=0;
    healthPower=80;
    magicPower=50;
    strength=30;
    dexterity=10;
    agility=30;
    money=50;
    experience=0;
    items=new Item*[10];
    spells=new Spell*[10];
    nitems=0;
    nspells=0;
    gun=NULL;
    armor=NULL;
    /*for(int i=0; i<10; i++)
        spells[i]= new IceSpell(entry->get_entry("spell"));
    nspells=10;
    for(int i=0; i<5; i++)
        items[i]= new Weapon(entry->get_entry("weapon"));
    for(int i=5; i<10; i++)
        items[i]= new Armor(entry->get_entry("armor"));
    nitems=10;
    */
    //cout << "A Warrior has been created!" << ", named " << name << endl;
    //ευνοημένος στον τομέα της δύναμης και της ευκινησίας
}
////////////////////////////////////////////////////////////////////////////////
Paladin::Paladin(string nam)
{
    name=nam;
    level=0;
    healthPower=80;
    magicPower=50;
    strength=30;
    dexterity=30;
    agility=10;
    money=50;
    experience=0;
    items=new Item*[10];
    spells=new Spell*[10];
    nitems=0;
    nspells=0;
    gun=NULL;
    armor=NULL;
    /*for(int i=0; i<10; i++)
        spells[i]= new IceSpell(entry->get_entry("spell"));
    nspells=10;
    for(int i=0; i<5; i++)
        items[i]= new Weapon(entry->get_entry("weapon"));
    for(int i=5; i<10; i++)
        items[i]= new Armor(entry->get_entry("armor"));
    nitems=10;
    */
    //cout << "A Paladin has been created!" << ", named " << name << endl;
    //ευνοημένος στον τομέα της δύναμης και της επιδεξιότητας.
}
////////////////////////////////////////////////////////////////////////////////
Sorcerer::Sorcerer(string nam)
{
    name=nam;
    level=0;
    healthPower=80;
    magicPower=50;
    strength=10;
    dexterity=30;
    agility=30;
    money=50;
    experience=0;
    items=new Item*[10];
    spells=new Spell*[10];
    nitems=0;
    nspells=0;
    gun=NULL;
    armor=NULL;
    /*for(int i=0; i<10; i++)
        spells[i]= new IceSpell(entry->get_entry("spell"));
    nspells=10;
    for(int i=0; i<5; i++)
        items[i]= new Weapon(entry->get_entry("weapon"));
    for(int i=5; i<10; i++)
        items[i]= new Armor(entry->get_entry("armor"));
    nitems=10;
    */
    //cout << "A Sorcerer has been created!" << ", named " << name << endl;
    //ευνοημένος στον τομέα της επιδεξιότητας και της ευκινησίας.
}
////////////////////////////////////////////////////////////////////////////////
Squad::Squad(int v)
{

    //for(int i=0;i<3;i++){
    //  squad[i]= new Hero(str);
    if(v>=3)
    {
        heroes = new Hero*[3];
        heroes[0]=new Sorcerer(entry->get_entry("name"));
        heroes[1]=new Warrior(entry->get_entry("name"));
        heroes[2]=new Paladin(entry->get_entry("name"));
        n=3;
        cout << "                                                                                                      \033[36mThe squad of heroes has arrived!\033[0m";
        cout <<R"(
                                                                                                      ,   A
                                                                                                     / \, | ,        .--.
                                                                          .=.,                      |    =|= >      /.--.\
                                                                          ;c =\                      \ /` | `       |====|
                                                                        __|  _/                       `   |         |`::`|
                                                                      .'-'-._/-'-._                       |     .-;`\..../`;-.           |\
                                                                     /..           \                     /\\/  /  |...::...|  \           \\           ___
                                                                    /' _   <&>   )  \                    |:'\ |   /'''::'''\   |           \\         /___\
                                                                   (  / \--    -/'._ )                    \ /\;-,/\   ::   /\--;            \\        [+++]
                                                                    \-;_/\__;__/ _/ _/                    |\ <` >  >._::_.<,<__>             \\    _ _\^^^/_ _
                                                                     '._}|==o==\{_\/                      | `""`  /   ^^   \|  |              \\/ (    '-'  ( )
                                                                      /  /-._.--\  \_                     |       |        |\::/              /( \/ | {&}   /\ \
                                                                     // /   /|   \ \ \                    |       |        |/|||                \  / \     / _> )
                                                                    / | |   | \;  |  \ \                  |       |___/\___| '''                "`   >:::;-'`""'-.
                                                                   / /  | :/   \: \   \_\                 |        \_ || _/                         /:::/         \
                                                                  /  |  /.'|   /: |    \ \                |        <_ >< _>                        /  /||   {&}   |
                                                                  |  |  |--| . |--|     \_\               |        |  ||  |                       (  / (\         /
                                                                  / _/   \ | : | /___--._) \              |        |  ||  |                       / /   \'-.___.-'
                                                                 |_(---'-| >-'-| |       '-'              |       _\.:||:./_                    _/ /     \ \
                                                                        /_/     \_\                       |      /____/\____\                  /___|    /___|
         )" << '\n';
    }
    else if(v==2)
    {
        n=2;
        heroes = new Hero*[2];
        heroes[0]=new Sorcerer(entry->get_entry("name"));
        heroes[1]=new Warrior(entry->get_entry("name"));
        cout << "                                                                                                      \033[36mThe squad of heroes has arrived!\033[0m";
        cout <<R"(
                                                                                                                            ,   A
                                                                                                                           / \, | ,        .--.
                                                                                                .=.,                      |    =|= >      /.--.\
                                                                                                ;c =\                      \ /` | `       |====|
                                                                                              __|  _/                       `   |         |`::`|
                                                                                            .'-'-._/-'-._                       |     .-;`\..../`;-.
                                                                                           /..           \                     /\\/  /  |...::...|  \
                                                                                          /' _   <&>   )  \                    |:'\ |   /'''::'''\   |
                                                                                         (  / \--    -/'._ )                    \ /\;-,/\   ::   /\--;
                                                                                          \-;_/\__;__/ _/ _/                    |\ <` >  >._::_.<,<__>
                                                                                           '._}|==o==\{_\/                      | `""`  /   ^^   \|  |
                                                                                            /  /-._.--\  \_                     |       |        |\::/
                                                                                           // /   /|   \ \ \                    |       |        |/|||
                                                                                          / | |   | \;  |  \ \                  |       |___/\___| '''
                                                                                         / /  | :/   \: \   \_\                 |        \_ || _/
                                                                                        /  |  /.'|   /: |    \ \                |        <_ >< _>
                                                                                        |  |  |--| . |--|     \_\               |        |  ||  |
                                                                                        / _/   \ | : | /___--._) \              |        |  ||  |
                                                                                       |_(---'-| >-'-| |       '-'              |       _\.:||:./_
                                                                                              /_/     \_\                       |      /____/\____\
         )" << '\n';
    }
    else if(v==1)
    {
        n=1;
        heroes = new Hero*[1];
        heroes[0]=new Warrior(entry->get_entry("name"));
        cout << "                                                                                                      \033[36mYour hero has arrived on his own!\033[0m";
        cout <<R"(


                                                                                                                      .=.,
                                                                                                                      ;c =\
                                                                                                                    __|  _/
                                                                                                                  .'-'-._/-'-._
                                                                                                                 /..           \
                                                                                                                /' _   <&>   )  \
                                                                                                               (  / \--    -/'._ )
                                                                                                               \-;_/\__;__/ _/ _/
                                                                                                                 '._}|==o==\{_\/
                                                                                                                  /  /-._.--\  \_
                                                                                                                 // /   /|   \ \ \
                                                                                                                / | |   | \;  |  \ \
                                                                                                               / /  | :/   \: \   \_\
                                                                                                              /  |  /.'|   /: |    \ \
                                                                                                              |  |  |--| . |--|     \_\
                                                                                                              / _/   \ | : | /___--._) \
                                                                                                             |_(---'-| >-'-| |       '-'
                                                                                                                    /_/     \_\
         )" << '\n';
    }


}

Squad::~Squad()
{
    for(int i=0; i<n; i++)
        delete heroes[i];
    delete[] heroes;
}
int Squad::isSquadHealthZero()
{
    for(int i=0; i<n; i++)
    {
        if(heroes[i]->get_healthPower()!=0)
            return 0;
    }
    return 1;
}

////////////////////////////////////////////////////////////////////////////////
Square::Square(int x,int y, int z, int w, int p)
{
   int v1 = rand() % 5 + 3;
   int v2 = rand() % 5 + 3;
   coords[0]=x;
   coords[1]=y;
   heroes=z;
   access=w;
   nheroes=p;
   int i=0;
   int chance;
   if(w==0){
        market=0;
        heroes=0;
        nitems=0;
        nspells=0;
   }
   else
        market=rand() % 2;
   if(z==1){
      market=1;
      heroes=1;
      access=1;
   }
   while(!nmonsters)
      nmonsters = rand() % p+abs(p/2)+1;
   monsters=new Monster*[nmonsters];
   for(i=0;i<nmonsters;i++)
   {
       chance=rand() % 3;
       if(chance==0)
       {
           monsters[i]= new Dragon(entry->get_entry("name"));
       }
       else if(chance==1)
       {
           monsters[i]= new Exoskeleton(entry->get_entry("name"));
       }
       else if(chance==2)
       {
           monsters[i]= new Spirit(entry->get_entry("name"));
       }
   }
   if(market==1)
   {
        nitems=v1;
        nspells=v2;
        items=new Item*[v1];
        for(i=0;i<v1;i++)
        {
            chance=rand() % 3;
            if(chance==0)
            {
                items[i]= new Potion(entry->get_entry("potion"));
            }
            else if(chance==1)
            {
                items[i]= new Armor(entry->get_entry("armor"));
            }
            else if(chance==2)
            {
                items[i]= new Weapon(entry->get_entry("weapon"));
            }
        }
        spells=new Spell*[v2];
        for(i=0;i<v2;i++)
        {
            chance=rand() % 3;
            if(chance==0)
            {
                spells[i]= new IceSpell(entry->get_entry("spell"));
            }
            else if(chance==1)
            {
                spells[i]= new FireSpell(entry->get_entry("spell"));
            }
            else if(chance==2)
            {
                spells[i]= new LightningSpell(entry->get_entry("spell"));
            }
        }
   }
}

Square::~Square()
{
    int i=0;
    if(market==1)
    {
        for(i=0;i<nspells;i++)
            delete spells[i];
        delete[] spells;
        for(i=0;i<nitems;i++)
            delete items[i];
        delete[] items;
    }
    for(i=0;i<nmonsters;i++)
        delete monsters[i];
    delete[] monsters;
}

int Square::fight(Squad* squad)
{
    int lost=0;
    int round=0;
    Hero* temp;
    cout << "\u001b[33;1m                   LET THE FIGHT BEGIN!!                                      " <<  endl;
    cout << "\u001b[37;1m";
    cout << R"(
    n                                                                 :.
    E%                                                                :"5
    z  %                                                              :" `
    K   ":                                                           z   R
    ?     %.                                                       :^    J
    ".    ^s                                                     f     :~
     '+.    #L                                                 z"    .*
       '+     %L                                             z"    .~
         ":    '%.                                         .#     +
           ":    ^%.                                     .#`    +"
             #:    "n                                  .+`   .z"
               #:    ":                               z`    +"
                 %:   `*L                           z"    z"
                   *:   ^*L                       z*   .+"
                     "s   ^*L                   z#   .*"
                       #s   ^%L               z#   .*"
                         #s   ^%L           z#   .r"
                           #s   ^%.       u#   .r"
                             #i   '%.   u#   .@"
                               #s   ^%u#   .@"
                                 #s x#   .*"
                                  x#`  .@%.
                                x#`  .d"  "%.
                              xf~  .r" #s   "%.
                        u   x*`  .r"     #s   "%.  x.
                        %Mu*`  x*"         #m.  "%zX"
                        :R(h x*              "h..*dN.
                      u@NM5e#>                 7?dMRMh.
                    z$@M@$#"#"                 *""*@MM$hL
                  u@@MM8*                          "*$M@Mh.
                z$RRM8F"                             "N8@M$bL
               5`RM$#                                  'R88f)R
               'h.$"                                     #$x*
    )" << '\n';
    //cout << "\u001b["<< endl;

    /*cout << "\n\u001b[33;1m                                  The squad is bravely fighting with the monsters...!" << endl;
    cout << "\n";
    float progress = 0.0;
    int b=254;
    while (progress <= 1.01) {
        usleep(50000);
        int barWidth = 100;
        cout << "\u001b[33;1m\u2503";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) cout << "\u001b[33;1m\u258A";
            else if (i == pos) cout << ">";
            else cout << "\u001b[33;1m\u2500";
        }
        cout << "\u001b[33;1m\u2503 " << int(progress * 100.0) << " %\r";
        cout.flush();
        progress += 0.01;
    }
    cout << "\u001b[\n\n"<< endl;
    */
    int chance=0;
    int choice=nmonsters+1;
    string action;
    int t=0;
    int dead=0;
    int leave=0;
    while(!(squad->isSquadHealthZero()))
    {
        cout << "\u001b[33;1m\u001b[1000D                   ROUND " << round << "!" <<  endl;
        int j=0;
        //if(nmonsters==0)
        //    cout << "NOMONSTERS" << endl;
        for(int i=0; i<nmonsters; i++){
            if(monsters[i]->get_healthPower()==0)
                j++;
        }
        if((j==nmonsters)&&(j!=0)){
            lost=1;
            break;
        }
        j=0;
        for(int i=0; i<nheroes; i++){
            temp = squad->get_hero(i);
            if(temp->get_healthPower()==0)
                j++;
        }
        if((j==nheroes)&&(j!=0)){
            lost=0;
            break;
        }
        cout << "                   Fight!" << endl;
        if(round%2==0)
        {
            cout << "\u001b[33;1m\u001b[1000D                   It's the heroes' turn !" << RESET << endl;
            for(int i=0; i<nheroes; i++)
            {
                choice=nmonsters+1;
                t=rand()%nmonsters;
                if(monsters[t]->get_healthPower()>0)
                    choice=t;
                if(choice==nmonsters+1)
                    for(int k=0; k<nmonsters; k++)
                    {
                        if(monsters[k]->get_healthPower()!=0)
                              choice=k;
                    }
                chance=0;
                temp = squad->get_hero(i);
                if(temp->get_healthPower()>0)
                    while(1)
                    {
                        cout << endl << temp->get_name() << " what is your move?" << endl;
                        cout << "\u001b[34mYour options are {'attack','castSpell','use','changegun','changearmor','displayStats','no'} or 'q' to quit the battle." << RESET << endl;
                        //usleep(5000000);
                        //cout << "\u001b[1000D" << flush;
                        getline(cin,action);
                        //cout << endl;
                        //cout << "\u001b[2K\u001b[2K" << flush;  //must clear two lines
                        if((action=="attack")||(action=="at"))
                        {
                            temp->attack(monsters[choice]);
                            chance++;
                            break;
                        }
                        else if((action=="castSpell")||(action=="cast")||(action=="spell")||(action=="ca"))
                        {
                            temp->castSpell(monsters[choice]);
                            chance++;
                            break;
                        }
                        else if((action=="use")||(action=="potion")||(action=="us"))
                        {
                            temp->use();
                            chance++;
                            break;
                        }
                        else if((action=="gun")||(action=="changegun")||(action=="gu"))
                        {
                            temp->equip(0);
                            chance++;
                            break;
                        }
                        else if((action=="armor")||(action=="changearmor")||(action=="arm"))
                        {
                            temp->equip(1);
                            chance++;
                            break;
                        }
                        else if((action=="nothing")||(action=="nada")||(action=="no")||(action=="n"))
                        {
                            chance++;
                            break;
                        }
                        else if((action=="displayStats")||(action=="displaystats")||(action=="stats")||(action=="Stats")||(action=="disp"))
                        {
                            displayStats(squad);
                            if(chance==0)
                                continue;
                            else
                                break;
                        }
                        else if(action=="q")
                        {
                            return 0;
                        }
                        else
                        {
                            cout << "Doesn't make sense. Try again\nIf you dont wish to act, type 'nothing'" << endl;
                            continue;
                        }
                    }

            }
        }
        else
        {
            cout << "\u001b[33;1m\u001b[1000D                   It's the monsters' turn !" << RESET << endl;
            for(int i=0; i<nheroes; i++)
            {
                chance=0;
                temp = squad->get_hero(i);
                if(temp->get_healthPower()>0)
                {
                    while(1)
                    {
                        cout << endl << temp->get_name() << ", do you wish to act? " << endl;
                        cout << "\u001b[34mYour options are {'changegun','changearmor','displayStats','no'} or 'q' to quit the battle." << RESET << endl;
                        //usleep(5000000);
                        //cout << "\u001b[1000D" << flush;
                        getline(cin,action);
                        //cout << endl;
                        //cout << "\u001b[2K\u001b[2K" << flush;  //must clear two lines
                        if((action=="gun")||(action=="changegun")||(action=="gu"))
                        {
                            temp->equip(0);
                            chance++;
                            break;
                        }
                        else if((action=="armor")||(action=="changearmor")||(action=="arm"))
                        {
                            temp->equip(1);
                            chance++;
                            break;
                        }
                        else if((action=="nothing")||(action=="nada")||(action=="no")||(action=="n"))
                        {
                            chance++;
                            break;
                        }
                        else if((action=="displayStats")||(action=="displaystats")||(action=="stats")||(action=="Stats")||(action=="disp"))
                        {
                            displayStats(squad);
                            if(chance==0)
                                continue;
                            else
                                break;
                        }
                        else if(action=="q")
                        {
                            return 0;
                        }
                        else
                        {
                            //cout << "Doesn't make sense. Try again\nIf you dont want to do anything, type 'no'" << endl;
                            //continue;
                            cout << "Doesn't make sense." << endl;
                            break;
                        }
                    }
                }
            }
            for(int i=0; i<nmonsters; i++)
            {
                dead=0;
                choice=nheroes+1;
                t=rand()%nmonsters;
                temp = squad->get_hero(t);
                if(temp->get_healthPower()>0)
                    choice=t;
                if(choice==nheroes+1)
                    for(int k=0; k<nheroes; k++)
                    {
                        temp = squad->get_hero(t);
                        if(temp->get_healthPower()>0)
                            choice=t;
                        else dead++;
                    }
                if(dead==nheroes){
                    lost=0;
                    break;
                }
                if(monsters[i]->get_healthPower()>0)
                {
                    temp = squad->get_hero(choice);
                    temp->defend(monsters[i]->attack());
                }
            }
        }
        cout << "\nDo you want to display some stats? \u001b[34m[y/n]" << RESET << endl;
        getline(cin,action);
        //cout << endl;
        if((action=="yes")||(action=="y"))
        {
            displayStats(squad);
        }
        cout << "\u001b[33;1m\u001b[1000D                   END OF ROUND " << round << "!\n" << RESET << endl;
        round++;

    }
    int lvl;
    for(int i=0; i<nheroes; i++)
    {
        temp = squad->get_hero(i);
        if(temp->get_healthPower()==0)
            temp->set_healthPower(40);
    }
    if(lost==0)
    {
        cout << "\u001b[31;1mMonsters won!" << RESET << endl;
        for(int i=0; i<nheroes; i++)
        {
            temp = squad->get_hero(i);
            temp->sub_money(temp->get_money()/2);
        }
    }
    else if(lost==1)
    {
        cout << "\u001b[32;1mHeroes won!" << RESET << endl;
        for(int i=0; i<nheroes; i++)
        {
            temp = squad->get_hero(i);
            lvl=temp->get_level();
            temp->add_experience(2*lvl*nmonsters);
            if(lvl>=2)
                lvl=abs((lvl-2)*0.5+2);
            temp->add_money(5*lvl*nmonsters);
            cout << temp->get_name() << " now has " << temp->get_money() << "$." << endl;
            cout << temp->get_name() << " now has " << temp->get_experience() << "XP." << endl;
        }
    }
    return 1;
}

void Square::displayStats(Squad* squad)
{
    cout << RESET << "\u001b[31m\nMonsters' stats: "<< endl;
    for(int i=0; i<nmonsters; i++)
    {
        monsters[i]->displayStats();
    }
    cout << RESET << "\u001b[32m\nHeroes' stats: "<< endl;
    for(int i=0; i<nheroes; i++)
    {
        (squad->get_hero(i))->displayStats();
    }
    cout << RESET;
}

void Square::displayMarket(int size)
{
  cout<<endl;
  cout << "\n\u001b[37;1m                                                               THE MARKET!\n"<< RESET << endl;
  cout<<" ";
  int i=1,j;
  int k=0;
  int l=0;
  int p=0;
  int pi=0;
  for(j = 0,i = 0; j <= 16*size; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
  for(i = 0; i <= 10*2; i++){
    if(i%10!=0){
      cout<<"  ";
    }
    //cout << "\033[31mbold red text\033[0m\n";
    for(j = 0; j <= 8*size; j++){
      if(i%10==0)
      {
        if(j==0)
            cout<<"  ";
        if(j%8==0)
            cout<<" ";
        else
            cout<<"---";
      }
      else{
        if(j%8==0)
            cout<<"|";
        else {

            if(i<10)
            {
                if((i%10)==1){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_cat();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==2){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_name();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==3){
                   if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_price();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==4){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_minlevel();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==5){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_range();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==6){
                    if(j%8==1){
                        if (p<nspells)
                            spells[p]->print_magiccost();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(p<nspells-1)
                            p++;
                        else
                            p=0;
                    }
                }
                else if((i%10)==7){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else{
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
            }
            else
            {
                if((i%10)==1){
                    if(j%8==1){
                        if(pi<nitems)
                            items[pi]->print_cat();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(pi<nitems-1)
                            pi++;
                        else
                            pi=0;
                    }
                }
                else if((i%10)==2){
                    if(j%8==1){
                        if(pi<nitems)
                            items[pi]->print_name();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(pi<nitems-1)
                            pi++;
                        else
                            pi=0;
                    }
                }
                else if((i%10)==3){
                   if(j%8==1){
                        if(pi<nitems)
                            items[pi]->print_price();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(pi<nitems-1)
                            pi++;
                        else
                            pi=0;
                    }
                }
                else if((i%10)==4){
                    if(j%8==1){
                        if(pi<nitems)
                            items[pi]->print_minlevel();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(pi<nitems-1)
                            pi++;
                        else
                            pi=0;
                    }
                }
                else if((i%10)==5){
                    if(j%8==1){
                        if(pi<nitems)
                            items[pi]->print_1();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(pi<nitems-1)
                            pi++;
                        else
                            pi=0;
                    }
                }
                else if((i%10)==6){
                    if(j%8==1){
                        if(pi<nitems)
                            items[pi]->print_2();
                        else
                            cout<<"\033[40m                     \033[0m";
                        if(pi<nitems-1)
                            pi++;
                        else
                            pi=0;
                    }
                }
                else if((i%10)==7){
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
                }
                else
                    if(j%8==1)
                        cout<<"\033[40m                     \033[0m";
            }
        }
      }
    }
    if(i%10!=0){
      cout<<" ";
    }
    cout<<endl;
  }
  cout<<" ";
  for(j = 0,i = 0; j <= 16*size; j++){
    if(j%16==0)
        k=0;
    if(j%16==5){
        cout<<"     ";
    }
    else{
        if(j>160)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<160)
            cout<<" ";
    }
  }
  cout<<endl;
}
////////////////////////////////////////////////////////////////////////////////
Grid::Grid(int N)
{

    SIZE=N;
    entry = new names();
    entry->readfiles();
    nheroes = rand() % 6 + 1;
    squad = new Squad(nheroes);
    gridp = new Square**[N];
    for (int i = 0; i < N; ++i) {
        gridp[i] = new Square*[N];
    }
    int access;
    location[0] = rand() % (N-1);
    location[1]= rand() % (N-1);

    cout << "\n\u001b[33;1m                                                                                                                   Loading..." << endl;
    cout << "\n";
    float progress = 0.0;
    int b=254;
    while (progress <= 1.01) {
        usleep(25000);
        //int barWidth = 161;
        int barWidth = 230;
        cout << "\u001b[33;1m\u2503";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) cout << "\u001b[33;1m\u258A";
            else if (i == pos) cout << ">";
            else cout << "\u001b[33;1m\u2500";
        }
        cout << "\u001b[33;1m\u2503 " << int(progress * 100.0) << " %\r";
        cout.flush();
        progress += 0.01;
    }
    cout << RESET << endl << endl;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            access=rand() % 8;
            if(location[0]==i&&location[1]==j){
                gridp[i][j] = new Square(i,j,1,1,nheroes);
                //if(access==0){
                //    location[0] = rand() %(N-i)+i;
                //    location[1] = rand() % (N-j)+j;
                //}
            }
            else
                gridp[i][j] = new Square(i,j,0,access,nheroes);
        }
    }
}

Grid::~Grid()
{
    for(int i = 0; i < SIZE; ++i)
        delete gridp[i];
    delete[] gridp;
    delete squad;
    delete entry;
}

void Grid::play()
{
    string action;
    string name;
    string cat;
    int n;
    int moved=0;
    int fought=0;
    Hero* temp;
    int found=0;
    while(1)
    {
        cout << "\033[1;34mplay\033[0m:\033[1;32m~\033[0m$ ";
        getline(cin,action);
        cout << endl;
        if(action=="quit"||action=="q")
            break;
        if(action=="checkInventory")
        {
            int k=9;
            while(1)
            {
                cout << "Type a hero's name." << endl;
                getline(cin,action);
                if(action=="q")
                    break;
                n=squad->getn();
                for(int j=0;j<n;j++)
                {
                    temp=squad->get_hero(j);
                    //cout << temp->get_name() << endl;
                    if(temp->get_name()==action){
                        k=j;
                        break;
                    }
                }
                if(k!=9)
                    break;
                cout << "No hero named " << action <<" in the squad" << endl;
                cout << "\u001b[34mChoose squad member to enter the shop [a hero's name]." << endl;
                cout << "{";
                for(int j=0;j<n;j++)
                {
                    temp=squad->get_hero(j);
                    cout << "'"<<temp->get_name()<< "'";
                    if(j<n-1)
                        cout << ", ";
                }
                cout << "}"<< RESET << endl;
            }
            temp->checkInventory(temp->dim());
        }
        else if(action=="equip")
        {
            int k=9;
            while(1)
            {
                cout << "Type a hero's name." << endl;
                getline(cin,action);
                if(action=="q")
                    break;
                n=squad->getn();
                for(int j=0;j<n;j++)
                {
                    temp=squad->get_hero(j);
                    //cout << temp->get_name() << endl;
                    if(temp->get_name()==action){
                        k=j;
                        break;
                    }
                }
                if(k!=9)
                    break;
                cout << "No hero named " << action <<" in the squad" << endl;
                cout << "\u001b[34mChoose squad member to enter the shop [a hero's name]." << endl;
                cout << "{";
                for(int j=0;j<n;j++)
                {
                    temp=squad->get_hero(j);
                    cout << "'"<<temp->get_name()<< "'";
                    if(j<n-1)
                        cout << ", ";
                }
                cout << "}"<< RESET << endl;
            }
            while(1)
            {
                cout << "Choose: \u001b[34m['armor'/'weapon']" << RESET << endl;
                getline(cin,action);
                if(action=="q")
                    break;
                if(action=="armor"){
                    temp->equip(1);
                    break;
                }
                if(action=="weapon"){
                    temp->equip(0);
                    break;
                }

            }
        }
        else if(action=="use")
        {
            int k=9;
            while(1)
            {
                cout << "Type a hero's name." << endl;
                getline(cin,action);
                if(action=="q")
                    break;
                n=squad->getn();
                for(int j=0;j<n;j++)
                {
                    temp=squad->get_hero(j);
                    //cout << temp->get_name() << endl;
                    if(temp->get_name()==action){
                        k=j;
                        break;
                    }
                }
                if(k!=9)
                    break;
                cout << "No hero named " << action <<" in the squad" << endl;
                cout << "\u001b[34mChoose squad member to enter the shop [a hero's name]." << endl;
                cout << "{";
                for(int j=0;j<n;j++)
                {
                    temp=squad->get_hero(j);
                    cout << "'"<<temp->get_name()<< "'";
                    if(j<n-1)
                        cout << ", ";
                }
                cout << "}"<< RESET << endl;

            }
            temp->use();
        }
        else if(action=="move")
        {
            displayMap();
            while(1)
            {
                cout << "\033[1;34mplay\033[0m:\033[1;32m~/move\033[0m$ ";
                //cin >> action;
                getline(cin,action);
                cout << endl;
                if(action=="quit"||action=="q")
                    break;
                moved=move(action);
                if(moved==1)
                {
                    moved=rand()%100;
                    if(moved>40)
                        fought=fight(squad);
                    moved=0;
                }
            }
        }
        else if(action=="market")
        {
            if(gridp[location[0]][location[1]]->market_in())
            {
                gridp[location[0]][location[1]]->displayMarket(gridp[location[0]][location[1]]->dim());
                while(1)
                {
                    int randomhero=4;
                    int first=1;
                    cout << "\033[1;34mplay\033[0m:\033[1;32m~/market\033[0m$ ";
                    //cin >> action;
                    getline(cin,action);
                    cout << endl;
                    if(action=="quit"||action=="q")
                        break;
                    if(action=="buy")
                    {
                        if(first==1)
                            first=0;
                        else
                            gridp[location[0]][location[1]]->displayMarket(gridp[location[0]][location[1]]->dim());
                        while(1)
                        {
                            cout << "\033[1;34mplay\033[0m:\033[1;32m~/market/buy\033[0m$ ";
                            //cin >> action;
                            getline(cin,action);
                            cout << endl;
                            if(action=="quit"||action=="q"){
                                break;
                            }
                            else
                            {
                                found=0;
                                n=squad->getn();
                                cout << "N ="<< n << endl;
                                for(int j=0;j<n;j++)
                                {
                                    temp=squad->get_hero(j);
                                    //cout << temp->get_name() << endl;
                                    name=temp->get_name();
                                    if(name==action){
                                        found=1;
                                        break;
                                    }
                                }
                                if(found==1)
                                {
                                    cout << temp->get_name() << " choose category: [Spell/Item]" << endl;
                                    getline(cin,cat);
                                    if(cat=="item"||cat=="Item"||cat=="spell"||cat=="Spell"){
                                        cout << action << " choose " << cat << " to buy: \u001b[34m[a " << cat << "'s name]" << RESET << endl;
                                        cout << temp->get_name() << " has " << temp->get_money() << "$ in his pocket. Spend it wisely!" << endl;
                                        getline(cin,name);
                                        cout << endl;
                                    }
                                    else if(cat=="quit"||cat=="q"){
                                        cout << endl;
                                        break;
                                    }
                                    else{
                                        cout << "market: "<< cat << " not found " << endl;
                                        continue;
                                    }
                                }
                                else
                                {
                                    cout << "No hero named " << action <<" in the squad" << endl;
                                    cout << "\u001b[34mChoose squad member to enter the shop [a hero's name]." << endl;
                                    cout << "{";
                                    for(int j=0;j<n;j++)
                                    {
                                        temp=squad->get_hero(j);
                                        cout << "'"<<temp->get_name()<< "'";
                                        if(j<n-1)
                                            cout << ", ";
                                    }
                                    cout << "}"<< RESET << endl;
                                    continue;
                                }

                            }
                            buy(temp,action,cat,name);
                        }
                    }
                    else if(action=="sell")
                    {
                        while(1)
                        {
                          cout << "\033[1;34mplay\033[0m:\033[1;32m~/market/sell\033[0m$ ";
                          //cin >> action;
                          getline(cin,action);
                          cout << endl;
                          if(action=="quit"||action=="q"){
                              break;
                          }
                          else
                          {

                              n=squad->getn();
                              found=0;
                              for(int j=0; j<n; j++)
                              {
                                  temp=squad->get_hero(j);
                                  if(temp->get_name()==action){
                                      found=1;
                                      break;
                                  }
                              }
                              if(found==1)
                              {
                                  if(temp->isInventoryEmpty()){
                                      cout << temp->get_name() << "'s inventory is empty. Choose another hero." <<endl;
                                      continue;
                                  }
                                  temp->checkInventory(temp->dim());
                                  cout << temp->get_name() << " Name the category of the stuff you have for sale: \u001b[34m[Spell/Item]" << RESET << endl;
                                  getline(cin,cat);
                                  if(cat=="item"||cat=="Item"||cat=="spell"||cat=="Spell"){
                                      cout << action << " choose " << cat << " to sell: [the " << cat << "'s name]" << endl;
                                      getline(cin,name);
                                      cout << endl;
                                  }
                                  else if(cat=="quit"||cat=="q"){
                                      cout << endl;
                                      break;
                                  }
                                  else{
                                      cout << "market: "<< cat << " not found " << endl;
                                      continue;
                                  }
                              }
                              else
                              {
                                  cout << "No hero named " << action <<" in the squad" << endl;
                                  cout << "\u001b[34mChoose squad member to enter the shop [a hero's name]." << endl;
                                  cout << "{";
                                  for(int j=0;j<n;j++)
                                  {
                                      temp=squad->get_hero(j);
                                      cout << "'"<<temp->get_name()<< "'";
                                      if(j<n-1)
                                          cout << ", ";
                                  }
                                  cout << "}"<< RESET << endl;
                                  continue;
                              }

                          }
                          sell(temp,action,cat,name);
                        }
                    }
                    else
                    {
                        cout << "market: " << action << ": command not found" << endl;
                        cout << "\u001b[34mYou want to buy or sell [buy/sell]?" << endl;
                        cout << "\u001b[34mType 'q' to quit." << RESET << endl;
                    }
                }
            }
            else{
                cout << "\a";
                cout << "play: no market in this square" << endl;
            }
        }
        else{
            cout << "\a";
            cout << "play: "<< action <<": command not found" << endl;
            cout << "\u001b[34mYou could type 'move' , 'market' , 'checkInventory' , 'equip' , 'use' or 'q' to quit." << RESET<< endl;
        }
    }

}

int Grid::fight(Squad* s)
{
    return gridp[location[0]][location[1]]->fight(s);
}

int Grid::buy(Hero* temp,string hero,string cat,string name)
{
    int i=0;
    int fail=0;
    int fail2=0;
    Item* tempi=NULL;
    Spell* temps=NULL;
    if(cat=="item"||cat=="Item")
    {
        for(i=0;i<gridp[location[0]][location[1]]->nitems;i++)
        {
            //cout << "iter " << i << " out of " <<  gridp[location[0]][location[1]]->nitems-1 << endl;
            tempi=gridp[location[0]][location[1]]->get_item(i);
            //cout << name==tempi->get_name() << temp->get_money() << tempi->get_price() << temp->get_level()<<tempi->get_minlevel();
            if((name==tempi->get_name())&&(temp->get_money()>=tempi->get_price())&&(temp->get_level()>=tempi->get_minlevel()))
            {
                //cout << name << tempi->get_name();
                cout << " You successfully bought ";
                tempi->print_name();
                cout << endl;
                temp->sub_money(tempi->get_price());
                temp->addItemtoInventory(tempi);
                cout << temp->get_name() << " now has " << temp->get_money() << "$ in his pocket. " << temp->dim()<< endl;
                temp->checkInventory(temp->dim());
                temp->put_on(tempi);
                break;
            }
            else if((name==tempi->get_name())&&(temp->get_money()<tempi->get_price())){
                cout << "You don't have enough money to buy the " << name << endl;
                fail2++;
                break;
            }
            else if((name==tempi->get_name())&&(temp->get_level()<tempi->get_minlevel())){
                cout << "You need to level up from level " << temp->get_level() << " to " << tempi->get_minlevel() << " in order to acquire the " << cat << " " << name << endl;
                fail2++;
                break;
            }
            else if(name!=tempi->get_name())
                fail++;
        }
        if((fail==gridp[location[0]][location[1]]->nitems)&&(fail2==0))
            cout << "error: There is no item named " << name << endl;
    }
    else if(cat=="spell"||cat=="Spell")
    {
        for(i=0;i<gridp[location[0]][location[1]]->nspells;i++)
        {
            temps=gridp[location[0]][location[1]]->get_spell(i);
            //cout << name==tempi->get_name() << temp->get_money() << tempi->get_price() << temp->get_level()<<tempi->get_minlevel();
            if((name==temps->get_name())&&(temp->get_money()>=temps->get_price())&&(temp->get_level()>=temps->get_minlevel()))
            {
                //cout << name << temps->get_name();
                cout << " You successfully bought ";
                temps->print_name();
                cout << endl;
                temp->sub_money(temps->get_price());
                temp->addSpelltoInventory(temps);
                cout << temp->get_name() << " now has " << temp->get_money() << "$ in his pocket. " << temp->dim()<< endl;
                temp->checkInventory(temp->dim());
                break;
            }
            else if((name==temps->get_name())&&(temp->get_money()<temps->get_price())){
                cout << "You don't have enough money to buy the " << name << endl;
                fail2++;
                break;
            }
            else if((name==temps->get_name())&&(temp->get_level()<temps->get_minlevel())){
                cout << "You need to level up from level " << temp->get_level() << " to " << temps->get_minlevel() << " in order to acquire the " << cat << " " << name << endl;
                fail2++;
                break;
            }
            else if(name!=temps->get_name())
                fail++;
        }
        if((fail==gridp[location[0]][location[1]]->nspells)&&(fail2==0))
            cout << "error: There is no spell named " << name << endl;
    }
    return 1;
}

int Grid::sell(Hero* temp,string hero,string cat,string name)
{
    int i=0;
    Item* tempi;
    Spell* temps;
    int cash;
    if(cat=="item")
    {
        for(i=0;i<gridp[location[0]][location[1]]->nitems;i++)
        {
            tempi=gridp[location[0]][location[1]]->get_item(i);
            if(name==tempi->get_name()){
                cout << hero << " successfully sold ";
                tempi->print_name();
                cash=tempi->get_price();
                temp->add_money(cash/2);
                temp->rmItemfromInventory(tempi);
                cout << endl;
                break;
              }
        }
    }
    else if(cat=="spell")
    {
        for(i=0;i<gridp[location[0]][location[1]]->nspells;i++)
        {
            temps=gridp[location[0]][location[1]]->get_spell(i);
            if(name==temps->get_name())
            {
                cout << hero << " successfully sold ";
                temps->print_name();
                cash=temps->get_price();
                temp->add_money(cash/2);
                temp->rmSpellfromInventory(temps);
                cout << endl;
                break;
            }
        }
    }
    return 1;
}
int Grid::move(string where)
{
    char a,b,c;
    if(where.length()>2){
        a = where.at(0);
        b = where.at(1);
        c = where.at(2);
    }
    if((where=="up")||(a==27)&&(b==91)&&(c==65))
    {
        if(location[0]>=1)
            if(gridp[location[0]-1][location[1]]->accessible())
            {
                gridp[location[0]][location[1]]->unset_heroes();
                gridp[location[0]-1][location[1]]->set_heroes();
                location[0]=location[0]-1;
                displayMap();
                cout << "Moved up" << endl;
                return 1;
            }
            else{
                cout << "\a";
                cout << "Non accessible square" << endl;
                return 0;
            }
        else if(location[0]<1){
            cout << '\a';
            cout << "Can't set foot outside the grid.."<<endl;
            return 0;
        }
    }
    else if((where=="down")||(a==27)&&(b==91)&&(c==66))
    {
        if(location[0]<SIZE)
            if(gridp[location[0]+1][location[1]]->accessible())
            {
                gridp[location[0]][location[1]]->unset_heroes();
                gridp[location[0]+1][location[1]]->set_heroes();
                location[0]=location[0]+1;
                displayMap();
                cout << "Moved down" << endl;
                return 1;
            }
            else{
                cout << "\a";
                cout << "Non accessible square" << endl;
                return 0;
            }
        else{
            cout << '\a';
            cout << "Can't set foot outside the grid.."<<endl;
            return 0;
        }
    }
    else if((where=="right")||(a==27)&&(b==91)&&(c==67))
    {
        if(location[1]<SIZE)
            if(gridp[location[0]][location[1]+1]->accessible())
            {
                gridp[location[0]][location[1]]->unset_heroes();
                gridp[location[0]][location[1]+1]->set_heroes();
                location[1]=location[1]+1;
                displayMap();
                cout << "Moved right" << endl;
                return 1;

            }
            else{
                cout << "\a";
                cout << "Non accessible square" << endl;
                return 0;
            }
        else{
            cout << '\a';
            cout << "Can't set foot outside the grid.."<<endl;
            return 0;
        }
    }
    else if((where=="left")||(a==27)&&(b==91)&&(c==68))
    {
        if(location[1]>=1)
            if(gridp[location[0]][location[1]-1]->accessible())
            {
                gridp[location[0]][location[1]]->unset_heroes();
                gridp[location[0]][location[1]-1]->set_heroes();
                location[1]=location[1]-1;
                displayMap();
                cout << "Moved left" << endl;
                return 1;
            }
            else{
                cout << "\a";
                cout << "Non accessible square" << endl;
                return 0;
            }
        else{
            cout << '\a';
            cout << "Can't set foot outside the grid.."<<endl;
            return 0;
        }
    }
    else{
        cout << "\a";
        cout << "command not found" << endl;
        cout << "\u001b[34mUse your keyboard arrows to move throughout the grid [ \u2190 / \u2191 / \u2192 / \u2193 ] and press ENTER \u23ce \nOr press 'q' to quit" << RESET << endl;
        return 0;
    }
    return 0;
}

void Grid::displayMap()
{
  cout<<endl;
  cout<<" ";
  int i=1,j;
  int k=0;
  int l=0;
  for(j = 0,i = 0; j <= 12*SIZE; j++){
    if(j%12==0)
        k=0;
    if(j%12==5){
        cout<<"     ";
    }
    else{
        if(j>120)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<120)
            cout<<" ";
    }
  }
  cout<<endl;
  for(i = 0; i <= 4*SIZE; i++){
    if(i%4!=0){
      cout<<"  ";
    }
    //cout << "\033[31mbold red text\033[0m\n";
    for(j = 0; j <= 6*SIZE; j++){
      if(i%4==0)
      {
        if(j==0)
            cout<<"  ";
        if(j%6==0)
            cout<<" ";
        else cout<<"---";
      }
      else{
        if(j%6==0)
            cout<<"|";
        else {
            //cout<<"   ";
            if((i%4)==1){
                if(j%6==1)
                    //cout<<1<<"    ";
                    //if(rand() % 2)
                    //cout<<array[i/4][j/6]->coords[0]<<array[i/4][j/6]->coords[1];
                    //cout<<i/4<<" "<<j/6;
                    if(gridp[i/4][j/6]->heroesin()){
                        cout << "\033[1;35;47m Heroes Squad  \033[0m";}
                    else
                        //cout<<"\033[40               \033[0m";
                        cout<<"               ";
                //cout<<"  ";
            }

            if((i%4)==2){
                if(j%6==1)
                    //cout<<i/4<<"    ";
                    //if(rand() % 2)
                    if(gridp[i/4][j/6]->accessible())
                        //cout<<"Accessible     ";
                        cout << "\033[1;32mAccessible     \033[0m";
                    else
                        //cout<<"non Accessible!";
                        cout << "\033[1;31mnon Accessible!\033[0m";
                //cout<<"  ";
            }

            if((i%4)==3){
                if(j%6==1)
                    //cout<<3<<"    ";
                    //if(rand() % 2)
                    if (gridp[i/4][j/6]->accessible()==0)
                        //cout<<"\033[40m               \033[0m";
                        cout<<"               ";
                    else if(gridp[i/4][j/6]->market_in())
                        //cout<<"Has Market     ";
                        cout << "\033[1;32mHas Market     \033[0m";
                    else
                        //cout<<"No Market!     ";
                        cout << "\033[31mNo Market!     \033[0m";


                //cout<<"  ";
            }
            //if((i%4)!=2)
              //  cout<<" ";
        }
      }
    }
    if(i%4!=0){
      cout<<" ";
    }
    cout<<endl;
  }
  cout<<" ";
  for(j = 0,i = 0; j <= 12*SIZE; j++){
    if(j%12==0)
        k=0;
    if(j%12==5){
        cout<<"     ";
    }
    else{
        if(j>120)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<120)
            cout<<" ";
    }
  }
  cout<<endl;

  //for(i=0;i<10;i++)
  //{
  //    for(j=0;j<10;j++)
  //    {
  //        if(gridp[i][j]->market_in()){
  //            cout << "square: " << i << " "<<j << endl;
  //            gridp[i][j]->displayMarket(gridp[i][j]->dim());
  //        }
  //    }
  //}
}
