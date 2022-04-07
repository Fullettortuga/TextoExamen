#include "tigr.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


Tigr *backdrop, *screen;


int main(int argc, char *argv[])
{
	
	
	
	// Make a window and an off-screen backdrop.
	screen = tigrWindow(320, 200, "GUI", 0);
	backdrop = tigrBitmap(screen->w, screen->h);

	// Fill in the background.
	tigrClear(backdrop, tigrRGB(255,255,255));
	
    // Repeat till they close the window.
	while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE))
	{
		
	
		// Composite the GUI
		tigrBlit(screen, backdrop, 0,0,0,0, backdrop->w, backdrop->h);
		
		//dibuja un rectangulo
		tigrRect(screen, 100, 100, 130, 30, tigrRGB(150,150,150));

		//dibuja el texto
		tigrPrint(screen, tfont, 120, 110, tigrRGB(0xff, 0x00, 0x00), "Rama experimental.");
		


		// Update the window.
		tigrUpdate(screen);
	}

	
	tigrFree(backdrop);
	tigrFree(screen);
	return 0;
}