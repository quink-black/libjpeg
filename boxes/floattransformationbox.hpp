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
** This box keeps a linear transformation that can be used either as L
** or C transformation. Unlike the lineartransformation box, the entries
** of the matrix defined here are 32-bit FLOATs.
**
** $Id: floattransformationbox.hpp,v 1.5 2014/09/30 08:33:15 thor Exp $
**
*/

#ifndef BOXES_FLOATTRANSFORMATIONBOX_HPP
#define BOXES_FLOATTRANSFORMATIONBOX_HPP

#include <assert.h>
#include "std/string.hpp"
#include "boxes/box.hpp"
#include "boxes/matrixbox.hpp"
///

/// class FloatTransformationBox
// This box keeps a linear transformation that can be used either as L
// or C transformation.
class FloatTransformationBox : public MatrixBox {
  //
  // The linear transformation coefficients as floating point.
  FLOAT m_fMatrix[9];
  //
  // The inverse matrix if it exists.
  FLOAT m_fInverse[9];
  //
  // Compute the inverse matrix and put it into m_lInverse. If it does not
  // exist, throw.
  void InvertMatrix(void);
  //
  // Second level parsing stage: This is called from the first level
  // parser as soon as the data is complete. Must be implemented
  // by the concrete box.
  virtual bool ParseBoxContent(class ByteStream *stream,UQUAD boxsize);
  //
  // Second level creation stage: Write the box content into a temporary stream
  // from which the application markers can be created.
  virtual bool CreateBoxContent(class MemoryStream *target);
  //
public:
  enum {
    Type = MAKE_ID('F','T','R','X')
  };
  //
  // The constructor.
  FloatTransformationBox(class Environ *env,class Box *&boxlist)
    : MatrixBox(env,boxlist,Type)
  { }
  //
  // Define a matrix from an ID and a coefficient list.
  void DefineMatrix(UBYTE id,const FLOAT *matrix)
  {
    m_ucID = id;
    memcpy(m_fMatrix,matrix,sizeof(m_fMatrix));
  }
  //
  virtual ~FloatTransformationBox(void)
  { }
  //
  // Return the matrix transformation of this box. The result is a pointer
  // to nine floating point constants.
  const FLOAT *MatrixOf(void) const
  {
    return m_fMatrix;
  }
  //
  // Return the inverse of the matrix. Throws if it does not exist.
  const FLOAT *InverseMatrixOf(void)
  {
    if (!m_bInverseValid)
      InvertMatrix();

    assert(m_bInverseValid);
    
    return m_fInverse;
  }
};
///


///
#endif
