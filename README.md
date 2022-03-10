
## homm3tools

homm3tools is a repository containing various tools for Heroes of Might and Magic 3, <a href="https://www.hota.acidcave.net/download.html">Horn of the Abyss</a>.
The code is currently tested working on HotA version 1.6.1.

## Base Code

The base code used to read savefiles and order the data in structs and classes is found in [src/h3](https://github.com/oysteinmyrmo/homm3tools/tree/master/src/h3).
The code in these files are used to build the other tools.

## h3viewer

[h3viewer](https://github.com/oysteinmyrmo/homm3tools/tree/master/src/app/h3viewer) is an application to visualize a series of save files (a game).

![h3viewer overview](images/h3viewer-overview.png)
| Plot Kingdom Army Strength | Plot Number of Heroes | Plot Number of Towns |
| -------------------------- | --------------------- | -------------------- |
|![kingdom army strength](images/plot-kingdom-army-strength.png)|![number of heroes](images/plot-number-of-heroes.png)|![number of towns](images/plot-number-of-towns.png)|

## h3decompress

[h3decompress](https://github.com/oysteinmyrmo/homm3tools/tree/master/src/app/h3decompress) is an application to decompress a single save file.
This is nothing but a `gunzip` of the target save file. First argument must be the HotA save file to decompress while the second argument must be the output filename.
