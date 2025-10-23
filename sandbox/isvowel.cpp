#include <iostream>
#include <string>

void analyzestring(const std::string &inputstring)
{

    std::string vowels = "aeiouyAEIOUY";
    std::string numbers = "0123456789";

    int vowelcounter = 0;
    int consonantcounter = 0;
    int numbercounter = 0;

    for (char c : inputstring)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            if (vowels.find(c) != std::string::npos)
                vowelcounter++;
            else
                consonantcounter++;
        }
        else if (numbers.find(c) != std::string::npos)
        {
            numbercounter++;
        }
    }

    int counts[3] = {vowelcounter, consonantcounter, numbercounter};

    for (int i : counts)
    {
        std::cout << i << std::endl;
    }
}

enum chartype
{
    vowel,
    consonant,
    nonalpha
};

chartype analyzechar(char &inputchar)
{
    std::string vowels = "aeiouyAEIOUY";
    std::string numbers = "0123456789";

    if (vowels.find(inputchar) != std::string::npos)
    {
        return vowel;
    }
    else if (numbers.find(inputchar) != std::string::npos)
    {
        return nonalpha;
    }
    else
    {
        return consonant;
    }
};

int main()
{

    int conditionsum = 0;
    int vowelscounted = 0;
    int consonantscounted = 0;
    char fromuser;

    std::cout << "Enter a character to add to the counters, type a number to stop" << std::endl;
    while (conditionsum < 1)
    {
        std::cout << "Vowels counted " << vowelscounted << " Consonants counted " << consonantscounted << std::endl;
        std::cout << "Enter input" << std::endl;
        std::cin >> fromuser;
        chartype temp = analyzechar(fromuser);
        switch (temp)
        {
        case 0:
            vowelscounted++;
            break;
        case 1:
            consonantscounted++;
            break;
        case 2:
            conditionsum++;
            break;
        }
    }

    return 0;
}