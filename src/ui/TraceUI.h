//
// rayUI.h
//
// The header file for the UI part
//

#ifndef __rayUI_h__
#define __rayUI_h__

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Button.H>

#include <FL/fl_file_chooser.H>		// FLTK file chooser

#include "TraceGLWindow.h"

class TraceUI {
public:
	TraceUI();

	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;

	Fl_Slider*			m_sizeSlider;
	Fl_Slider*			m_depthSlider;
	Fl_Slider* m_attConstant_;
	Fl_Slider* m_attLinear_;
	Fl_Slider* m_attQuatric_;
	Fl_Slider* m_ambient_;
	Fl_Slider* m_threshold_;
	Fl_Slider* m_supersampling_;

	Fl_Button*			m_renderButton;
	Fl_Button*			m_stopButton;

	TraceGLWindow*		m_traceGlWindow;

	// member functions
	void show();

	void		setRayTracer(RayTracer *tracer);

	int			getSize();
	int			getDepth();

	int m_supersampling = 1;

	double m_attConstant;
	double m_attLinear;
	double m_attQuatric;
	double m_ambient=1;
	double m_threshold;
	

private:
	RayTracer*	raytracer;

	int			m_nSize;
	int			m_nDepth;
	

// static class members
	static Fl_Menu_Item menuitems[];

	static TraceUI* whoami(Fl_Menu_* o);

	static void cb_load_scene(Fl_Menu_* o, void* v);
	static void cb_save_image(Fl_Menu_* o, void* v);
	static void cb_exit(Fl_Menu_* o, void* v);
	static void cb_about(Fl_Menu_* o, void* v);

	static void cb_exit2(Fl_Widget* o, void* v);

	static void cb_sizeSlides(Fl_Widget* o, void* v);
	static void cb_depthSlides(Fl_Widget* o, void* v);
	static void cb_attenuationConstant(Fl_Widget* o, void* v);
	static void cb_attenuationLinear(Fl_Widget* o, void* v);
	static void cb_attenuationQuatric(Fl_Widget* o, void* v);
	static void cb_ambient(Fl_Widget* o, void* v);
	static void cb_threshold(Fl_Widget* o, void* v);
	static void cb_supersampling(Fl_Widget* o, void* v);

	static void cb_render(Fl_Widget* o, void* v);
	static void cb_stop(Fl_Widget* o, void* v);
};

#endif
