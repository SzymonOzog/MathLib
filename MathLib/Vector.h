#pragma once
#include <vector>
#include <cmath>
#include "MathLib.h"
namespace MathLib 
{
	template <class T>
	class Vector
	{
	public:
		Vector(std::vector<T> coords) : _coords(coords) {}
		T length();
		Vector normalise();
		std::vector<T>& getCoords();
		bool operator == (const Vector& otherVec);
		Vector<T> operator + (const Vector& otherVec);
		Vector<T> operator - (const Vector& otherVec);
		Vector<T> operator * (const T& scalar);
		Vector<T> operator / (const T& scalar);
		Vector<T> operator += (const Vector& otherVec);
		Vector<T> operator -= (const Vector& otherVec);
		Vector<T> operator *= (const T& scalar);
		Vector<T> operator /= (const T& scalar);

	private:
		std::vector<T> _coords;
	};

	//IMPLEMENTATIONS ------------------------------------------------------
	//template <class T>
	//Vector<T>::Vector(std::vector<T> coords)
	//{
	//	_coords = coords;
	//}
	template <class T>
	Vector<T> Vector<T>::normalise()
	{
		T length = length();
		std::vector<T> vec;
		for (auto c : _coords)
			vec.push_back(c / length);
		return Vector<T>(vec);
	}
	template <class T>
	T Vector<T>::length()
	{
		T sqSum = 0;
		for (auto c : _coords)
			sqSum += c * c;
		return sqrt(sqSum);
	}
	template <class T>
	std::vector<T>& Vector<T>::getCoords()
	{
		return _coords;
	}

	//OPERATORS-------------------------------------------------------------
	template <class T>
	bool Vector<T>::operator == (const Vector<T>& otherVec)
	{
		if (this->_coords.size() != otherVec._coords.size())
			return false;
		for (int i = 0; i = otherVec._coords.size(); i++)
			if (this->_coords[i] != otherVec._coords[i])
				return false;
		return true;
	}

	template <class T>
	Vector<T> Vector<T>::operator + (const Vector<T>& otherVec)
	{
		std::vector<T> vec;
		int n = this->_coords.size() - otherVec._coords.size();
		if (this->_coords.size() != otherVec._coords.size())
			MathLib::fillVector(MathLib::getSmaller(this->_coords, otherVec._coords), std::abs(n));
		for (int i = 0; i < otherVec._coords.size(); i++)
			vec.push_back(this->_coords[i] + otherVec._coords[i]);
		return Vector<T>(vec);
	}
	
	//template <class T>
	//Vector<T> operator - (Vector<T> otherVec);
	//template <class T>
	//Vector<T> operator * (T scalar);
	/*template <class T>*/
	//Vector<T> operator / (T scalar);
	//template <class T>
	//Vector<T> operator += (Vector<T> otherVec);
	//template <class T>
	//Vector<T> operator -= (Vector<T> otherVec);
	//template <class T>
	//Vector<T> operator *= (T scalar);
	//template <class T>
	//Vector<T> operator /= (T scalar);
}
