/* Beatbox - main.h
 * Copyright (c) 2011 Tanner Babcock */
#ifndef MAIN_H
#define MAIN_H

#include <oslib/oslib.h>
#include <pspkernel.h>
#define FALSE 0
#define TRUE (!FALSE)
#define VERSION "1.6"

enum UN { METRONOMEM, SOUNDSETM, MODEM, SCHEMEM, EDITCOLORS, HELP, QUIT };
enum DEUX { ROCK, HIPHOP, BONGO, TONE };
enum TROIS { FOURKEY, EIGHTKEY };
enum QUATRE { RED, GREEN, BLUE };
enum CINQ { WHITE, BLACK };

struct sound {
	OSL_SOUND *one, *two, *three, *four;
	OSL_SOUND *five, *six, *seven, *eight;
} sound;

struct colors {
	int onergb[3];
	int tworgb[3];
	int threergb[3];
	int fourrgb[3];
	int fivergb[3];
	int sixrgb[3];
	int sevenrgb[3];
	int eightrgb[3];
	char one, two, three, four, five;
	char six, seven, eight, nine, ten;
} colors;

SceUID musica;
clock_t start, current, d;
OSL_IMAGE *bgimage, *intro, *splash, *babkock, *options;
OSL_SOUND *metronome;
FILE *musicconfig;
char menuoption, soundset, colorset, mode, colorsb, musexist;
char soundstring[25];
int metronomeb;

void BBmsg(int x, int y, const char *str);
void BBinit(void);
void BBpause(void);
void BBhelp(void);
void BBmusic(void);
void BBsoundsetswitch(char soundsetaa);
void BBdrawgrid(void);
void BBeditcolors(void);
void BBcolorsetswitch(char colorsetaa);
void setUpVirtualFileMenu(void);
void BBloadfiles(void);

#endif
