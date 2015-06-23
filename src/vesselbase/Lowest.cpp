/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Copyright (c) 2012-2014 The plumed team
   (see the PEOPLE file at the root of the distribution for a list of names)

   See http://www.plumed-code.org for more information.

   This file is part of plumed, version 2.

   plumed is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   plumed is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with plumed.  If not, see <http://www.gnu.org/licenses/>.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#include "OrderingVessel.h"
#include "VesselRegister.h"

namespace PLMD {
namespace vesselbase{

class Lowest : public OrderingVessel {
public:
  static void registerKeywords( Keywords& keys );
  static void reserveKeyword( Keywords& keys );
  Lowest( const VesselOptions& da );
  std::string value_descriptor();
  bool compare( const double& , const double& );
};

PLUMED_REGISTER_VESSEL(Lowest,"LOWEST")

void Lowest::registerKeywords( Keywords& keys ){
  OrderingVessel::registerKeywords( keys );
}

void Lowest::reserveKeyword( Keywords& keys ){
  keys.reserveFlag("LOWEST",false,"calculate the lowest of these variables.",true);
  keys.addOutputComponent("lowest","LOWEST","the lowest of the quantitities calculated by this action");
}

Lowest::Lowest( const VesselOptions& da ) :
OrderingVessel(da)
{
}

std::string Lowest::value_descriptor(){
  return "the lowest of the individual colvar values";
}

bool Lowest::compare( const double& val1, const double& val2 ){
  return val1<val2;
}

}
}