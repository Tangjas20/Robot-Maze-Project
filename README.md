# ELEC1601 Robot-Maze Project

Template by Chris. P taken from https://github.sydney.edu.au/cpol3526/ELEC1601-project-template

## Table of Contents

- [Structure of repo](#structure-of-repo)
- [Dependencies](#dependencies)
  - [Windows](#windows)
  - [macOS](#macos)
  - [Linux](#linux)
- [Running the program](#running-the-program)
  - [Windows](#windows-1)
  - [macOS/Linux](#macoslinux)
- [Compiling without running](#compiling-without-running)
  - [Windows](#windows-powershellcommand-prompt)
  - [macOS/Linux](#macoslinux-1)

## Structure of repo

- `.vscode/` - various adjustments for Visual Studio Code users for easier coding, such as updating `includePath` property so that VS Code can recognise our header files. Configurations available for Windows, macOS and Linux.
  - If you are developing on Windows, it is important to run 
    ```powershell
    git config --global core.autocrlf false
    ```
    to avoid any strange conflicts that might come in commit diffs based on how Windows handle end-of-line characters, as well as setting your end-of-line sequence in your IDE to "LF" rather than "CRLF".
- `include/` - folder containing header files (files that have the `.h` extension) - these usually contain code we want to import in other files.
- `os/` - folder which contains OS-specific files for compilation - for our case, this contains the SDL2 and SDL2_gfx files required just for Windows users.
- `src/` - folder containing source code files (files that have the `.c` extension) - these control how various components of our program work.
- `Makefile` - automatically compiles program and allows for easy checking of source code changes by using the Make build automation program.
- `build_run_clean.sh` - Bash shell script to to easily build, run, and clean up files after building program in one step for macOS and Linux - a really handy shortcut!
- `build_run_clean.sh` - a Batch script for Windows that does the same things as `build_run_clean.sh`, just, well, for Windows.

## Dependencies

- GCC compiler for code
  - On Windows, you will have to install a toolkit which supports this. The most common one is Mingw-w64 - instructions for installing are below.
  - On macOS, if you have Command Line Tools for Xcode installed, `gcc` points to Clang to compile C programs, which effecitvely produces the same output.
  - On Linux, `gcc` should be available from most distro's repositories.
- SDL2 (included in repository for Windows)
- SDL2_gfx (included in repository for Windows)
- Make program for interpreting makefiles
  - On Windows, we will use `mingw32-make` from Mingw-w64
  - On macOS, this is usually preinstalled as `make`
  - On Linux, this is available in most distro repositories as `make`

Installation instructions are below:

### Windows

To be able to compile the code in this repository, you will need to obtain a GCC compiler for Windows. The most popular one is included in the Mingw-w64 toolkit.

To install the latest version of GCC available for Windows with Mingw-w64, you can install the MSYS2 platform, which provides a variety of Unix tools for Windows, as well as a Unix-like shell for managing and updating them. The installation for MSYS2, as well as Mingw-w64, are available from their website: https://www.msys2.org/. Alternatively, you can also install Mingw-w64 as a standalone software: https://sourceforge.net/projects/mingw-w64/.

Once Mingw-w64 is installed, you will need to add the location of its executible files to the Windows `PATH` environment variable to allow for us to be able to access them by name from the command line. There is a good guide by Microsoft on their Visual Studio Code website on how you can do this: https://code.visualstudio.com/docs/cpp/config-mingw - simply scroll to 
"Step 4" under "Prerequisites". If you installed Mingw-w64 as standalone software, the instructions will be the same - just ensure you are referring to the `bin\` folder from the Mingw-w64 installation folder, rather than under the MSYS2 folder as in the guide.

SDL2 and SDL2_gfx files are included within this repository and are used when compiling on Windows, so after this, you are ready to compile and run!

### macOS

If you don't already have Command Line tools for Xcode installed, install them by typing this into your terminal:

```bash
xcode-select --install
```

After installing them, you will need to agree to the license in order to be able to use them - you can do so by running

```bash
sudo xcode-build -license
```

and scrolling to the bottom and agreeing to the terms.

After this, if you don't have Homebrew or an equivalent package manager for macOS installed, install Homebrew by following their website: https://brew.sh/.

Using Homebrew, run:

```bash
brew install sdl2 sdl2-gfx
```

To compile the project, you will need configure the compiler to recognise the SDL2 libraries you installed from Homebrew.

To do this, you'll need to adjust the environment variables `CPATH` and `LIBRARY_PATH` in your shell profile (usually `~/.zshrc`).

If you have an M1 Mac, add the following to your profile:

```bash
export CPATH=/opt/homebrew/include
export LIBRARY_PATH=/opt/homebrew/lib
```

If you have an Intel Mac, add the following to your profile:

```bash
export CPATH=/usr/local/include
export LIBRARY_PATH=/usr/local/lib
```

After that you should be all set.

### Linux

Ensure you have both `gcc` and `make` installed on your system. Once done, install SDL2 and SDL2_gfx from your distro's package manager.

#### Ubuntu/Debian

Installing `gcc` and `make` with the `build-essential` metapackage:

```bash
sudo apt install build-essential
```

Installing SDL2 and SDL2_gfx:

```bash
sudo apt install libsdl2-2.0-0 libsdl2-dev libsdl2-gfx-1.0-0 libsdl2-gfx-dev
```

#### Fedora

Installing `gcc` and `make`:

```bash
sudo dnf install gcc make
```

Installing SDL2 and SDL2_gfx:

```bash
sudo dnf install SDL2 SDL2-devel SDL2_gfx SDL_gfx-devel
```

#### Arch Linux

Installing `gcc` and `make` with the `base-devel` metapackage:

```bash
sudo pacman -S base-devel
```

Installing SDL2 and SDL2_gfx:

```bash
sudo pacman -S sdl2 sdl2_gfx
```

## Running the program

### Windows

Double click the `build_run_clean.bat` script, or, alternatively, within PowerShell or Command Prompt, run

```powershell
.\build_run_clean.bat
```

### macOS/Linux

To compile, run and clean up the compiled files in one step, simply run the following in your terminal from the project directory:

```bash
./build_run_clean.sh
```

## Compiling without running

To compile the program without running, in your terminal, simply run `mingw32-make` on Windows, or `make` on macOS/Linux, in the project directory.

The compiled file will be saved to the `bin` folder as `main` on macOS and Linux, and `main.exe` on Windows.

To run the compiled program from your terminal:

### macOS/Linux

```bash
./bin/main
```

### Windows (PowerShell/Command Prompt)

```powershell
.\bin\main.exe
```

You can also remove the compiled files from your terminal by running `mingw32-make clean` on Windows, or `make clean` on macOS/Linux.

Marks awarded for both maze completion and completion time.
