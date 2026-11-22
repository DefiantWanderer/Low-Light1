# Low Light

A 2D platformer built in C with the DigiPen CProcessing library for the CSD1401 Software Engineering Project.

You guide a Princess born in darkness towards a light. The light is a lamp you control. Move it to reveal platforms, move the Princess across gaps and avoid hazards. Each level opens with a short story screen and instructions.

## Story

1. The Princess is born in darkness and is drawn towards a light.
2. She follows the light and learns she can affect it.
3. The light reveals a catastrophe.

## Features

- Main menu with a bouncing lamp light and background music
- Level select and loading screens with story text and instructions
- Lamp-based gameplay: platforms are only visible and solid where the lamp light reaches
- Hazards: spikes, red lines and falling stars
- Portals, light cubes and a door to the next level
- Princess voice lines, sound effects and per-level music
- Level maps loaded from text files, with save data for stars, score, time and coins
- Round lost screen

## Requirements

- Windows
- Visual Studio (MSVC) with the C toolset
- The CProcessing library, included in the `Extern` folder

## Build and Run

1. Open `LowLight.sln` in Visual Studio.
2. Select the `Proj 4` project as the startup project.
3. Build and run with F5. The game window opens at 1600x900.

Note: asset paths in the source (fonts, music, images) are currently absolute paths into the `Assets` folder. Update them to match your machine's location if you move the project.

## Project Structure

| Path | Purpose |
| --- | --- |
| `Proj 4/main.c` | Entry point. Sets the window size and starts at the main menu |
| `Proj 4/mainmenu.c/.h` | Main menu and lamp light |
| `Proj 4/levelselect.c/.h` | Level select screen |
| `Proj 4/loadingscreen.c/.h` | Story, instructions and round lost screens |
| `Proj 4/story.c/.h` | Story text screen |
| `Proj 4/level1.c/.h` | Gameplay state used by the levels |
| `Proj 4/utils.c/.h` | Collision, drawing, platform parsing, princess, hazards and lamp logic |
| `Proj 4/fileloader.c/.h` | Level file loading and save data |
| `Proj 4/Sound.c/.h` | Music and sound effect loading |
| `Assets/` | Fonts, music, sounds, images and level files |
| `Extern/` | CProcessing library |

## Author

Lu Yong Wei - L.yongwei@digipen.edu.sg

## Copyright

Copyright (C) 2026 DigiPen Institute of Technology Singapore. All rights reserved.
