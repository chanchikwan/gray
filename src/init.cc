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

#include "geode.h"

void Data::init(State (*ic)(int))
{
  if(ic)
    for(size_t i = 0; i < n; ++i)
      buf[i] = ic(i);
  else {
    real *h = (real *)buf;
    for(size_t i = 0; i < NVAR * n; ++i)
      h[i] = 0;
  }

  if(cudaSuccess != h2d())
    error("Data::init(): fail to copy host data to device\n");
}