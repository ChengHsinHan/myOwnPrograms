#include <iostream>
#include <windows.h>
#include <string>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <ctime>
#include <sstream>

class Player
{
private:
    std::string m_name;
    int m_numFouls = 0;
    int m_loses = 0;
    bool m_foul = false;

public:
    Player(std::string name)
        : m_name(name), m_numFouls(0), m_loses(0), m_foul(false)
    {
    }

    friend bool operator==(const Player &player1, const Player &player2);
    const std::string& getName() const { return m_name; }
    int getNumFouls() { return m_numFouls; }
    void addFouls() { ++m_numFouls; }
    void resetFouls() { m_numFouls = 0; }
    bool isFoulToLose(int foulNumToLose) { return m_numFouls == foulNumToLose; }
    int getLoses() { return m_loses; }
    void addLoses() { ++m_loses; }
    void resetLoses() { m_loses = 0; }
    bool isLose(int numLose) { return m_loses == numLose; }
    bool getFoul() { return m_foul; }
    void setFoul(bool foul) { m_foul = foul; }
};

bool operator==(const Player &player1, const Player &player2)
{
    return player1.m_name == player2.m_name;
}

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;
    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset() { m_beg = clock_t::now(); }
    double elapsed() { return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count(); }

    void delay(double time)
    {
        reset();
        while (elapsed() < time)
        {
        }
    }
};

void colorPrint(std::string color, std::string message = "")
{
    static HANDLE bBlack = GetStdHandle(STD_OUTPUT_HANDLE);

    static WORD cWhite  = FOREGROUND_BLUE  | FOREGROUND_GREEN     | FOREGROUND_RED | FOREGROUND_INTENSITY;
    static WORD cBlue   = FOREGROUND_BLUE  | FOREGROUND_INTENSITY;
    static WORD cGreen  = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    static WORD cRed    = FOREGROUND_RED   | FOREGROUND_INTENSITY;
    static WORD cYellow = FOREGROUND_GREEN | FOREGROUND_RED       | FOREGROUND_INTENSITY;

    if (color == "blue")
        SetConsoleTextAttribute(bBlack, cBlue);
    else if (color == "green")
        SetConsoleTextAttribute(bBlack, cGreen);
    else if (color == "red")
        SetConsoleTextAttribute(bBlack, cRed);
    else if (color == "yellow")
        SetConsoleTextAttribute(bBlack, cYellow);
    else
        SetConsoleTextAttribute(bBlack, cWhite);

    std::cout << message;
    SetConsoleTextAttribute(bBlack, cWhite);
}

std::string toString(int input)
{
    std::stringstream temp;
    temp << input;

    std::string output;
    temp >> output;
    return output;
}

int getNumPlayers()
{
    colorPrint("white");
    int numPlayer;
    while (true)
    {
        std::cout << "How many players are there to play the game \"number bomb\"? ";
        std::cin >> numPlayer;

        std::cin.ignore(32767, '\n');

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            colorPrint("red", "Please enter a number.\n");
        }
        else if (numPlayer <= 1)
            colorPrint("red", "There shall be at least 2 players.\n");
        else
        {
            std::cout << '\n';
            return numPlayer;
        }
    }
    return 0;
}

std::vector<Player> askForPlayerNames(int numPlayer)
{
    std::vector<Player> player;
    for (int index = 0; index < numPlayer; ++index)
    {
        colorPrint("green", "Enter player name # " + toString(index + 1) + ": ");

        std::string name;
        std::getline(std::cin, name);

        if (std::find(player.begin(), player.end(), Player(name)) != player.end())
        {
            colorPrint("red", "Oops! ");
            colorPrint("green", name);
            colorPrint("red", " has already been used. Please choose another one.\n");
            --index;
        }
        else
            player.push_back(Player(name));
    }
    return player;
}

void introduction(const std::vector<Player> &player, int foulNumToLose, int numLose, Timer &t)
{
    std::cout << "\nHello";
    for (unsigned int index = 0; index < player.size(); ++index)
    {
        if (index == player.size() - 1)
            std::cout << " and ";
        else
            std::cout << ", ";

        std::cout << player[index].getName();
    }
    std::cout << '\n';

    std::cout << "Here are the game rules:\n";
    std::cout << "1) Every player should guess one number each round in the range shown.\n";
    std::cout << "2) There will be one random number each round. The one that picks it loses that round.\n";
    std::cout << "3) The one who gets " << numLose << " loses first, loses the game.\n";
    std::cout << "4) I will show you the range of the number each time someone guesses and update it. ";
    std::cout << "The numbers shown are exclusive.\n";
    std::cout << "5) Any input of invalid characters or numbers out of the range will be accused of a foul. ";
    std::cout << foulNumToLose << " fouls will turn into a lose in that round. ";
    std::cout << "No fouls will be carried on to the next round.\n";
    std::cout << "6) The order of players will change after each round to enhance equality.\n";

    t.delay(10.0);
}

void changeRange(int &minOut, int &maxOut)
{
    char choice;
    do
    {
        std::cout << "\nWould you like to change the range? Default is " << minOut - 1 << " ~ " << maxOut + 1 << ". (y/n) ";
        std::cin >> choice;

        std::cin.ignore(32767, '\n');
    }
    while (choice != 'y' && choice != 'n');
    std::cout << '\n';

    if (choice == 'n')
        return;
    else
    {
        while (true)
        {
            colorPrint("yellow", "Enter the lower limit: ");
            std::cin >> minOut;

            std::cin.ignore(32767, '\n');

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                colorPrint("red", "Please enter a number.\n");
            }
            else if (minOut < 0)
            {
                colorPrint("red", "Please enter a positive number.\n");
                continue;
            }
            else
            {
                ++minOut;
                break;
            }

        }
        std::cout << '\n';
        while (true)
        {
            colorPrint("yellow", "Enter the upper limit: ");
            std::cin >> maxOut;

            std::cin.ignore(32767, '\n');

            if (std::cin.fail() || maxOut < minOut)
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                colorPrint("red", "Please enter a number.\n");
            }
            else if (maxOut < minOut)
            {
                colorPrint("yellow", "Please enter a number greater than the lower limit.\n");
                continue;
            }
            else
            {
                --maxOut;
                break;
            }
        }
    }
}

int getRandomNumber(int min, int max)
{
    static double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void playOneRound(int answer, int min, int max, std::vector<Player> &player, int foulNumToLose, Timer &t)
{
    for (unsigned int index = 0; index < player.size(); ++index)
    {
        int guess;
        bool bingo(false);

        colorPrint("green", player[index].getName() + "'s term.\n");
        do
        {
            std::cout << "The range now: " << min - 1 << " ~ " << max + 1 << '\t';
            std::cin >> guess;

            if (std::cin.fail() || guess < min || guess > max)
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');

                player[index].setFoul(true);
                player[index].addFouls();

                colorPrint("green", player[index].getName());
                colorPrint("red", " fouls #" + toString(player[index].getNumFouls()) + "!\n");

                if (player[index].isFoulToLose(foulNumToLose))
                {
                    player[index].addLoses();

                    colorPrint("green", player[index].getName());
                    colorPrint("red", " loses this round!\n\n");

                    return;
                }
                continue;
            }

            std::cout << player[index].getName() << " guesses " << guess;
            t.delay(0.5);

            if (max - min < 20)
            {
                if (max == min)
                    ;
                else
                    for (int dot = 0; dot < 3; ++dot)
                    {
                        t.delay(1.0);
                        std::cout << ".";
                    }
            }
            std::cout << "\n\n";

            if (guess < answer)
            {
                player[index].setFoul(false);
                min = guess + 1;
            }
            else if (guess > answer)
            {
                player[index].setFoul(false);
                max = guess - 1;
            }
            else
            {
                bingo = true;
                player[index].addLoses();

                colorPrint("red", "Boom!\n");
                colorPrint("green", player[index].getName());
                colorPrint("red", " loses this round!\n");

                break;
            }
        }
        while (player[index].getFoul());

        if (bingo)
            return;
        if (index == player.size() - 1)
            index = -1;
    }
}

void changeOrder(std::vector<Player> &player)
{
    for (unsigned int index = 0; index < player.size() - 1; ++index)
        std::swap(player[index], player[index + 1]);
}

bool playAgain()
{
    char choice;
    do
    {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> choice;
        std::cin.ignore(32767, '\n');
    }
    while (choice != 'y' && choice != 'n');

    std::cout << '\n';
    return choice == 'y';
}

void removePlayer(std::vector<Player> &player)
{
    char choice;
    do
    {
        std::cout << "Any players want to quit (y/n)? ";
        std::cin >> choice;
        std::cin.ignore(32767, '\n');
    }
    while (choice != 'y' && choice != 'n');

    if (choice == 'n')
        return;
    else
    {
        int numQuit;
        while (true)
        {
            std::cout << "How many are there to quit? ";
            std::cin >> numQuit;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');

                colorPrint("red", "Please enter a number.\n");
            }
            else if (numQuit <= 0)
                colorPrint("red", "Please enter a positive number.\n");
            else if (numQuit > static_cast<int>(player.size()))
                colorPrint("red", "The number you entered is greater than the total number of players.\n");
            else
            {
                std::cin.ignore(32767, '\n');
                if (player.size() - numQuit <= 1)
                {
                    colorPrint("yellow", "\nWarning: the number of players will not be able to continue the game!\n");
                    char cont;
                    do
                    {
                        std::cout << "Still want to continue(y/n)? ";
                        std::cin >> cont;
                        std::cin.ignore(32767, '\n');
                    }
                    while (cont != 'y' && cont != 'n');

                    if (cont == 'n')
                        return;
                }

                for (int index = 0; index < numQuit; ++index)
                {
                    colorPrint("green", "Enter the name of player who wants to quit: ");

                    std::string name;
                    std::getline(std::cin, name);

                    std::cout << '\n';
                    std::vector<Player>::iterator it = std::find(player.begin(), player.end(), Player(name));
                    if (it == player.end())
                    {
                        colorPrint("red", "player ");
                        colorPrint("green", name);
                        colorPrint("red", " not found. Please try again.\n");
                        --index;
                    }
                    else
                    {
                        colorPrint("red", "player ");
                        colorPrint("green", it->getName());
                        colorPrint("red", " removed.\n\n");
                        player.erase(it);
                    }
                }
                break;
            }
        }
    }
}

void addNewPlayer(std::vector<Player> &player)
{
    while (true)
    {
        char choice;
        do
        {
            std::cout << "Any new players to join (y/n)? ";
            std::cin >> choice;
            std::cin.ignore(32767, '\n');
        }
        while (choice != 'y' && choice != 'n');

        if (choice == 'n')
        {
            if (player.size() <= 1)
            {
                colorPrint("yellow", "\nWarning: the number of players will not be able to continue the game!\n");
                char cont;
                do
                {
                    std::cout << "Still want to continue (y/n)? ";
                    std::cin >> cont;
                    std::cin.ignore(32767, '\n');
                }
                while (cont != 'y' && cont != 'n');

                if (cont == 'y')
                    return;
                else
                    continue;
            }
            else
                return;
        }
        else
        {
            int numNew;
            while (true)
            {
                std::cout << "How many are there to join? ";
                std::cin >> numNew;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(32767, '\n');

                    colorPrint("red", "Please enter a number.\n");
                    continue;
                }
                else if (numNew <= 0)
                {
                    colorPrint("red", "Please enter a positive number.\n");
                    continue;
                }
                else
                {
                    std::cin.ignore(32767, '\n');
                    if (player.size() + numNew <= 1)
                    {
                        colorPrint("yellow", "\nWarning: the number of players will not be able to continue the game!\n");
                        char cont;
                        do
                        {
                            std::cout << "Still want to continue (y/n)? ";
                            std::cin >> cont;
                            std::cin.ignore(32767, '\n');
                        }
                        while (cont != 'y' && cont != 'n');

                        if (cont == 'n')
                            return;
                    }

                    for (int index = 0; index < numNew; ++index)
                    {
                        colorPrint("green", "Enter new player name #" + toString(player.size() + 1) + ": ");

                        std::string name;
                        std::getline(std::cin, name);

                        std::cout << '\n';
                        std::vector<Player>::iterator it = std::find(player.begin(), player.end(), Player(name));
                        if (it != player.end())
                        {
                            colorPrint("red", "Oops! ");
                            colorPrint("green", name);
                            colorPrint("red", " has already been used. Please choose another one.\n");
                            --index;
                        }
                        else
                        {
                            player.push_back(Player(name));

                            colorPrint("red", "player ");
                            colorPrint("green", name);
                            colorPrint("red", " added.\n\n");
                        }
                    }
                    return;
                }
            }
        }
    }
}

int main()
{
    int numPlayer = getNumPlayers();
    if (numPlayer == 0)
    {
        colorPrint("red", "Error: getNumPlayer() function has some fatal issue!\nleaving...\n");
        return 1;
    }
    std::vector<Player> player = askForPlayerNames(numPlayer);

    const int foulNumToLose = 3;
    const int numLose = 3;

    Timer t;
    introduction(player, foulNumToLose, numLose, t);

    srand(static_cast<unsigned int>(time(0)));
    rand();

    int set = 1;
    int min = 2;
    int max = 99;
    do
    {
        if (set > 1)
        {
            removePlayer(player);
            addNewPlayer(player);

            if (player.size() <= 1)
            {
                colorPrint("red", "Error: too few players to play the game!\nleaving...\n");
                return 1;
            }

            char choice;
            do
            {
                std::cout << "do you want to watch the introduction again? (y/n) ";
                std::cin >> choice;
                std::cin.ignore(32767, '\n');
            }
            while (choice != 'y' && choice != 'n');

            std::cout << '\n';
            if (choice == 'y')
                introduction(player, foulNumToLose, numLose, t);
        }
        changeRange(min, max);

        int round = 1;
        while (true)
        {
            std::cout << "\nRound " << round << "\n\n";
            std::cout << "Players' order: \n";
            for (unsigned int index = 0; index < player.size(); ++index)
                std::cout << index + 1 << ". " << player[index].getName() << '\n';

            std::cout << '\n';
            int answer = getRandomNumber(min, max);
            playOneRound(answer, min, max, player, foulNumToLose, t);

            int loserIndex = -1;
            for (unsigned int index = 0; index < player.size(); ++index)
            {
                player[index].resetFouls();
                if (player[index].isLose(numLose))
                    loserIndex = index;
            }

            if (loserIndex >= 0)
            {
                colorPrint("green", player[loserIndex].getName());
                colorPrint("red", " loses the game!\n\n");
                break;
            }

            colorPrint("red", "\nAll loses now:\n");
            for (unsigned int index = 0; index < player.size(); ++index)
            {
                colorPrint("green", player[index].getName());
                std::cout << ":\t" << player[index].getLoses() << '\n';
            }

            changeOrder(player);
            ++round;
        }
        for (unsigned int index = 0; index < player.size(); ++index)
            player[index].resetLoses();
        ++set;
    }
    while (playAgain());

    std::cout << "Thank you for playing!\n";

    return 0;
}
