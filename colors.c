/* Beatbox - colors.c
 * Copyright (c) 2011 Tanner Babcock */
#include <oslib/oslib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

void BBdrawgrid(void) {
	if (colorset == BLACK)
		oslDrawFillRect(75, 51, 405, 221, RGBA(255, 255, 255, 200));
	else
		oslDrawFillRect(75, 51, 405, 221, RGBA(0, 0, 0, 200));
	if (colors.one == TRUE)
		oslDrawFillRect(85, 61, 155, 131, RGBA(colors.onergb[0], colors.onergb[2], colors.onergb[1], 200));
	else
		oslDrawFillRect(85, 61, 155, 131, RGBA(colors.onergb[0], colors.onergb[2], colors.onergb[1], 100));
	if (colors.two == TRUE)
		oslDrawFillRect(165, 61, 235, 131, RGBA(colors.tworgb[0], colors.tworgb[2], colors.tworgb[1], 200));
	else
		oslDrawFillRect(165, 61, 235, 131, RGBA(colors.tworgb[0], colors.tworgb[2], colors.tworgb[1], 100));
	if (colors.three == TRUE)
		oslDrawFillRect(245, 61, 315, 131, RGBA(colors.threergb[0], colors.threergb[2], colors.threergb[1], 200));
	else
		oslDrawFillRect(245, 61, 315, 131, RGBA(colors.threergb[0], colors.threergb[2], colors.threergb[1], 100));
	if (colors.four == TRUE)
		oslDrawFillRect(325, 61, 395, 131, RGBA(colors.fourrgb[0], colors.fourrgb[2], colors.fourrgb[1], 200));
	else
		oslDrawFillRect(325, 61, 395, 131, RGBA(colors.fourrgb[0], colors.fourrgb[2], colors.fourrgb[1], 100));
	if (colors.five == TRUE)
		oslDrawFillRect(85, 141, 155, 211, RGBA(colors.fivergb[0], colors.fivergb[2], colors.fivergb[1], 200));
	else
		oslDrawFillRect(85, 141, 155, 211, RGBA(colors.fivergb[0], colors.fivergb[2], colors.fivergb[1], 100));
	if (colors.six == TRUE)
		oslDrawFillRect(165, 141, 235, 211, RGBA(colors.sixrgb[0], colors.sixrgb[2], colors.sixrgb[1], 200));
	else
		oslDrawFillRect(165, 141, 235, 211, RGBA(colors.sixrgb[0], colors.sixrgb[2], colors.sixrgb[1], 100));
	if (colors.seven == TRUE)
		oslDrawFillRect(245, 141, 315, 211, RGBA(colors.sevenrgb[0], colors.sevenrgb[2], colors.sevenrgb[1], 200));
	else
		oslDrawFillRect(245, 141, 315, 211, RGBA(colors.sevenrgb[0], colors.sevenrgb[2], colors.sevenrgb[1], 100));
	if (colors.eight == TRUE)
		oslDrawFillRect(325, 141, 395, 211, RGBA(colors.eightrgb[0], colors.eightrgb[2], colors.eightrgb[1], 200));
	else
		oslDrawFillRect(325, 141, 395, 211, RGBA(colors.eightrgb[0], colors.eightrgb[2], colors.eightrgb[1], 100));
	return;
}

void BBeditcolors(void) {
	char select = 0, rselect = RED;
	char rstring[10], gstring[10], bstring[10];
	while (!osl_quit) {
		oslStartDrawing();
		oslReadKeys();
		oslCls();
		oslDrawImage(bgimage);
		if (colorsb == TRUE)
			BBdrawgrid();
		oslDrawFillRect(0, 0, 480, 272, RGBA(0, 0, 0, 100));
		if (select == 0) {
			oslDrawString(10, 260, "Color selected: one");
			bzero(rstring, sizeof(rstring));
			bzero(gstring, sizeof(gstring));
			bzero(bstring, sizeof(bstring));
			/* that function zeroes out strings */
			if (rselect == RED)
				sprintf(rstring, "-> R: %d", colors.onergb[0]);
			else
				sprintf(rstring, "   R: %d", colors.onergb[0]);
			if (rselect == GREEN)
				sprintf(gstring, "-> G: %d", colors.onergb[2]);
			else
				sprintf(gstring, "   G: %d", colors.onergb[2]);
			if (rselect == BLUE)
				sprintf(bstring, "-> B: %d", colors.onergb[1]);
			else
				sprintf(bstring, "   B: %d", colors.onergb[1]);
		}
		/* green and blue are mixed up */
		else if (select == 1) {
			oslDrawString(10, 260, "Color selected: two");
			bzero(rstring, sizeof(rstring));
			bzero(gstring, sizeof(gstring));
			bzero(bstring, sizeof(bstring));
			if (rselect == RED)
				sprintf(rstring, "-> R: %d", colors.tworgb[0]);
			else
				sprintf(rstring, "   R: %d", colors.tworgb[0]);
			if (rselect == GREEN)
				sprintf(gstring, "-> G: %d", colors.tworgb[2]);
			else
				sprintf(gstring, "   G: %d", colors.tworgb[2]);
			if (rselect == BLUE)
				sprintf(bstring, "-> B: %d", colors.tworgb[1]);
			else
				sprintf(bstring, "   B: %d", colors.tworgb[1]);
		}
		else if (select == 2) {
			oslDrawString(10, 260, "Color selected: three");
			bzero(rstring, sizeof(rstring));
			bzero(gstring, sizeof(gstring));
			bzero(bstring, sizeof(bstring));
			if (rselect == RED)
				sprintf(rstring, "-> R: %d", colors.threergb[0]);
			else
				sprintf(rstring, "   R: %d", colors.threergb[0]);
			if (rselect == GREEN)
				sprintf(gstring, "-> G: %d", colors.threergb[2]);
			else
				sprintf(gstring, "   G: %d", colors.threergb[2]);
			if (rselect == BLUE)
				sprintf(bstring, "-> B: %d", colors.threergb[1]);
			else
				sprintf(bstring, "   B: %d", colors.threergb[1]);
		}
		else if (select == 3) {
			oslDrawString(10, 260, "Color selected: four");
			bzero(rstring, sizeof(rstring));
			bzero(gstring, sizeof(gstring));
			bzero(bstring, sizeof(bstring));
			if (rselect == RED)
				sprintf(rstring, "-> R: %d", colors.fourrgb[0]);
			else
				sprintf(rstring, "   R: %d", colors.fourrgb[0]);
			if (rselect == GREEN)
				sprintf(gstring, "-> G: %d", colors.fourrgb[2]);
			else
				sprintf(gstring, "   G: %d", colors.fourrgb[2]);
			if (rselect == BLUE)
				sprintf(bstring, "-> B: %d", colors.fourrgb[1]);
			else
				sprintf(bstring, "   B: %d", colors.fourrgb[1]);
		}
		else if (select == 4) {
			oslDrawString(10, 260, "Color selected: five");
			bzero(rstring, sizeof(rstring));
			bzero(gstring, sizeof(gstring));
			bzero(bstring, sizeof(bstring));
			if (rselect == RED)
				sprintf(rstring, "-> R: %d", colors.fivergb[0]);
			else
				sprintf(rstring, "   R: %d", colors.fivergb[0]);
			if (rselect == GREEN)
				sprintf(gstring, "-> G: %d", colors.fivergb[2]);
			else
				sprintf(gstring, "   G: %d", colors.fivergb[2]);
			if (rselect == BLUE)
				sprintf(bstring, "-> B: %d", colors.fivergb[1]);
			else
				sprintf(bstring, "   B: %d", colors.fivergb[1]);
		}
		else if (select == 5) {
			oslDrawString(10, 260, "Color selected: six");
			bzero(rstring, sizeof(rstring));
			bzero(gstring, sizeof(gstring));
			bzero(bstring, sizeof(bstring));
			if (rselect == RED)
				sprintf(rstring, "-> R: %d", colors.sixrgb[0]);
			else
				sprintf(rstring, "   R: %d", colors.sixrgb[0]);
			if (rselect == GREEN)
				sprintf(gstring, "-> G: %d", colors.sixrgb[2]);
			else
				sprintf(gstring, "   G: %d", colors.sixrgb[2]);
			if (rselect == BLUE)
				sprintf(bstring, "-> B: %d", colors.sixrgb[1]);
			else
				sprintf(bstring, "   B: %d", colors.sixrgb[1]);
		}
		else if (select == 6) {
			oslDrawString(10, 260, "Color selected: seven");
			bzero(rstring, sizeof(rstring));
			bzero(gstring, sizeof(gstring));
			bzero(bstring, sizeof(bstring));
			if (rselect == RED)
				sprintf(rstring, "-> R: %d", colors.sevenrgb[0]);
			else
				sprintf(rstring, "   R: %d", colors.sevenrgb[0]);
			if (rselect == GREEN)
				sprintf(gstring, "-> G: %d", colors.sevenrgb[2]);
			else
				sprintf(gstring, "   G: %d", colors.sevenrgb[2]);
			if (rselect == BLUE)
				sprintf(bstring, "-> B: %d", colors.sevenrgb[1]);
			else
				sprintf(bstring, "   B: %d", colors.sevenrgb[1]);
		}
		else if (select == 7) {
			oslDrawString(10, 260, "Color selected: eight");
			bzero(rstring, sizeof(rstring));
			bzero(gstring, sizeof(gstring));
			bzero(bstring, sizeof(bstring));
			if (rselect == RED)
				sprintf(rstring, "-> R: %d", colors.eightrgb[0]);
			else
				sprintf(rstring, "   R: %d", colors.eightrgb[0]);
			if (rselect == GREEN)
				sprintf(gstring, "-> G: %d", colors.eightrgb[2]);
			else
				sprintf(gstring, "   G: %d", colors.eightrgb[2]);
			if (rselect == BLUE)
				sprintf(bstring, "-> B: %d", colors.eightrgb[1]);
			else
				sprintf(bstring, "   B: %d", colors.eightrgb[1]);
		}
		oslDrawString(10, 180, rstring);
		oslDrawString(10, 190, gstring);
		oslDrawString(10, 200, bstring);
		oslDrawString(10, 220, "Press X to confirm.");
		oslDrawString(10, 230, "Use the L and R triggers to change the color selected.");
		if (colorsb == TRUE)
			oslDrawString(10, 240, "Press SELECT to disable colors.");
		else
			oslDrawString(10, 240, "Press SELECT to enable colors.");
		if (osl_keys->pressed.down) {
			if (rselect != BLUE)
				rselect++;
		}
		if (osl_keys->pressed.up) {
			if (rselect != RED)
				rselect--;
		}
		if (osl_keys->held.left) {
			if (select == 7) {
				if ((rselect == RED) && (colors.eightrgb[0] != 0))
					colors.eightrgb[0]--;
				else if ((rselect == GREEN) && (colors.eightrgb[2] != 0))
					colors.eightrgb[2]--;
				else if ((rselect == BLUE) && (colors.eightrgb[1] != 0))
					colors.eightrgb[1]--;
			}
			else if (select == 6) {
				if ((rselect == RED) && (colors.sevenrgb[0] != 0))
					colors.sevenrgb[0]--;
				else if ((rselect == GREEN) && (colors.sevenrgb[2] != 0))
					colors.sevenrgb[2]--;
				else if ((rselect == BLUE) && (colors.sevenrgb[1] != 0))
					colors.sevenrgb[1]--;
			}
			else if (select == 5) {
				if ((rselect == RED) && (colors.sixrgb[0] != 0))
					colors.sixrgb[0]--;
				else if ((rselect == GREEN) && (colors.sixrgb[2] != 0))
					colors.sixrgb[2]--;
				else if ((rselect == BLUE) && (colors.sixrgb[1] != 0))
					colors.sixrgb[1]--;
			}
			else if (select == 4) {
				if ((rselect == RED) && (colors.fivergb[0] != 0))
					colors.fivergb[0]--;
				else if ((rselect == GREEN) && (colors.fivergb[2] != 0))
					colors.fivergb[2]--;
				else if ((rselect == BLUE) && (colors.fivergb[1] != 0))
					colors.fivergb[1]--;
			}
			else if (select == 3) {
				if ((rselect == RED) && (colors.fourrgb[0] != 0))
					colors.fourrgb[0]--;
				else if ((rselect == GREEN) && (colors.fourrgb[2] != 0))
					colors.fourrgb[2]--;
				else if ((rselect == BLUE) && (colors.fourrgb[1] != 0))
					colors.fourrgb[1]--;
			}
			else if (select == 2) {
				if ((rselect == RED) && (colors.threergb[0] != 0))
					colors.threergb[0]--;
				else if ((rselect == GREEN) && (colors.threergb[2] != 0))
					colors.threergb[2]--;
				else if ((rselect == BLUE) && (colors.threergb[1] != 0))
					colors.threergb[1]--;
			}
			else if (select == 1) {
				if ((rselect == RED) && (colors.tworgb[0] != 0))
					colors.tworgb[0]--;
				else if ((rselect == GREEN) && (colors.tworgb[2] != 0))
					colors.tworgb[2]--;
				else if ((rselect == BLUE) && (colors.tworgb[1] != 0))
					colors.tworgb[1]--;
			}
			else if (select == 0) {
				if ((rselect == RED) && (colors.onergb[0] != 0))
					colors.onergb[0]--;
				else if ((rselect == GREEN) && (colors.onergb[2] != 0))
					colors.onergb[2]--;
				else if ((rselect == BLUE) && (colors.onergb[1] != 0))
					colors.onergb[1]--;
			}
		}
		if (osl_keys->held.right) {
			if (select == 7) {
				if ((rselect == RED) && (colors.eightrgb[0] != 255))
					colors.eightrgb[0]++;
				else if ((rselect == GREEN) && (colors.eightrgb[2] != 255))
					colors.eightrgb[2]++;
				else if ((rselect == BLUE) && (colors.eightrgb[1] != 255))
					colors.eightrgb[1]++;
			}
			else if (select == 6) {
				if ((rselect == RED) && (colors.sevenrgb[0] != 255))
					colors.sevenrgb[0]++;
				else if ((rselect == GREEN) && (colors.sevenrgb[2] != 255))
					colors.sevenrgb[2]++;
				else if ((rselect == BLUE) && (colors.sevenrgb[1] != 255))
					colors.sevenrgb[1]++;
			}
			else if (select == 5) {
				if ((rselect == RED) && (colors.sixrgb[0] != 255))
					colors.sixrgb[0]++;
				else if ((rselect == GREEN) && (colors.sixrgb[2] != 255))
					colors.sixrgb[2]++;
				else if ((rselect == BLUE) && (colors.sixrgb[1] != 255))
					colors.sixrgb[1]++;
			}
			else if (select == 4) {
				if ((rselect == RED) && (colors.fivergb[0] != 255))
					colors.fivergb[0]++;
				else if ((rselect == GREEN) && (colors.fivergb[2] != 255))
					colors.fivergb[2]++;
				else if ((rselect == BLUE) && (colors.fivergb[1] != 255))
					colors.fivergb[1]++;
			}
			else if (select == 3) {
				if ((rselect == RED) && (colors.fourrgb[0] != 255))
					colors.fourrgb[0]++;
				else if ((rselect == GREEN) && (colors.fourrgb[2] != 255))
					colors.fourrgb[2]++;
				else if ((rselect == BLUE) && (colors.fourrgb[1] != 255))
					colors.fourrgb[1]++;
			}
			else if (select == 2) {
				if ((rselect == RED) && (colors.threergb[0] != 255))
					colors.threergb[0]++;
				else if ((rselect == GREEN) && (colors.threergb[2] != 255))
					colors.threergb[2]++;
				else if ((rselect == BLUE) && (colors.threergb[1] != 255))
					colors.threergb[1]++;
			}
			else if (select == 1) {
				if ((rselect == RED) && (colors.tworgb[0] != 255))
					colors.tworgb[0]++;
				else if ((rselect == GREEN) && (colors.tworgb[2] != 255))
					colors.tworgb[2]++;
				else if ((rselect == BLUE) && (colors.tworgb[1] != 255))
					colors.tworgb[1]++;
			}
			else if (select == 0) {
				if ((rselect == RED) && (colors.onergb[0] != 255))
					colors.onergb[0]++;
				else if ((rselect == GREEN) && (colors.onergb[2] != 255))
					colors.onergb[2]++;
				else if ((rselect == BLUE) && (colors.onergb[1] != 255))
					colors.onergb[1]++;
			}
		}
		if (osl_keys->pressed.R) {
			if (select != 7)
				select++;
		}
		if (osl_keys->pressed.L) {
			if (select != 0)
				select--;
		}
		if (osl_keys->pressed.select) {
			if (colorsb == FALSE)
				colorsb++;
			else
				colorsb--;
		}
		if (osl_keys->pressed.cross)
			break;
		oslEndDrawing();
		oslSyncFrame();
	}
	return;
}

void BBcolorsetswitch(char colorsetaa) {
	/* if ((colorsetaa == BLACK) || (colorsetaa == 69)) {
		green and blue are mixed up, so [2] and [1] are switched
		colors.onergb[0] = 177, colors.onergb[2] = 2, colors.onergb[1] = 2;
		colors.tworgb[0] = 228, colors.tworgb[2] = 143, colors.tworgb[1] = 3;
		colors.threergb[0] = 76, colors.threergb[2] = 174, colors.threergb[1] = 161;
		colors.fourrgb[0] = 81, colors.fourrgb[2] = 39, colors.fourrgb[1] = 8;
		colors.fivergb[0] = 78, colors.fivergb[2] = 134, colors.fivergb[1] = 1;
		colors.sixrgb[0] = 0, colors.sixrgb[2] = 64, colors.sixrgb[1] = 128;
		colors.sevenrgb[0] = 255, colors.sevenrgb[2] = 102, colors.sevenrgb[1] = 0;
		colors.eightrgb[0] = 208, colors.eightrgb[2] = 133, colors.eightrgb[1] = 4;
	} else if (colorsetaa == WARM) {
		colors.onergb[0] = 255, colors.onergb[2] = 0, colors.onergb[1] = 0;
		colors.tworgb[0] = 208, colors.tworgb[2] = 133, colors.tworgb[1] = 4;
		colors.threergb[0] = 255, colors.threergb[2] = 255, colors.threergb[1] = 0;
		colors.fourrgb[0] = 255, colors.fourrgb[2] = 255, colors.fourrgb[1] = 255;
		colors.fivergb[0] = 255, colors.fivergb[2] = 255, colors.fivergb[1] = 255;
		colors.sixrgb[0] = 255, colors.sixrgb[2] = 255, colors.sixrgb[1] = 0;
		colors.sevenrgb[0] = 208, colors.sevenrgb[2] = 133, colors.sevenrgb[1] = 4;
		colors.eightrgb[0] = 255, colors.eightrgb[2] = 0, colors.eightrgb[1] = 0;
	} else if (colorsetaa == COOL) {
		colors.onergb[0] = 0, colors.onergb[2] = 255, colors.onergb[1] = 0;
		colors.tworgb[0] = 0, colors.tworgb[2] = 0, colors.tworgb[1] = 255;
		colors.threergb[0] = 0, colors.threergb[2] = 255, colors.threergb[1] = 255;
		colors.fourrgb[0] = 255, colors.fourrgb[2] = 50, colors.fourrgb[1] = 255;
		colors.fivergb[0] = 255, colors.fivergb[2] = 50, colors.fivergb[1] = 255;
		colors.sixrgb[0] = 0, colors.sixrgb[2] = 255, colors.sixrgb[1] = 255;
		colors.sevenrgb[0] = 0, colors.sevenrgb[2] = 0, colors.sevenrgb[1] = 255;
		colors.eightrgb[0] = 0, colors.eightrgb[2] = 255, colors.eightrgb[1] = 0;
	} else */ if (colorsetaa == BLACK) {
		bzero(colors.onergb, sizeof(colors.onergb));
		bzero(colors.tworgb, sizeof(colors.tworgb));
		bzero(colors.threergb, sizeof(colors.threergb));
		bzero(colors.fourrgb, sizeof(colors.fourrgb));
		bzero(colors.fivergb, sizeof(colors.fivergb));
		bzero(colors.sixrgb, sizeof(colors.sixrgb));
		bzero(colors.sevenrgb, sizeof(colors.sevenrgb));
		bzero(colors.eightrgb, sizeof(colors.eightrgb));
	} else {
		colors.onergb[0] = 255, colors.onergb[2] = 255, colors.onergb[1] = 255;
		colors.tworgb[0] = 255, colors.tworgb[2] = 255, colors.tworgb[1] = 255;
		colors.threergb[0] = 255, colors.threergb[2] = 255, colors.threergb[1] = 255;
		colors.fourrgb[0] = 255, colors.fourrgb[2] = 255, colors.fourrgb[1] = 255;
		colors.fivergb[0] = 255, colors.fivergb[2] = 255, colors.fivergb[1] = 255;
		colors.sixrgb[0] = 255, colors.sixrgb[2] = 255, colors.sixrgb[1] = 255;
		colors.sevenrgb[0] = 255, colors.sevenrgb[2] = 255, colors.sevenrgb[1] = 255;
		colors.eightrgb[0] = 255, colors.eightrgb[2] = 255, colors.eightrgb[1] = 255;
	} /* else if (colorsetaa == STEEL) {
		colors.onergb[0] = 255, colors.onergb[2] = 0, colors.onergb[1] = 0;
		colors.tworgb[0] = 255, colors.tworgb[2] = 255, colors.tworgb[1] = 255;
		colors.threergb[0] = 255, colors.threergb[2] = 255, colors.threergb[1] = 255;
		colors.fourrgb[0] = 0, colors.fourrgb[2] = 0, colors.fourrgb[1] = 0;
		colors.fivergb[0] = 255, colors.fivergb[2] = 255, colors.fivergb[1] = 255;
		colors.sixrgb[0] = 0, colors.sixrgb[2] = 0, colors.sixrgb[1] = 0;
		colors.sevenrgb[0] = 0, colors.sevenrgb[2] = 0, colors.sevenrgb[1] = 0;
		colors.eightrgb[0] = 255, colors.eightrgb[2] = 0, colors.eightrgb[1] = 0;
	} */
	if (colorsetaa == 69) {
		colors.one = FALSE;
		colors.two = FALSE;
		colors.three = FALSE;
		colors.four = FALSE;
		colors.five = FALSE;
		colors.six = FALSE;
		colors.seven = FALSE;
		colors.eight = FALSE;
	}
	return;
}
