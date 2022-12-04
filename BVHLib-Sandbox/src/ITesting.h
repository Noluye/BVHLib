#pragma once
#include <memory>
#include <iostream>
#include <chrono>
#include <functional>
#include <vector>

class Timer
{
public:
	Timer() = default;
	~Timer() = default;
	void Start();
	float GetIntervalMilliseconds();
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint;
};

struct TestMessage
{
	bool success;
	float milliseconds;
};

class ITesting
{
public:
	void Test();
protected:
	virtual void AddTests() {};
	void AddTest(std::function<bool()> func);
private:
	std::vector<std::function<bool()>> testFunctions;
};
