Presentation
------------
Flame is a small C++ graphical user interface for interactively exploring Mandelbrot and Julia fractals using mouse and keyboard. This software is distributed under LGPL license. An example of exploration is illustrated on the image below for the Mandelbrot fractal:

![Screenshot](https://i.ibb.co/VVJvjFy/foobar.png)

Requirements
------------
* The [OpenGL](https://opengl.org/) library for handling graphics.
* The [GLEW](https://glew.sourceforge.net/) library for loading OpenGL extensions.
* The [SDL1.2](https://www.libsdl.org/) library as window manager.
* The [freetype](https://freetype.org/) library for fonts rendering.

Compilation
-----------
Once the archive decompressed, go into the root directory and type `make` in a terminal.

Execution
---------
The software can be run by typing `./main` in a terminal.

Documentation
-------------
The LaTeX / HTML documentation in the "doc" directory can be generated by typing `make doc` in a terminal.
