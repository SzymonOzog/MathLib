#pragma once

namespace MathLib {
	template <class T>
	struct Static3Vector
	{
		T x, y, z;
		Static3Vector() : x(0), y(0), z(0) {}
		Static3Vector(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
		Static3Vector(const Static3Vector& v) : x(v.x), y(v.y), z(v.z) {}
		Static3Vector<double> normalise();
		T length()												{ return sqrt(x * x + y * y + z * z); };
		bool operator == (const Static3Vector& rhs)				{ return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z); }
		bool operator != (const Static3Vector& rhs)				{ return !(*this == rhs); }
		Static3Vector operator + (const Static3Vector& rhs)		{ Static3Vector v(*this); return v += rhs; }
		Static3Vector operator - (const Static3Vector& rhs)		{ Static3Vector v(*this); return v -= rhs; }
		Static3Vector operator * (const T& rhs)					{ Static3Vector v(*this); return v *= rhs; }
		Static3Vector operator / (const T& rhs)					{ Static3Vector v(*this); return v /= rhs; }
		Static3Vector operator += (const Static3Vector& rhs)	{ this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; return *this; }
		Static3Vector operator -= (const Static3Vector& rhs)	{ this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; return *this; }
		Static3Vector operator *= (const T& rhs)				{ this->x *= rhs; this->y *= rhs; this->z *= rhs; return *this; }
		Static3Vector operator /= (const T& rhs)				{ this->x /= rhs; this->y /= rhs; this->z /= rhs; return *this; }
	};
	template <class T>
	Static3Vector<double> Static3Vector<T>::normalise()
	{
		T l = this->length();
		Static3Vector<double> v;
		v.x = (double)this->x / l;
		v.y = (double)this->y / l;
		v.z = (double)this->z / l;
		return v;
	}
}