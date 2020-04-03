#include "MathLib.h"
namespace MathLib
{
	template <class T>
	void fillVector(std::vector<T>& toFill, T destinedSize)
	{
		int i = destinedSize - toFill.size();
		while (i--)
			toFill.push_back(0);
	}

	template <class T>
	std::vector<T> getSmaller(std::vector<T> vec1, std::vector<T> vec2)
	{
		return vec1.size() > vec2.size() ? vec2 : vec1;
	}
}