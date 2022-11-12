#include "ITesting.h"

void Timer::Start()
{
    startTimePoint = std::chrono::high_resolution_clock::now();
}

float Timer::GetIntervalMilliseconds()
{
    auto endTimePoint = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

    auto duration = end - start;

    return duration * 0.001;
}


void ITesting::Test()
{
    AddTests();
    for (int i = 0; i < testFunctions.size(); ++i)
    {
        Timer t;
        t.Start();
        bool success = testFunctions[i]();
        float ms = t.GetIntervalMilliseconds();
        std::cout << "Test " << i << (success ? "\tPASS\t" : "\tFAILED\t") << ms << "ms\n";
    }
}

void ITesting::AddTest(std::function<bool()> func)
{
    testFunctions.push_back(func);
}
