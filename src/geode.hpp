// Copyright (C) 2012 Chi-kwan Chan
// Copyright (C) 2012 Steward Observatory
//
// This file is part of geode.
//
// Geode is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Geode is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
// License for more details.
//
// You should have received a copy of the GNU General Public License
// along with geode.  If not, see <http://www.gnu.org/licenses/>.

#ifndef GEODE_HPP
#define GEODE_HPP

#ifdef ISABLE_GL
#  define DISABLE_GL
#endif

#ifndef DISABLE_GL
#  ifdef __APPLE__
#    include <GLUT/glut.h>
#  else
#    include <GL/glut.h>
#  endif
#endif

#ifdef OUBLE
#  define DOUBLE
#endif

#ifdef DOUBLE
  typedef double Real;
#else
  typedef float Real;
#endif

#include <iostream>
#include <cuda_runtime_api.h> // C-style CUDA runtime API
#include <state.hpp>          // problem specific state structure

namespace global {
  extern cudaEvent_t c0, c1;
  extern size_t n;
  extern State *s;
}

void evolve(void);
int  setup (int &, char **);
int  solve (void);
void vis   (void);

#endif // GEODE_HPP
