/* Beatbox - main.c
 * Copyright (c) 2011 Tanner Babcock */
#include <oslib/oslib.h>
#include <pspsdk.h>
#include <psputils.h>
#include <time.h>
#include <stdio.h>
#include "main.h"
PSP_MODULE_INFO("Beatbox by Babkock", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-2048);

void BBmsg(int x, int y, const char *str) {
	int z;
	for (z = 0; z != 3; z++) {
		oslStartDrawing();
		oslDrawString(x, y, str);
		oslEndDrawing();
		oslSyncFrame();
	}
	return;
}

void BBinit() {
	oslInit(0);
	oslInitGfx(OSL_PF_8888, 1);
	oslInitConsole();
	oslInitAudio();
	BBloadfiles();
	if (!sound.one || !sound.two || !sound.three || !sound.four || !sound.five ||
		!sound.six || !sound.seven || !sound.eight) {
		BBmsg(10, 40, "ERROR: one or more sound files missing, exiting...");
		oslEndGfx();
		oslQuit();
	}
	BBcolorsetswitch(WHITE);
	oslSetBkColor(RGBA(0, 0, 0, 0));
	musica = (pspSdkLoadStartModule("music.prx", PSP_MEMORY_PARTITION_KERNEL));
	return;
}

int main() {
	BBinit();
	int foo;
	oslCls();
	int x;
	for (x = 0; !osl_quit && x != 2; x++) {
		oslStartDrawing();
		if (!splash) {
			oslDrawFillRect(0, 0, 480, 272, RGBA(0, 0, 0, 255));
			oslDrawString(10, 10, "- Part of -");
			oslDrawString(10, 30, "NPT\'S PSP GENESIS COMPETITION");
			oslDrawString(10, 50, "Presented by");
			oslDrawString(10, 60, "psp-hacks.com");
			oslDrawString(200, 60, "pspgen.com");
			oslDrawString(10, 70, "wololo.net");
			oslDrawString(200, 70, "exophase.com");
			oslDrawString(10, 80, "gamegaz.jp");
			oslDrawString(200, 80, "pspcustomfirmware.com");
			oslDrawString(10, 90, "daxhordes.org");
			oslDrawString(200, 90, "pspslimhacks.com");
		} else
			oslDrawImage(splash);
		oslEndDrawing();
		oslSyncFrame();
	} sceKernelDelayThread(2000000);
	oslCls();
	while (!osl_quit) {
		oslStartDrawing();
		oslReadKeys();
		if (!intro) {
			oslDrawFillRect(0, 0, 480, 272, RGBA(0, 0, 0, 0));
			oslDrawString(10, 10, "Beatbox 2 by Babkock");
			oslDrawString(10, 20, "Press X to start jamming.");
			oslDrawString(10, 30, "Press O to quit.");
		} else
			oslDrawImage(intro);
		if (osl_keys->pressed.cross) {
			foo = TRUE;
			break;
		} if (osl_keys->pressed.circle) {
			foo = FALSE;
			break;
		} oslEndDrawing();
		oslSyncFrame();
	}
	if (foo == FALSE) {
		oslEndGfx();
		oslQuit();
		return 0;
	} soundset = ROCK;
	metronomeb = FALSE;
	menuoption = METRONOMEM;
	mode = FOURKEY;
	colorsb = TRUE;
	start = sceKernelLibcClock();
	oslCls();
	while (!osl_quit) {
		oslStartDrawing();
		oslReadKeys();
		oslCls();
		current = sceKernelLibcClock();
		d = (current - start);
		oslDrawImage(bgimage);
		if (d <= 2000000) {
			/* go away after two seconds */
			oslDrawImageXY(babkock, 0, 0);
			oslDrawImageXY(options, 0, 245);
		}
		if (colorsb == TRUE)
			BBdrawgrid();
		if (osl_keys->pressed.start) {
			BBpause();
			start = sceKernelLibcClock();
		}
		if (osl_keys->held.select)
			BBmusic();
		if (osl_keys->pressed.cross) {
			if (mode == FOURKEY)
				oslPlaySound(sound.one, 0);
			else
				oslPlaySound(sound.five, 4);
			if (colors.five == FALSE)
				colors.five++;
			else
				colors.five--;
		}
		/* Four key mode uses the same sounds for cross and down,
		 * square and left, etc. */
		if (osl_keys->pressed.circle) {
			if (mode == FOURKEY)
				oslPlaySound(sound.two, 1);
			else
				oslPlaySound(sound.six, 5);
			if (colors.six == FALSE)
				colors.six++;
			else
				colors.six--;
		}
		if (osl_keys->pressed.square) {
			if (mode == FOURKEY)
				oslPlaySound(sound.four, 3);
			else if (metronomeb == FALSE)
				oslPlaySound(sound.eight, 7);
			else
				oslPlaySound(sound.eight, 6);
			if (colors.eight == FALSE)
				colors.eight++;
			else
				colors.eight--;
		}
		if (osl_keys->pressed.triangle) {
			if (mode == FOURKEY)
				oslPlaySound(sound.three, 2);
			else
				oslPlaySound(sound.seven, 6);
			if (colors.seven == FALSE)
				colors.seven++;
			else
				colors.seven--;
		}
		if (osl_keys->pressed.down) {
			oslPlaySound(sound.one, 0);
			if (colors.one == FALSE)
				colors.one++;
			else
				colors.one--;
		}
		if (osl_keys->pressed.right) {
			oslPlaySound(sound.two, 1);
			if (colors.two == FALSE)
				colors.two++;
			else
				colors.two--;
		}
		if (osl_keys->pressed.left) {
			oslPlaySound(sound.four, 3);
			if (colors.four == FALSE)
				colors.four++;
			else
				colors.four--;
		}
		if (osl_keys->pressed.up) {
			oslPlaySound(sound.three, 2);
			if (colors.three == FALSE)
				colors.three++;
			else
				colors.three--;
		}
		oslAudioVSync();
		oslEndDrawing();
		oslSyncFrame();
	}
	sceKernelUnloadModule(musica);
	oslEndGfx();
	oslQuit();
	return 0;
}
