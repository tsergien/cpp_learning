//
// Created by Andrii BYTKO on 13.10.2018.
//

#ifndef GRAPHICALMODE_HPP
#define GRAPHICALMODE_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <unistd.h>
#include <string>
#include "TextMode.hpp"
#include "OsInfoModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"
#include "HostnameModule.hpp"
#include "RAMModule.hpp"
#include "DiskModule.hpp"
#include "NetworkModule.hpp"
#include <curses.h>

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 1000

class GraphicalMode {

private:

	int		_x;
	int		_y;
	SDL_Window 		*_win;
	SDL_Event 		e;
	int				_loop;
	SDL_Surface		*_pic;
	SDL_Renderer 	*_ren;
	SDL_Texture		*_texture;
	SDL_Renderer 	*_renderer;

	SDL_Texture 	*_username;
	SDL_Texture 	*_hostname;
	SDL_Texture 	*_username_v;
	SDL_Texture 	*_hostname_v;
	SDL_Texture 	*_system;
	SDL_Texture 	*_system_v;
	SDL_Texture 	*_kernel;
	SDL_Texture 	*_dateTime;
	SDL_Texture 	*_date;
	SDL_Texture 	*_time;


public:

	GraphicalMode();
	GraphicalMode(GraphicalMode const &other);
	~GraphicalMode();

	GraphicalMode    &operator=(GraphicalMode const &other);

	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
	void 			run();
	SDL_Texture		*renderText(const std::string &message, const std::string &fontFile,
								   SDL_Color color, int fontSize, SDL_Renderer *renderer);

	SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
	void logSDLError(std::ostream &os, const std::string &msg);
};


#endif //GRAPHICALMODE_HPP
