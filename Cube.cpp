///////////////////////////////////////////////////////////
//  Cube.cpp
//  Implementation of the Class Cube
//  Created on:      25-oct.-2018 20:47:57
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Cube.h"


Cube::Cube(const Point3D& pt, float ln, float lg, float ht)
	: PrimitiveAbs(pt)
{
	if (ln < 0.0 || lg < 0.0 || ht < 0.0)
		throw std::range_error("Invalid dimension value for cube. Must be larger than 0");
	else{
		this->m_dimensions[0] = ln;
		this->m_dimensions[1] = lg;
		this->m_dimensions[2] = ht;
	}
	// A Completer...
}

Cube::~Cube(){
}

Cube * Cube::clone() const
{
	// A Completer...
	Cube* copie = new Cube(this->m_center, this->m_dimensions[0], this->m_dimensions[1], this->m_dimensions[2]);
	return copie;
}

size_t Cube::getNbParameters() const {

	// A Completer...
	return 4;
}

PrimitiveParams Cube::getParameters() const 
{
	// A Completer...

	PrimitiveParams params; 

	params.push_back(this->m_center.x());
	params.push_back(this->m_center.y());
	params.push_back(this->m_center.z());
	params.push_back(this->m_dimensions[0]);
	params.push_back(this->m_dimensions[1]);
	params.push_back(this->m_dimensions[2]);
	return params;
}

void Cube::setParameter(size_t pIndex, float pValue){
	if (pIndex < 0 || pIndex > 2)
		throw std::range_error("Invalid parameter index for cube. Must be between 0 and 2");

	if(pValue<0.0)
		throw std::range_error("Invalid dimension value for cube. Must be larger than 0");

	this->m_dimensions[pIndex] = pValue;
	
	// A Completer...
}

std::ostream & Cube::toStream(std::ostream & o) const
{
	return o << "Cube:      center = " << m_center
		<< "; ln = " << m_dimensions[0]
		<< "; lg = " << m_dimensions[1]
		<< "; ht = " << m_dimensions[2] << ";";
}
