///////////////////////////////////////////////////////////
//  Cylinder.cpp
//  Implementation of the Class Cylinder
//  Created on:      25-oct.-2018 20:47:26
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Cylinder.h"

Cylinder::Cylinder(const Point3D& pt, float r, float ht)
: PrimitiveAbs(pt)
{
	if (r < 0.0 || ht < 0.0)
		throw std::range_error("Invalid parameter value for cylinder. Must be larger than 0");
	else{
		this.m_dimensions[0] = r;
		this.m_dimensions[1] = ht;
	}
	// A Completer...
}

Cylinder::~Cylinder(){
}

Cylinder * Cylinder::clone() const
{
	// A Completer...
	Cylinder* copie = new Cylindre(this.m_center, this.m_dimensions[0], this.m_dimensions[1]);
	return copie;
}

size_t Cylinder::getNbParameters() const {

	// A Completer...
	return 3;
}

PrimitiveParams Cylinder::getParameters() const
{
	// A Completer...
	PrimitiveParams params;
	params.push_back(this.m_center.x);
	params.push_back(this.m_center.y);
	params.push_back(this.m_center.z);
	params.push_back(this.m_dimensions[0]);
	params.push_back(this.m_dimensions[1]);
	return params;
}

void Cylinder::setParameter(size_t pIndex, float pValue){
	if (pIndex < 0 || pIndex > 1)
		throw std::range_error("Invalid parameter index for cylinder. Must be between 0 and 1");

	if (pValue < 0.0)
		throw std::range_error("Invalid parameter value for cylinder. Must be larger than 0");
	else
		this.m_dimensions[pIndex] = pValue;
	// A Completer...
}

std::ostream & Cylinder::toStream(std::ostream & o) const
{
	return o << "Cylinder:  center = " << m_center
		<< "; r = " << m_dimensions[0]
		<< "; ht = " << m_dimensions[1] << ";";
}
