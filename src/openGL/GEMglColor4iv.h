 /* ------------------------------------------------------------------
  * GEM - Graphics Environment for Multimedia
  *
  *  Copyright (c) 2002 IOhannes m zmoelnig. forum::f�r::uml�ute. IEM
  *	zmoelnig@iem.kug.ac.at
  *  For information on usage and redistribution, and for a DISCLAIMER
  *  OF ALL WARRANTIES, see the file, "GEM.LICENSE.TERMS"
  *
  *  this file has been generated...
  * ------------------------------------------------------------------
  */

#ifndef INCLUDE_GEM_GLCOLOR4IV_H_
#define INCLUDE_GEM_GLCOLOR4IV_H_

#include "GemGLBase.h"

/*
 CLASS
	GEMglColor4iv
 KEYWORDS
	openGL	0
 DESCRIPTION
	wrapper for the openGL-function
	"glColor4iv( GLint* v)"
 */

class GEM_EXTERN GEMglColor4iv : public GemGLBase
{
	CPPEXTERN_HEADER(GEMglColor4iv, GemGLBase)

	public:
	  // Constructor
	  GEMglColor4iv (t_float, t_float, t_float, t_float);	// CON
	protected:
	  // Destructor
	  virtual ~GEMglColor4iv ();
	  // Do the rendering
	  virtual void	render (GemState *state);

	// variable
	GLint	v[4];		// VAR
	virtual void	vMess(t_float, t_float, t_float, t_float);	// FUN

	private:

	// we need one inlet
	  t_inlet *m_inlet;

	// static member functions
         static void    vMessCallback (void*, t_floatarg, t_floatarg, t_floatarg, t_floatarg);
};
#endif // for header file