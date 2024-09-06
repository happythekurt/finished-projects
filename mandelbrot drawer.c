#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <complex.h>

struct app
{
	SDL_Window *window;
	SDL_Renderer *rend;
} app;


bool init()
{
	double complex z = 0 + 0 * I;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("an error occured: %s", SDL_GetError());
		return false;
	}

	app.window = SDL_CreateWindow("mandelbrot", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, 0);
	app.rend = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_RenderPresent(app.rend);
	
	for(int width = 0; width < 1000; width++)
	{
		for(int height = 0; height < 1000; height++)
		{
			float scaledx = width / 300.0;
			float scaledy = height / 300.0;
			double complex c = (scaledx - 2.5) + (scaledy - 1.75) * I; // this scales and centers the set 

			for(int iteration = 0; iteration < 50; iteration++) // this loop iterates over z using the value of complex c
			{
				z = cpow(z, 2);
				z += c;
				
				if(fabs(z) >= 2) // checking if z is out of the set and draws a white pixel if thats the case
				{
					SDL_SetRenderDrawColor(app.rend, 255, 255, 255, 255);
					SDL_RenderDrawPoint(app.rend, width, height); 
					break;
				}
			}
			z = 0 + 0*I;
		}
		SDL_RenderPresent(app.rend);
	}
	return true;
}


int main()
{
	bool running = init();
	SDL_Event event;

	while(running)
	{
		if(SDL_PollEvent(&event) && event.type == SDL_QUIT)
		{
			SDL_DestroyRenderer(app.rend);
			SDL_DestroyWindow(app.window);
			SDL_Quit();
			break;
		}
	}
	return 0;
}
