# Desperabis

Hello adventurers and friends of good old DOS games!

## About

_Desperabis_ is a DOS-based 3D adventure game, published in 1999. It had been downloaded multiple hundred thousand times and it has also been on numerous cover disks of well known print magazines.

Other 3D games had been on the market for years already, but _Desperabis_ was acclaimed for its dense atmosphere, embedded into a captivating story. Creepy atmosphere instead of splatter.

Furthermore, it came up with some not-so-common rendering features, such as dynamic lighting or water reflections.

The fact that MS-DOS games were declining in 1999 already (in favour of hardware accelerated Windows games), caused _Desperabis_ to get less recognition than it could have gotten. But most importantly, it was mostly limited to German speaking market, since the whole game was in German language. 

However, this is one of the reasons why I created this repo: Reverse engineering and re-packaging the assets now allows us to create an [English localization](readme.md#english-version) of the game. Special Kudos to user Sir John aka @ungesundes-halbwissen, who came up with the initial idea of a language port and who did all the translation work!

### About the Author

My name is Florian Born and I'm a computer graphics enthusiast since my first computer, a C64 in the year 1984! When I looked at games, I was always more interested in _how_ they worked rather than playing them. I soon started writing smaller games myself, soon exploring the mystery of 3D graphics. Since there had barely been any 'online' (internet?!) resource about how to write a renderer, I learned on the job.

I have stayed within the industry since then. Today, I'm working as a development lead in the VR space.

### About the Game

_Desperabis_ was my first game that can be considered finished. It was written in the years 1996-1999, started as a pet project alongside my studies and soon evolved due to overwhelming feedback. Programming-wise, at the time I hadn't transitioned to C/C++, so the game was written in Turbo Pascal 7.0 with major parts hand-optimized through inline assembler.

Due to the lack of affordable(!) industry standards for 3D tooling, I wrote all the tools myself: A texture editor, a 3D modeling/animation tool, and a WYSIWYG game editor. Unfortunately, it's all gone - see next paragraph.

### Source Code

Before you ask: No, I lost it! It's a pity because it would have allowed me to do a full port of the game to modern graphics, including the gameplay code. Anyway, reverse engineering all the asset parts was a fun endeavor, as it brought back all the good memories!

### License

This repo is Open Source using the permissive "MIT License", which essentially means you can do whatever you like with it, as long as you include the original copyright and license notice in any copy of the code or a substantial portion of it. See [License file here](LICENSE).

## Running the Game

Given that _Desperabis_ is a pure MS-DOS game, it needs to run in an emulator, such as famous [DosBox](https://www.dosbox.com/). The self-contained game binaries is part of this repo and can be found here: [Game/Original](Game/Original)

### English version

### Dosbox settings

### Savegames

This repo comes with a bunch of save games, essentially one for every level in the game. The files are located within the [Data/SaveGames](Data/SaveGames) folder of this repo.

To use them, you need to copy them next to the DESPERAB.EXE in the games folder. Since the in-game UI is limited to listing only 10 files (named STAND1..10.SPL), they are separated in folders and you need to copy them over the existing 10 files.

## Localization

## Music

I was looking for a good fit for royalty-free music that I can use. It was just good coincidence that a close friend of mine recorded their own music CD, the album "Et". I got permissions to put the [full album on YouTube](https://www.youtube.com/watch?v=rZwh6bSWDDQ&list=PLmkuT--rMY1qd7M4o5UknBGlGjppDSUeU). For completeness, .mp3 files in high quality and full length are also stored in this repo: [Data/Menestrels](Data/Menestrels).

## Contributing

Any feedback and/or contribution is highly appreciated! Feel free to fork this repo and make contributions via pull requests.

## Future Plans

I have written a new renderer that uses the old assets as is. I'm in the process of cleaning it all up and then I'll release it here. Stay tuned!
