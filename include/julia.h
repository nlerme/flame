#ifndef __JULIA_H__
#define __JULIA_H__

#include "fractal.h"


class CJulia : public IFractal
{
     public :
	CJulia( const point2f & min=point2f(-2.0f,-2.2f), 
		const point2f & max=point2f(2.0f,2.2f), 
		const float radius=2.0f, 
		const float exponent=2.0f, 
		const int max_nb_iterations=80, 
		const color4f & in_color=color4f(color3f::black,1.0f), 
		const color4f & out_color1=color4f(color3f::green,1.0f), 
		const color4f & out_color2=color4f(color3f::orange,1.0f) );
	virtual ~CJulia();
	virtual void render( IWindow *window );
};

#endif //__JULIA_H__
