#pragma once
#include <Vector.h>
#include <CelestialBody.h>

class Satellite: CelestialBody {
public:

	Satellite(math::Vector* position, math::Vector* speed, double mass, math::Vector* acceleration):
	CelestialBody(position,speed,mass,acceleration)
	{
		
	}

	~Satellite() {
		__super::~CelestialBody();
	}

	

private:
	

};