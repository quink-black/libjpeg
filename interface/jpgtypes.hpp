/*************************************************************************

    This project implements a complete(!) JPEG (10918-1 ITU.T-81) codec,
    plus a library that can be used to encode and decode JPEG streams. 
    It also implements ISO/IEC 18477 aka JPEG XT which is an extension
    towards intermediate, high-dynamic-range lossy and lossless coding
    of JPEG. In specific, it supports ISO/IEC 18477-3/-6/-7/-8 encoding.

    Copyright (C) 2012-2018 Thomas Richter, University of Stuttgart and
    Accusoft.

    This program is available under two licenses, GPLv3 and the ITU
    Software licence Annex A Option 2, RAND conditions.

    For the full text of the GPU license option, see README.license.gpl.
    For the full text of the ITU license option, see README.license.itu.
    
    You may freely select beween these two options.

    For the GPL option, please note the following:

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************/
/*
 * System independent type definitions.
 * $Id: jpgtypes.hpp,v 1.9 2014/09/30 08:33:17 thor Exp $
 *
 * The following header defines basic types to be used in the JPG interface
 * routines.
 *
 * These are external definitions, visible to the outher world and part of
 * the jpeg interface.
 */


#ifndef JPGTYPES_HPP
#define JPGTYPES_HPP

#include <stdint.h>

typedef int32_t           JPG_LONG;
typedef uint32_t          JPG_ULONG;

// Floating point types, available by ANSI.
// Precision doesn't matter too much
typedef float             JPG_FLOAT;
///

/// Convenience boolean types
#define JPG_TRUE  (1)
#define JPG_FALSE (0)
///

/// Limits
/* Limits of the types defined above. It is rather important that
 * the specific implementation meets these limits.
 */

// Define the following only if not yet defined:
#define JPG_MIN_LONG ((JPG_LONG)(-0x80000000L))
#define JPG_MAX_LONG ((JPG_LONG)(0x7fffffffL))

#define JPG_MIN_ULONG ((JPG_ULONG)(0x00000000UL))
#define JPG_MAX_ULONG ((JPG_ULONG)(0xffffffffUL))
///

/// Pointers
// The next one defines a "generic" pointer ("A PoiNTeR").
#ifndef JPG_NOVOIDPTR
typedef void *JPG_APTR;
typedef const void *JPG_CPTR;
#else
#define JPG_APTR void *
#define JPG_CPTR const void *
#endif
///

///
#endif

