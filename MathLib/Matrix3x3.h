#pragma once
#include <algorithm>
#include "Static3Vector.h"
namespace MathLib 
{
	template <class T>
	class Matrix3x3
	{
	public:
	//constructors---------------------------------------------------------------------------------------------------------------------------------------------------------
		Matrix3x3() : m_rows{ Static3Vector<T>(), Static3Vector<T>(), Static3Vector<T>() } {}
		Matrix3x3(Static3Vector<T> v1, Static3Vector<T> v2, Static3Vector<T> v3) : m_rows{ v1, v2, v3 } {}
		Matrix3x3(T scalar) : m_rows{ Static3Vector(scalar, 0, 0), Static3Vector(0, scalar, 0), Static3Vector(0, 0, scalar) } {} //creates a scaled identity matrix
		~Matrix3x3() = default;

	//functions------------------------------------------------------------------------------------------------------------------------------------------------------------
		size_t size() { return sizeof(m_rows) / sizeof(m_rows[0]); }
		size_t size() const { return sizeof(m_rows) / sizeof(m_rows[0]); }
		T determinant();
		void transpose();

	//operators------------------------------------------------------------------------------------------------------------------------------------------------------------
		bool operator == (const Matrix3x3& rhs) {
			for (int i = 0; i < this->size(); i++) 
				if ((*this)[i] != rhs[i]) 
					return false; 
			return true;
		}
		bool			  operator != (const Matrix3x3& rhs) { return !(*this == rhs); }
		Static3Vector<T>& operator [] (size_t i)			 { return m_rows[i]; }
		Matrix3x3&		  operator += (const Matrix3x3& rhs) { for (int i = 0; i < this->size(); i++) (*this)[i] += rhs[i]; return *this; }
		Matrix3x3&		  operator -= (const Matrix3x3& rhs) { for (int i = 0; i < this->size(); i++) (*this)[i] -= rhs[i]; return *this; }
		Matrix3x3&		  operator *= (const T& rhs) 		 { for (int i = 0; i < this->size(); i++) (*this)[i] *= rhs;	return *this; }
		Matrix3x3&		  operator /= (const T& rhs)		 { for (int i = 0; i < this->size(); i++) (*this)[i] /= rhs; return *this; }
		Matrix3x3		  operator -  (const Matrix3x3& rhs) { Matrix3x3 m(*this); m -= rhs; return m; }
		Matrix3x3		  operator *  (const T& rhs)		 { Matrix3x3 m(*this); m *= rhs; return m; }
		Matrix3x3		  operator *  (const Matrix3x3& rhs) { Matrix3x3 m((*this)[0] * rhs, (*this)[1] * rhs, (*this)[2] * rhs); return m; }
		Matrix3x3		  operator +  (const Matrix3x3& rhs) { Matrix3x3 m(*this); m += rhs; return m; }
		Matrix3x3		  operator /  (const T& rhs)		 { Matrix3x3 m(*this); m /= rhs; return m; }

	//const operators------------------------------------------------------------------------------------------------------------------------------------------------------
		const bool operator == (const Matrix3x3& rhs) const {
			for (int i = 0; i < this->size(); i++)
				if ((*this)[i] != rhs[i])
					return false;
			return true;
		}
		const bool				operator != (const Matrix3x3& rhs) const { return !(*this == rhs); }
		const Static3Vector<T>& operator [] (size_t i)             const { return m_rows[i]; }
		const Matrix3x3         operator +  (const Matrix3x3& rhs) const { Matrix3x3 m(*this); m += rhs; return m; }
		const Matrix3x3         operator -  (const Matrix3x3& rhs) const { Matrix3x3 m(*this); m -= rhs; return m; }
		const Matrix3x3         operator *  (const T& rhs)         const { Matrix3x3 m(*this); m *= rhs; return m; }
		const Matrix3x3			operator *  (const Matrix3x3& rhs) const { Matrix3x3 m((*this)[0] * rhs, (*this)[1] * rhs, (*this)[2] * rhs); return m; }
		const Matrix3x3         operator /  (const T& rhs)         const { Matrix3x3 m(*this); m /= rhs; return m; }
	private:							    
		Static3Vector<T> m_rows[3];
	};

	// Function implemantations--------------------------------------------------------------------------------------------------------------------------------------------
	template <class T>
	T Matrix3x3<T>::determinant()
	{
		T det = 0;
		for (int i = 0; i < this->size(); i++)
		{
			det += (*this)[i % 3][0] * (*this)[(i + 1) % 3][1] * (*this)[(i + 2) % 3][2];
			det -= (*this)[i % 3][2] * (*this)[(i + 1) % 3][1] * (*this)[(i + 2) % 3][0];
		}
		return det;
	}
	template <class T>
	void Matrix3x3<T>::transpose()
	{
		std::swap((*this)[1][0], (*this)[0][1]);
		std::swap((*this)[2][0], (*this)[0][2]);
		std::swap((*this)[2][1], (*this)[1][2]);
	}
	// Vector matrix multiplication----------------------------------------------------------------------------------------------------------------------------------------
	template <class T>
	Static3Vector<T>  operator * (const Static3Vector<T>& lhs, const Matrix3x3<T>& rhs)
	{
		Static3Vector<T> v;
		for (size_t i = 0; i < rhs.size(); i++)
			for (size_t j = 0; j < rhs.size(); j++)
				v[i] += lhs[j] * rhs[j][i];
		return v;
	}
}