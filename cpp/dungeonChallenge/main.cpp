#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;

public:
    Creature(std::string name, char symbol, int health, int damage, int gold)
        : m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
    {
    }

    const std::string& getName() { return m_name; }
    char getSymbol() { return m_symbol; }
    int getHealth() { return m_health; }
    int getDamage() { return m_damage; }
    int getGold() { return m_gold; }

    void reduceHealth(int health) { m_health -= health; }
    bool isDead() { return m_health <= 0; }
    void addGold(int gold) { m_gold += gold; }
};

class Player : public Creature
{
private:
    int m_level = 1;
    int m_numToLevel = 1;
    char m_degree;
    int m_bonusDamage;
    int m_bonusHealth;

public:
    Player(std::string name, char degree)
        : Creature(name, '@', 10, 1, 0), m_degree(degree)
    {
        switch (m_degree)
        {
            case 'e':
            case 'E':
                m_bonusDamage = 2;
                m_bonusHealth = 10;
                break;
            case 'm':
            case 'M':
                m_bonusDamage = 2;
                m_bonusHealth = 5;
                break;
            case 'h':
            case 'H':
                m_bonusDamage = 1;
                m_bonusHealth = 5;
                break;
            case 'n':
            case 'N':
                m_bonusDamage = 1;
                m_bonusHealth = 3;
                break;
        }
    }

    void levelUp()
    {
        ++m_level;
        m_damage += m_bonusDamage;
        m_health += m_bonusHealth;
        m_numToLevel = m_level;
    }

    int getLevel() { return m_level; }
    int getNumToLevel() { return m_numToLevel; }
    char getDegree() { return m_degree; }
    int getBonusDamage() { return m_bonusDamage; }
    int getBonusHealth() { return m_bonusHealth; }
    bool hasWon() { return m_level >= 20; }
    void killOneMonster() { --m_numToLevel; }
};


int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Monster : public Creature
{
public:
    enum Type
    {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPE,
    };

    struct MonsterData
    {
        std::string name;
        char symbol;
        int health;
        int damage;
        int gold;
    };

    static MonsterData monsterData[MAX_TYPE];

    Monster(Type type)
        : Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health,
                   monsterData[type].damage, monsterData[type].gold)
    {
    }

    static Monster getRandomMonster()
    {
        int index = getRandomNumber(0, MAX_TYPE - 1);
        return Monster(static_cast<Type>(index));
    }
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPE]
{
    { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 }
};

void attackMonster(Monster &monster, Player &player)
{
    if (player.isDead())
        return;

    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
    monster.reduceHealth(player.getDamage());

    if (monster.isDead())
    {
        std::cout << "You killed the " << monster.getName() << ".\n";
        player.killOneMonster();
        if (player.getNumToLevel() == 0)
        {
            player.levelUp();
            std::cout << "You are now level " << player.getLevel() << ".\n";
        }
        else
            std::cout << player.getNumToLevel() << " more to level!\n";

        std::cout << "You found " << monster.getGold() << " gold.\n";
        player.addGold(monster.getGold());
    }
}

void attackPlayer(Monster &monster, Player &player)
{
    if (monster.isDead())
        return;

    std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
    player.reduceHealth(monster.getDamage());
}

void fightMonster(Player &player)
{
    Monster monster = Monster::getRandomMonster();
    std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

    while (!monster.isDead() && !player.isDead())
    {
        std::cout << player.getName() << "\thealth: " << player.getHealth() << "\tdamage: " << player.getDamage() << '\n';
        std::cout << monster.getName() << "\thealth: " << monster.getHealth() << "\tdamage: " << monster.getDamage() << '\n';

        std::cout << "(R)un or (F)ight: ";
        char choice;
        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        std::cout << '\n';

        if (choice == 'R' || choice == 'r')
        {
            if (getRandomNumber(0, 1))
            {
                std::cout << "You successfully fled.\n\n";
                return;
            }
            else
            {
                std::cout << "You failed to flee.\n\n";
                attackPlayer(monster, player);
                continue;
            }
        }

        if (choice == 'F' || choice == 'f')
        {
            attackMonster(monster, player);
            attackPlayer(monster, player);
        }

        std::cout << '\n';
    }
}

void introduction(Player &player)
{
    std::cout << "Welcome, " << player.getName() << ". You selected the ";
    switch (player.getDegree())
    {
        case 'e':
        case 'E':
            std::cout << "easy mode.\n";
            break;
        case 'm':
        case 'M':
            std::cout << "middle mode.\n";
            break;
        case 'h':
        case 'H':
            std::cout << "hard mode.\n";
            break;
        case 'n':
        case 'N':
            std::cout << "nightmare mode.\n";
            break;
    }

    std::cout << "You will encounter many monsters here, all you have to do is to collect as much gold as possible by killing them!\n";
    std::cout << "You can either run or fight when you encounter a monster.\n";
    std::cout << "If you choose run, you will have 50% of success rate. If you failed, you will get hit.\n";
    std::cout << "Every time you level up, you will get " << player.getBonusDamage() << " extra damage and recover " << player.getBonusHealth() << " health.\n";
    std::cout << "As your level gets higher, it will be more difficult to level up, so think twice when you face a dragon!\n";

    while (true)
    {
        std::cout << "So, are you ready? (y/n)";
        char ready;
        std::cin >> ready;
        std::cin.ignore(32767, '\n');

        if (ready == 'y')
        {
            std::cout << '\n';
            return;
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    std::cout << "Enter your name: ";
    std::string playerName;
    std::getline(std::cin, playerName);

    char degree;
    do
    {
        std::cout << "Select degree of difficulty: (E)asy, (M)iddle, (H)ard, or (N)ightmare? ";
        std::cin >> degree;
        std::cin.ignore(32767, '\n');
    } while (degree != 'e' && degree != 'E' && degree != 'm' && degree != 'M' &&
             degree != 'h' && degree != 'H' && degree != 'n' && degree != 'N');

    Player player(playerName, degree);
    introduction(player);

    while (!player.hasWon() && !player.isDead())
        fightMonster(player);

    if (player.isDead())
    {
        std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }
    else
        std::cout << "You won the game with " << player.getGold() << " gold!\n";

	return 0;
}
