/***************************************************************************/
/*                                                                         */
/*  ftheader.h                                                             */
/*                                                                         */
/*    Build macros of the FreeType 2 library.                              */
/*                                                                         */
<<<<<<< HEAD
/*  Copyright 1996-2008, 2010, 2012, 2013 by                               */
=======
/*  Copyright 1996-2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2010 by */
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

#ifndef __FT_HEADER_H__
#define __FT_HEADER_H__


  /*@***********************************************************************/
  /*                                                                       */
  /* <Macro>                                                               */
  /*    FT_BEGIN_HEADER                                                    */
  /*                                                                       */
  /* <Description>                                                         */
  /*    This macro is used in association with @FT_END_HEADER in header    */
  /*    files to ensure that the declarations within are properly          */
  /*    encapsulated in an `extern "C" { .. }' block when included from a  */
  /*    C++ compiler.                                                      */
  /*                                                                       */
#ifdef __cplusplus
#define FT_BEGIN_HEADER  extern "C" {
#else
#define FT_BEGIN_HEADER  /* nothing */
#endif


  /*@***********************************************************************/
  /*                                                                       */
  /* <Macro>                                                               */
  /*    FT_END_HEADER                                                      */
  /*                                                                       */
  /* <Description>                                                         */
  /*    This macro is used in association with @FT_BEGIN_HEADER in header  */
  /*    files to ensure that the declarations within are properly          */
  /*    encapsulated in an `extern "C" { .. }' block when included from a  */
  /*    C++ compiler.                                                      */
  /*                                                                       */
#ifdef __cplusplus
#define FT_END_HEADER  }
#else
#define FT_END_HEADER  /* nothing */
#endif


  /*************************************************************************/
  /*                                                                       */
  /* Aliases for the FreeType 2 public and configuration files.            */
  /*                                                                       */
  /*************************************************************************/

  /*************************************************************************/
  /*                                                                       */
  /* <Section>                                                             */
  /*    header_file_macros                                                 */
  /*                                                                       */
  /* <Title>                                                               */
  /*    Header File Macros                                                 */
  /*                                                                       */
  /* <Abstract>                                                            */
  /*    Macro definitions used to #include specific header files.          */
  /*                                                                       */
  /* <Description>                                                         */
  /*    The following macros are defined to the name of specific           */
  /*    FreeType~2 header files.  They can be used directly in #include    */
  /*    statements as in:                                                  */
  /*                                                                       */
  /*    {                                                                  */
  /*      #include FT_FREETYPE_H                                           */
  /*      #include FT_MULTIPLE_MASTERS_H                                   */
  /*      #include FT_GLYPH_H                                              */
  /*    }                                                                  */
  /*                                                                       */
  /*    There are several reasons why we are now using macros to name      */
  /*    public header files.  The first one is that such macros are not    */
  /*    limited to the infamous 8.3~naming rule required by DOS (and       */
  /*    `FT_MULTIPLE_MASTERS_H' is a lot more meaningful than `ftmm.h').   */
  /*                                                                       */
  /*    The second reason is that it allows for more flexibility in the    */
  /*    way FreeType~2 is installed on a given system.                     */
  /*                                                                       */
  /*************************************************************************/


  /* configuration files */

  /*************************************************************************
   *
   * @macro:
   *   FT_CONFIG_CONFIG_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing
   *   FreeType~2 configuration data.
   *
   */
#ifndef FT_CONFIG_CONFIG_H
<<<<<<< HEAD
#define FT_CONFIG_CONFIG_H  <config/ftconfig.h>
=======
#define FT_CONFIG_CONFIG_H  <freetype/config/ftconfig.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#endif


  /*************************************************************************
   *
   * @macro:
   *   FT_CONFIG_STANDARD_LIBRARY_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing
   *   FreeType~2 interface to the standard C library functions.
   *
   */
#ifndef FT_CONFIG_STANDARD_LIBRARY_H
<<<<<<< HEAD
#define FT_CONFIG_STANDARD_LIBRARY_H  <config/ftstdlib.h>
=======
#define FT_CONFIG_STANDARD_LIBRARY_H  <freetype/config/ftstdlib.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#endif


  /*************************************************************************
   *
   * @macro:
   *   FT_CONFIG_OPTIONS_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing
   *   FreeType~2 project-specific configuration options.
   *
   */
#ifndef FT_CONFIG_OPTIONS_H
<<<<<<< HEAD
#define FT_CONFIG_OPTIONS_H  <config/ftoption.h>
=======
#define FT_CONFIG_OPTIONS_H  <freetype/config/ftoption.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#endif


  /*************************************************************************
   *
   * @macro:
   *   FT_CONFIG_MODULES_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   list of FreeType~2 modules that are statically linked to new library
   *   instances in @FT_Init_FreeType.
   *
   */
#ifndef FT_CONFIG_MODULES_H
<<<<<<< HEAD
#define FT_CONFIG_MODULES_H  <config/ftmodule.h>
=======
#define FT_CONFIG_MODULES_H  <freetype/config/ftmodule.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#endif

  /* */

  /* public headers */

  /*************************************************************************
   *
   * @macro:
   *   FT_FREETYPE_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   base FreeType~2 API.
   *
   */
<<<<<<< HEAD
#define FT_FREETYPE_H  <freetype.h>
=======
#define FT_FREETYPE_H  <freetype/freetype.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_ERRORS_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   list of FreeType~2 error codes (and messages).
   *
   *   It is included by @FT_FREETYPE_H.
   *
   */
<<<<<<< HEAD
#define FT_ERRORS_H  <fterrors.h>
=======
#define FT_ERRORS_H  <freetype/fterrors.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_MODULE_ERRORS_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   list of FreeType~2 module error offsets (and messages).
   *
   */
<<<<<<< HEAD
#define FT_MODULE_ERRORS_H  <ftmoderr.h>
=======
#define FT_MODULE_ERRORS_H  <freetype/ftmoderr.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_SYSTEM_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   FreeType~2 interface to low-level operations (i.e., memory management
   *   and stream i/o).
   *
   *   It is included by @FT_FREETYPE_H.
   *
   */
<<<<<<< HEAD
#define FT_SYSTEM_H  <ftsystem.h>
=======
#define FT_SYSTEM_H  <freetype/ftsystem.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_IMAGE_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing type
   *   definitions related to glyph images (i.e., bitmaps, outlines,
   *   scan-converter parameters).
   *
   *   It is included by @FT_FREETYPE_H.
   *
   */
<<<<<<< HEAD
#define FT_IMAGE_H  <ftimage.h>
=======
#define FT_IMAGE_H  <freetype/ftimage.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_TYPES_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   basic data types defined by FreeType~2.
   *
   *   It is included by @FT_FREETYPE_H.
   *
   */
<<<<<<< HEAD
#define FT_TYPES_H  <fttypes.h>
=======
#define FT_TYPES_H  <freetype/fttypes.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_LIST_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   list management API of FreeType~2.
   *
   *   (Most applications will never need to include this file.)
   *
   */
<<<<<<< HEAD
#define FT_LIST_H  <ftlist.h>
=======
#define FT_LIST_H  <freetype/ftlist.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_OUTLINE_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   scalable outline management API of FreeType~2.
   *
   */
<<<<<<< HEAD
#define FT_OUTLINE_H  <ftoutln.h>
=======
#define FT_OUTLINE_H  <freetype/ftoutln.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_SIZES_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   API which manages multiple @FT_Size objects per face.
   *
   */
<<<<<<< HEAD
#define FT_SIZES_H  <ftsizes.h>
=======
#define FT_SIZES_H  <freetype/ftsizes.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_MODULE_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   module management API of FreeType~2.
   *
   */
<<<<<<< HEAD
#define FT_MODULE_H  <ftmodapi.h>
=======
#define FT_MODULE_H  <freetype/ftmodapi.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_RENDER_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   renderer module management API of FreeType~2.
   *
   */
<<<<<<< HEAD
#define FT_RENDER_H  <ftrender.h>


  /*************************************************************************
   *
   * @macro:
   *   FT_AUTOHINTER_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing
   *   structures and macros related to the auto-hinting module.
   *
   */
#define FT_AUTOHINTER_H  <ftautoh.h>


  /*************************************************************************
   *
   * @macro:
   *   FT_CFF_DRIVER_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing
   *   structures and macros related to the CFF driver module.
   *
   */
#define FT_CFF_DRIVER_H  <ftcffdrv.h>


  /*************************************************************************
   *
   * @macro:
   *   FT_TRUETYPE_DRIVER_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing
   *   structures and macros related to the TrueType driver module.
   *
   */
#define FT_TRUETYPE_DRIVER_H  <ftttdrv.h>
=======
#define FT_RENDER_H  <freetype/ftrender.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_TYPE1_TABLES_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   types and API specific to the Type~1 format.
   *
   */
<<<<<<< HEAD
#define FT_TYPE1_TABLES_H  <t1tables.h>
=======
#define FT_TYPE1_TABLES_H  <freetype/t1tables.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_TRUETYPE_IDS_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   enumeration values which identify name strings, languages, encodings,
   *   etc.  This file really contains a _large_ set of constant macro
   *   definitions, taken from the TrueType and OpenType specifications.
   *
   */
<<<<<<< HEAD
#define FT_TRUETYPE_IDS_H  <ttnameid.h>
=======
#define FT_TRUETYPE_IDS_H  <freetype/ttnameid.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_TRUETYPE_TABLES_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   types and API specific to the TrueType (as well as OpenType) format.
   *
   */
<<<<<<< HEAD
#define FT_TRUETYPE_TABLES_H  <tttables.h>
=======
#define FT_TRUETYPE_TABLES_H  <freetype/tttables.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_TRUETYPE_TAGS_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   definitions of TrueType four-byte `tags' which identify blocks in
   *   SFNT-based font formats (i.e., TrueType and OpenType).
   *
   */
<<<<<<< HEAD
#define FT_TRUETYPE_TAGS_H  <tttags.h>
=======
#define FT_TRUETYPE_TAGS_H  <freetype/tttags.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_BDF_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   definitions of an API which accesses BDF-specific strings from a
   *   face.
   *
   */
<<<<<<< HEAD
#define FT_BDF_H  <ftbdf.h>
=======
#define FT_BDF_H  <freetype/ftbdf.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_CID_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   definitions of an API which access CID font information from a
   *   face.
   *
   */
<<<<<<< HEAD
#define FT_CID_H  <ftcid.h>
=======
#define FT_CID_H  <freetype/ftcid.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_GZIP_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   definitions of an API which supports gzip-compressed files.
   *
   */
<<<<<<< HEAD
#define FT_GZIP_H  <ftgzip.h>
=======
#define FT_GZIP_H  <freetype/ftgzip.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_LZW_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   definitions of an API which supports LZW-compressed files.
   *
   */
<<<<<<< HEAD
#define FT_LZW_H  <ftlzw.h>
=======
#define FT_LZW_H  <freetype/ftlzw.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_BZIP2_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   definitions of an API which supports bzip2-compressed files.
   *
   */
<<<<<<< HEAD
#define FT_BZIP2_H  <ftbzip2.h>
=======
#define FT_BZIP2_H  <freetype/ftbzip2.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_WINFONTS_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   definitions of an API which supports Windows FNT files.
   *
   */
<<<<<<< HEAD
#define FT_WINFONTS_H   <ftwinfnt.h>
=======
#define FT_WINFONTS_H   <freetype/ftwinfnt.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_GLYPH_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   API of the optional glyph management component.
   *
   */
<<<<<<< HEAD
#define FT_GLYPH_H  <ftglyph.h>
=======
#define FT_GLYPH_H  <freetype/ftglyph.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_BITMAP_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   API of the optional bitmap conversion component.
   *
   */
<<<<<<< HEAD
#define FT_BITMAP_H  <ftbitmap.h>
=======
#define FT_BITMAP_H  <freetype/ftbitmap.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_BBOX_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   API of the optional exact bounding box computation routines.
   *
   */
<<<<<<< HEAD
#define FT_BBOX_H  <ftbbox.h>
=======
#define FT_BBOX_H  <freetype/ftbbox.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_CACHE_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   API of the optional FreeType~2 cache sub-system.
   *
   */
<<<<<<< HEAD
#define FT_CACHE_H  <ftcache.h>
=======
#define FT_CACHE_H  <freetype/ftcache.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_CACHE_IMAGE_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   `glyph image' API of the FreeType~2 cache sub-system.
   *
   *   It is used to define a cache for @FT_Glyph elements.  You can also
   *   use the API defined in @FT_CACHE_SMALL_BITMAPS_H if you only need to
   *   store small glyph bitmaps, as it will use less memory.
   *
   *   This macro is deprecated.  Simply include @FT_CACHE_H to have all
   *   glyph image-related cache declarations.
   *
   */
#define FT_CACHE_IMAGE_H  FT_CACHE_H


  /*************************************************************************
   *
   * @macro:
   *   FT_CACHE_SMALL_BITMAPS_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   `small bitmaps' API of the FreeType~2 cache sub-system.
   *
   *   It is used to define a cache for small glyph bitmaps in a relatively
   *   memory-efficient way.  You can also use the API defined in
   *   @FT_CACHE_IMAGE_H if you want to cache arbitrary glyph images,
   *   including scalable outlines.
   *
   *   This macro is deprecated.  Simply include @FT_CACHE_H to have all
   *   small bitmaps-related cache declarations.
   *
   */
#define FT_CACHE_SMALL_BITMAPS_H  FT_CACHE_H


  /*************************************************************************
   *
   * @macro:
   *   FT_CACHE_CHARMAP_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   `charmap' API of the FreeType~2 cache sub-system.
   *
   *   This macro is deprecated.  Simply include @FT_CACHE_H to have all
   *   charmap-based cache declarations.
   *
   */
#define FT_CACHE_CHARMAP_H  FT_CACHE_H


  /*************************************************************************
   *
   * @macro:
   *   FT_MAC_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   Macintosh-specific FreeType~2 API.  The latter is used to access
   *   fonts embedded in resource forks.
   *
   *   This header file must be explicitly included by client applications
   *   compiled on the Mac (note that the base API still works though).
   *
   */
<<<<<<< HEAD
#define FT_MAC_H  <ftmac.h>
=======
#define FT_MAC_H  <freetype/ftmac.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_MULTIPLE_MASTERS_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   optional multiple-masters management API of FreeType~2.
   *
   */
<<<<<<< HEAD
#define FT_MULTIPLE_MASTERS_H  <ftmm.h>
=======
#define FT_MULTIPLE_MASTERS_H  <freetype/ftmm.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_SFNT_NAMES_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   optional FreeType~2 API which accesses embedded `name' strings in
   *   SFNT-based font formats (i.e., TrueType and OpenType).
   *
   */
<<<<<<< HEAD
#define FT_SFNT_NAMES_H  <ftsnames.h>
=======
#define FT_SFNT_NAMES_H  <freetype/ftsnames.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_OPENTYPE_VALIDATE_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   optional FreeType~2 API which validates OpenType tables (BASE, GDEF,
   *   GPOS, GSUB, JSTF).
   *
   */
<<<<<<< HEAD
#define FT_OPENTYPE_VALIDATE_H  <ftotval.h>
=======
#define FT_OPENTYPE_VALIDATE_H  <freetype/ftotval.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_GX_VALIDATE_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   optional FreeType~2 API which validates TrueTypeGX/AAT tables (feat,
   *   mort, morx, bsln, just, kern, opbd, trak, prop).
   *
   */
<<<<<<< HEAD
#define FT_GX_VALIDATE_H  <ftgxval.h>
=======
#define FT_GX_VALIDATE_H  <freetype/ftgxval.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_PFR_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   FreeType~2 API which accesses PFR-specific data.
   *
   */
<<<<<<< HEAD
#define FT_PFR_H  <ftpfr.h>
=======
#define FT_PFR_H  <freetype/ftpfr.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_STROKER_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   FreeType~2 API which provides functions to stroke outline paths.
   */
<<<<<<< HEAD
#define FT_STROKER_H  <ftstroke.h>
=======
#define FT_STROKER_H  <freetype/ftstroke.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_SYNTHESIS_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   FreeType~2 API which performs artificial obliquing and emboldening.
   */
<<<<<<< HEAD
#define FT_SYNTHESIS_H  <ftsynth.h>
=======
#define FT_SYNTHESIS_H  <freetype/ftsynth.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_XFREE86_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   FreeType~2 API which provides functions specific to the XFree86 and
   *   X.Org X11 servers.
   */
<<<<<<< HEAD
#define FT_XFREE86_H  <ftxf86.h>
=======
#define FT_XFREE86_H  <freetype/ftxf86.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_TRIGONOMETRY_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   FreeType~2 API which performs trigonometric computations (e.g.,
   *   cosines and arc tangents).
   */
<<<<<<< HEAD
#define FT_TRIGONOMETRY_H  <fttrigon.h>
=======
#define FT_TRIGONOMETRY_H  <freetype/fttrigon.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_LCD_FILTER_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   FreeType~2 API which performs color filtering for subpixel rendering.
   */
<<<<<<< HEAD
#define FT_LCD_FILTER_H  <ftlcdfil.h>
=======
#define FT_LCD_FILTER_H  <freetype/ftlcdfil.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_UNPATENTED_HINTING_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   FreeType~2 API which performs color filtering for subpixel rendering.
   */
<<<<<<< HEAD
#define FT_UNPATENTED_HINTING_H  <ttunpat.h>
=======
#define FT_UNPATENTED_HINTING_H  <freetype/ttunpat.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_INCREMENTAL_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   FreeType~2 API which performs color filtering for subpixel rendering.
   */
<<<<<<< HEAD
#define FT_INCREMENTAL_H  <ftincrem.h>
=======
#define FT_INCREMENTAL_H  <freetype/ftincrem.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_GASP_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   FreeType~2 API which returns entries from the TrueType GASP table.
   */
<<<<<<< HEAD
#define FT_GASP_H  <ftgasp.h>
=======
#define FT_GASP_H  <freetype/ftgasp.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /*************************************************************************
   *
   * @macro:
   *   FT_ADVANCES_H
   *
   * @description:
   *   A macro used in #include statements to name the file containing the
   *   FreeType~2 API which returns individual and ranged glyph advances.
   */
<<<<<<< HEAD
#define FT_ADVANCES_H  <ftadvanc.h>
=======
#define FT_ADVANCES_H  <freetype/ftadvanc.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /* */

<<<<<<< HEAD
#define FT_ERROR_DEFINITIONS_H  <fterrdef.h>
=======
#define FT_ERROR_DEFINITIONS_H  <freetype/fterrdef.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


  /* The internals of the cache sub-system are no longer exposed.  We */
  /* default to FT_CACHE_H at the moment just in case, but we know of */
  /* no rogue client that uses them.                                  */
  /*                                                                  */
<<<<<<< HEAD
#define FT_CACHE_MANAGER_H           <ftcache.h>
#define FT_CACHE_INTERNAL_MRU_H      <ftcache.h>
#define FT_CACHE_INTERNAL_MANAGER_H  <ftcache.h>
#define FT_CACHE_INTERNAL_CACHE_H    <ftcache.h>
#define FT_CACHE_INTERNAL_GLYPH_H    <ftcache.h>
#define FT_CACHE_INTERNAL_IMAGE_H    <ftcache.h>
#define FT_CACHE_INTERNAL_SBITS_H    <ftcache.h>


#define FT_INCREMENTAL_H          <ftincrem.h>

#define FT_TRUETYPE_UNPATENTED_H  <ttunpat.h>


  /*
   * Include internal headers definitions from <internal/...>
   * only when building the library.
   */
#ifdef FT2_BUILD_LIBRARY
#define  FT_INTERNAL_INTERNAL_H  <internal/internal.h>
=======
#define FT_CACHE_MANAGER_H           <freetype/ftcache.h>
#define FT_CACHE_INTERNAL_MRU_H      <freetype/ftcache.h>
#define FT_CACHE_INTERNAL_MANAGER_H  <freetype/ftcache.h>
#define FT_CACHE_INTERNAL_CACHE_H    <freetype/ftcache.h>
#define FT_CACHE_INTERNAL_GLYPH_H    <freetype/ftcache.h>
#define FT_CACHE_INTERNAL_IMAGE_H    <freetype/ftcache.h>
#define FT_CACHE_INTERNAL_SBITS_H    <freetype/ftcache.h>


#define FT_INCREMENTAL_H          <freetype/ftincrem.h>

#define FT_TRUETYPE_UNPATENTED_H  <freetype/ttunpat.h>


  /*
   * Include internal headers definitions from <freetype/internal/...>
   * only when building the library.
   */
#ifdef FT2_BUILD_LIBRARY
#define  FT_INTERNAL_INTERNAL_H  <freetype/internal/internal.h>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include FT_INTERNAL_INTERNAL_H
#endif /* FT2_BUILD_LIBRARY */


#endif /* __FT2_BUILD_H__ */


/* END */
