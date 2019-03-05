Warp2010
========

A multiplatform program to create fictional solar systems, Diaspora Custers and starmaps 2300AD-style

It's written in C++ using multiplatform QT Libraries ( http://qt.nokia.com ) 

First releases have been developed on a windows machine using Mingw as compiler and QTCreator as ide. Latest ones are developed on a Linux Fedora machine (however, from time to time I also test windows build. If a kind soul wants to test the whole stuff on MacOS, well... here's the code :-) 

Major feature of this release:

* Full Celestia stellar system generation, down to the textures.
* Moving from raw pointers to smart pointers (`std::unique_ptr` and `QSharedPointer`)
* Inclusion of Libnoise (http://libnoise.sourceforge.net) as a texture generation engine
* Creating a texture generation program

It's something I'm developing in my spare time, so don't hold your breath. 

### Docs

Some scarce docs can be found here:

* [A brief description of WarpNow!](./warpnow.md)
* [Create fictional solar systems for Celestia using WarpNow!](./docs/celestia/celestia-tutorial.md)