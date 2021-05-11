#include "fractal.h"


point2f IFractal::_window_to_fractal_coords( const point2i & p ) const
{
	return point2f(m_Min.x + ((m_Max.x-m_Min.x)/m_Window->width()) * p.x, m_Min.y + ((m_Max.y-m_Min.y)/m_Window->height()) * p.y);
}

IFractal::IFractal( const point2f & min, 
		    const point2f & max, 
		    const float radius, 
		    const float exponent, 
		    const int max_nb_iterations, 
		    const color4f & in_color, 
		    const color4f & out_color1, 
		    const color4f & out_color2 ) : m_Min(min), 
						   m_Max(max), 
						   m_Radius(radius), 
						   m_Exponent(exponent), 
						   m_MaxNbIterations(max_nb_iterations), 
						   m_InColor(in_color), 
						   m_OutColor1(out_color1), 
						   m_OutColor2(out_color2){}

IFractal::~IFractal(){}

void IFractal::zoom( const point2i & min, const point2i & max )
{
	m_Min = _window_to_fractal_coords(min);
	m_Max = _window_to_fractal_coords(max);
}

void IFractal::set_inside_color( const color4f & c )
{
	m_InColor = c;
}

void IFractal::set_outside_color1( const color4f & c )
{
	m_OutColor1 = c;
}

void IFractal::set_outside_color2( const color4f & c )
{
	m_OutColor2 = c;
}

void IFractal::set_exponent( const float exponent )
{
	m_Exponent = exponent;
}

void IFractal::set_radius( const float radius )
{
	m_Radius = radius;
}

float IFractal::get_exponent() const
{
	return m_Exponent;
}

float IFractal::get_radius() const
{
	return m_Radius;
}

void IFractal::set_max_nb_iterations( const int max_nb_iterations )
{
	m_MaxNbIterations = max_nb_iterations;
}

int IFractal::get_max_nb_iterations() const
{
	return m_MaxNbIterations;
}
