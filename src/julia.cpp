#include "julia.h"


CJulia::CJulia( const point2f & min, 
		const point2f & max, 
		const float radius, 
		const float exponent, 
		const int max_nb_iterations, 
		const color4f & in_color, 
		const color4f & out_color1, 
		const color4f & out_color2 ) : IFractal(min, max, radius, exponent, max_nb_iterations, in_color, out_color1, out_color2){}

CJulia::~CJulia(){}

void CJulia::render( IWindow *window )
{
	float norm, e, a;
	bool is_inside;
	point2f p;
	complex c, z;
	int k;


	m_Window = window;

	for( int y=0; y<m_Window->height(); y++ )
	{
		for( int x=0; x<m_Window->width(); x++ )
		{
			p         = _window_to_fractal_coords(point2i(x,y));
			c         = complex(0.285f, 0.01f);
			z         = complex(p.x, p.y);
			is_inside = true;
			k         = 0;

			while( k++<m_MaxNbIterations && is_inside )
			{
				z    = sq(z) + c;
				norm = std::sqrt(std::norm(z));

				if( norm > m_Radius )
				{
					e = k + (std::log(2.0f * std::log(m_Radius)) - std::log(std::log(norm))) / std::log(m_Exponent);
					a = std::fabs(e / m_MaxNbIterations);

					m_Window->set_pixel(x, y, mix(m_OutColor1, m_OutColor2, a));
					is_inside = false;
				}
			}

			if( is_inside )
				m_Window->set_pixel(x, y, m_InColor);
		}
	}
}
