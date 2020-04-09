#pragma once
#include <vector>
#include <cmath>
#include "Vector.h"

namespace MathLib
{
	template <class T>
	void fillVector(MathLib::Vector<T>&&toFill, T destinedSize);
	template <class T>
	std::vector<T> getSmaller(const std::vector<T> &vec1, const std::vector<T> &vec2);

	//IMPLEMENTATNIONS ------------------------------------------------------------
	template <class T>
	void fillVector(MathLib::Vector<T>& toFill, int destinedSize)
	{
		while (toFill.size()!=destinedSize)
			toFill.push_back(0);
	}
	template <class T>
	std::vector<T> getSmaller(std::vector<T>& vec1, std::vector<T> &vec2)
	{
		return vec1.size() > vec2.size() ? vec2 : vec1;
	}
}

