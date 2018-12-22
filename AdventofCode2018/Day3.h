#pragma once
#include "Day2.h"
#include <array>

namespace day3
{
	class Rect
	{
	public:
		Rect() = default;

		Rect( int top, int bot, int left, int right )
			:
			top( top ), bot( bot ), left( left ), right( right )
		{
		}

		int top;
		int bot;
		int left;
		int right;

	};

	class Claim
	{
	public:
		Claim( int id, int posx, int posy, int w, int h )
			:
			id( id ),
			posx( posx ),
			posy( posy ),
			w( w ),
			h( h )
		{
			area = { posy, posy + h, posx, posx + w };
		}
		void Print()
		{
			std::cout << id << " " << posx << "," << posy << " " << w << "x" << h << std::endl;
			std::cout << "t: " << area.top << " b: " << area.bot << " l: " << area.left << " r: " << area.right << std::endl;
		}
	public:
		int id;
		int posx;
		int posy;
		int w;
		int h;
		Rect area;
	};

	void day3()
	{
		std::cout << "Day3:" << std::endl;

		auto input = day2::ReadInput( "Day3.txt" );
		
		//for( auto s : input )
		//{
		//	std::cout << s << std::endl;
		//}

		Timer timer;

		std::vector<Claim> claims;

		for( auto s : input )
		{
			int id = std::stoi( s.substr( s.find( "#" ) + 1, s.find( " " ) ) );
			int posx = std::stoi( s.substr( s.find( "@" ) + 2, s.find( "," ) ) );
			int posy = std::stoi( s.substr( s.find( "," ) + 1, s.find( ":" ) ) );

			int w = std::stoi( s.substr( s.find( ":" ) + 2, s.find( "x" ) ) );
			int h = std::stoi( s.substr( s.find( "x" ) + 1 ) );

			//std::cout << id << " " << posx << "," << posy << " " << w << "x" << h << std::endl;

			claims.emplace_back( id, posx, posy, w, h );

		}

		//for( auto c : claims )
		//{
		//	c.Print();
		//}

		const int size = 1000;
		std::array<char, size * size> fabric;
		fabric.fill( 0 );

		int overlap = 0;

		for( auto c : claims )
		{
			for( int x = c.posx; x < c.posx + c.w; x++ )
			{
				for( int y = c.posy; y < c.posy + c.h; y++ )
				{
					fabric[y * size + x] += 1;
					if( fabric[y * size + x] == 2 )
					{
						overlap++;
					}
				}
			}
		}

		std::cout << overlap << std::endl;
		timer.Print();

		//part 2

		int solution = 0;

		for( auto c : claims )
		{
			bool nooverlap = true;
			for( int x = c.posx; x < c.posx + c.w; x++ )
			{
				for( int y = c.posy; y < c.posy + c.h; y++ )
				{
					if( fabric[y * size + x] > 1 )
					{
						nooverlap = false;
					}
				}
			}
			if( nooverlap )
			{
				solution = c.id;
				break;
			}
		}

		std::cout << solution << std::endl;
		timer.Print();
	}
}