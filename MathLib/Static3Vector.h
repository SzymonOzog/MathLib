#pragma once

namespace MathLib {
	template <class T>
	class Static3Vector
	{
	public:
		//constructors-------------------------------------------------------------------------------------------------------------------------------------------------------------
		Static3Vector() : m_coords{ 0, 0, 0 } {}
		Static3Vector(T x, T y, T z) : m_coords{ x, y, z } {}
		Static3Vector(const Static3Vector& v) : m_coords{v[0], v[1], v[2]} {}
		~Static3Vector() = default;
		//functions------------------------------------------------------------------------------------------------------------------------------------------------------------
		T length();
		Static3Vector<double> normalise();
		size_t size() { return sizeof(m_coords) / sizeof(m_coords[0]); }

		//operators------------------------------------------------------------------------------------------------------------------------------------------------------------
		T&			   operator [] (const size_t& i)            { return m_coords[i]; }
		bool		   operator == (const Static3Vector& rhs)	{ for (int i = 0; i < this->size(); i++) if ((*this)[i] != rhs[i]) return false; return true; }
		bool		   operator != (const Static3Vector& rhs)	{ return !(*this == rhs); }
		Static3Vector  operator +  (const Static3Vector& rhs)	{ Static3Vector v(*this); return v += rhs; }
		Static3Vector  operator -  (const Static3Vector& rhs)   { Static3Vector v(*this); return v -= rhs; }
		Static3Vector  operator *  (const T& rhs)				{ Static3Vector v(*this); return v *= rhs; }
		Static3Vector  operator /  (const T& rhs)				{ Static3Vector v(*this); return v /= rhs; }
		Static3Vector& operator += (const Static3Vector& rhs)   { for (int i = 0; i < this->size(); i++) (*this)[i] += rhs[i]; return *this; }
		Static3Vector& operator -= (const Static3Vector& rhs)	{ for (int i = 0; i < this->size(); i++) (*this)[i] -= rhs[i]; return *this; }
		Static3Vector& operator *= (const T& rhs)				{ for (int i = 0; i < this->size(); i++) (*this)[i] *= rhs; return *this; }
		Static3Vector& operator /= (const T& rhs)				{ for (int i = 0; i < this->size(); i++) (*this)[i] /= rhs; return *this; }
		
		//const operators------------------------------------------------------------------------------------------------------------------------------------------------------
		const T&			 operator [] (const size_t& i)          const { return m_coords[i]; }
		bool				 operator == (const Static3Vector& rhs) const { for (int i = 0; i < this->size(); i++) if ((*this)[i] != rhs[i]) return false; return true; }
		bool				 operator != (const Static3Vector& rhs) const { return !(*this == rhs); }
		const Static3Vector  operator +  (const Static3Vector& rhs) const { Static3Vector v(*this); return v += rhs; }
		const Static3Vector  operator -  (const Static3Vector& rhs) const { Static3Vector v(*this); return v -= rhs; }
		const Static3Vector  operator *  (const T& rhs)			    const { Static3Vector v(*this); return v *= rhs; }
		const Static3Vector  operator /  (const T& rhs)			    const { Static3Vector v(*this); return v /= rhs; }
	private:
		T m_coords[3];
	};
	//function declatations----------------------------------------------------------------------------------------------------------------------------------------------------
	template <class T>
	T Static3Vector<T>::length() 
	{ 
		T l = 0; 
		for (int i = 0; i < this->size(); i++) 
			l += (*this)[i] * (*this)[i]; 
		return sqrt(l); 
	}
	template <class T>
	Static3Vector<double> Static3Vector<T>::normalise()
	{
		T l = this->length();
		Static3Vector<double> v;
		v[0] = (double)(*this)[0] / l;
		v[1] = (double)(*this)[1] / l;
		v[2] = (double)(*this)[2] / l;
		return v;
	}

}