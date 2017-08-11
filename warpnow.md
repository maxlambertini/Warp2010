# WarpNow!

### What is it?

**WarpNow** is a suite of programs dedicated to the creation of fictous star sectors whose characteristics is that hyperspace technology allow jumps no longer than a definite distance in light years. These tool stem from the need to calculate every possible jump route in the Near Star Map provided with the roleplaying game 2300AD (1986!). 

The game set a limit of 7.7ly, so it was possible to construct a star topology complete with hubs and choke points. The original star data is still included in this package so, if you are a 2300AD fan, you can re-create the jumpmap of your favorite game.

The first version of this program dates back to 1997, and a sligthly more definitive version was released in 1998. I did not update the software until 2010, when, as a result of a challenge, I began rewriting it in Qt/C++, making it multiplatform.

Nowadays the software is **far** from being production-ready, but it quite satisfies my needs.

**WarpMain**, the proper sector mapping software, now can:

- Load and create star sectors
- Calculate jump maps
- Create solar systems
- Export sector map as PDF or SVG
- Export sector's jumpmap as a topology in graphviz format or yED format
- Export sector data as a Celestia addon, **complete with planetary textures**.

Moreover, since texture generation library _libgen_ has been integrated into **WarpMain**, I've also created a simple texture editor that allows me to generate, edit and preview texture definition files (which are simple .json files). So, as a byproduct, you get a _planetary texture editor_ that you can use in your favorite 3d software (like Blender) and that can help you create new planetary textures should you feel the need. 

## WarpMain

**WarpMain** is the centerpiece of this suite. If you used this program before, you will note that its interface has undergone quite an overhaul. I tried to make it more streamlined, and removed unnecessary features from it, 

**WarpMain** operates under two modes: the *Star Sector Mode*, where you create, load, save and export star sectors, and the *Solar System Mode*, where you select a star and inspect its solar system. 

You switch mode by clicking `ctrl+tab` keys or by toggling one of the two leftmost buttons. The first activates _Star Sector Mode_, which is the default mode; the second activates _Solar System Mode_. 

### Creating a Star Sector

To create a Star Sector, go into _Solar System Mode_ and press `ctrl-n`. This will activate the _New Sector_ dialog. For now, just hit OK. Defaults mean that you will create a Star Sector with 50ly radius, with an average density of 750 stars for 50 cubic parsecs. You will see new shiny stars filling your map :-) and -- hopefully -- most of them will be connected by a jumproute. 

When you load or create a Star Sector, jumpmap is calculated right away. The maximum jump distance is determined by the input box labeled "Distance in LY" on the top right corner. Default is 7.7ly. To change jump distance and force recalculation you change the numeric value and double-click on the star you want to use as a reference. (Our Sun is labeled "SOL"). This operation works in both modes. 

### Populating Star Systems

Once you've created or loaded a Star Sector, you might want to populate it by filling the stars with random-generated solar systems. 

To do this, you should switch to Solar System Mode by clicking on the second from left icon in the toolbar or by hitting Ctrl-Tab. 

Options local to the selected mode are accessed by clicking on the gear icon, on the right-top corner of the window. These are the menu options:

### Star Sector Mode menu

* **New Sector** -- Hotkey: `ctrl-n`. Creates a new Star Sector from scratch. When doing this, you will be asked some info about the sector to be created like its radius in light years, its star density and its center relative to Sun (this is important if you want to export your sector as a Celestia add-on)
* **Load Sector** -- Hotkey: `ctrl-o`. Opens a previously saved sector. Sector file formats come in two flavors: `.str` files, which represent lists of stars described in a pipe-separated fashion, and `.starj` files, which are json representation of a whole star sector _including planets and trade routes_. Sample star sectors included with the software are `.str` files.
* **Save Sector** -- Hotkey: `ctrl-s`. Saves sector data. You can opt to save a simple star list by choosing `.str` file format or save the whole data tree -- stars, planets, moons, trade routes -- by selecting the `.starj` format. 
* **Export Sector** -- Hotkey: `ctrl-e`. Exports sector information as data to be used by third-party programs. You can export sector data in these formats:
  - `.dot` (Graphviz format).  You generate a file that can be processed by the graphviz suite -- http://www.graphviz.org. You can choose to limit the exported data to main reachability tree and only to worlds containing garden planets. 
  - `.gml` (Graph Markup Language). It's a simple, albeit light on feature, markup language for graphs. 
  - `.graphml` (yED). It's yED native file format, which allows for styles and labels on nodes and edges. yED itself is a powerful graphing tool, that can help you arrange the nodes should they overlap. 
  - `.stc` (Celestia). This options export the whole star sector as a Celestia Addon. The process generates two files -- one containing stars, the other containing planets and satellites -- and a subdiredtory containing texture **for every planet and satellite in the sector**. You are thus advised to export a Celestia Addon on its own subriectory. Needless to say, this feature benefits from all of the raw processing power that your machine can muster: seven years old quad-core desktop processors perform way, way better than latest generation intel notebook processors. You also might need a lot of space: texture definition files range from 1024x512 to 1600x800 textures, but a simple 50-stars sector might generate 1GB of texture data. However, if you love seeing your fictious solar system in that first-class universe simulator that goes under the name of Celestia, this options might well be worth the wait. 
* **Export Map to Image** -- Hotkey: `ctrl-i`. Exports the sector map as a PDF or a SVG. 
* **Print Map**. Prints the sector as a multipage document, including a legend on every page.
* **Add New Star**. -- Hotkey: `ctrl-m`. Adds one or more star in a Star Sector. You can perform this operation on empty subsector. When creating more than one star, you can specify the spread radius and the minimum distance from center. It's an useful alternative to create smallish sector, even if it somehow duplicates _New Sector_ functionality. 
* **Add stars between two stars**. -- Hotkey: `ctrl-t`. Adds one or more stars (up to 20) between two stars selected from the ones in sector. 
* **Sector map options**. This submenu lets you specify how the map can be drawn on screen:
  - _Show all stars_: draws **all** stars in sectors
  - _Show reachable stars_: draws only stars that can be reached from the reference star
  - _Show stars on trade route only_: draws only stars in trade routes
  - _Show hexmap with reachable stars_: shows an hexmap representation of the star sector (useful for you Traveller buffs)
  - _Show hexmap with trade route only_: same as above, only stars in trade route are drawn
  - _Show metromap with reachable stars_: shows an metromap (hexmap without hexes, thus reducing overlay)  representation of the star sector (useful for you Traveller buffs)
  - _Show metromap with trade route only_: same as above, only stars in trade route are drawn
* **Planar projection mode**. Lets you choose the projection mode (default is XY axis) 
* **Clear Star Sector data**. Wipes out current Star Sector informations. 
* **Preferences**. Allows you to set fonts and display options. Currently **very** limited.
* **Exit**. -- Hotkey: `ctrl-x`. Exits the program

### Solar System Mode menu

* **New Solar System** -- Hotkey: `ctrl-w`. Creates a solar system on the currently selected star
* **Solar System for All Stars** -- Hotkey: `ctrl-l`. Create a solar system for all stars in the sector.
* **Save Solar System to HTML**  -- Generates a textual html file for the current solar system. 
* **Trade route to all garden planets**. Creates a trade route -- that is an object describing the reachability of a given star in jumps -- to all garden planets. 
* **Preferences**. Allows you to set fonts and display options. Currently **very** limited.
* **Exit**. -- Hotkey: `ctrl-x`. Exits the program


