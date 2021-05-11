#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "application_base.h"
#include "singleton.h"
#include "logger.h"
#include "global_timer.h"
#include "types.h"
#include "fractal_factory.h"
#include "geometry.h"


class CApplication : public IApplicationBase, public CSingleton<CApplication>, public CScopeLogger
{
     friend class CSingleton<CApplication>;

     protected :
	IFractal *m_Fractal;
	std::string m_FractalType;

	CApplication();
	virtual ~CApplication();
	virtual void begin();
	virtual void mouse_motion( const int x, const int y );
	virtual void mouse_button_up( const int x, const int y, const EMouseButton & button );
	virtual void mouse_button_down( const int x, const int y, const EMouseButton & button );
	//virtual void mouse_wheel_up( const int x, const int y );
	//virtual void mouse_wheel_down( const int x, const int y );
	virtual void key_up( const int key );
	virtual void key_down( const int key );
	virtual void render() const;
	virtual void update();
	virtual void end();
};

#endif //__APPLICATION_H__
