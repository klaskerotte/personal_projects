#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <thread>
#include <chrono>
#include <sys/stat.h>

int factorial(int inputinteger)
{

    int sum = 1;
    for (int i = 1; i < (inputinteger + 1); i++)
    {
        sum *= i;
    }
    return sum;
}

float max3(float inputnumber[3])
{
    float temp = inputnumber[0];
    for (int i = 0; i < 3; i++)
    {
        if (inputnumber[i] > temp)
        {
            temp = inputnumber[i];
        }
    }
    return temp;
}

void infiniteseries(int base, int n)
{
    double sum = 0;
    double precision = 1e-8;

    for (int i = 1; i < (n + 1); i++)
    {
        if (std::abs(1 - sum) < precision)
        {
            std::cout << "precision hit, converged to " << sum << std::endl;
            break;
        }
        else
        {

            sum += 1 / pow(base, i);
            std::cout << std::fixed << std::setprecision(15) << sum << std::endl;
        }
    }
}

double distancetraveled(double time)
{
    double g = 9.80665; // ms^-2
    double distance = 0.5 * g * pow(time, 2);

    return distance;
}

double distancetraveled(double time1, double time2)
{
    double diff = distancetraveled(time2) - distancetraveled(time1);
    return diff;
}

void loadingAnimation(int duration_seconds, int interval_ms = 500)
{
    using namespace std::chrono_literals;
    std::string frames[] = {"   ", ".  ", ".. ", "..."};
    int frameCount = sizeof(frames) / sizeof(frames[0]);
    int totalIterations = (duration_seconds * 1000) / interval_ms;

    for (int i = 0; i < totalIterations; ++i)
    {
        std::cout << "\r" << frames[i % frameCount];
        std::cout.flush(); // ensures immediate display
        std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
    }

    std::cout << "\rDone!" << std::endl; // finish line
}

bool fileExists(const std::string &filename)
{
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

int main()
{
    std::cout << "Initializing: " << std::endl;
    loadingAnimation(3); // animate for 3 seconds

    std::string filename = "distances.txt";
    bool exists = fileExists(filename); // check if the desired file exists.
    std::cout << exists << std::endl;

    std::fstream outfile;
    outfile.open(filename, std::ios::app); // append mode

    if (!outfile)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    if (!exists)
    {
        outfile << "time1\ttime2\tdistance\n";
    }
    // Example data to append
    double times[] = {0, 1, 2, 3, 4};
    int n = sizeof(times) / sizeof(times[0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double distance = 0.5 * 9.80665 * (pow(times[j], 2) - pow(times[i], 2)); // simple physics formula
            outfile << std::fixed << std::setprecision(8)
                    << times[i] << "\t" << times[j] << "\t" << distance << "\n";
        }
    }

    outfile << "Hello this is a test :)" << std::endl;

    outfile.close();
    std::cout << "Data appended to " << filename << std::endl;

    struct player
    {
        std::string name;
        int age;
        float height;
    };

    player player1 = {"Samuel", 25, 1.81};
    std::cout << player1.name << std::endl;
    return 0;
}
