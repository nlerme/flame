#ifndef __FRACTAL_FACTORY_H__
#define __FRACTAL_FACTORY_H__

#include <string>
#include "fractal.h"
#include "mandelbrot.h"
#include "julia.h"


struct CFractalFactory
{
	static IFractal* create( const std::string & type )
	{
		if( type == "mandelbrot" )
			return new CMandelbrot();
		else if( type == "julia" )
			return new CJulia();
		else
			return NULL;
	}
};

#endif //__FRACTAL_FACTORY_H__
