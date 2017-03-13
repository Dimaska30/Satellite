#include<CelestialBody.h>
//#include<Satellite.h>
#include<iostream>
#include <stdio.h>

int main() {
	CelestialBody body1= CelestialBody(new math::Vector(0,0),new math::Vector(0, 10),(double)10,new math::Vector(0, 0));
	CelestialBody body2= CelestialBody(new math::Vector(100, 100), new math::Vector(-15,-5), (double)20, new math::Vector(0, 0));
	double time;
	std::cin >> time;
	double deltatime;
	std::cin >> deltatime;
	int n = (int)(time / deltatime);
	for (int i = 0; i < n; i++) {
		body1.update(deltatime, &body2);
		body2.update(deltatime, &body1);
		std::cout << "---- " << deltatime*i << " from " << time << " ----" << std::endl;
		std::cout << "body 1: " << std::endl;
		std::cout << "Mass: " << body1.getMass() << std::endl;
		std::cout << "Position: " << " X: " << body1.getPosition()->getX() << " Y: " << body1.getPosition()->getY() << std::endl;
		std::cout<<"Speed: " << " X: " << body1.getSpeed()->getX() << " Y: " << body1.getSpeed()->getY() << std::endl;
		std::cout<<"Acceleration: "<< " X: " << body1.getAcceleration()->getX() << " Y: " << body1.getAcceleration()->getY() << std::endl;
		std::cout << "---" << std::endl;
		std::cout << "body 2: " << std::endl;
		std::cout << "Mass: " << body2.getMass() << std::endl;
		std::cout << "Position: " << " X: " << body2.getPosition()->getX() << " Y: " << body2.getPosition()->getY() << std::endl;
		std::cout << "Speed: " << " X: " << body2.getSpeed()->getX() << " Y: " << body2.getSpeed()->getY() << std::endl;
		std::cout << "Acceleration: " << " X: " << body2.getAcceleration()->getX() << " Y: " << body2.getAcceleration()->getY() << std::endl;
	}

	system("pause");
	return 0;
}