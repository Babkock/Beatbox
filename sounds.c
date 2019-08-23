/* Beatbox - sounds.c
 * Copyright (c) 2011 Tanner Babcock */
#include <oslib/oslib.h>
#include <stdio.h>
#include "main.h"

void BBsoundsetswitch(char soundsetaa) {
	BBmsg(10, 10, "Loading sound set...");
	if (soundsetaa == ROCK) {
		sound.one = oslLoadSoundFile("sounds/rock_1.wav", OSL_FMT_NONE);
		sound.two = oslLoadSoundFile("sounds/rock_2.wav", OSL_FMT_NONE);
		sound.three = oslLoadSoundFile("sounds/rock_3.wav", OSL_FMT_NONE);
		sound.four = oslLoadSoundFile("sounds/rock_4.wav", OSL_FMT_NONE);
		sound.five = oslLoadSoundFile("sounds/rock_5.wav", OSL_FMT_NONE);
		sound.six = oslLoadSoundFile("sounds/rock_6.wav", OSL_FMT_NONE);
		sound.seven = oslLoadSoundFile("sounds/rock_7.wav", OSL_FMT_NONE);
		sound.eight = oslLoadSoundFile("sounds/rock_8.wav", OSL_FMT_NONE);
	}
	else if (soundsetaa == HIPHOP) {
		sound.one = oslLoadSoundFile("sounds/hiphop_1.wav", OSL_FMT_NONE);
		sound.two = oslLoadSoundFile("sounds/hiphop_2.wav", OSL_FMT_NONE);
		sound.three = oslLoadSoundFile("sounds/hiphop_3.wav", OSL_FMT_NONE);
		sound.four = oslLoadSoundFile("sounds/hiphop_4.wav", OSL_FMT_NONE);
		sound.five = oslLoadSoundFile("sounds/hiphop_5.wav", OSL_FMT_NONE);
		sound.six = oslLoadSoundFile("sounds/hiphop_6.wav", OSL_FMT_NONE);
		sound.seven = oslLoadSoundFile("sounds/hiphop_7.wav", OSL_FMT_NONE);
		sound.eight = oslLoadSoundFile("sounds/hiphop_8.wav", OSL_FMT_NONE);
	}
	else if (soundsetaa == BONGO) {
		sound.one = oslLoadSoundFile("sounds/bongo_1.wav", OSL_FMT_NONE);
		sound.two = oslLoadSoundFile("sounds/bongo_2.wav", OSL_FMT_NONE);
		sound.three = oslLoadSoundFile("sounds/bongo_3.wav", OSL_FMT_NONE);
		sound.four = oslLoadSoundFile("sounds/bongo_4.wav", OSL_FMT_NONE);
		sound.five = oslLoadSoundFile("sounds/bongo_5.wav", OSL_FMT_NONE);
		sound.six = oslLoadSoundFile("sounds/bongo_6.wav", OSL_FMT_NONE);
		sound.seven = oslLoadSoundFile("sounds/bongo_7.wav", OSL_FMT_NONE);
		sound.eight = oslLoadSoundFile("sounds/bongo_8.wav", OSL_FMT_NONE);
	}
	else {
		sound.one = oslLoadSoundFile("sounds/tones_1.wav", OSL_FMT_NONE);
		sound.two = oslLoadSoundFile("sounds/tones_2.wav", OSL_FMT_NONE);
		sound.three = oslLoadSoundFile("sounds/tones_3.wav", OSL_FMT_NONE);
		sound.four = oslLoadSoundFile("sounds/tones_4.wav", OSL_FMT_NONE);
		sound.five = oslLoadSoundFile("sounds/tones_5.wav", OSL_FMT_NONE);
		sound.six = oslLoadSoundFile("sounds/tones_6.wav", OSL_FMT_NONE);
		sound.seven = oslLoadSoundFile("sounds/tones_7.wav", OSL_FMT_NONE);
		sound.eight = oslLoadSoundFile("sounds/tones_8.wav", OSL_FMT_NONE);
	}
	if (!sound.one || !sound.two || !sound.three || !sound.four || !sound.five ||
		!sound.six || !sound.seven || !sound.eight) {
		BBmsg(10, 10, "ERROR: one or more sound files missing, exiting...");
		oslEndGfx();
		oslQuit();
	}
	soundset = soundsetaa;
	return;
}
