#pragma once
#include <math.h>

namespace math {
	class Vector {
	public:

		Vector(double x, double y) {
			this->x = x;
			this->y = y;
		}

		~Vector() {

		}

		double getLength() {
			return sqrt(x*x+y*y);
		}

		Vector operator +(Vector vector) {
			return Vector(vector.getX()+this->x, vector.getX() + this->x);
		}

		Vector operator *(double a) {
			return Vector(this->x*a, this->y*a);
		}



		double getX() {
			return x;
		}

		double getY() {
			return y;
		}

		void setX(double x) {
			this->x = x;
		}

		void setY(double y) {
			this->y = y;
		}

	private:
		double x, y;
	};
}