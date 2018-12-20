#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Timer.h"

namespace day2
{
	void day2()
	{
		std::ifstream inputstream( "Day2.txt" );
		std::vector<std::string> input;
		if( inputstream.is_open() )
		{
			std::string temp;
			while( std::getline( inputstream, temp ) )
			{
				if( temp.size() > 0 )
				{
					input.push_back( temp );
				}
			}
		}

		//for( auto s : input )
		//{
		//	std::cout << s << std::endl;
		//}
		Timer timer;

		int twotimes = 0;
		int threetimes = 0;

		for( auto id : input )
		{
			bool notfound2 = true;
			bool notfound3 = true;
			for( auto c : id )
			{
				char letter = c;
				char counter = std::count( id.begin(), id.end(), letter );
				if( notfound2 && counter == 2 )
				{
					twotimes++;
					notfound2 = false;
				}
				if( notfound3 && counter == 3 )
				{
					threetimes++;
					notfound3 = false;
				}

				if( !notfound2 && !notfound3 )
					break;
			}
		}

		int cheksum = twotimes * threetimes;

		std::cout << cheksum << std::endl;
		std::cout << timer.Mark() << std::endl;
		//part 2

		std::string commonletters = "";
		bool found = false;
		for( auto id : input )
		{
			for( auto id2 : input )
			{
				int counter = 0;
				//first mismatch
				auto mm = std::mismatch( id.begin(), id.end(), id2.begin(), id2.end() );

				//if equal its the same id (looping over all ids)
				if( mm.first != id.end() )
				{
					auto idnext = std::next( mm.first );
					auto id2next = std::next( mm.second );
					//if no 2nd mismatch we found our solution
					if( std::mismatch( idnext, id.end(), id2next, id2.end() ).first == id.end() )
					{
						int temp = std::distance( id.begin(), mm.first );
						commonletters = id.erase( temp, 1 );
						found = true;
						break;
					}
				}
			}
			if( found )
				break;
		}
		std::cout << commonletters << std::endl;
		std::cout << timer.Mark() << std::endl;

		std::cin.get();
	}



}