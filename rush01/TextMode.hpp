#ifndef TEXTMODE_HPP
#define TEXTMODE_HPP

#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#define DELAY 300000

class TextMode
{

private:

	char 	*_str;

public:

	TextMode();
	TextMode(TextMode const &other);
	~TextMode();

	TextMode    &operator=(TextMode const &other);

	void 		initialize();
};


#endif
