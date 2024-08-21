#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <complex.h>

//TESTING
SDL_Window *window;
SDL_Renderer *rend;


bool init()
{
	double complex z = 0 + 0 * I;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("an error occured: %s", SDL_GetError());
		return false;
	}
	window = SDL_CreateWindow("mandelbrot", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
						1000, 1000, 0);
	rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_RenderClear(rend);
	SDL_RenderPresent(rend);

	for(int width = 0; width < 1000; width++)
    	{
		for(int height = 0; height < 1000; height++)
		{
			float scaledx = width / 300.0;
            		float scaledy = height / 300.0;
            		double complex c = (scaledx - 2.5) + (scaledy - 1.75) * I;
			
			for(int iteration = 0; iteration < 100; iteration++)
            		{
                		z = cpow(z, 2);
                		z += c;
                		iteration++;

               			if(fabs(z) >= 2)
               			{
					SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
					SDL_RenderDrawPoint(rend, width, height);
               				break;
               			}
            		}
           		z = 0 + 0*I;
		}
       		SDL_RenderPresent(rend);
       	}
	return true;
}


int main()
{
	bool running = init();
	SDL_Event event;

	while(running)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:

					running = false;
					break;
			}
		}
	}
	return 0;
}
