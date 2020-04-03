#pragma once
#include <vector>
#include "MathLib.h"
template <class T>
class Vector
{
public:
	Vector(std::vector<T> coords);
	T length();
	Vector normalise();
	Vector<T> operator + (Vector& otherVec);
	Vector<T> operator - (Vector& otherVec);
	Vector<T> operator * (T& scalar);
	Vector<T> operator / (T& scalar);
	Vector<T> operator += (Vector& otherVec);
	Vector<T> operator -= (Vector& otherVec);
	Vector<T> operator *= (T& scalar);
	Vector<T> operator /= (T& scalar);

private:
	std::vector<T> _coords;
};

