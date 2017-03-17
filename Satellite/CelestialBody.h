#pragma once
#include<Vector.h>

const double G = 6.6740831*pow(10,-11);

class  CelestialBody {
public:

	CelestialBody(math::Vector* position,
				  math::Vector* speed,
				  double mass,
				  math::Vector* acceleration) {
		this->position = position;
		this->speed = speed;
		this->mass = &mass;
		this->acceleration = acceleration;
	}

	~CelestialBody(){
		position = nullptr;
		speed = nullptr;
		mass = nullptr;
		acceleration = nullptr;
	}

	void update(double deltaTime,CelestialBody* body) {
		culculateAcceleration(body);
		culculateSpeed(deltaTime);
		culculatePosition(deltaTime);
	}

	void culculateAcceleration(CelestialBody* body) {
		acceleration->~Vector();
		double temp = (pow((pow(body->getPosition()->getX() - position->getX(), 2) + pow(body->getPosition()->getY() - position->getY(), 2)), 2 / 3));

		math::Vector* tempForce =new math::Vector((G*(body->getPosition()->getX() - position->getX())*body->getMass()) / temp,
											(G*(body->getPosition()->getY() - position->getY())*body->getMass()) / temp);
		acceleration = (tempForce);
	}

	void culculateSpeed(double deltaTime) {
		speed = &((*speed)+math::Vector(acceleration->getX()*deltaTime, acceleration->getY()*deltaTime));
	}

	void culculatePosition(double deltaTime) {
		position = &((*position) + math::Vector(speed->getX()*deltaTime, speed->getY()*deltaTime));
	}
	
	math::Vector* getPosition() {
		return this->position;
	}

	double getMass() {
		return *(this->mass);
	}

	math::Vector* getSpeed() {
		return this->speed;
	}

	math::Vector* getAcceleration() {
		return this->acceleration;
	}

private:

	math::Vector* position;
	math::Vector* speed;
	double* mass;
	math::Vector* acceleration;

};