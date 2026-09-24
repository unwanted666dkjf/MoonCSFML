# MoonCSFML


## About

MoonCSFML is a high-performance binding of 
[SFML2.6.2](https://github.com/SFML/SFML/releases/tag/2.6.2) for C. 
The goal was to make C game development a less painful experience.<br>

When creating this library, I took into account the experience of 
creating the previous one: [SSW_SFML3](https://github.com/unwanted666dkjf/SSW_SFML3).<br>

This project is independent and is in no way related to the official one:
[CSFML](https://github.com/SFML/csfml).<br>

Why 'Moon'?
I developed this library mostly at night.<br>


## Notes

SFML 2.6.2 was chosen as binding target, even 
though [SFML3.1.0](https://github.com/SFML/SFML/releases/tag/3.1.0) is the stable version at the time of writing.<br>
SFML2.6.2 is a recent bug-fix and is no longer maintained.
My choice was driven by the fact that more tutorials are available for SFML 2. 
Also, my goal was to achieve high binding performance, and using SFML 2 helped 
reduce the number of object copies between C++ and C.


## Status

I'll contribute bug fixes and update the library as needed.<br>

I also plan to rewrite SFML 2.6.2 slightly. I don't promise anything, 
but if the need arises, I will definitely do it.<br>

As they used to say, “If it works, don’t touch it.”.<br>

I also want to note that SFML always doesn't work well with 
unicode characters. As the ['SFML Team'](https://github.com/SFML/SFML/issues/3406) themselves say, 
this is a C and C++ problem.<br>

Also, any link here may become invalid at any time through no fault of my own.<br>

This library does not have a module for working with networking. 
This is done on purpose so as not to overcomplicate the project.<br>


## Building

You can download built version of library from 'release' page or build it yourself.<br>

Building requirements:
- OS: Windows(8.1 or newer) or Linux, macOS not supported;
- Architecture: 64-bit only;
- Compiler: gcc for Linux or mingw for Windows, other compilers are not supported;
- Compiler must support C99/gnu99 and C++14/gnu++14;
- Built static SFML2.6.2 libraries and headers;
- CMake 3.18 or higher.<br>

Also, although I already provide dependencies for the build, 
the following packages may need to be installed on Linux: 
X11, Xrandr, Xcursor, Xinerama, Xi, Xxf86vm, 
xkbcommon-x11 and Xrender.
Btw, wayland sucks.<br>

Building:
0. Download repository.
1. Check the CMake file, change the build mode if necessary.
2. Create a build directory inside the project folder and go to it.
3. 
```bash
cmake .. or cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . or cmake --build . --config Release
```


## Learn

Please, use these official sources for SFML:
* The [official tutorials](https://www.sfml-dev.org/tutorials/)
* The [online API documentation](https://www.sfml-dev.org/documentation/)
* The [community wiki](https://github.com/SFML/SFML/wiki/)
* The [community forum](https://en.sfml-dev.org/forums/) (or [French](https://fr.sfml-dev.org/forums/))

My API is not much different from the standard one for SFML2.6.2.
But, of course, as always, the best tutorial is the source code.<br>

Also, you have documentation in headers and example in file 'main.c'.
To run the example you need to go to the 'Build' directory, change 
the build mode in the CMake file and enter the following commands:
```bash
cmake .. or cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . or cmake --build . --config Release
```
<br>After build you can launch executable and see if it works.


## Author

unwanted666dkjf/void: turtlem225@gmail.com
