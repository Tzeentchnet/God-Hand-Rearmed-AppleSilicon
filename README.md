![God Hand: Rearmed](assets/logo.png)

# God Hand: Rearmed — Apple Silicon (かみて · おもてなし)

**God Hand for PS2. Recompiled, Refined, Rearmed — natively on Apple Silicon.**

An unofficial, fan-made Apple Silicon port of Clover Studio's **God Hand** (PlayStation 2, 2006). The game's own code
is recompiled into a native arm64 program: no emulator running the show. It plays from start to credits with locked
30 and 60 FPS modes, widescreen support, modern controls, and as much or as little of our own nonsense as you want.

> [!WARNING]
> **Apple Silicon Preview!** Plays from the first punch to the credits, but expect the odd bug. Found one?
> [Tell us](#found-a-bug).

> [!NOTE]
> This fork ships a native Apple Silicon release using PCSX2's graphics renderer through the bundled KosmicKrisp
> Vulkan-on-Metal driver. It requires macOS 26 or newer. Windows users should use the
> [upstream project](https://github.com/God-Hand-Rearmed/God-Hand-Rearmed).

> **No game files included!** Play your own damn copy! (USA, SLUS-21503; see [DISC_HASHES.md](DISC_HASHES.md)).

<!-- MEDIA: assets/readme/hero.gif — the hero shot: a fight at 60 FPS, widescreen -->

## Compatibility

| | Requirement |
| --- | --- |
| **Mac** | Apple Silicon (`arm64`). Intel Macs are not supported. |
| **macOS** | macOS 26 or newer. |
| **Graphics** | Bundled KosmicKrisp Vulkan-on-Metal; no separate Vulkan installation is needed. |
| **Game** | Your own unmodified USA disc image, serial `SLUS-21503`, as `.iso` or `.chd`. |
| **Release status** | Experimental preview, ad-hoc signed and not notarized. |

## Get It Running

1. Download
   [`GHR-v0.6.9.1-apple-silicon.1-macOS-arm64.zip`](https://github.com/Tzeentchnet/God-Hand-Rearmed-AppleSilicon/releases/download/v0.6.9.1-apple-silicon.1/GHR-v0.6.9.1-apple-silicon.1-macOS-arm64.zip)
   from [Apple Silicon Preview 1](https://github.com/Tzeentchnet/God-Hand-Rearmed-AppleSilicon/releases/tag/v0.6.9.1-apple-silicon.1).
2. Unzip it somewhere you can write to. Keep **the entire `God Hand Rearmed` folder together**: `GHR.app` needs the
   `GHR` executable, dylibs, `kosmickrisp/`, and `resources/` beside it. Do not move only the app to Applications.
3. Put your USA God Hand disc image (`SLUS-21503`, `.iso` or `.chd`) in the included `game/` folder.
4. Open **GHR.app**.
5. If macOS blocks it, right-click **GHR.app** and choose **Open**. If it is still blocked, allow it under
   **System Settings > Privacy & Security**, then open it again.

The first start compiles shaders for your GPU, so the screen may stay black before coming back. Patience, young ass-whooper.
It also prepares files from your own disc; later starts are much quicker.

SHA-256 for the preview ZIP:
`3c710337d444fea808156fbbeac0acb0d65de839a43542ec56c0f0e27839e493`.

This preview launches straight into the game and does not include the Windows saloon launcher or its automatic
updater. See [How do I update?](#how-do-i-update) before replacing an existing installation.

## What's In It

### God Hand - Gone Native!

Recompiled as a native Apple Silicon arm64 program. PCSX2 supplies the graphics renderer, while the bundled
KosmicKrisp `v26.1.5-ryujinx` driver translates Vulkan to Metal.

---

### You've Been Hit by, You've Been Struck by, My Smooth Visuals!

True 60FPS (fists punching swiftly) game logic, that by a thousand fixes was achieved. <!-- tag:Fps60 --> `Remastered+`

<!-- MEDIA: assets/readme/60fps.gif — 30 vs 60 side by side -->
---

### Wider Than Yo Momma's!

I'll kick up your goddamn Aspect Ratio, boy! 

Up to 32:9. With enemy behavior adjusted, so everyone on screen is
invited to kick your ass, too! <!-- tag:AspectRatio --> `Remastered+`

No UI stretching in gameplay; menus at 4:3 unless you like 'em on the thicker side!

![God Hand: Rearmed](assets/wide_ass.webp)
---

### Modern Controls, Tank Me Later!

Switch between classic tank controls and modern third-person freecam on the fly. <!-- tag:ControlStyle --> `Remastered+`

Includes a toggle to automatically enter Brawl Mode (tank controls) in combat.

The alpha's Hold to Brawl is back: hold L1 for tank controls, double-tap it to spin around. Rather toggle Brawl Mode with R3? Pick Modern: Toggle. `Remastered+`

---

### Smokin' S | E | X | Y Style Switching!

Set up Moveset Presets in the Techniques screen, switch with the d-pad in gameplay. <!-- tag:StyleSwitching --> `Rearmed+`

For the Buck Breakers out there, you can also pick your pummel per style. <!-- tag:BuckBreaker --> `Rearmed+`

![God Hand: Rearmed](assets/moveset_presets.webp)

---

### I'm Into BDSM: Bindings & Device Scheme Mappings!

Customizable controls with button prompts for Xbox, PlayStation, Nintendo, Steam, and keyboard and mouse (for the
freaks who want to play God Hand at their desks).

![God Hand: Rearmed](assets/controls-collage.webp)
---

### Just Liek... Play Game!

Too many choices? How about just one? Pick a preset and get to playing right away.

> **NOTE:** New installs run at 60 FPS by default. Choose **Classic** for Clover's original 30 FPS gameplay; the other
> gameplay changes remain opt-in, so no bitchin!
>
> Both modes are software-paced and locked. Normal sub-frame timing jitter is smoothed, but a larger hitch is never
> followed by a multi-frame overspeed burst. VSync changes presentation and tearing only; it does not remove the
> 30/60 FPS cap.

### The Presets

<!-- BEGIN GENERATED: presets (tools/readme/gen_readme.py) -->
| Preset | Tagline | What you get |
| --- | --- | --- |
| **Classic** | Clover's Vanilla Thrilla | Cinetastic 30FPS, 4:3, Classic Camera & Controls, as handed by God. |
| **Remastered** | Spitshine Edition | Smooth Sexy Silky 60FPS, Fills your screen - edge to edge, Modern Controls, etc. |
| **Rearmed** | That's the Spice! | Adds: New Cam Angle, Roulette Refinements, Moveset Presets, Buck Breaker, Busta-Chan Jive, and Misqué & Risqué. |
| **Sleazy Mode** | ...is Now Selectable! For the girl who just wants to have fun. | Adds: Cunt Punter, Tension - Off the Cuff, and Wild Curry Funk. |
<!-- END GENERATED: presets -->

Each one includes everything before it. Change any option a preset sets and you're on **Custom**. The tags below say
which preset first switches a feature on; `Toggle` means none does, it's yours to flip.

### Everything Else

**Controls**
- Camera & FOV presets (As on the PS2, Wider, Widest, Action) or your own field of view, distance and tilt; enemies conduct themselves accordingly at any setting. <!-- tag:CameraPreset --> `Remastered+`
- See Through: walls between you and the action go see-through instead of vanishing. <!-- tag:SeeThrough --> `Rearmed+`
- Menu controls - Western, Japanese or Classic: confirm on the button you're used to.
- (Nearly) every button rebindable, with a full keyboard & mouse layout and save states (F5 / F9; Select / Select + Start).

**Display & Graphics**
- Fullscreen (borderless), maximized or windowed; any aspect ratio from 4:3 to 32:9. On Apple Silicon, macOS Game Mode
  activates while the game is frontmost and fullscreen.
- Internal resolution up to 8x through bundled KosmicKrisp Vulkan. Direct3D 11 is not available on macOS.
- Texture filtering from the PS2's own smoothing to Dangerously Crunchy, plus trilinear, anisotropic, FXAA,
  brightness and depth of field.
- HD texture packs in PCSX2's format, with the game's own transparency kept intact. (K recommends this [texture pack](https://gbatemp.net/threads/god-hand-usa-uhd-remaster-definitive-fixed-transparency-glitches.638847), and no, Santins, you didn't fix the transparency issues, but no worries, GHR fixed 'em for you)

**Interface**
- The HUD out at the screen edges or where the PS2 had it. <!-- tag:HudLayout --> `Remastered+`
- Sway Bar: a stun gauge for enemies and bosses. <!-- tag:SwayBar --> `Rearmed+`
- Button prompts that follow your controller (Xelu's prompt art; PlayStation pads keep the game's own).

**Gameplay**
- Click-Stick Dash: press and hold the stick (or bind) to dash. <!-- tag:L3Dash --> `Remastered+`
- Intro Skipper: skip developer intros straight to the title screen. <!-- tag:SkipIntro --> `Remastered+`
- Hard-On: Hard difficulty from the start, no clear needed. <!-- tag:UnlockHard --> `Remastered+`
- Target Select: switch Roulette targets with the right stick or the d-pad. <!-- tag:RouletteTargetCycle --> `Rearmed+`
- Dry Spinning: open the Roulette with no balls to your name. <!-- tag:RouletteNoOrbs --> `Rearmed+`
- Busta-Chan Jive: sprint attacks slide under and vault over railings and through windows. <!-- tag:SprintTraversal --> `Rearmed+`
- Misqué & Risqué: better shop and casino poses, and more. <!-- tag:Money --> `Rearmed+`
- Cunt Punter: Ball Buster works on women. <!-- tag:BallBusterWomen --> `Sleazy Mode`
- Tension is Placable: leash the God Hand early and keep what's left; Off the Cuff unleashes it with any Tension.
  <!-- tag:TensionPlacable --> `Sleazy Mode`
- Wild Curry Funk: pick up, carry and throw more objects. Mostly chairs. <!-- tag:LiftChairs --> `Sleazy Mode`
- Roulette Timer: double time to pick your move. <!-- tag:RouletteTimer --> `Toggle`

**Sound**
- Separate Music, Sound Effects and Voices volumes; Roulette Ratchet clicks as you flick. <!-- tag:RouletteRatchet --> `Remastered+`

**The Apple Silicon App**
- `GHR.app` is a small Game Mode-aware wrapper that launches the native `GHR` executable beside it.
- The current macOS build skips the Windows saloon launcher, Add to Steam, and automatic updater. Configure controls
  with **F1**, use the in-game options and **F2** menu, and update manually from this fork's Releases page.

**Muscleanious Improvements**
> The following are default features of GHR you'll have to deal with cause I ain't cluttering the options any more than they already are:
- Spin Me Right Round: You can rotate Gene on the Techniques screen with the Right Stick.
- Roulette Finesse: You can scroll the Roulette with the d-pad, up and down too.
- Don't Not Fix What's Not Broken't: A bunch of base game bugs and minor issues were fixed.

## Controls

Defaults for new installs. Everything is rebindable in game with **F1** or **Options > Controls**.

<!-- BEGIN GENERATED: controls (tools/readme/gen_readme.py) -->
| Action | Controller | Keyboard & mouse |
| --- | --- | --- |
| Move | Left stick | W A S D |
| Dodge | Right stick | Shift + W A S D |
| Combo | X / ▢ | Left click |
| Assigned move | Y / △ | Right click |
| Assigned move | A / ✕ | Space |
| Action (talk, pick up, open) | B / ○ | E |
| 180° turn | LB / L1 | Q |
| Roulette | RB / R1 | R |
| Taunt | LT / L2 | F |
| Unleash the God Hand | RT / R2 | G |
| Brawl mode / freecam *(Modern: Toggle)* | Right stick click | Middle click |
| Brawl mode while held, double-tap for the 180° turn *(Modern: Hold)* | LB / L1 | — |
| Dash *(Click-Stick Dash on the controller)* | Left stick click | Double-tap a direction |
| Styles S / E / X / Y *(Moveset Presets)* | D-pad up / right / down / left | 1 2 3 4 |
| Pause | Start / Options | Esc |
<!-- END GENERATED: controls -->

In menus the keyboard works as you'd expect: arrows or WASD to move, Enter / Space to confirm, Esc / Backspace to go
back, Q / E to switch tabs. **F2** opens the developer menu (live camera, poses, debug switches); **F3** the FPS counter;
**F11** fullscreen.

## Options

Every shared option, with the same help text used in game. Windows-only choices are labelled as such; the Apple
Silicon build always uses KosmicKrisp Vulkan.

<!-- BEGIN GENERATED: options (tools/readme/gen_readme.py) -->
<details>
<summary><b>Controls</b></summary>

**Camera**

- **Camera & FOV:** How far you see to the side. Works with Aspect Ratio; enemies adapt. *As on the PS2 / Wider / Widest / Action / Custom* (F2 while playing tunes it live) `Remastered+`
  - **Field of View:** How much the camera shows, both ways, outside fights. *100%: as on the PS2 / 110% / 120% / 130% / 140% / 150%*
  - **Field of View in Fights:** The same while the game's battle camera is on (Gene has an enemy targeted). 100% frames fights as on the PS2. *100%: as on the PS2 / 110% / 120% / 130% / 140% / 150%*
  - **Camera Distance:** At a wider field of view, how far back the camera stays. 0% keeps Gene the size he is at 100%; 100% shows more round him. *0%: Gene keeps his size / 50%: halfway out / 100%: wider view looks zoomed out*
  - **Camera Tilt:** At a wider field of view, the camera also rises and looks down at Gene by this much: more of the floor ahead, less sky. *None / 5 degrees / 10 degrees / 15 degrees*
- **Steady Idle Cam:** Whether the camera bobs with Gene. (F2 > Camera switches it while playing)
- **See Through:** Instead of removing walls, the camera sees through them around Gene and enemies. (F2 > Camera sizes it while playing) `Rearmed+`

**Controller**

- **Vibration:** Controller rumble. Girls know what it's for.
- **Left Stick Deadzone:** How far the left stick must move before it counts. Raise it if Gene walks on his own. *0% to 50%*
- **Right Stick Deadzone:** How far the right stick must move before it counts. Raise it if the camera drifts or Gene dodges on his own. *0% to 50%*
- **Menu Controls:** Western: bottom button confirms; right cancels. Japanese: right button confirms; bottom cancels. *Western / Japanese / Classic*

</details>
<details>
<summary><b>Display</b></summary>

**Game Window**

- **Display Mode:** Window, max window, or borderless fullscreen. On Apple Silicon, macOS Game Mode activates while the game is frontmost and fullscreen. You can also use F11, if you're into that. *Fullscreen (Borderless) / Maximized Window / Window*
  - **Window Size:** The window's size when it opens (not maximized or fullscreen). *Automatic (follows internal resolution) / PS2 size*
- **Aspect Ratio:** Screen width from 4:3 to wider than yo momma! *4:3 (the PS2's) / 16:9 / 16:10 / 21:9 / 32:9 / Match the screen* `Remastered+`
- **VSync:** Presentation only; the 30/60 FPS gameplay lock remains. Off: smooth KosmicKrisp on Apple Silicon. On: tear-free Windows. *On / Off*

</details>
<details>
<summary><b>Graphics</b></summary>

**Renderer**

- **Graphics API:** Apple Silicon: bundled KosmicKrisp Vulkan. Windows: Vulkan with Direct3D 11 fallback. *Vulkan (KosmicKrisp on Apple Silicon) / Direct3D 11 (Windows)*
- **Internal Resolution:** 1x: 448p | 2x: 896p | 3x: 1344p | 4x: 1792p *1x native (512x448) / 2x 1024x896 / 3x 1536x1344 / 4x 2048x1792 / 5x 2560x2240 / 6x 3072x2688 / 8x 4096x3584*

**Textures**

- **Texture Filtering:** PS2: the game's original texture smoothing. Crunchy: unfiltered 3D. | Dangerously Crunchy: the UI too. *PS2 (Bilinear) / Crunchy (Unfiltered 3D) / Dangerously Crunchy (3D+UI)*
- **Trilinear Filtering:** PS2: the game's original texture smoothing. Forced: textures blend smoothly into the distance. *PS2 / Forced*
- **Anisotropic Filtering:** Keeps floors and walls sharp at a slant. Costs next to nothing. Max it out. *Off / 2x / 4x / 8x / 16x*

**Effects**

- **Anti-Aliasing:** FXAA smooths jagged edges. Makes the picture a little softer. Like you. *FXAA / Off*
- **Brightness:** 100% is the game as it was. Turn it up if you can't see who's kicking you. *50% to 150%*
- **Post Effects:** The blur effects (depth of field, heat haze) are drawn from small copies of the frame. PS2 resolution keeps them aligned but grainy at high internal resolutions; Upscaled draws them sharp. *PS2 resolution (PCSX2's fix) / Upscaled / No fix*
- **Depth of Field:** Blur in the distance. It can't hurt you. (F2 switches it while playing)

</details>
<details>
<summary><b>Interface</b></summary>

**HUD**

- **HUD Layout:** Where the health bar, radar, and the rest of the in-game HUD go on a wide screen. Wider than 16:9 keeps them at the edges of a 16:9 area. *16:9: HUD at the screen edges / 4:3: HUD where the PS2 had it* (F7 switches it while playing) `Remastered+`
- **Enemy Life Gauge:** Select whether to display an enemy's life gauge.
- **Sway Bar:** Stun gauge for enemies and bosses. Fills up till they're stunned, then drains. `Rearmed+`

**Menus & Prompts**

- **Menu Width:** Menus and screens (pause, options, roulette setup) are drawn for 4:3: shown 4:3 with side bars, or stretched to the screen. *4:3: as on the PS2, with side bars / Stretched to the screen*
- **Button Prompts:** Controller button hint style. This choice reflects your value as a person. *Automatic (follows your controller) / Xbox / PlayStation (the game's own) / Nintendo Switch / Steam*

**Overlays**

- **FPS Counter:** Framerate and game speed statistics.

</details>
<details>
<summary><b>Gameplay</b></summary>

**Speed & Feed**

- **60 FPS:** Locked 60 FPS gameplay; cutscenes stay at 30. OFF locks gameplay to the OG 30 FPS. `Remastered+`

**Move & Groove**

- **Control Style: Pad:** Classic: PS2's OG fixed facing brawling. Modern (rebindable): Toggle Brawl (R3) | Hold to Brawl (L1). *Classic / Modern: Toggle / Modern: Hold* (F2 > Controls changes it while playing) `Remastered+`
  - **Modern: Auto:** Brawling starts when dealing or taking damage. Press the stick (rebindable) to go back to freecam.
  - **Modern: Hold Mode:** Hold to Brawl: hold L1 to brawl, double-tap it to turn. Hold to Cam: hold L1 for freecam, tap it to turn. *Hold to Brawl / Hold to Cam* `Remastered+`
  - **Modern: Auto:** Brawling starts when dealing or taking damage. It stops once no enemy is near. `Remastered+`
- **Control Style: KBM:** Keyboard & mouse. Classic: PS2's OG brawling. Modern: mouse freecam. *Classic / Modern: Toggle* `Remastered+`
  - **Modern: Auto:** Brawling starts when dealing or taking damage. Middle-click (rebindable) to go back to freecam.
  - **Modern: Mouse Look:** Freak... (F2 > Controls sets the sensitivity)
- **Click-Stick Dash:** Press and hold the stick to dash. Rebindable in Controls. `Remastered+`
- **Busta-Chan Jive:** Sprint attacks go through 99% of obstacles. Slide right through, swooce right over. (F2 > Debug > Stage collision marks them) `Rearmed+`

**Style Shuffle**

- **Moveset Presets:** Configure up to 4 styles; switch with the d-pad. Letters around the radar show your sweet sexy styles. `Rearmed+`
  - **Signal Style Switch:** Gene calls out each style as you switch to it, and his God Hand flashes. `Rearmed+`
- **Buck Breaker:** Pick how to punish stunned enemies. Works with Moveset Presets. Some restrictions apply. `Rearmed+`

**Fightin' Excitement**

- **Cunt Punter:** Ball Buster works on women. Name changes on target. This also works IRL, though your mileage may vary. `Sleazy Mode`
- **Tension is Placable:** After unleashing the God Hand, pull the trigger again to leash it early and keep your remaining Tension. `Sleazy Mode`
  - **Off the Cuff:** Unleash the God Hand with any Tension, not just full. Gene is invulnerable only when unleashing at full Tension. `Sleazy Mode`
- **Wild Curry Funk:** Carry and throw more types of objects. Mostly chairs. If it's not obvious, this makes the game easier. `Sleazy Mode`

**Roulette Charrette**

- **Roulette Timer:** Time limit to select a move after opening the Roulette. Techniques fire off automatically at the end of the timer. *Normal / Double time*
- **Target Select:** Switch Roulette targets with the right stick and the d-pad. HINT: You can also use the d-pad to cycle Roulette moves. `Rearmed+`
- **Dry Spinning:** You can open the Roulette even when you don't have balls. HINT: You can use the Roulette camera for targeting. `Rearmed+`

**Skip Poker**

- **Intro Skipper:** Start at the main menu: no Capcom and Clover logos and no "Press Start" screen. `Remastered+`
- **Hard-On:** Hard can be picked from the start instead of after a clear. Your save is not changed. `Remastered+`

**Misqué & Risqué**

- **Better Shop & Casino Poses:** Give the shop and casino people better poses. Not sure what else you were expecting... (F2 > NPCs sets the poses) `Rearmed+`
- **Cash:** Recommended: 115% *100% to 130%* `Rearmed+`
- **Money:** Recommended: 115% *85% to 130%* `Rearmed+`

</details>
<details>
<summary><b>Sound</b></summary>

**Sound**

- **Mode:** Select between monaural, stereo, or surround sound. *Mono / Stereo / Dolby Pro Logic II*
- **Roulette Ratchet:** When you flick, it clicks. `Remastered+`

**Volume**

- **Music:** Set stage, boss, menu, and minigame music volume. *0% to 100%*
- **Sound Effects:** Set the volume of ingame sound effects. *0% to 100%*
- **Voices:** Set the volume of ingame voice lines. Cutscene music and voices are one track. *0% to 100%*

</details>
<details>
<summary><b>Mods</b></summary>

**Character**

- **Character:** Who you play as. Currently, other characters use Gene's moves and his God Hand.

**Texture Packs**

- **Replacement Textures:** HD texture packs in PCSX2's format.

</details>
<!-- END GENERATED: options -->

## FAQ

**Is this legal?**
GHR ships no game assets or disc files. It only runs with a disc image you dumped from your own damn copy.

**Which disc?**
Only the unmodified USA release (`SLUS-21503`) is supported; the port checks it and refuses other regions or damaged
images. `.iso` and `.chd` are accepted. [DISC_HASHES.md](DISC_HASHES.md) has the verified ISO checksums.

**Why is the screen black for a while on the first start?**
The shaders are being compiled for your GPU. Once. After that it's quick.

**macOS says the app is from an unidentified developer.**
This preview is ad-hoc signed but not Developer ID signed or notarized. Right-click **GHR.app**, choose **Open**, and
confirm. If needed, allow it under **System Settings > Privacy & Security**, then try again.

**Can I move GHR.app to Applications?**
Not by itself. `GHR.app` launches the flat `GHR` executable beside the app, which loads the bundled dylibs,
`kosmickrisp/`, and `resources/`. Move the whole `God Hand Rearmed` folder if you want it somewhere else.

**Where is the fancy launcher?**
The current Apple Silicon build disables the Windows saloon launcher and starts the game directly. Use **F1** for
bindings, the in-game Options screens for normal settings, and **F2** for live settings and diagnostics.

**Steam Deck? Linux?**
Not supported by this fork. This release is native Apple Silicon only; use the
[upstream project](https://github.com/God-Hand-Rearmed/God-Hand-Rearmed) for other platform work.

**Windows?**
Use the [upstream Windows releases](https://github.com/God-Hand-Rearmed/God-Hand-Rearmed/releases). This fork's ZIP
contains Mach-O arm64 binaries and cannot run on Windows.

**Will my PCSX2 texture pack work?**
Yes. Put the pack's `replacements/` folder at `textures/SLUS-21503/replacements/` inside the extracted
`God Hand Rearmed` folder.

**Can I bring my PCSX2 saves?**
The port uses PS2 memory-card images in `memcards/`. Back up the folder before replacing a card.

**Where are my saves?**
`memcards/Mcd001.ps2` holds the first memory card, and `states/` holds save states. Both are inside the extracted
`God Hand Rearmed` folder, beside `GHR`.

**How do I update?**
Updates are manual in this preview. Unzip the new release into a new folder, then move your `game/`, `memcards/`,
`states/`, `mods/`, `textures/`, `GHR.ini`, and `controls.ini` from the old folder. Do not replace the old installation
folder wholesale in Finder: it contains your disc image and saves.

**I want it at 30 FPS!**
Switch off **60 FPS** in Options > Gameplay, or pick the **Classic** preset.

## Found a Bug?

Open an [issue](https://github.com/Tzeentchnet/God-Hand-Rearmed-AppleSilicon/issues/new/choose) with the release tag,
what happened and `logs/kamite.log` from the extracted game folder. If something feels off at 60 FPS (too fast, too
slow, an enemy acting weird), the template explains how to record a **test case** of it: one file that shows us exactly
what you saw.

## Not Yet in the Apple Silicon Preview

- **Developer ID signing and notarization.**
- **The saloon launcher, Add to Steam, and automatic updater.**
- **Linux / Steam Deck and Android builds.**
- **Photo mode** with a free camera.
- **Subtitles** for the cutscenes.
- **More playable characters.**

Building it yourself, or curious how it works? See [docs/BUILDING.md](docs/BUILDING.md). What changed and when:
[CHANGELOG.md](CHANGELOG.md).

## Credits

This Apple Silicon fork is maintained by [Tzeentchnet](https://github.com/Tzeentchnet). God Hand: Rearmed is directed,
play-tested and written by K, built with AI assistance (Claude by Anthropic), with ideas and testing from the boys.

**Built on**
- [KosmicKrisp](https://github.com/Kenji-NX/KosmicKrisp): the bundled Vulkan-on-Metal driver and Vulkan loader, pinned
  to `v26.1.5-ryujinx` for compatible, smooth Apple Silicon presentation.
- [LasVola/godhand-recomp](https://github.com/LasVola/godhand-recomp): the recompilation God Hand: Rearmed started from
  (the running game, the SNR2 overlay loader, the first fixes), built on [PS2Recomp](https://github.com/ran-j/PS2Recomp)
  by ran-j and contributors, the [sotc-port runtime fork](https://github.com/LightVelox/PS2Recomp) by LightVelox, and
  the [Urban Reign port](https://github.com/thiagordsfx/urban-reign-recomp) by thiagordsfx (runtime, VU1 compiler,
  sound, PCSX2 graphics bridge).
- [PCSX2](https://github.com/PCSX2/pcsx2): the hardware renderer and the game's GameIndex fixes.
- [gow-native-pc](https://github.com/Vnnc1/gow-native-pc) by Vnnc1, after the
  [Killzone port](https://github.com/drakolordx7/KillzoneRecomp) by drakolordx7: the recompiler's register-locals code
  and the lean guest calls (GPL-3.0).
- [Ace Combat 5 static recompilation](https://github.com/sal063/Ace-Combat-5-Static-recompilation): the movie decoder
  (Apache-2.0).

**Thanks to the researchers**
- [LucasPicoli/god-hand-decomp](https://github.com/LucasPicoli/god-hand-decomp) and its contributors: function names,
  boundaries and structures.
- The "60 Fps" and "Widescreen 16:9" PCSX2 patches for SLUS-21503 (Puggsy and others): where the 60 FPS mode and the
  aspect-ratio support started.
- [GT3 Revisited](https://github.com/matt-pulsipher/GT3-revisited) (MIT): the PS2's exact float arithmetic (the EE's adder,
  multiplier and divider, worked out by its authors).
- [anasrar/chihuahua](https://github.com/anasrar/chihuahua) (MIT): file-format knowledge and the motion reader.
- [akitotheanimator/God-Hand-Tools](https://github.com/akitotheanimator/God-Hand-Tools) (with CarLoiD, Kerilk and Roni
  Evil): model, motion and motion-event formats.

**Borrowed with love**
- Nicolae "Xelu" Berbece (Those Awesome Guys): [Xelu's free controller and keyboard prompts](https://opengameart.org/content/free-keyboard-and-controllers-prompts-pack)
  (CC0), the button prompts (the Nintendo L / R shoulders are our own).
- [Quaternius](https://quaternius.com): the Universal Animation Library 1 and 2 (CC0), the NPCs' rail lean, dance and
  folded-arms idle.
- [Denys Almaral](https://denysalmaral.com): the Free Animation Pack for City People, two of the NPCs' idles.
- masterlynx: the Steam library cover art, used with the artist's permission.
- [Flaticon](https://www.flaticon.com): the sketched Steam icon on the launcher's bill of fare (inked into a ring by us).
- Harold Lohner ([haroldsfonts.com](http://www.haroldsfonts.com)): the Dominican font, the launcher's writing (the bill of
  fare, the Options book, the splash text).
- Dennis Ludlow / Sharkshock ([sharkshock.net](http://www.sharkshock.net)): the Wendyville font of the wanted posters and
  the launcher's headings.
- The Holtwood One SC Project Authors: [Holtwood One SC](https://fonts.google.com/specimen/Holtwood+One+SC) (OFL-1.1),
  the posters' SELECTED stamp and the Options book's stamps.
- The Archivo Narrow Project Authors: [Archivo Narrow](https://github.com/Omnibus-Type/ArchivoNarrow) (OFL-1.1), the
  OPTIONS screen's labels and the launcher newspaper's date lines.
- Bitstream and the DejaVu fonts team: [DejaVu Sans](https://dejavu-fonts.github.io) (Bitstream Vera licence), the
  OPTIONS screen's help text.
- The launcher's saloon is rendered from Quixel Megascans' [Saloon Interior](https://www.fab.com/listings/57991a62-f98f-4c6a-9b94-a74ec12f242e)
  (via Fab) and Sketchfab models by Carissa, JoshElo, gelmi.com.br, polyplant3d, inciprocal, markus.blend, pizzaguyty,
  Zinaida.Kovrova, Kenty110 and Mei; the renders' licences and every credit are in `resources/saloon/LICENSE.txt`.
- The EB Garamond Project Authors: [EB Garamond](https://github.com/octaviopardo/EBGaramond12) (OFL-1.1), the
  launcher's letters Dominican lacks and the newspaper's stories.
- j. 'mach' wust and Peter Wiegel: [UnifrakturMaguntia](https://fonts.google.com/specimen/UnifrakturMaguntia) (OFL-1.1),
  the launcher newspaper's masthead.
- [libavif](https://github.com/AOMediaCodec/libavif) and [dav1d](https://code.videolan.org/videolan/dav1d) (BSD-2-Clause),
  decoding the saloon's images.

## Legal

The code is GPL-3.0 ([LICENSE](LICENSE)), like PS2Recomp. Third-party licenses are in `docs/licenses/` and the
`thirdparty/` folders. **No game data is included.** God Hand is a trademark of Capcom. This project is not affiliated
with or endorsed by Capcom or Clover Studio.
