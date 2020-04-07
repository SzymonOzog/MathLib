#include "pch.h"
#include "MathLib.h"
namespace MathLibTests
{

	TEST(MathLibTests, fillTest)
	{
		std::vector<int> vec = { 1 };
		std::vector<int> vec2 = { 1,0,0,0,0 };
		MathLib::fillVector(vec, 5);
		EXPECT_EQ(vec, vec2);
		EXPECT_TRUE(true);
	}
	TEST(MathLibTests, smaller)
	{
		std::vector<int> vec1 = { 1 };
		std::vector<int> vec2 = { 2,0,0,0,0 };
		EXPECT_EQ(MathLib::getSmaller(vec1, vec2), vec1);
		EXPECT_TRUE(true);
	}
}
namespace vTests
{

	TEST(VectorTests, Equal)
	{
		MathLib::Vector<int> vec1({ 1,2,3 });
		MathLib::Vector<int> vec2({ 1,2,3 });
		EXPECT_TRUE(vec1 == vec2);
	}
	//TEST(VectorTests, Addition)
	//{
	//	MathLib::Vector<int> vec1({ 1,2,3 });
	//	MathLib::Vector<int> vec2({ 1,2,3,4 });
	//	MathLib::Vector<int> vec3({ 2,4,6,4 });
	//	MathLib::Vector<int> vecAdd = vec1 + vec2;
	//	EXPECT_EQ(vecAdd, vec3);
	//}
	//TEST(VectorTests, AdditionAssignment)
	//{
	//	MathLib::Vector<int> vec1({ 1,2,3 });
	//	MathLib::Vector<int> vec2({ 1,2,3,4 });
	//	MathLib::Vector<int> vec3({ 2,4,6,4 });
	//	vec1 += vec2;
	//	EXPECT_EQ(vec1, vec3);
	//}
	//TEST(VectorTests, Subtraction)
	//{
	//	MathLib::Vector<int> vec1({ 1,2,3 });
	//	MathLib::Vector<int> vec2({ 1,2,3,4 });
	//	MathLib::Vector<int> vec3({ 0,0,0,-4 });
	//	MathLib::Vector<int> vecSub = vec1 - vec2;
	//	EXPECT_EQ(vecSub, vec3);
	//}
	//TEST(VectorTests, SubtractionAssignment)
	//{
	//	MathLib::Vector<int> vec1({ 1,2,3 });
	//	MathLib::Vector<int> vec2({ 1,2,3,4 });
	//	MathLib::Vector<int> vec3({ 0,0,0,-4 });
	//	vec1 -= vec2;
	//	EXPECT_EQ(vec1, vec3);
	//}
	//TEST(VectorTests, Multiplication)
	//{
	//	MathLib::Vector<int> vec1({ 1,2,3 });
	//	MathLib::Vector<int> vec2({ 2,4,6 });
	//	MathLib::Vector<int> vecMult = vec1 * 2;
	//	EXPECT_EQ(vecMult, vec2);
	//}
	//TEST(VectorTests, MultiplicationAssignment)
	//{
	//	MathLib::Vector<int> vec1({ 1,2,3 });
	//	MathLib::Vector<int> vec2({ 2,4,6 });
	//	vec1 *= 2;
	//	EXPECT_EQ(vec1, vec2);
	//}
	//TEST(VectorTests, Division)
	//{
	//	MathLib::Vector<int> vec1({ 2,4,6 });
	//	MathLib::Vector<int> vec2({ 1,2,3 });
	//	MathLib::Vector<int> vecDiv = vec1 / 2;
	//	EXPECT_EQ(vecDiv, vec2);
	//}
	//TEST(VectorTests, DivisionAssignment)
	//{
	//	MathLib::Vector<int> vec1({ 2,4,6 });
	//	MathLib::Vector<int> vec2({ 1,2,3 });
	//	 vec1 /= 2;
	//	EXPECT_EQ(vec1, vec2);
	//}
}