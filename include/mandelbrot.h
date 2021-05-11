#ifndef __MANDELBROT_H__
#define __MANDELBROT_H__

#include "fractal.h"


class CMandelbrot : public IFractal
{
     public :
	CMandelbrot( const point2f & min=point2f(-3.0f,-2.0f), 
		     const point2f & max=point2f(2.0f,2.0f), 
		     const float radius=2.0f, 
		     const float exponent=2.0f, 
		     const int max_nb_iterations=80, 
		     const color4f & in_color=color4f(color3f::black,1.0f), 
		     const color4f & out_color1=color4f(color3f::green,1.0f), 
		     const color4f & out_color2=color4f(color3f::orange,1.0f) );
	virtual ~CMandelbrot();
	virtual void render( IWindow *window );
};

#endif //__MANDELBROT_H__
