/******************************************************************************\

    OpenSCAM is an Open-Source CAM software.
    Copyright (C) 2011-2014 Joseph Coffland <joseph@cauldrondevelopment.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#ifndef OPENSCAM_DXFPOLY_LINE_H
#define OPENSCAM_DXFPOLY_LINE_H

#include "DXFEntity.h"

#include <vector>


namespace OpenSCAM {
  class DXFPolyLine : public DXFEntity {
    std::vector<cb::Vector3D> vertices;

  public:
    DXFPolyLine() {}

    const std::vector<cb::Vector3D> &getVertices() const {return vertices;}

    // From DXFEntity
    void addVertex(const cb::Vector3D &v) {vertices.push_back(v);}
    type_t getType() const {return DXF_POLYLINE;}
  };
}

#endif // OPENSCAM_DXFPOLY_LINE_H

