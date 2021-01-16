#define SDL_MAIN_HANDLED
#include "task1.cpp"
#include <time.h>
#include <cstdlib>


int main(int argc, char* args[]) {
	vector<Shape*> S;
	srand(time(NULL));

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("le formes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,SDL_WINDOW_OPENGL);
	if (window == nullptr)
	{
		SDL_Log("Could not create a window: %s", SDL_GetError());
		return -1;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
		return -1;
	}
	
	while (true)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				break;
			}
		}
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_c: {
				Circle third;
				third.SetRadius(rand() % 10);
				Shape* Sthird = &third;
				Sthird->SetR(rand() % 255);
				Sthird->SetG(rand() % 255);
				Sthird->SetB(rand() % 255);
				Sthird->SetAlpha(rand() % 255);
				Sthird->_Point2D._x = rand() % 10;
				Sthird->_Point2D._y = rand() % 10;
				S.push_back(Sthird);
			}
				
			
			case SDLK_r: {
				Rectangle first;
				first.SetHeight(rand() % 5);
				first.SetWidth(rand() % 5);
				Shape* Sfirst = &first;
				Sfirst->SetR(rand() % 255);
				Sfirst->SetG(rand() % 255);
				Sfirst->SetB(rand() % 255);
				Sfirst->SetAlpha(rand() % 255);
				Sfirst->_Point2D._x = rand() % 5;
				Sfirst->_Point2D._y = rand() % 5;
				S.push_back(Sfirst);
			}
				

			case SDLK_t: {
				Triangle second;
				second.SetBase(rand() % 5);
				second.SetHeight(rand() % 5);
				Shape* Ssecond = &second;
				Ssecond->SetR(rand() % 255);
				Ssecond->SetG(rand() % 255);
				Ssecond->SetB(rand() % 255);
				Ssecond->SetAlpha(rand() % 255);
				Ssecond->_Point2D._x = rand() % 5;
				Ssecond->_Point2D._y = rand() % 5;
				S.push_back(Ssecond);
			}
				
			
			case SDLK_q: 
			{break; }
			
			case SDLK_x: 
			{S.clear(); }
			}
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		testRendering(S,renderer);//the correct renderer?

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}