# Sonic CD 2011 Engine Revisited (RSDKv3)
### A fork of [Rubberduckycooly's Sonic CD 2011 Decompilation](https://github.com/Rubberduckycooly/Sonic-CD-2011-Script-Decompilation)
&nbsp;

## Please support the official releases!
Just like the original decompilation that this project is based on, it will not run correctly without assets from the official release. If possible, please update your copy of the official release to the newest version before retrieving the RSDK file from the app's install folder.

+ You can purchase an official copy of Sonic CD that is compatible with this project from the following links:
  * [Windows (via Steam)](https://store.steampowered.com/app/200940/Sonic_CD/)
  * [iOS (via the App Store)](https://apps.apple.com/us/app/sonic-cd-classic/id454316134)
  * [Android (via Google Play)](https://play.google.com/store/apps/details?id=com.sega.soniccd.classic&hl=en&gl=US)
  * [Android (via Amazon Appstore)](https://www.amazon.com/Sega-of-America-Sonic-CD/dp/B008K9UZY4/ref=sr_1_2?dchild=1&keywords=Sonic+CD&qid=1607930514&sr=8-2)

## Current Project Goals
### Completed
+ None (yet!)
### Partially Completed
+ Enhance pause functionality to allow for non-janky animations directly over paused gameplay
  * Introduced soft/hard pause modes and a script variable to enable/disable soft pause functionality on a per-stage basis
  * Disabled fixed-speed horizontal and vertical parallax updates while soft paused
  * However, soft pause doesn't prevent objects from updating when state-altering code is present in an object's ObjectDraw function. This can also include parallax, deformation, and animated tile effects on BG and FG tiles. Objects that do so must be manually hunted down and corrected (ugh).
### Planned
+ Ability to detect, switch between, and use keyboard/physical and mouse/touch controls on all platforms
+ Reduction of reliance on engine callbacks for some common operations
+ Elimination of accommodations for outdated platforms (WP7, anyone?)
+ Elimination of unnecessary code for trial/demo versions, GDPR/age gates, etc.
+ Where necessary/possible, changes to support merging standard/mobile script sections
+ Ability to port completed changes to the RSDKv4 decompilation
### Possible
+ Manual updating of fixed-speed parallax effects via scripting and a script variable to enable/disable it
+ Additional, more specific script functions to replace engine callbacks (for exiting the game, etc.)
+ Android Studio project for building an Android version of the project

## Building a working executable:
These instructions were copied from the original repository and slightly modified for this project. If you encounter difficulties, please view the Readme file on the original repository [here](https://github.com/Rubberduckycooly/Sonic-CD-2011-Script-Decompilation) in case changes were made there and pushed to this forked repository without an update to this Readme.

### Windows:
* Clone the repo, follow the instructions in the [dependencies readme for Windows](./dependencies/windows/dependencies.txt) to setup dependencies, then build via the provided Visual Studio solution.

### Universal Windows Platform (UWP):
* Clone the repo, follow the instructions in the [dependencies readme for Windows](./dependencies/windows/dependencies.txt) and [dependencies readme for UWP](./dependencies/win-uwp/dependencies.txt) to setup dependencies, then build and deploy via the provided UWP-specific Visual Studio solution.
* After installation, copy your `Data.rsdk` and `videos` folder into the app's localstate folder.

### Windows via MSYS2 (64-bit only):
* Download the newest version of the MSYS2 installer from [here](https://www.msys2.org/) and install it.
* Run the MINGW64 command prompt (from the Windows Start Menu/MSYS2 64-bit/MSYS2 MinGW 64-bit). When the program starts, enter `pacman -Syuu` into the prompt and hit Enter. Press `Y` when it asks if you want to update packages. If it asks you to close the prompt, do so and then restart it and run the same command again. This will update the packages to their latest versions.
* Now install the dependencies with the following command: `pacman -S pkg-config make git mingw-w64-x86_64-gcc mingw-w64-x86_64-SDL2 mingw-w64-x86_64-libogg mingw-w64-x86_64-libvorbis mingw-w64-x86_64-libtheora`.
* Clone the repo with the following command: `git clone https://github.com/asistacular/Sonic-CD-2011-Engine-Revisited.git`.
* Go into the repo you just cloned with `cd Sonic-CD-2011-Engine-Revisited`.
* Then run the following command: `make CXXFLAGS=-O2 CXX=x86_64-w64-mingw32-g++ STATIC=1 -j5` (the -j switch is optional, but will make building faster. It's based on the number of cores you have +1, so 8 cores would be -j9).

### MacOS:
* Clone the repo, follow the instructions in the [dependencies readme for Mac](./dependencies/mac/dependencies.txt) to setup dependencies, then build via the provided Xcode project.

### Linux:
* To setup your build enviroment and library dependecies, run the following commands:
* Ubuntu (Mint, Pop!_OS, etc...): `sudo apt install build-essential git libsdl2-dev libvorbis-dev libogg-dev libtheora-dev`
* Arch Linux: `sudo pacman -S base-devel git sdl2 libvorbis libogg libtheora`
* Clone the repo with the following command: `git clone https://github.com/asistacular/Sonic-CD-2011-Engine-Revisited.git`.
* Go into the repo you just cloned with `cd Sonic-CD-2011-Engine-Revisited`.
* Then run the following command: `make CXXFLAGS=-O2 -j5` (the -j switch is optional, but will make building faster. It's based on the number of cores you have +1, so 8 cores would be -j9).

### iOS:
* Clone the repo, follow the instructions in the [dependencies readme for iOS](./dependencies/ios/dependencies.txt) to setup dependencies, then build via the provided Xcode project.

### PS Vita:
* Ensure you have Docker installed and run the script `build.sh` from `SonicCD.Vita`. If you are on Windows, WSL2 is recommended.
NOTE: You will need to copy your Sonic CD game data into `ux0:data/SonicCD` in order to boot the game.

### Other platforms:
Currently the only "officially" supported platforms are the ones listed above, however the backend uses libogg, libvorbis, libtheora & SDL2 to power it, so the codebase is very multi-platform. An Android version built using an Android Studio project may be added eventually. If an Android Studio project is added, I will also submit it to Rubberduckycooly's original repository as well.
