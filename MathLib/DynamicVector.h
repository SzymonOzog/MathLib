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
		DynamicVector() = default;
		DynamicVector(std::vector<T> coords) : m_coords(coords) {}
		~DynamicVector() = default;

		double length();
		DynamicVector <double> normalise();

		size_t size() const { return m_coords.size(); }
		void push_back(T x) { m_coords.push_back(x); }
		auto begin() { return m_coords.begin(); }
		auto end() { return m_coords.end(); }
		auto rbegin() { return m_coords.rbegin(); }
		auto rend() { return m_coords.rend(); }
		
		auto begin() const { return m_coords.begin(); }
		auto end() const { return m_coords.end(); }
		auto rbegin() const{ return m_coords.rbegin(); }
		auto rend() const{ return m_coords.rend(); }

		T& operator [](size_t i) { return m_coords[i]; }
		bool operator == (const DynamicVector<T>& rhs)
		{
			if (this->size() != rhs.size())
				return false;
			for (size_t i = 0; i < rhs.size(); i++)
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
		
		const T& operator [](size_t i) const { return m_coords[i]; }		
		bool operator == (const DynamicVector<T>& rhs) const
		{
			if (this->size() != rhs.size())
				return false;
			for (size_t i = 0; i < rhs.size(); i++)
				if ((*this)[i] != rhs[i])
					return false;
			return true;
		}
		bool operator != (const DynamicVector<T>& rhs)				 const { return !((*this) == rhs); }
		const DynamicVector<T> operator + (const DynamicVector& rhs) const { DynamicVector<T> vec = *this; return vec += rhs; }
		const DynamicVector<T> operator - (const DynamicVector& rhs) const { DynamicVector<T> vec = *this; return vec -= rhs; }
		const DynamicVector<T> operator * (const T& scalar)		     const { DynamicVector<T> vec = *this; return vec *= scalar; }
		const DynamicVector<T> operator / (const T& scalar)		     const { DynamicVector<T> vec = *this; return vec /= scalar; }

	private:
		std::vector<T> m_coords;
	};

	//IMPLEMENTATIONS ------------------------------------------------------

	template <class T>
	DynamicVector<double> DynamicVector<T>::normalise()
	{
		T length = this->length();
		std::vector<double> vec;
		for (auto c : m_coords)
			vec.push_back((double)c / length);
		return DynamicVector<double>(vec);
	}
	template <class T>
	double DynamicVector<T>::length()
	{
		double sqSum = 0;
		for (auto c : m_coords)
			sqSum += (double)c * (double)c;
		return sqrt(sqSum);
	}
}
