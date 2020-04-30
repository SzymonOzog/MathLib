#pragma once
#include <vector>
#include <cmath>
#include <algorithm>
#include "MathLib.h"
namespace MathLib 
{
	template <class T>
	class DynamicVector 
	{
	public:
		DynamicVector(std::vector<T> coords) : _coords(coords) {}
		T length();
		DynamicVector <double> normalise();

		size_t size() const { return _coords.size(); }
		void push_back(T x) { _coords.push_back(x); }
		auto begin() { return _coords.begin(); }
		auto end() { return _coords.end(); }
		auto begin() const { return _coords.begin(); }
		auto end() const { return _coords.end(); }

		T& operator [](size_t i) { return _coords[i]; }
		const T& operator [](size_t i) const { return _coords[i]; }
		bool operator == (const DynamicVector<T>& rhs)
		{
			if (this->size() != rhs.size())
				return false;
			for (int i = 0; i < rhs.size(); i++)
				if ((*this)[i] != rhs[i])
					return false;
			return true;
		}
		bool operator != (const DynamicVector<T>& rhs) { return !((*this) == rhs); }
		DynamicVector<T> operator + (const DynamicVector& rhs) { DynamicVector<T> vec = *this; return vec += rhs;}
		DynamicVector<T> operator - (const DynamicVector& rhs) { DynamicVector<T> vec = *this; return vec -= rhs; }
		DynamicVector<T> operator * (const T& scalar) { DynamicVector<T> vec = *this; return vec *= scalar; }
		DynamicVector<T> operator / (const T& scalar) { DynamicVector<T> vec = *this; return vec /= scalar; }
		DynamicVector<T> operator += (const DynamicVector& rhs)
		{
			if (this->size() < rhs.size())
				MathLib::fillDynamicVector((*this), rhs.size());
			std::transform(rhs.begin(), rhs.end(), this->begin(), this->begin(), [](T x, T y) {return x + y;});
			return *this;
		}
		DynamicVector<T> operator -= (const DynamicVector& rhs)
		{
			if (this->size() < rhs.size())
				MathLib::fillDynamicVector((*this), rhs.size());
			std::transform(rhs.begin(), rhs.end(), this->begin(), this->begin(), [](T x, T y) {return y - x;});
			return *this;
		}
		DynamicVector<T> operator *= (const T& scalar) { std::transform(this->begin(), this->end(), this->begin(), [scalar](T x) {return x * scalar;}); return *this; }
		DynamicVector<T> operator /= (const T& scalar) { std::transform(this->begin(), this->end(), this->begin(), [scalar](T x) {return x / scalar;}); return *this; }

	private:
		std::vector<T> _coords;
	};

	//IMPLEMENTATIONS ------------------------------------------------------

	template <class T>
	DynamicVector<double> DynamicVector<T>::normalise()
	{
		T length = this->length();
		std::vector<double> vec;
		for (auto c : _coords)
			vec.push_back((double)c / length);
		return DynamicVector<double>(vec);
	}
	template <class T>
	T DynamicVector<T>::length()
	{
		T sqSum = 0;
		for (auto c : _coords)
			sqSum += c * c;
		return sqrt(sqSum);
	}
}
