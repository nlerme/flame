#ifndef __GL_WINDOW_H__
#define __GL_WINDOW_H__

#include <SDL/SDL.h>
#include "window.h"
#include "logger.h"


class CGLWindow : public IWindow
{
     public :
	CGLWindow( const std::string & title, const int width, const int height, const int flags=SDL_OPENGL|SDL_RESIZABLE, const bool centered=true );
	virtual ~CGLWindow();

	virtual void swap_buffers() const;
	virtual void resize( const int width, const int height );
	virtual void clear( const color4f & c );
	virtual void set_pixel( const int x, const int y, const color4f & c );
	virtual color4f get_pixel( const int x, const int y ) const;
	virtual void draw_rectangle( const int x1, const int y1, const int x2, const int y2, const color4f & c );
	virtual void fill_rectangle( const int x1, const int y1, const int x2, const int y2, const color4f & c );
	virtual void draw_circle( const int xc, const int yc, const int radius, const color4f & c );
	virtual void fill_circle( const int xc, const int yc, const int radius, const color4f & c );
	virtual void draw_line( const int x1, const int y1, const int x2, const int y2, const color4f & c );
	virtual EWindowType get_window_type() const;
};

#endif //__GL_WINDOW_H__
