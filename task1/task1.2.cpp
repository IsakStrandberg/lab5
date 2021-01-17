#define SDL_MAIN_HANDLED
#include "task1.h"



void testRendering(vector<Shape*> S, SDL_Renderer* renderer) {//where should the pointer be?????????
	for (auto x : S) {
		x->render(renderer);
	}
	//int size = S->size();
	//for (int x = 0; x < size; x++) {
		//S[x]->render();
	//}
}


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
	
	bool loop = true;
	while (loop == true)
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
				third.SetRadius((rand() % 200)+1);
				Shape* Sthird = &third;
				Sthird->SetR(rand() % 255);
				Sthird->SetG(rand() % 255);
				Sthird->SetB(rand() % 255);
				Sthird->SetAlpha(rand() % 255);
				Sthird->_Point2D._x = rand() % 200;
				Sthird->_Point2D._y = rand() % 200;
				S.push_back(Sthird);
				break;
			}
				
			
			case SDLK_r: {
				Rectangle first;
				first.SetHeight((rand() % 200)+1);
				first.SetWidth((rand() % 200)+1);
				Shape* Sfirst = &first;
				Sfirst->SetR(rand() % 255);
				Sfirst->SetG(rand() % 255);
				Sfirst->SetB(rand() % 255);
				Sfirst->SetAlpha(rand() % 255);
				Sfirst->_Point2D._x = rand() % 200;
				Sfirst->_Point2D._y = rand() % 200;
				S.push_back(Sfirst);
				break;
			}
				

			case SDLK_t: {
				Triangle second;
				second.SetBase((rand() % 200)+1);
				second.SetHeight((rand() % 200)+1);
				Shape* Ssecond = &second;
				Ssecond->SetR(rand() % 255);
				Ssecond->SetG(rand() % 255);
				Ssecond->SetB(rand() % 255);
				Ssecond->SetAlpha(rand() % 255);
				Ssecond->_Point2D._x = rand() % 200;
				Ssecond->_Point2D._y = rand() % 200;
				S.push_back(Ssecond);
				break;
			}
				
			
			case SDLK_q: 
			{loop = false;
			break; }
			
			case SDLK_x: 
			{S.clear();
			break; }
			}
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		testRendering(S,renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}