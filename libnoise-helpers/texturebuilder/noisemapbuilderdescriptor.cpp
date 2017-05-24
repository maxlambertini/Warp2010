/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA#
############################################################################
*/

#include "noisemapbuilderdescriptor.h"

using namespace std;
using namespace noise;

NoiseMapBuilderDescriptor::NoiseMapBuilderDescriptor(QObject *parent) : QObject(parent)
{

}

//from descriptor to actual object
QSharedPointer<utils::NoiseMapBuilder> NoiseMapBuilderDescriptor::makeBuilder() {
    QSharedPointer<utils::NoiseMapBuilder> res;
    switch (_builderType) {
        case NoiseMapBuilderType::CYLINDER:
            res =  makeCylinderBuilder();
        break;
    case NoiseMapBuilderType::PLANE:
        res = makePlaneBuilder();
    break;
    case NoiseMapBuilderType::SPHERE:
        res = makeSphereBuilder();
    break;
    default:
        res = makeSphereBuilder();
    break;
    }
    _currentNoiseMapBuilder = res;
    return res;
}

QSharedPointer<utils::NoiseMapBuilder> NoiseMapBuilderDescriptor::makeCylinderBuilder() {
    utils::NoiseMapBuilderCylinder *p = new utils::NoiseMapBuilderCylinder();
    p->SetBounds( std::get<0>(_bounds)
                 ,std::get<1>(_bounds)
                 ,std::get<2>(_bounds)
                 ,std::get<3>(_bounds));
    p->SetDestSize(std::get<0>(_size), std::get<1>(_size));
    p->SetSourceModule( *this->_modules[this->_src1].data());
    p->SetDestNoiseMap( * this->_noiseMaps[this->_dest].data());
    //p->EnableSeamless(_seamless);
    QSharedPointer<utils::NoiseMapBuilder> sp; sp.reset(p);
    return sp;
}

QSharedPointer<utils::NoiseMapBuilder> NoiseMapBuilderDescriptor::makePlaneBuilder() {
    utils::NoiseMapBuilderPlane *p = new utils::NoiseMapBuilderPlane();
    p->SetBounds( std::get<0>(_bounds)
                 ,std::get<1>(_bounds)
                 ,std::get<2>(_bounds)
                 ,std::get<3>(_bounds));
    p->SetDestSize(std::get<0>(_size), std::get<1>(_size));
    p->SetSourceModule( *this->_modules[this->_src1].data());
    p->SetDestNoiseMap( * this->_noiseMaps[this->_dest].data());
    p->EnableSeamless(_seamless);

    QSharedPointer<utils::NoiseMapBuilder> sp; sp.reset(p);
    return sp;

}

QSharedPointer<utils::NoiseMapBuilder> NoiseMapBuilderDescriptor::makeSphereBuilder() {
    utils::NoiseMapBuilderSphere *p = new utils::NoiseMapBuilderSphere();
    p->SetBounds( std::get<0>(_bounds)
                 ,std::get<1>(_bounds)
                 ,std::get<2>(_bounds)
                 ,std::get<3>(_bounds));
    p->SetDestSize(std::get<0>(_size), std::get<1>(_size));
    p->SetSourceModule( *this->_modules[this->_src1].data());
    p->SetDestNoiseMap( * this->_noiseMaps[this->_dest].data());
    //p->EnableSeamless(_seamless);
    QSharedPointer<utils::NoiseMapBuilder> sp; sp.reset(p);
    return sp;

}
