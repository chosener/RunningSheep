/***************************************************************************/
/*                                                                         */
/*  ftsynth.h                                                              */
/*                                                                         */
/*    FreeType synthesizing code for emboldening and slanting              */
/*    (specification).                                                     */
/*                                                                         */
<<<<<<< HEAD
/*  Copyright 2000-2001, 2003, 2006, 2008, 2012, 2013 by                   */
=======
/*  Copyright 2000-2001, 2003, 2006, 2008 by                               */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used,       */
/*  modified, and distributed under the terms of the FreeType project      */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/


  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/
  /*********                                                       *********/
  /*********        WARNING, THIS IS ALPHA CODE!  THIS API         *********/
  /*********    IS DUE TO CHANGE UNTIL STRICTLY NOTIFIED BY THE    *********/
  /*********            FREETYPE DEVELOPMENT TEAM                  *********/
  /*********                                                       *********/
  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/


  /* Main reason for not lifting the functions in this module to a  */
  /* `standard' API is that the used parameters for emboldening and */
  /* slanting are not configurable.  Consider the functions as a    */
<<<<<<< HEAD
  /* code resource that should be copied into the application and   */
=======
  /* code resource which should be copied into the application and  */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
  /* adapted to the particular needs.                               */


#ifndef __FTSYNTH_H__
#define __FTSYNTH_H__


#include <ft2build.h>
#include FT_FREETYPE_H

#ifdef FREETYPE_H
#error "freetype.h of FreeType 1 has been loaded!"
#error "Please fix the directory search order for header files"
#error "so that freetype.h of FreeType 2 is found first."
#endif


FT_BEGIN_HEADER

  /* Embolden a glyph by a `reasonable' value (which is highly a matter of */
  /* taste).  This function is actually a convenience function, providing  */
  /* a wrapper for @FT_Outline_Embolden and @FT_Bitmap_Embolden.           */
  /*                                                                       */
<<<<<<< HEAD
  /* For emboldened outlines the height, width, and advance metrics are    */
  /* increased by the strength of the emboldening.  You can also call      */
  /* @FT_Outline_Get_CBox to get precise values.                           */
=======
  /* For emboldened outlines the metrics are estimates only; if you need   */
  /* precise values you should call @FT_Outline_Get_CBox.                  */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
  FT_EXPORT( void )
  FT_GlyphSlot_Embolden( FT_GlyphSlot  slot );

  /* Slant an outline glyph to the right by about 12 degrees. */
  FT_EXPORT( void )
  FT_GlyphSlot_Oblique( FT_GlyphSlot  slot );

  /* */

<<<<<<< HEAD

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
FT_END_HEADER

#endif /* __FTSYNTH_H__ */


/* END */
