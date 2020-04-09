#pragma once
#include <vector>
#include <cmath>
#include <algorithm>
#include "MathLib.h"
namespace MathLib 
{
	template <class T>
	class Vector 
	{
	public:
		using iterator = typename std::vector<T>::iterator;
		using const_iterator = typename std::vector<T>::const_iterator;

		Vector(std::vector<T> coords) : _coords(coords) {}
		T length();
		Vector normalise();

		int size() const { return _coords.size(); }
		void push_back(T x) { _coords.push_back(x); }
		iterator begin() { return _coords.begin(); }
		iterator end() { return _coords.end(); }
		const_iterator begin() const { return _coords.begin(); }
		const_iterator end() const { return _coords.end(); }

		T& operator [](size_t i) { return _coords[i]; }
		const T& operator [](size_t i) const { return _coords[i]; }
		bool operator == (const Vector<T>& rhs)
		{
			if (this->size() != rhs.size())
				return false;
			for (int i = 0; i < rhs.size(); i++)
				if ((*this)[i] != rhs[i])
					return false;
			return true;
		}
		bool operator != (const Vector<T>& rhs) { return !((*this) == rhs); }
		Vector<T> operator + (const Vector& rhs) { Vector<T> vec = *this; return vec += rhs;}
		Vector<T> operator - (const Vector& rhs) { Vector<T> vec = *this; return vec -= rhs; }
		Vector<T> operator * (const T& scalar) { Vector<T> vec = *this; return vec *= scalar; }
		Vector<T> operator / (const T& scalar) { Vector<T> vec = *this; return vec /= scalar; }
		Vector<T> operator += (const Vector& rhs)
		{
			if (this->size() < rhs.size())
				MathLib::fillVector((*this), rhs.size());
			std::transform(rhs.begin(), rhs.end(), this->begin(), this->begin(), [](T x, T y) {return x + y;});
			return *this;
		}
		Vector<T> operator -= (const Vector& rhs)
		{
			if (this->size() < rhs.size())
				MathLib::fillVector((*this), rhs.size());
			std::transform(rhs.begin(), rhs.end(), this->begin(), this->begin(), [](T x, T y) {return y - x;});
			return *this;
		}
		Vector<T> operator *= (const T& scalar) { std::transform(this->begin(), this->end(), this->begin(), [scalar](T x) {return x * scalar;}); return *this; }
		Vector<T> operator /= (const T& scalar) { std::transform(this->begin(), this->end(), this->begin(), [scalar](T x) {return x / scalar;}); return *this; }

	private:
		std::vector<T> _coords;
	};

	//IMPLEMENTATIONS ------------------------------------------------------

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
}
