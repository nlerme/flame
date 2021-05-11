#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <unistd.h>
#include "window.h"
#include "config.h"
#include "application.h"

using std::cout;
using std::cerr;
using std::endl;


CApplication::CApplication() : CScopeLogger(__FUNCTION__)
{
	// Help
	std::cout << "[ Mouse / keys features ]\n";
	std::cout << "-------------------------\n";
	std::cout << "mouse left button  -> zoom in\n";
	std::cout << "mouse right button -> zoom out\n";
	std::cout << "key f              -> windowed / fullscreen mode\n";
	std::cout << "key t              -> mandelbrot / julia fractal\n";
	std::cout << "key a              -> decreases exponent (in [1,+oo[)\n";
	std::cout << "key q              -> increases exponent (in [1,+oo[)\n";
	std::cout << "key z              -> decreases radius (in [1,+oo[)\n";
	std::cout << "key s              -> increases radius (in [1,+oo[)\n";
	std::cout << "key e              -> decreases maximum number of iterations (in [1,+oo[)\n";
	std::cout << "key d              -> increases maximum number of iterations (in [1,+oo[)\n";
	std::cout << "key esc            -> quit\n";

	// Fractal settings
	m_FractalType = CConfig::FractalType;
	m_Fractal = CFractalFactory::create(m_FractalType);
	m_Fractal->set_inside_color(CConfig::FractalInColor);
	m_Fractal->set_outside_color1(CConfig::FractalOutColor1);
	m_Fractal->set_outside_color2(CConfig::FractalOutColor2);
	m_Fractal->set_max_nb_iterations(CConfig::FractalMaxNbIterations);

	pause();
}

CApplication::~CApplication()
{
	delete m_Fractal, m_Fractal=NULL;
}

void CApplication::begin()
{
	window()->clear(color4f(color3f::black, 1.0f));

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void CApplication::mouse_motion( const int x, const int y ){}

void CApplication::mouse_button_up( const int x, const int y, const EMouseButton & button ){}

void CApplication::mouse_button_down( const int x, const int y, const EMouseButton & button )
{
	int width = window()->width();
	int height = window()->height();

	if( button == MOUSE_BUTTON_LEFT )
	{
		point2i min = point2i(x-(width/CConfig::ZoomInFactor),y-(height/CConfig::ZoomInFactor));
		point2i max = point2i(x+(width/CConfig::ZoomInFactor),y+(height/CConfig::ZoomInFactor));
		m_Fractal->zoom(min, max);
		render();
	}

	if( button == MOUSE_BUTTON_RIGHT )
	{
		point2i min = point2i(x-(width/CConfig::ZoomOutFactor),y-(height/CConfig::ZoomOutFactor));
		point2i max = point2i(x+(width/CConfig::ZoomOutFactor),y+(height/CConfig::ZoomOutFactor));
		m_Fractal->zoom(min, max);
		render();
	}
}

/*void CApplication::mouse_wheel_up( const int x, const int y ){}*/

/*void CApplication::mouse_wheel_down( const int x, const int y ){}*/

void CApplication::key_down( const int key )
{
	switch( key )
	{
		case SDLK_ESCAPE :
			quit();
			break;

		case 'f' :
			window()->toggle_fullscreen();
			break;

		case 'a' :
			m_Fractal->set_exponent(std::max(m_Fractal->get_exponent()-1.0f,1.0f));
			render();
			break;

		case 'q' :
			m_Fractal->set_exponent(m_Fractal->get_exponent()+1.0f);
			render();
			break;

		case 'z' :
			m_Fractal->set_radius(std::max(m_Fractal->get_radius()-1.0f,1.0f));
			render();
			break;

		case 's' :
			m_Fractal->set_radius(m_Fractal->get_radius()+1.0f);
			render();
			break;

		case 'e' :
			m_Fractal->set_max_nb_iterations(std::max(m_Fractal->get_max_nb_iterations()-5,1));
			render();
			break;

		case 'd' :
			m_Fractal->set_max_nb_iterations(m_Fractal->get_max_nb_iterations()+5);
			render();
			break;

		case 't' :
			delete m_Fractal;
			m_FractalType = (m_FractalType=="mandelbrot" ? "julia" : "mandelbrot");
			m_Fractal = CFractalFactory::create(m_FractalType);
			render();
			break;
	}
}

void CApplication::key_up( const int key ){}

void CApplication::render() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	m_Fractal->render(window());

	window()->swap_buffers();
}

void CApplication::update(){}

void CApplication::end(){}
