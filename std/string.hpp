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
** This is an Os abstraction of the stdlib
** include file. It might possibly contain fixes for
** various Os derivations from the intended stdlib.
**
** $Id: string.hpp,v 1.7 2014/09/30 08:33:18 thor Exp $
*/

#ifndef STRING_HPP
#define STRING_HPP

#include <string.h>

/// strSize: XML compliant string size computation
// Compute the length of the string in bytes (without the NUL!) for
// XML encoded strings. This can be either a UTF-8 string, or a UTF-16
// string. In the latter case, the string is expected to start with a
// byte-order mark (0xfeff for big and 0xfffe for little endian).
inline static size_t strSize(const unsigned char *data)
{
  if (((data[0] == 0xff) && (data[1] == 0xfe)) ||
      ((data[0] == 0xfe) && (data[1] == 0xff))) {
    const unsigned char *p = data;
    // Repeat until a double 0 is found. Note that we cannot
    // cast to UWORD since the alignment isn't clear.
    do {
      p += 2; // The first one isn't NUL for sure!
    } while(p[0] | p[1]);
    //
    return p - data;
  } else {
    return strlen((const char *)data);
  }
}

#endif
