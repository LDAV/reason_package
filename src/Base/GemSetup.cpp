////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// zmoelnig@iem.kug.ac.at
//
// Implementation file
//
//    Copyright (c) 1997-2000 Mark Danks.
//    Copyright (c) G�nther Geiger.
//    Copyright (c) 2001-2002 IOhannes m zmoelnig. forum::f�r::uml�ute
//
//    For information on usage and redistribution, and for a DISCLAIMER OF ALL
//    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.
//
/////////////////////////////////////////////////////////

/* -------------------------- setup function ------------------------------ */

#include "GemMan.h"
#include "GemVersion.h"


static const char GEM_MAINTAINER[] = "IOhannes m zmoelnig";

static const char *GEM_AUTHORS[] = {
  "Chris Clepper",
  "James Tittle",
  "IOhannes m zmoelnig"
};

static const char GEM_OTHERAUTHORS[] =
  "Guenter Geiger, Daniel Heckenberg, Cyrille Henry, et al.";



extern "C" {
//#define GEM_ADDOWNPATH
#ifdef GEM_ADDOWNPATH
# include "s_stuff.h"
# include <string.h>

  /* this is ripped from m_imp.h */
struct _gemclass
{
    t_symbol *c_name;                   /* name (mostly for error reporting) */
    t_symbol *c_helpname;               /* name of help file */
    t_symbol *c_externdir;              /* directory extern was loaded from */
  /* ... */ /* the real t_class continues here... */
};

#define t_gemclass struct _gemclass
static t_class *Gem_setup_class;
#endif

  GEM_EXTERN void Gem_setup()
  {
#ifdef GEM_ADDOWNPATH
    t_namelist*searchpath=sys_searchpath;
    char*mypath=0;
    t_gemclass *c = (t_gemclass*)class_new(gensym("Gem"), 0, 0, 0, 0, A_NULL);
    mypath=c->c_externdir->s_name;

    verbose(1, "eventually adding Gem path '%s' to search-paths", mypath);
    sys_searchpath = namelist_append(sys_searchpath, mypath, 0);
#endif

    // startup GEM

    post("GEM: Graphics Environment for Multimedia");
    post("GEM: ver: %s", GemVersion::versionString());
    post("GEM: compiled: " __DATE__);
    post("GEM: maintained by %s", GEM_MAINTAINER);
    post("GEM: Authors :\tMark Danks (original version)");
    for(unsigned int i=0; i<sizeof(GEM_AUTHORS)/sizeof(*GEM_AUTHORS); i++) {
      post("GEM:\t\t%s", GEM_AUTHORS[i]);
    }  
    post("GEM: with help by %s", GEM_OTHERAUTHORS);
    post("GEM: found a bug? miss a feature? please report it:");
    post("GEM: \thomepage http://gem.iem.at/");
    post("GEM: \tbug-tracker http://sourceforge.net/projects/pd-gem/");
    post("GEM: \tmailing-list http://lists.puredata.info/listinfo/gem-dev/");

    GemMan::initGem();
  }

  GEM_EXTERN void gem_setup()
  {
    Gem_setup();
  }

  GEM_EXTERN void GEM_setup()
  {
    Gem_setup();
  }

}   // for extern "C"
