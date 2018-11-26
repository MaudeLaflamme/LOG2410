///////////////////////////////////////////////////////////
//  VisitorPrimitiveSelector.cpp
//  Implementation of the Class VisitorPrimitiveSelector
//  Created on:      07-nov.-2018 21:20:38
//  Original author: p482457
///////////////////////////////////////////////////////////

#include <exception>

#include "VisitorPrimitiveSelector.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Object3DComposite.h"
#include "TransformedObject3D.h"

VisitorPrimitiveSelector::VisitorPrimitiveSelector(PRIMITIVE_TYPE typ)
	: m_type(typ)
{
}

VisitorPrimitiveSelector::~VisitorPrimitiveSelector()
{
}

void VisitorPrimitiveSelector::visitCube(class Cube& cub)
{
	// A COMPLETER:
	// Verifier que la pile d'objets courants n'est pas vide
	// Verifier que le type de la primitive est bien celui recherchee
	// Si oui, ajouter la primitive dans les objets selectionnes

	if (!m_currentObjStack.empty())
		if (typeid(*(*(m_currentObjStack.begin()))) == typeid(m_type)){		//Il faudrait que l'élément de gauche soit le type du visiteur.
			m_selectObjContainer.push_back(*(m_currentObjStack.begin()));
		}
}

void VisitorPrimitiveSelector::visitCylinder(class Cylinder& cyl)
{
	// A COMPLETER:
	if (!m_currentObjStack.empty())
		if (typeid(*(*(m_currentObjStack.begin()))) == typeid(Cylinder)) {
			m_selectObjContainer.push_back(*(m_currentObjStack.begin()));
		}
	// Verifier que la pile d'objets courants n'est pas vide
	// Verifier que le type de la primitive est bien celui recherchee
	// Si oui, ajouter la primitive dans les objets selectionnes
}

void VisitorPrimitiveSelector::visitObjComposite(const Object3DComposite& comp)
{
	throw(std::invalid_argument("VisitorPrimitiveSelector cannot process const Objects"));
}

void VisitorPrimitiveSelector::visitObjComposite(class Object3DComposite& comp)
{
	// A COMPLETER:
	// Iterer sur les enfants du composite
	for (auto it = comp.begin(); it != comp.end(); it++) {
		m_currentObjStack.push_back(it);
		if ()
			this->visitCube(*(it));
	}
	//		- Stocker l'enfant sur la pile des objets courants
	//		- Traiter l'enfant
	//		- Retirer l'enfant de sur la pile
}

void VisitorPrimitiveSelector::visitPrimitive(const class PrimitiveAbs& prim)
{
	throw(std::invalid_argument("VisitorPrimitiveSelector cannot process const Objects"));
}

void VisitorPrimitiveSelector::visitPrimitive(class PrimitiveAbs& prim)
{
	// Type de primitive inconnue... cette primitive n'est pas selectionnee
}

void VisitorPrimitiveSelector::visitSphere(class Sphere& sph)
{
	// A COMPLETER:
	// Verifier que la pile d'objets courants n'est pas vide
	// Verifier que le type de la primitive est bien celui recherchee
	// Si oui, ajouter la primitive dans les objets selectionnes
	if (!m_currentObjStack.empty())
		if (typeid(*(*(m_currentObjStack.begin()))) == typeid(Sphere)) {
			m_selectObjContainer.push_back(*(m_currentObjStack.begin()));
		}
	
}

void VisitorPrimitiveSelector::visitTransformedObj(class TransformedObject3D& tobj)
{
	// A COMPLETER:
	// Deleguer le traitement a la primitive contenue dans le decorateur 
}

void VisitorPrimitiveSelector::getSelectObjects(Obj3DIteratorContainer & objContainer)
{
	// A COMPLETER:
	// Transferer les objets selectionnes du conteneur local au visiteur
	// vers le conteneur fourni en argument
}
