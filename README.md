# FicelloEngine
A small open source C++ SDL2 game engine for linux with lua as scripting language

This is still in creation so there is no doc at the moment.

## Downloading dependencies
Arch Linux:

```bash
pacman -S sdl2
pacman -S base-devel
pacman -S cmake
```

Debian:

```bash
apt-get install build-essentials
apt-get install libsdl2-dev libsdl2-2.0-0
```

## Building

```bash
cd FicelloEngine/build
chmod +x build.sh
./build.sh
```

## How to use FicelloEngine to make games?
You need to go on release section to download the latest version of FicelloEngine or you can build from source to get "FicelloEngine" binary located in build/src

Once you got it, you can try your game by doing that command:

```bash
./FicelloEngine yourfile.lua
```
