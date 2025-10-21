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

int main()
{

    std::string mystring = "Jalla ahhh script";

    analyzestring(mystring);

    return 0;
}