#include "pmFunc.h"
#include <math.h>

const float PI = 3.14159;

namespace pmFunc {
	float xVel(float vel, float angle){
		float radians = angle * PI / 180;
		return vel * cos(radians);
	}

	float yVel(float vel, float angle){
		float radians = angle * PI / 180;
		return vel * sin(radians);
	}

	float quadraticEquation(float a, float b, float c, bool sign) {
		switch(sign) {
			case 0:
				return (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
			case 1:
				return (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		}
	}

	float calculateAirTime(float initialHeight, float finalHeight, float initialYVelocity, float acceleration){
		float A = 0.5 * acceleration;
		float B = initialYVelocity;
		float C = initialHeight - finalHeight;
		float time = quadraticEquation(A, B, C, 1);

		return time;
	}
}
