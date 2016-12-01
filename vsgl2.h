/*
  Copyright (C) 2016 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef VSGL2_H_INCLUDED
#define VSGL2_H_INCLUDED

/*! \mainpage Very Simple Graphic Library 2
 *
 * \section intro_sec Introduzione
 *
 * This is a very simple (as in its name) library,
 * a sort of wrapper around the very good SDL2 library.
 * It is inspired by the PyGame library, even though I have wanted
 * to stay very C-style, so no classes, no dot-notation in general.
 *
 */

/*! \file
 *  \brief Very Simple Graphic Library 2
 *  \author Alessandro Bugatti
 *  \version 0.1
 *  \date  Creation 2016/11/08
 */

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

namespace vsgl2
{


class Color
{

public:
    SDL_Color c;
    Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    {
        c.r = r;
        c.g = g;
        c.b = b;
        c.a = a;
    }
};

namespace general
{

const int FULLSCREEN = SDL_WINDOW_FULLSCREEN;

/**
* \brief Use this function to initiate the library, must be called first.
*/
void init();

/**
* \brief Close and free all the resources, must be called last.
*/
void close();

/**
* \brief Use this function to create a window with the specified dimensions and a title, optionally in full screen
* \param w the width of the window, in screen coordinates
* \param h the height of the window, in screen coordinates
* \param title the title of the window
* \param fullscreen Flag to set the application to fullscreen mode (fullscreen = 1)
* or windowed (fullscreen = 0)
*/
void set_window(int w, int h, string title, int fullscreen = 0);

/**
* \brief Use this function to get the width of the current window
* \return The width of the current window
*/
int get_window_width();

/**
* \brief Use this function to get the height of the current window
* \return The height of the current window
*/
int get_window_height();

}//closing namespace general

namespace video
{
/**
* \brief Use this function to check when to stop the main loop
* \return True if the user has clicked on the X to close the window
*    or has pressed ESC to close the program
*/
bool done();

/**
* \brief Use this function to update the screen after drawing on it
* Typically called at the end of the main loop
*/
void update();

/** \brief Use to draw a point at x,y coordinates
*   \param x The x coordinate
*   \param y The y coordinate
*   \param c The color of the point
*   \warning In the present implementation this function is very slow,
*   so using it for drawing a large amount of points should be avoided
*/
void draw_point(int x, int y, const Color &c);

/**
*   \brief Use to draw a line
*   \param x1 The x coordinate of an end point
*   \param y1 The y coordinate of an end point
*   \param x2 The x coordinate of the other end point
*   \param y2 The y coordinate of the other end point
*   \param c The color of the line
*/
void draw_line(int x1, int y1, int x2, int y2, const Color &c);

/**
*   \brief Use to draw a rectangle (only the border),
*   use instead draw_filled_rect to draw a
*   rectangle filled with color
*   \param x The x coordinate of the upper left corner
*   \param y The y coordinate of the upper left corner
*   \param w The width of the rectangle
*   \param h The height of the rectangle
*   \param c The color of the rectangle
*/
void draw_rect(int x, int y, int w, int h, const Color &c);

/**
*   \brief Use to draw a filled rectangle,
*   use instead draw_rect to draw an empty
*   rectangle with colored borders
*   \param x The x coordinate of the upper left corner
*   \param y The y coordinate of the upper left corner
*   \param w The width of the rectangle
*   \param h The height of the rectangle
*   \param c The color of the borders of the rectangle
*/
void draw_filled_rect(int x, int y, int w, int h, const Color &c);

/**
*   \brief Use to draw an image (BMP, PNG, JPG)
*   \param image The image name, either absolute or relative
*   \param x The x coordinate of the upper left corner of the image
*   inside the window coordinates
*   \param y The y coordinate of the upper left corner of the image
*   inside the window coordinates
*   \param w The width of the image as it will appear inside the window,
*   not its original value
*   \param h The height of the image as it will appear inside the window,
*   not its original value
*   \warning The width and the height can be set as wanted, but it is better
*   to have the dimension of the image in the file the same as in w and h
*   to reduce CPU load and improve performance
*/
void draw_image(string image, int x, int y, int w, int h);

}//closing video namespace


namespace io
{
    bool isPressed(int key);
}

namespace utils
{

/**
*   \brief Use this function to wait for any button to be pressed
*   \warning This freezes the program while waiting for the
*   button to be pressed so that no drawing or updating
*   can occur at the same time
*/
void wait_for_button_pressed();

/**
*   \brief Use this function to stop the execution for a given amount of milliseconds
*   \param milliseconds Amount of time the program is stopped, in milliseconds
*/
void delay(int milliseconds);

}//closing namaspace utility

}

//This is here to avoid using of namespace by the user of the library
using namespace vsgl2;
using namespace vsgl2::general;
using namespace vsgl2::video;
using namespace vsgl2::utils;
#endif //VSGL2_H_INCLUDED