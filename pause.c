/* Beatbox - pause.c
 * Copyright (c) 2011 Tanner Babcock */
#include <oslib/oslib.h>
#include <pspsdk.h>
#include <stdio.h>
#include "main.h"

void BBpause(void) {
	int x = FALSE, y = FALSE, z = FALSE;
	char mstr[20];
	while (!osl_quit) {
		oslStartDrawing();
		oslReadKeys();
		oslCls();
		oslDrawImage(bgimage);
		if (colorsb == TRUE)
			BBdrawgrid();
		oslDrawFillRect(0, 0, 480, 272, RGBA(0, 0, 0, 100));
		if (menuoption == METRONOMEM) {
			if (metronomeb == FALSE)
				oslDrawString(10, 80, "-> Metronome: off");
			else
				oslDrawString(10, 80, "-> Metronome: on");
		} else {
			if (metronomeb == FALSE)
				oslDrawString(10, 80, "   Metronome: off");
			else
				oslDrawString(10, 80, "   Metronome: on");
		} if (menuoption == SOUNDSETM) {
			if (soundset == ROCK)
				oslDrawString(10, 90, "-> Sound set: rock");
			else if (soundset == HIPHOP)
				oslDrawString(10, 90, "-> Sound set: hip hop");
			else if (soundset == BONGO)
				oslDrawString(10, 90, "-> Sound set: bongo");
			else
				oslDrawString(10, 90, "-> Sound set: tones");
		} else {
			if (soundset == ROCK)
				oslDrawString(10, 90, "   Sound set: rock");
			else if (soundset == HIPHOP)
				oslDrawString(10, 90, "   Sound set: hip hop");
			else if (soundset == BONGO)
				oslDrawString(10, 90, "   Sound set: bongo");
			else
				oslDrawString(10, 90, "   Sound set: tones");
		} if (menuoption == MODEM) {
			if (mode == FOURKEY)
				oslDrawString(10, 100, "-> Mode: four-key");
			else
				oslDrawString(10, 100, "-> Mode: eight-key");
		} else {
			if (mode == FOURKEY)
				oslDrawString(10, 100, "   Mode: four-key");
			else
				oslDrawString(10, 100, "   Mode: eight-key");
		} if (menuoption == SCHEMEM) {
			if (colorset == BLACK)
				oslDrawString(10, 120, "-> Grid style: black");
			else
				oslDrawString(10, 120, "-> Grid style: white");
		} else {
			if (colorset == BLACK)
				oslDrawString(10, 120, "   Grid style: black");
			else
				oslDrawString(10, 120, "   Grid style: white");
		} if (menuoption == EDITCOLORS)
			oslDrawString(10, 130, "-> Edit colors");
		else
			oslDrawString(10, 130, "   Edit colors");
		if (menuoption == HELP)
			oslDrawString(10, 140, "-> Help me");
		else
			oslDrawString(10, 140, "   Help me");
		if (menuoption == QUIT)
			oslDrawString(10, 150, "-> Quit");
		else
			oslDrawString(10, 150, "   Quit");
		if ((osl_keys->pressed.down) && (menuoption != QUIT))
			menuoption++;
		if ((osl_keys->pressed.up) && (menuoption != METRONOMEM))
			menuoption--;
		if (osl_keys->pressed.right) {
			if (menuoption == METRONOMEM) {
				if (metronomeb == FALSE) {
					oslSetSoundLoop(metronome, 1);
					oslPlaySound(metronome, 7);
					metronomeb++;
				}
			} if (menuoption == SOUNDSETM) {
				if (soundset != TONE)
					soundset++;
				x = TRUE;
			} else if (menuoption == MODEM) {
				if (mode == FOURKEY)
					mode++;
			} else if (menuoption == SCHEMEM) {
				if (colorset == WHITE)
					colorset = BLACK;
				y = TRUE;
			}
		}
		if (osl_keys->pressed.left) {
			if (menuoption == METRONOMEM) {
				if (metronomeb == TRUE) {
					oslStopSound(metronome);
					metronomeb--;
				}
			} if (menuoption == SOUNDSETM) {
				if (soundset != ROCK)
					soundset--;
				x = TRUE;
			} else if (menuoption == MODEM) {
				if (mode == EIGHTKEY)
					mode--;
			} else if (menuoption == SCHEMEM) {
				if (colorset == BLACK)
					colorset = WHITE;
				y = TRUE;
			}
		}
		if (osl_keys->pressed.cross) {
			if (menuoption == QUIT) {
				oslEndGfx();
				oslQuit();
				break;
			} else if (menuoption == HELP)
				BBhelp();
			else if (menuoption == EDITCOLORS)
				BBeditcolors();
		}
		if (osl_keys->pressed.start)
			break;
		oslAudioVSync();
		oslEndDrawing();
		oslSyncFrame();
	}
	if (x == TRUE)
		BBsoundsetswitch(soundset);
	if (y == TRUE)
		BBcolorsetswitch(colorset);
	return;
}

void BBhelp(void) {
	while (!osl_quit) {
		oslStartDrawing();
		oslReadKeys();
		oslDrawImage(bgimage);
		if (colorsb == TRUE)
			BBdrawgrid();
		oslDrawFillRect(0, 0, 480, 272, RGBA(0, 0, 0, 100));
		oslDrawString(10, 10, "Beatbox is a drum machine for the PlayStation Portable.");
		oslDrawString(10, 20, "There are four sound sets: rock and roll drums, hip hop");
		oslDrawString(10, 30, "drums, bongo drums, and tones.");
		oslDrawString(10, 50, "Change the sound set in the pause menu.");
		oslDrawString(10, 70, "Eight-key mode allows you to play eight different drum");
		oslDrawString(10, 80, "sounds, as opposed to four-key mode, which only allows you");
		oslDrawString(10, 90, "to play four different drum sounds.");
		oslDrawString(10, 110, "Toggle eight-key mode in the pause menu.");
		oslDrawString(10, 130, "As you play, lights will flash in the middle of");
		oslDrawString(10, 140, "the screen. You can edit the colors in the pause menu.");
		oslDrawString(10, 160, "Or, you can disable this function in the pause menu.");
		oslDrawString(10, 180, "You can play along with your own music in the ms0:/MUSIC");
		oslDrawString(10, 190, "folder. Hold SELECT while playing to use the music");
		oslDrawString(10, 200, "player.");
		oslDrawString(10, 220, "The Music PRX has been fixed in version 1.6.");
		oslDrawString(10, 230, "Music PRX plugin by joek2100.");
		oslDrawString(10, 250, "Press O to hide this screen.");
		if (osl_keys->pressed.circle)
			break;
		oslEndDrawing();
		oslSyncFrame();
	}
	return;
}

void BBmusic(void) {
	oslDrawFillRect(0, 0, 480, 272, RGBA(0, 0, 0, 100));
	if (musexist == FALSE)
		oslDrawString(12, 80, "Music plug-in is disabled.");
	else {
		oslDrawString(12, 80, "SELECT + L Trigger");
		oslDrawString(200, 80, "Play / pause");
		oslDrawString(12, 90, "SELECT + R Trigger");
		oslDrawString(200, 90, "Toggle random");
		oslDrawString(12, 100, "SELECT + Left");
		oslDrawString(200, 100, "Previous track");
		oslDrawString(12, 110, "SELECT + Right");
		oslDrawString(200, 110, "Next track");
		oslDrawString(12, 120, "SELECT + Up");
		oslDrawString(200, 120, "Increase music volume");
		oslDrawString(12, 130, "SELECT + Down");
		oslDrawString(200, 130, "Decrease music volume");
		oslDrawString(12, 140, "SELECT + Square");
		oslDrawString(200, 140, "Display");
	}
	return;
}
