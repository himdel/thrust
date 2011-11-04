// sdl output for thrust
// (adapted from tank [ https://github.com/himdel/tank/ ])
// input in sdlkey.c

#include <stdlib.h>
#include <stdlib.h>
#include <assert.h>
#define __USE_BSD
#include <unistd.h>

#include <SDL/SDL.h>
#include "thrust.h"
#include "gr_drv.h"

static const int X = 320;
static const int Y = 200;

static SDL_Surface *scr = NULL;


// used for output-specific options
char *
graphicsname(void)
{
	static char name[] = "SDL";
	return name;
}

// run before init, empty
void
graphics_preinit(void)
{
	;
}

// parse options, init graphics
int
graphicsinit(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
		return -1;
	}

	SDL_WM_SetCaption("thrust", "thrust");
	// SDL_WM_SetIcon(SDL_LoadBMP("img/icon.bmp"), NULL);

	assert((scr = SDL_SetVideoMode(X, Y, 8, SDL_SWSURFACE)));

	return 0;
}

// close graphics
int
graphicsclose(void)
{
	SDL_Quit();
	scr = NULL;

	return 0;
}

// clear screen
void
clearscr(void)
{
	if (SDL_MUSTLOCK(scr))
		SDL_LockSurface(scr);

	for (int x = 0; x < X; x++)
		for (int y = 0; y < Y; y++)
			putpixel(x, y, 0);

	if (SDL_MUSTLOCK(scr))
		SDL_UnlockSurface(scr);

	// displayscreen does the actual repaint
	displayscreen();
}

// flip buffer
void
displayscreen(void)
{
	SDL_UpdateRect(scr, 0, 0, 0, 0);
}

// wait for sync, empty
void
syncscreen(void)
{
	;
}

// paint a pixel
void
putpixel(int x, int y, byte color)
{
	if (SDL_MUSTLOCK(scr))
		SDL_LockSurface(scr);

	*((Uint8 *) scr->pixels + (scr->pitch * y) + x) = color;

	if (SDL_MUSTLOCK(scr))
		SDL_UnlockSurface(scr);
}

// copy an area
void
putarea(byte *source, int x, int y, int width, int height, int bytesperline, int destx, int desty)
{
	if (SDL_MUSTLOCK(scr))
		SDL_LockSurface(scr);

	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++)
			*((Uint8 *) scr->pixels + (scr->pitch * (desty + j)) + (destx + i)) = source[bytesperline * (y + j) + x + i];

	if (SDL_MUSTLOCK(scr))
		SDL_UnlockSurface(scr);
}

// set/fade pallete
// fade ignored for now
void
fadepalette(int first, int last, byte *RGBtable, int fade, int flag)
{
	int n = last - first + 1;
	SDL_Color *col = calloc(n, sizeof(SDL_Color));

	for (int foo = 0; foo < n; foo++) {
		col[foo].r = RGBtable[3 * foo + 0];
		col[foo].g = RGBtable[3 * foo + 1];
		col[foo].b = RGBtable[3 * foo + 2];
	}

	SDL_SetColors(scr, col, first, n);
	free(col);

	if (flag)
		displayscreen();
}

// fade in gradually
void
fade_in(void)
{
	for (int i = 1; i <= 64; i++)
		fadepalette(0, 255, bin_colors, i, 1);

	displayscreen();
}

// fade out gradually
void
fade_out(void)
{
	for (int i = 64; i; i--)
		fadepalette(0, 255, bin_colors, i, 1);

	clearscr();
	usleep(500000L);
}
