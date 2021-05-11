#ifndef __FRACTAL_H__
#define __FRACTAL_H__

#include <complex>
#include "window.h"
#include "geometry.h"
#include "color.h"


typedef std::complex<float> complex;

class IFractal
{
     protected :
	IWindow *m_Window;
	point2f m_Min, m_Max;
	float m_Radius, m_Exponent;
	int m_MaxNbIterations;
	color4f m_InColor;
	color4f m_OutColor1;
	color4f m_OutColor2;

	point2f _window_to_fractal_coords( const point2i & p ) const;

     public :
	IFractal( const point2f & min, const point2f & max, const float radius, const float exponent, const int max_nb_iterations, const color4f & in_color, const color4f & out_color1, const color4f & out_color2 );
	virtual ~IFractal();
	virtual void render( IWindow *window ) = 0;
	virtual void zoom( const point2i & min, const point2i & max );
	virtual void set_inside_color( const color4f & c );
	virtual void set_outside_color1( const color4f & c );
	virtual void set_outside_color2( const color4f & c );
	virtual void set_exponent( const float exponent );
	virtual void set_radius( const float radius );
	virtual void set_max_nb_iterations( const int max_nb_iterations );
	virtual float get_exponent() const;
	virtual float get_radius() const;
	virtual int get_max_nb_iterations() const;
};

#endif //__FRACTAL_H__
