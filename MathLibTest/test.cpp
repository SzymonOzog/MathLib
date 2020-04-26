#include "pch.h"
#include "MathLib.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MATH LIB TESTS///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	TEST(MathLibTests, fillTest)
	{
		MathLib::DynamicVector<int> vec({ 1 });
		MathLib::DynamicVector<int> vec2({ 1,0,0,0,0 });
		MathLib::fillDynamicVector(vec, 5);
		EXPECT_TRUE(vec == vec2);
	}
	TEST(MathLibTests, smaller)
	{
		MathLib::DynamicVector<int> vec1({ 1 });
		MathLib::DynamicVector<int> vec2({ 2,0,0,0,0 });
		EXPECT_TRUE(MathLib::getSmaller(vec1, vec2) == vec1);
	}

	TEST(MathLibTests, dotProd)
	{
		MathLib::DynamicVector<int> vec1({ 1,2,6 });
		MathLib::DynamicVector<int> vec2({ 3,2 });
		EXPECT_EQ(MathLib::dotProduct(vec1, vec2), 7);
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DYNAMIC VECTOR FUNCTIONS TESTS///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	TEST(DynamicVectorFunctionsTests, Length)
	{
		MathLib::DynamicVector<int> vec1({ 1 });
		MathLib::DynamicVector<int> vec2({ 6,8,0});
		EXPECT_EQ(vec1.length() , 1);
		EXPECT_EQ(vec2.length(), 10);
	}
	TEST(DynamicVectorFunctionsTests, Normalise)
	{
		MathLib::DynamicVector<int> vec1({ 6,8,10,1 });
		double normalisedLength = vec1.normalise().length();
		EXPECT_TRUE(normalisedLength>0.95&&normalisedLength<1.05);
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DYNAMIC VECTOR OPERATOR TESTS////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	TEST(DynamicVectorOperatorTests, Equal)
	{
		MathLib::DynamicVector<int> vec1({ 1,2,3 });
		MathLib::DynamicVector<int> vec2({ 1,2,3 });
		EXPECT_TRUE(vec1 == vec2);
	}
	TEST(DynamicVectorOperatorTests, NotEqual)
	{
		MathLib::DynamicVector<int> vec1({ 3,2,3 });
		MathLib::DynamicVector<int> vec2({ 1,2,3 });
		EXPECT_TRUE(vec1 != vec2);
	}
	TEST(DynamicVectorOperatorTests, Addition)
	{
		MathLib::DynamicVector<int> vec1({ 1,2,3 });
		MathLib::DynamicVector<int> vec2({ 1,2,3,4 });
		MathLib::DynamicVector<int> vec3({ 2,4,6,4 });
		MathLib::DynamicVector<int> vecAdd = vec1 + vec2;
		EXPECT_TRUE(vecAdd == vec3);
	}
	TEST(DynamicVectorOperatorTests, AdditionAssignment)
	{
		MathLib::DynamicVector<int> vec1({ 1,2,3,0,6 });
		MathLib::DynamicVector<int> vec2({ 1,2,3,5});
		MathLib::DynamicVector<int> vec3({ 2,4,6,5,6});
		vec1 += vec2;
		EXPECT_TRUE(vec1 == vec3);
	}
	TEST(DynamicVectorOperatorTests, Subtraction)
	{
		MathLib::DynamicVector<int> vec1({ 1,2,3 });
		MathLib::DynamicVector<int> vec2({ 1,2,3,4 });
		MathLib::DynamicVector<int> vec3({ 0,0,0,-4 });
		MathLib::DynamicVector<int> vecSub = vec1 - vec2;
		EXPECT_TRUE(vecSub == vec3);
	}
	TEST(DynamicVectorOperatorTests, SubtractionAssignment)
	{
		MathLib::DynamicVector<int> vec1({ 1,2,3 });
		MathLib::DynamicVector<int> vec2({ 1,2,3,4 });
		MathLib::DynamicVector<int> vec3({ 0,0,0,-4 });
		vec1 -= vec2;
		EXPECT_TRUE(vec1 == vec3);
	}
	TEST(DynamicVectorOperatorTests, Multiplication)
	{
		MathLib::DynamicVector<int> vec1({ 1,2,3 });
		MathLib::DynamicVector<int> vec2({ 2,4,6 });
		MathLib::DynamicVector<int> vecMult = vec1 * 2;
		EXPECT_TRUE(vecMult == vec2);
	}
	TEST(DynamicVectorOperatorTests, MultiplicationAssignment)
	{
		MathLib::DynamicVector<int> vec1({ 1,2,3 });
		MathLib::DynamicVector<int> vec2({ 2,4,6 });
		vec1 *= 2;
		EXPECT_TRUE(vec1 == vec2);
	}
	TEST(DynamicVectorOperatorTests, Division)
	{
		MathLib::DynamicVector<int> vec1({ 2,4,6 });
		MathLib::DynamicVector<int> vec2({ 1,2,3 });
		MathLib::DynamicVector<int> vecDiv = vec1 / 2;
		EXPECT_TRUE(vecDiv == vec2);
	}
	TEST(DynamicVectorOperatorTests, DivisionAssignment)
	{
		MathLib::DynamicVector<int> vec1({ 2,4,6 });
		MathLib::DynamicVector<int> vec2({ 1,2,3 });
		 vec1 /= 2;
		EXPECT_TRUE(vec1 == vec2);
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//STATIC 3 VECTOR OPERATOR TESTS///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	TEST(Static3VectorOperatorTests, Equal)
	{
		MathLib::Static3Vector<int> vec1({ 1,2,3 });
		MathLib::Static3Vector<int> vec2({ 1,2,3 });
		EXPECT_TRUE(vec1 == vec2);
	}
	TEST(Static3VectorOperatorTests, NotEqual)
	{
		MathLib::Static3Vector<int> vec1({ 3,2,3 });
		MathLib::Static3Vector<int> vec2({ 1,2,3 });
		EXPECT_TRUE(vec1 != vec2);
	}
	TEST(Static3VectorOperatorTests, Addition)
	{
		MathLib::Static3Vector<int> vec1({ 1,2,3 });
		MathLib::Static3Vector<int> vec2({ 1,2,3 });
		MathLib::Static3Vector<int> vec3({ 2,4,6 });
		MathLib::Static3Vector<int> vecAdd = vec1 + vec2;
		EXPECT_TRUE(vecAdd == vec3);
	}
	TEST(Static3VectorOperatorTests, AdditionAssignment)
	{
		MathLib::Static3Vector<int> vec1({ 1,2,3 });
		MathLib::Static3Vector<int> vec2({ 1,2,3 });
		MathLib::Static3Vector<int> vec3({ 2,4,6 });
		vec1 += vec2;
		EXPECT_TRUE(vec1 == vec3);
	}
	TEST(Static3VectorOperatorTests, Subtraction)
	{
		MathLib::Static3Vector<int> vec1({ 1,2,3 });
		MathLib::Static3Vector<int> vec2({ 1,2,3 });
		MathLib::Static3Vector<int> vec3({ 0,0,0 });
		MathLib::Static3Vector<int> vecSub = vec1 - vec2;
		EXPECT_TRUE(vecSub == vec3);
	}
	TEST(Static3VectorOperatorTests, SubtractionAssignment)
	{
		MathLib::Static3Vector<int> vec1({ 1,2,3 });
		MathLib::Static3Vector<int> vec2({ 1,2,3 });
		MathLib::Static3Vector<int> vec3({ 0,0,0 });
		vec1 -= vec2;
		EXPECT_TRUE(vec1 == vec3);
	}
	TEST(Static3VectorOperatorTests, Multiplication)
	{
		MathLib::Static3Vector<int> vec1({ 1,2,3 });
		MathLib::Static3Vector<int> vec2({ 2,4,6 });
		MathLib::Static3Vector<int> vecMult = vec1 * 2;
		EXPECT_TRUE(vecMult == vec2);
	}
	TEST(Static3VectorOperatorTests, MultiplicationAssignment)
	{
		MathLib::Static3Vector<int> vec1({ 1,2,3 });
		MathLib::Static3Vector<int> vec2({ 2,4,6 });
		vec1 *= 2;
		EXPECT_TRUE(vec1 == vec2);
	}
	TEST(Static3VectorOperatorTests, Division)
	{
		MathLib::Static3Vector<int> vec1({ 2,4,6 });
		MathLib::Static3Vector<int> vec2({ 1,2,3 });
		MathLib::Static3Vector<int> vecDiv = vec1 / 2;
		EXPECT_TRUE(vecDiv == vec2);
	}
	TEST(Static3VectorOperatorTests, DivisionAssignment)
	{
		MathLib::Static3Vector<int> vec1({ 2,4,6 });
		MathLib::Static3Vector<int> vec2({ 1,2,3 });
		vec1 /= 2;
		EXPECT_TRUE(vec1 == vec2);
	}