# Beatbox 1.6

![test](https://raw.githubusercontent.com/Babkock/Beatbox/master/files/PIC1.png)

Beatbox version 1.6 was originally completed in May 2011. Back in those days, I compiled images directly into the binary, for loading them from the virtual file system in RAM. `fopen()` calls with a `ms0:/` prefix on the file path denotes the PSP's Memory Stick. `ram:/` denotes RAM. The various flash drives for loading firmware and system resources can also be accessed via `flash0:/`, `flash1:/`, and so on.

## Original Readme

Beatbox is a drum machine for the PlayStation Portable. There are four sound sets: rock and roll drums, hip hop, drums, and bongo drums. Change the sound set in the pause menu.
Eight-key mode allows you to play eight different drum sounds, as opposed to four-key mode, which only allows you to play four different drum sounds. Toggle eight-key mode in the pause menu. As you play, lights will flash in the middle of the screen. You can edit the colors in the pause menu.
Or, you can disable this function in the pause menu.

## Installation

If you have custom firmware or a homebrew-enabled PSP, create a folder named "Beatbox" in your `/PSP/GAME` folder, and place `EBOOT.PBP` inside of it.

## License

This program is free software; you can redistribute it and/or modify it under the terms of the [GNU General Public License](https://github.com/Babkock/Beatbox/blob/master/LICENSE.md) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, visit [http://www.gnu.org/licenses/gpl-2.0.txt](http://www.gnu.org/licenses/gpl-2.0.txt)

If you want to redistribute any modifications you make to the program, please credit yourself in the modified source file(s) under my name as,

```
Copyright (c) <year> <your name here>
```

Feel free to contact me at [babkock@gmail.com](mailto:babkock@gmail.com) if you have any questions or concerns. Thanks for playing :)
