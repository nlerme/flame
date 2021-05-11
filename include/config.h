#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>
#include "config.h"
#include "window.h"
#include "color.h"


// Default values of some parameters
namespace CConfig
{
	static const EWindowType WindowType     = WT_OPENGL;
	static const std::string WindowTitle    = "Flame 0.1.0";
	static const int WindowWidth            = 1024;
	static const int WindowHeight           = 768;
	static const std::string LogFilename    = "output.log";
	static const float VSync                = 1.0f/50.0f;
	static const float ZoomInFactor         = 3.0f;
	static const float ZoomOutFactor        = 1.5f;
	static const std::string FractalType    = "mandelbrot";
	static const float FractalRadius        = 2.0f;
	static const float FractalExponent      = 2.0f;
	static const color4f FractalInColor     = color4f(color3f::black,1.0f);
	static const color4f FractalOutColor1   = color4f(color3f::green,1.0f);
	static const color4f FractalOutColor2   = color4f(color3f::orange,1.0f);
	static const int FractalMaxNbIterations = 80;
};

#endif //__CONFIG_H__
