#pragma once
#include <vector>
template <class T>
class Point
{
public:
	Point(std::vector<T> coords);
private:
	std::vector<T> _coords;
};

