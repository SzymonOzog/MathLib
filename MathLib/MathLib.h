#pragma once
#include <vector>
#include <cmath>
#include "Vector.h"

namespace MathLib
{
	template <class T>
	void fillVector(std::vector<T> &toFill, T destinedSize);
	template <class T>
	std::vector<T> getSmaller(std::vector<T> vec1, std::vector<T> vec2);
};

