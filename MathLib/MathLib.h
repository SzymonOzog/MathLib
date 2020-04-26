#pragma once
#include <vector>
#include <cmath>
#include "DynamicVector.h"
#include "Static3Vector.h"

namespace MathLib
{
	template <class T>
	void fillDynamicVector(DynamicVector<T>&&toFill, T destinedSize);
	template <class T>
	DynamicVector<T> getSmaller(const DynamicVector<T>& vec1, const DynamicVector<T>& vec2);

	//IMPLEMENTATNIONS ------------------------------------------------------------
	template <class T>
	void fillDynamicVector(DynamicVector<T>& toFill, int destinedSize)
	{
		while (toFill.size()!=destinedSize)
			toFill.push_back(0);
	}
	template <class T>
	DynamicVector<T> getSmaller(const DynamicVector<T>& v1, const DynamicVector<T>& v2)
	{
		return v1.size() > v2.size() ? v2 : v1;
	}
	template <class T>
	T dotProduct(DynamicVector<T> &v1, DynamicVector<T> &v2)
	{
		//auto v = MathLib::getSmaller(v1, v2);
		MathLib::fillDynamicVector((v1.size() > v2.size() ? v2 : v1), std::max(v1.size(), v2.size()));
		T dotProd = 0;
		for (int i = 0; i < v1.size(); i++)
			dotProd += v1[i] * v2[i];
			return dotProd;
	}

}

