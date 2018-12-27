#pragma once
#include "Day2.h"
#include <array>

namespace day4
{
	class Guard
	{
	public:
		Guard( std::vector<std::string>& input )
			:
			RawInput( input )
		{

		}

		int Id;
		std::array<int, 60> SleepAmount;		//0-59 are the minutes between 00:00 - 00:59 the time during which the guards sleep,
											//counts on how many days the guard is asleep at that minute
		int TotalSleepTime;

		std::vector<std::string> RawInput;
	};


	void day4()
	{
		std::cout << "Day4:" << std::endl;

		auto input = day2::ReadInput( "Day4.txt" );

		Timer timer;


	}
}