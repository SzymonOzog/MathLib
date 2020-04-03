#include "Vector.h"
template <class T>
Vector<T>::Vector(std::vector<T> coords)
{
	_coords = coords;
}
template <class T>
Vector<T> Vector<T>::normalise()
{
	T length = length();
	std::vector<T> vec;
	for (auto c : _coords)
		vec.push_back(c/length);
	return Vector<T>(vec);
}
template <class T>
T Vector<T>::length()
{
	T sqSum;
	for (auto c : _coords)
		sqSum += c * c;
	return sqrt(sqSum);
}
template <class T>
Vector<T> operator + (Vector<T> otherVec)
{
	std::vector<T> vec;
	if (this.size() != otherVec.size())
		MathLib::toFill(MathLib::getSmaller(*this, otherVec), abs(this->size() - otherVec, size());
	for(int i = )
}
template <class T>
Vector<T> operator - (Vector<T> otherVec);
template <class T>
Vector<T> operator * (T scalar);
template <class T>
Vector<T> operator / (T scalar);
template <class T>
Vector<T> operator += (Vector<T> otherVec);
template <class T>
Vector<T> operator -= (Vector<T> otherVec);
template <class T>
Vector<T> operator *= (T scalar);
template <class T>
Vector<T> operator /= (T scalar);