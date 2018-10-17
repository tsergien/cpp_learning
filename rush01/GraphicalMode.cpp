//
// Created by Andrii BYTKO on 13.10.2018.
//

#include "GraphicalMode.hpp"


GraphicalMode::GraphicalMode() {


	HostnameModule	hostname;
	OsInfoModule os;
	DateTimeModule date;
	CPUModule cpu;
	RAMModule ram;
	DiskModule disk;
	NetworkModule net;

	hostname.set_data();
	os.set_data();
	date.set_data();

	_loop = 1;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return ;
	}
	_win = SDL_CreateWindow("ft_gkrellm", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (_win == nullptr) {
		logSDLError(std::cout, "CreateWindow");
		return ;
	}

	_renderer = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	if (TTF_Init() != 0){
		logSDLError(std::cout, "TTF_Init");
		SDL_Quit();
		return ;
	}

	//_renderer = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Color color = { 255, 255, 255, 255 };
	const std::string		path = "./raleway/Raleway-Black.ttf";
	_username = renderText("Username:", path,
									color, 15, _renderer);
	_username_v = renderText(hostname.get_user_s(), path,
									color, 15, _renderer);
	_hostname = renderText("Hostname:", path,
						   color, 15, _renderer);
	_hostname_v = renderText(hostname.get_host_s(), path,
						   color, 15, _renderer);
	_system = renderText("OsInfo", path,
						   color, 15, _renderer);
	_system_v = renderText(os.get_system_version(), path,
						   color, 15, _renderer);
	_kernel = renderText(os.get_kernel_version(), path,
						   color, 15, _renderer);
	_dateTime = renderText("Date/Time", path,
						   color, 15, _renderer);
	_date = renderText(date.get_date(), path,
						   color, 15, _renderer);
	_time = renderText(date.get_time(), path,
						   color, 15, _renderer);



	if (_username == nullptr || _hostname == nullptr){

		TTF_Quit();
		SDL_Quit();
		return ;
	}
//Get the texture w/h so we can center it in the screen
	int iW, iH;
	SDL_QueryTexture(_username, NULL, NULL, &iW, &iH);
	_x = SCREEN_WIDTH / 2 - iW / 2;
	_y = SCREEN_HEIGHT / 2 - iH / 2;

	SDL_RenderClear(_renderer);
//We can draw our message as we do any other texture, since it's been
//rendered to a texture
	renderTexture(_username, _renderer, _x - 100, _y - 400);
	renderTexture(_username_v, _renderer, _x, _y - 400);
	renderTexture(_hostname, _renderer, _x - 100, _y - 380);
	renderTexture(_hostname_v, _renderer, _x, _y - 380);
	renderTexture(_system, _renderer, _x, _y - 340);
	renderTexture(_system_v, _renderer, _x - 40, _y - 320);
	renderTexture(_kernel, _renderer, _x - 20, _y - 300);
	renderTexture(_dateTime, _renderer, _x - 10, _y - 260);
	renderTexture(_date, _renderer, _x - 40, _y - 240);
	renderTexture(_time, _renderer, _x, _y - 220);
	SDL_RenderPresent(_renderer);

}









void GraphicalMode::logSDLError(std::ostream &os, const std::string &msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}

SDL_Texture* GraphicalMode::loadTexture(const std::string &file, SDL_Renderer *ren)
{
	//Initialize to nullptr to avoid dangling pointer issues
	_texture = nullptr;
	//Load the image
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	//If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr){
		_texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (_texture == nullptr){
			logSDLError(std::cout, "CreateTextureFromSurface");
		}
	}
	else {
		logSDLError(std::cout, "LoadBMP");
	}
	return _texture;
}

void GraphicalMode::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

GraphicalMode& GraphicalMode::operator=(GraphicalMode const &other) {

	_loop = other._loop;
	_pic = other._pic;
	_ren = other._ren;
	_win = other._win;
	return *this;
}

GraphicalMode::GraphicalMode(GraphicalMode const &other) {

	*this = other;
	return ;
}

SDL_Texture * GraphicalMode::renderText(const std::string &message, const std::string &fontFile, SDL_Color color,
										int fontSize, SDL_Renderer *renderer)
{
	//Open the font
	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr){
		logSDLError(std::cout, "TTF_OpenFont");
		return nullptr;
	}
	//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == nullptr){
		logSDLError(std::cout, "TTF_RenderText");
		TTF_CloseFont(font);
		return nullptr;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr){
		logSDLError(std::cout, "CreateTexture");
	}
	//Clean up the surface and font
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}




void GraphicalMode::run() {

	while(_loop)
	{

		while (SDL_PollEvent(&e) && _loop)
		{
			if (e.type == SDL_QUIT)
				_loop = 0;
			

			 else if (e.type == SDL_KEYDOWN)
			 {
			 	if (e.key.keysym.sym == SDLK_ESCAPE)
					_loop = 0;
			 }
		}
	}
}

GraphicalMode::~GraphicalMode() {

	SDL_DestroyWindow(_win);
	SDL_Quit();
}