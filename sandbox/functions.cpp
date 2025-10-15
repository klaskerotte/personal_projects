#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <unistd.h>
#include <iomanip>

void greet()
{

    const std::string lines[] = {
        "  _____              _____                       ",
        " / ____|            / ____|                      ",
        "| |     __ _ _ __  | |  __  __ _ _ __ ___   ___  ",
        "| |    / _` | '__| | | |_ |/ _` | '_ ` _ \\ / _ \\ ",
        "| |___| (_| | |    | |__| | (_| | | | | | |  __/ ",
        " \\_____\\__,_|_|     \\_____|\\__,_|_| |_| |_|\\___| "};

    for (const auto &line : lines)
    {
        for (char c : line)
        {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(10)); // delay between characters
        }
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // delay between lines
    }

    std::cout << std::endl;
}

void pokemonstring(std::string text)
{
    {

        const std::string lines[] = {text};

        for (const auto &line : lines)
        {
            for (char c : line)
            {
                std::cout << c << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(2)); // delay between characters
            }
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(50)); // delay between lines
        }

        std::cout << std::endl;
    }
}

void loadingAnimation()
{
    for (int j = 0; j < 3; j++)
    {
        std::cout << "\rLoading   \rLoading ";
        for (int i = 0; i < 3; i++)
        {
            std::cout << ".";
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    }
}

void dots()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\r." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cout << "\r.." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cout << "\r..." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

class user
{
public:
    std::string name;
    int age;
    float height;
};

main()
{
    user player1;

    greet();
    loadingAnimation();
    std::cout << "\n\n\n";

    pokemonstring("----------------------------------------------------------------------------");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    dots();
    pokemonstring("Hmmmm...");
    pokemonstring("Who are you?");

    std::cin >> player1.name;
    pokemonstring("Oh, so your name is " + player1.name + "? That's a nice name!");
    pokemonstring("How old are you?");

    std::cin >> player1.age;
    pokemonstring("Wow, " + std::to_string(player1.age) + " years old! You look great for your age!");
    pokemonstring("And finally, how tall are you in meters?");
    std::cin >> player1.height;
    pokemonstring("So you're " + std::to_string(player1.height) + " meters tall? Impressive!");
    pokemonstring("It's nice to meet you, " + player1.name + "!");

    return 0;
}