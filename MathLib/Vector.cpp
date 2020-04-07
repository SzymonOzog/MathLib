//#include "Vector.h"
//namespace MathLib
//{
//	template <class T>
//	Vector<T>::Vector(std::vector<T> coords)
//	{
//		_coords = coords;
//	}
//	template <class T>
//	Vector<T> Vector<T>::normalise()
//	{
//		T length = length();
//		std::vector<T> vec;
//		for (auto c : _coords)
//			vec.push_back(c / length);
//		return Vector<T>(vec);
//	}
//	template <class T>
//	T Vector<T>::length()
//	{
//		T sqSum;
//		for (auto c : _coords)
//			sqSum += c * c;
//		return sqrt(sqSum);
//	}
//	//template <class T>
//	//Vector<T> operator + (Vector<T> otherVec)
//	//{
//	//	std::vector<T> vec;
//	//	int n = this->_coords.size();
//	//	if (this->_coords.size() != otherVec._coords.size())
//	//		MathLib::toFill(MathLib::getSmaller(*this, otherVec), abs(n - otherVec._coords.size()));
//	//	for (int i = 0; i < otherVec.size(); i++)
//	//		vec.push_back(this->_coords[i] + otherVec._coords[i]);
//	//	return Vector<T>(vec);
//	//}
//	//template <class T>
//	//Vector<T> operator - (Vector<T> otherVec);
//	//template <class T>
//	//Vector<T> operator * (T scalar);
//	//template <class T>
//	//Vector<T> operator / (T scalar);
//	//template <class T>
//	//Vector<T> operator += (Vector<T> otherVec);
//	//template <class T>
//	//Vector<T> operator -= (Vector<T> otherVec);
//	//template <class T>
//	//Vector<T> operator *= (T scalar);
//	//template <class T>
//	//Vector<T> operator /= (T scalar);
//}