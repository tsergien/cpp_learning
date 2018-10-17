//
// Created by Andrii BYTKO on 13.10.2018.
//

#include <iostream>
#include <ncurses.h>

#include "TextMode.hpp"
#include "GraphicalMode.hpp"

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		if(argv[1][0] == '1')
		{
			GraphicalMode	graphic;
			graphic.run();
		}
		else if(argv[1][0] == '2')
		{
			TextMode	text;
			text.initialize();
		}
	}
	return (0);
}