# Ed Hunter Fix
### **⚠️ WARNING: This ONLY works on version 1.12 of the game! Earlier version won't be supported. ⚠️**

The idea of this fix is to make it as easy as possible to run Ed Hunter on modern machines.

### Features
- **Removed CD Dependency** - Removes the CD check entirely and fixes the path being checked by the game.
- **Removed Registry Dependency** - The game will instead parse and write to an INI file, which also subsequently fixes the game requiring admin rights to work.
- **Additional Saving** - The fix makes absolutely all of the settings save now, not just the ones the developers picked out originally. To give you an example, the difficulty will save now.
- **Skip Intros** - Self-explanatory addition, part of the QoL section in the INI.
- **Pause on Focus Loss** - The game will pause itself when you tab out. Also part of the QoL section.
- **Fixed Rendering (cnc-ddraw)** - The fix comes bundled with a pre-configured version of it which fixes various issues such as sprites getting misaligned when tabbing out.

### Notes
- **Saving** - In order for anything to save in the INI, you must quit the game from the main menu. Force closing the game won't work.

### Installation
- Take EDHUNTER.JFS from the play disc and put in your game directory.
- Download the latest release from the repo and extract it to your game folder as well.

### Credits

- Help: [ermaccer](https://github.com/ermaccer), [Edness](https://github.com/EdnessP), [jas0n098](https://github.com/jas0n098) (testing on Linux)
- Silent: [ModUtils](https://github.com/CookiePLMonster/ModUtils)
- FunkyFr3sh: [cnc-ddraw](https://github.com/FunkyFr3sh/cnc-ddraw) (bundled with the releases)
- ThirteenAG: [Ultimate-ASI-Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) (bundled with the releases)
