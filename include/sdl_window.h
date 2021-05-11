#ifndef __SDL_WINDOW_H__
#define __SDL_WINDOW_H__

#include <SDL/SDL.h>
#include "window.h"
#include "logger.h"


class CSDLWindow : public IWindow
{
     public :
	CSDLWindow( const std::string & title, const int width, const int height, const int flags=SDL_SWSURFACE | SDL_DOUBLEBUF, const bool centered=true );
	virtual ~CSDLWindow();

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

#endif //__SDL_WINDOW_H__
