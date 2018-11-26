///////////////////////////////////////////////////////////
//  PrimitiveAbs.cpp
//  Implementation of the Class PrimitiveAbs
//  Created on:      25-oct.-2018 20:47:13
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "PrimitiveAbs.h"

// Declaration d'un conteneur vide pour retourner des iterateurs toujours valides
Objet3DContainer PrimitiveAbs::m_emptyContainer;

PrimitiveAbs::PrimitiveAbs(){

}

PrimitiveAbs::PrimitiveAbs(const Point3D& c)
	// A Completer...
{
	this->m_center = c;
}

PrimitiveAbs::~PrimitiveAbs(){

}

void PrimitiveAbs::addChild(const Objet3DAbs& obj3d){
	// Echoue silencieusement
}

Objet3DIterator PrimitiveAbs::begin(){

	// A Completer...
	Objet3DIterator it = this->m_emptyContainer.begin();
	return it;
}

Objet3DIterator_const PrimitiveAbs::cbegin() const {

	// A Completer...
	Objet3DIterator_const it_const = this->m_emptyContainer.begin();
	return it_const;
}

Objet3DIterator_const PrimitiveAbs::cend() const {

	// A Completer...
	Objet3DIterator_const it_const = this->m_emptyContainer.end();
	return it_const;
}

Objet3DIterator PrimitiveAbs::end(){

	// A Completer...
	return Objet3DBaseIterator();
}

void PrimitiveAbs::removeChild(Objet3DIterator_const obj3dIt){
	// Echoue silencieusement
}

Point3D PrimitiveAbs::getCenter() const {

	// A Completer...

	return  this->m_center;
}

void PrimitiveAbs::moveCenter(const Point3D & delta)
{
	this->m_center.x() += delta.x();
	this->m_center.y() += delta.y();
	this->m_center.z() += delta.z();

	// A Completer...
}

void PrimitiveAbs::setCenter(const Point3D& center)
{
	this->m_center.x() = center.x();
	this->m_center.y() = center.y();
	this->m_center.z() = center.z();
	// A Completer...
}

std::ostream & operator<<(std::ostream & o, const Objet3DAbs& obj3d )
{
	return obj3d.toStream(o);
}