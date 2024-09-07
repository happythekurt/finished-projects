#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <raylib.h>


int main()
{
	double complex z = 0 + 0 * I;


	InitWindow(1000, 1000, "TITLE");
	BeginDrawing();

	while(!WindowShouldClose())
	{
		for(int width = 0; width < 1000; width++)
		{
			float scaledx = width / 300.0;
			for(int height = 0; height < 1000; height++)
			{
				float scaledy = height / 300.0;
				double complex c = (scaledx - 2.5) + (scaledy - 1.75) * I;

				for(int iteration = 0; iteration < 50; iteration++)
				{
					z = cpow(z, 2);
					z += c;

					if(fabs(z) >= 2)
					{
						DrawPixel(width, height, RAYWHITE);
						break;
					}
				}
				z = 0 + 0*I;
			}
			EndDrawing();
		}
	}

	CloseWindow();

	return 0;
}
