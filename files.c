/* Beatbox - files.c
 * Copyright (c) 2011 Tanner Babcock */
#include <oslib/oslib.h>
#include <pspsdk.h>
#include "main.h"
#include "files.h"

void setUpVirtualFileMenu() {
	OSL_VIRTUALFILENAME ram_files[] = {
		{"ram:/babkock.png", (void*)babkock_data, sizeof(babkock_data), &VF_MEMORY},
		{"ram:/background.png", (void*)background_data, sizeof(background_data), &VF_MEMORY},
		{"ram:/intro.png", (void*)intro_data, sizeof(intro_data), &VF_MEMORY},
		{"ram:/options.png", (void*)options_data, sizeof(options_data), &VF_MEMORY},
		{"ram:/splash.png", (void*)splash_data, sizeof(splash_data), &VF_MEMORY}};
	oslAddVirtualFileList(ram_files, oslNumberof(ram_files));
}

void BBloadfiles() {
	musexist = TRUE;
	BBmsg(10, 10, "Loading virtual files to RAM...");
	setUpVirtualFileMenu();
	BBmsg(10, 20, "Loading rock sound set...");
	sound.one = oslLoadSoundFile("sounds/rock_1.wav", OSL_FMT_NONE);
	sound.two = oslLoadSoundFile("sounds/rock_2.wav", OSL_FMT_NONE);
	sound.three = oslLoadSoundFile("sounds/rock_3.wav", OSL_FMT_NONE);
	sound.four = oslLoadSoundFile("sounds/rock_4.wav", OSL_FMT_NONE);
	sound.five = oslLoadSoundFile("sounds/rock_5.wav", OSL_FMT_NONE);
	sound.six = oslLoadSoundFile("sounds/rock_6.wav", OSL_FMT_NONE);
	sound.seven = oslLoadSoundFile("sounds/rock_7.wav", OSL_FMT_NONE);
	sound.eight = oslLoadSoundFile("sounds/rock_8.wav", OSL_FMT_NONE);
	BBmsg(10, 30, "Loading metronome...");
	metronome = oslLoadSoundFile("sounds/metronome.wav", OSL_FMT_NONE);
	BBmsg(10, 40, "Loading images from RAM...");
	bgimage = oslLoadImageFile("ram:/background.png", OSL_IN_RAM, OSL_PF_5551);
	intro = oslLoadImageFile("ram:/intro.png", OSL_IN_RAM, OSL_PF_5551);
	babkock = oslLoadImageFile("ram:/babkock.png", OSL_IN_RAM, OSL_PF_5551);
	options = oslLoadImageFile("ram:/options.png", OSL_IN_RAM, OSL_PF_5551);
	splash = oslLoadImageFile("ram:/splash.png", OSL_IN_RAM, OSL_PF_5551);
	BBmsg(10, 50, "Checking for music PRX config...");
	musicconfig = fopen("ms0:/seplugins/music_conf.txt", "r");
	if (musicconfig == NULL) {
		while (!osl_quit) {
			oslStartDrawing();
			oslReadKeys();
			oslDrawString(10, 70, "ms0:/seplugins/music_conf.txt doesn\'t exist. You will not be able to");
			oslDrawString(10, 80, "use the in-game music plugin without it. Would you like to write a");
			oslDrawString(10, 90, "default configuration file? (X - yes, O - no)");
			if (osl_keys->pressed.cross) {
				fclose(musicconfig);
				musicconfig = fopen("ms0:/seplugins/music_conf.txt", "w");
				BBmsg(10, 100, "Writing default music PRX config...");
				fwrite(mcdata, sizeof(mcdata), 1, musicconfig);
				fclose(musicconfig);
				break;
			} if (osl_keys->pressed.circle) {
				musexist = FALSE;
				break;
			}
			oslEndDrawing();
			oslSyncFrame();
		}
	} else
		fclose(musicconfig);
	return;
}
