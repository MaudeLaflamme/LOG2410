///////////////////////////////////////////////////////////
//  Cube.cpp
//  Implementation of the Class Cube
//  Created on:      25-oct.-2018 20:47:57
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Torus.h"


Torus::Torus(const Point3D& pt, float smallRad, float bigRad)
	: PrimitiveAbs(pt)
{
	if (smallRad < 0.0 || bigRad < 0.0 )
		throw std::range_error("Invalid dimension value for cube. Must be larger than 0");
	else {
		this->m_radius[0] = smallRad;
		this->m_radius[1] = bigRad;
	}
	// A Completer...
}

Torus::~Torus() {
}

Torus * Torus::clone() const
{
	// A Completer...
	Torus* copie = new Torus(this->m_center, this->m_radius[0], this->m_radius[1]);
	return copie;
}

size_t Torus::getNbParameters() const {

	// A Completer...
	return 3;
}

PrimitiveParams Torus::getParameters() const
{
	// A Completer...
	PrimitiveParams params;
	params.push_back(m_center.x);
	params.push_back(m_center.y);
	params.push_back(m_center.z);
	params.push_back(this->m_radius[0]);
	params.push_back(this->m_radius[1]);
	return params;
}

void Torus::setParameter(size_t pIndex, float pValue) {
	if (pIndex < 0 || pIndex > 2)
		throw std::range_error("Invalid parameter index for cube. Must be between 0 and 2");

	if (pValue<0.0)
		throw std::range_error("Invalid dimension value for cube. Must be larger than 0");
	else {
		this->m_radius[pIndex] = pValue;
	}
	// A Completer...
}

std::ostream & Torus::toStream(std::ostream & o) const
{
	return o << "Torus:      center = " << m_center
		<< "; smallRad = " << m_radius[0]
		<< "; bigRad = " << m_radius[1]
		<<  ";";
}