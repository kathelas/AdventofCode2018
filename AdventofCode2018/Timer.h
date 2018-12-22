#pragma once
#include <iostream>
#include <chrono>

class Timer
{
public:
	Timer()
	{
		last = std::chrono::steady_clock::now();
	}
	float Mark()
	{
		using namespace std::chrono;

		const auto old = last;
		last = steady_clock::now();
		const duration<float> frameTime = last - old;
		return frameTime.count();
	}
	void Print()
	{
		std::cout << "Time: " << Mark() << std::endl;
	}
private:
	std::chrono::steady_clock::time_point last;
};