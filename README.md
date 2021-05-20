# Role-Playing-Game

In this project, I implement in C++ the simulation of a role playing game. The game
has objects, spells, heroes and monsters. Heroes and monsters live in a world that is
represented by a grid. Heroes can be involved in battles with monsters, where they
use objects and spells to defeat monsters, or they can buy objects
to help them in their adventure. Every time the heroes defeat some monsters they collect
some money and gain experience. When they gain enough experience, the heroes "go up"
a level, which means they become stronger in their individual abilities.
An item has a name, a purchase price and has a minimum level
in which the hero must be in order to use it. A weapon is an
object that can be used by the hero to attack a monster. It's got
a certain amount of damage that it inflicts on its opponent and may require one or more
two hands of the hero to use it. When a hero wears an armor, 
it reduces the damage he receives from an attack of his opponent. When a filter is 
used by a hero, it increases a statistic of his
to some extent. Filters are disposable, which means that after use,
can not be reused. A spell represents a magical attack that a hero can perform.
A spell has a name, a price, and some minimum level at which the hero must be
to use it. A spell has a range of damage that it can cause as well as one
amount of magic energy it takes to execute. After execution, this amount of magic
energy is removed by the hero. The level of damage caused by a spell depends on
value the hero's dexterity and is always within the specified range. An ice spell
is a spell which, in addition to the damage it causes, it also reduces the opponent's damage range
for some rounds. A FireSpell is a spell that, in addition to
the damage it causes, it reduces the amount of defense of the opponent for some rounds. A spell
is a spell which, in addition to causing damage, also reduces
the chance of the opponent avoiding an attack for some rounds.
A living being represents a living entity of the game world. he's got
a name, a level as well as an amount of vital energy. When
his vital energy gets to zero, the living being faints. A Hero is a
living being. It has an amount of magic energy, as well as some features
affecting his ability in battle. A hero has some strength value,
some value of dexterity as well as some value of agility. His power
is added to the amount of damage caused by a weapon, his dexterity allows him to perform them
spells more efficiently and finally his agility allows him to be able to somehow escape
some attack by his opponent. A hero has an amount of money as well as
an amount of experience. When the hero gains enough experience, he goes up a level. 
At each level, the values of the hero's strength, dexterity and agility,
increase by some amount. A Warrior is a hero who is favored in
in the field of strength and agility. This means that the initial values in these statistics,
are higher than the rest, and that when the hero's level rises, these statistics
will be more affected. A sorcerer is a hero who is favored
in the field of dexterity and agility. A knight is a hero who is
favored in the field of strength and dexterity.
A monster is a living being. It has a range of damage that it can cause
in each of his attacks, an amount of defense deducted from the damage he receives in an attack
of his opponent, and a chance to avoid an attack by his opponent. A dragon
is a monster that is favored in the range of damage it can cause. One being
with exoskeleton is a monster that is favored in the amount of defense it has.
A spirit is a monster that is favored in how often it avoids attacks
of his opponent. The game world is described by a grid of specific dimensions. 
At any given time the group of heroes (at least one and at most three) are in a
square of the grid and can be moved one square up, down,
right or left. The grid squares may not be accessible to the heroes, 
they can have a market or simply be common squares. The
heroes can not visit a square that is not accessible. Heroes can
buy items and spells in the market, if they have enough money.
They can also sell items and spells, that they own at half the price
they bought them. The transactions in this case are made through a suitable menu (in the market place of any square) where the
player is able to see all items that are for sale or for purchase as well
information about them. Finally, every time the
heroes are visiting a common square, there is a chance of getting involved in a battle with
monsters of a similar level to that of the heroes. The battle in this case happens automatically.
When heroes do not buy or sell items or fight, they can check the
items they own, use different weapons and armor or use a filter. 
The player can display information about his heroes at any time.
The player can display the grid at any time.
Information is then displayed for each square of the grid, such as if the heroes are in
this, if it is not accessible or if it has a market. The player can also pause the game.

Finally, a battle takes place between the heroes and some monsters. The battle takes place in rounds,
starting with the heroes, and does not stop until the vital energy of all the monsters arrives
or all the heroes to zero. If the battle ends because the heroes have won, then they win
some money based on their level and the number of monsters they encountered. also
each hero gains an amount of experience that is again commensurate with the level of the hero and the crowd
the monster. If the battle ends because the monsters have been defeated, the heroes lose half their money.
The heroes as well as the monsters regenerate in each round a certain amount of their vital energy
unless it has reached zero. Also, the heroes regenerate an amount of it in each round
their magical energy. If after the end of a battle a hero is left with zero vital energy, 
then it returns to half of his normal vital energy. During a battle, when it is 
the turn of the heroes, the player chooses for each hero if he will make a normal
attack, if he will attack with a spell or if he will use some filter. He could also change weapons and armor. 
Each hero can only perform one of the previous actions in each round. In each round, the player can see the
statistics of each hero and monster.

The game gets compiled as follows:

    g++ -o game game.cpp gamefunc.cpp


The game can be executed as follows:

    ./game
    
Enjoy!

