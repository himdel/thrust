// sdl input for thrust
// (adapted from tank [ https://github.com/himdel/tank/ ])
// output in sdl.c

#include <SDL/SDL.h>
#include <SDL/SDL_keysym.h>
#include "thrust.h"
#include "keyboard.h"

static int keyz[SDLK_LAST];


// key driver name
char *
keyname(void)
{
	static char name[] = "SDL";
	return name;
}

// init key system
int
keyinit(void)
{
	flushkeyboard();
	return 0;
}

// close, empty
int
keyclose(void)
{
	return 0;
}

// stub, non-default keys not implemented
char *
keystring(int key)
{
	static char stub[] = "STUB";
	return stub;
}

// stub, non-default keys not implemented
int
keycode(char *keyname)
{
	return 0;
}

// read keypress and update array
static int
update_keys(int retdown)
{
	SDL_Event ev;
	int n = 0;
	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
			case SDL_KEYDOWN:
				n++;
				keyz[ev.key.keysym.sym] = 1;
				if (retdown)
					return ev.key.keysym.sym;
				break;
			case SDL_QUIT:
				keyz[SDLK_ESCAPE] = 1;
				if (retdown)
					return SDLK_ESCAPE;
				break;
			case SDL_KEYUP:
				keyz[ev.key.keysym.sym] = 0;
				break;
		}
	}
	return 0;
}

// read one keypress
int
getkey(void)
{
	return update_keys(1);
}

// return key status in a byte
byte
getkeys(void)
{
	byte keybits = 0;

	update_keys(0);

	if (keyz[SDLK_p])
		keybits |= pause_bit;
	if (keyz[SDLK_q] || keyz[SDLK_ESCAPE])
		keybits |= escape_bit;

	if (keyz[SDLK_a])
		keybits |= left_bit;
	if (keyz[SDLK_s])
		keybits |= right_bit;
	if (keyz[SDLK_LCTRL] || keyz[SDLK_RCTRL])
		keybits |= thrust_bit;
	if (keyz[SDLK_RETURN])
		keybits |= fire_bit;
	if (keyz[SDLK_SPACE])
		keybits |= pickup_bit;

	return keybits;
}

// set singlekey mode
void
singlekey(void)
{
}

// set multikey mode, stub
void
multiplekeys(void)
{
}

// get one key
int
getonemultiplekey(void)
{
	return getkey();
}

// flush keyboard
void
flushkeyboard(void)
{
	update_keys(0);
	for (int foo = 0; foo < SDLK_LAST; foo++)
		keyz[foo] = 0;
}

// is a key waiting
int
keywaiting(void)
{
	update_keys(0);
	for (int foo = 0; foo < SDLK_LAST; foo++)
		if (keyz[foo])
			return 1;
	return 0;
}
