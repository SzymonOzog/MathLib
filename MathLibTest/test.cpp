#include "pch.h"
#include "MathLib.h"

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

	TEST(MathLibTests, dotProdDynamic)
	{
		MathLib::DynamicVector<int> vec1({ 1,2,6 });
		MathLib::DynamicVector<int> vec2({ 3,2 });
		EXPECT_EQ(MathLib::dotProduct(vec1, vec2), 7);
	}
	TEST(MathLibTests, dotProdStatic)
	{
		MathLib::Static3Vector<int> vec1({ 1,2,6 });
		MathLib::Static3Vector<int> vec2({ 3,2,1 });
		EXPECT_EQ(MathLib::dotProduct(vec1, vec2), 13);
	}
	TEST(MathLibTests, crossProdStatic)
	{
		MathLib::Static3Vector<int> vec1({ 1,0,0 });
		MathLib::Static3Vector<int> vec2({ 0,1,0 });
		MathLib::Static3Vector<int> vec3({ 0,0,1 });
		EXPECT_TRUE(MathLib::crossProduct(vec1, vec2) == vec3);
	}

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

	TEST(Static3VectorFunctionsTests, Length)
	{
		MathLib::Static3Vector<int> vec1({ 1, 0, 0 });
		MathLib::Static3Vector<int> vec2({ 6,8,0 });
		EXPECT_EQ(vec1.length(), 1);
		EXPECT_EQ(vec2.length(), 10);
	}
	TEST(Static3VectorFunctionsTests, Normalise)
	{
		MathLib::Static3Vector<int> vec1({ 6,8,10 });
		double normalisedLength = vec1.normalise().length();
		EXPECT_TRUE(normalisedLength > 0.95 && normalisedLength < 1.05);
	}

	TEST(Matrix3x3OperatorTests, Equal)
	{
		MathLib::Static3Vector v1(3, 4, 5);
		MathLib::Static3Vector v2(5, 4, 5);
		MathLib::Static3Vector v3(3, 4, 5);

		MathLib::Matrix3x3 m1(v1, v2, v3);
		v2 = { 0,0,0 };
		MathLib::Matrix3x3 m2(v1, v2, v3);
		EXPECT_TRUE(m1 == m1);
		EXPECT_TRUE(m1 != m2);
	}

	TEST(Matrix3x3OperatorTests, Multiplication)
	{
		MathLib::Static3Vector v1(3, 4, 5);
		MathLib::Static3Vector v2(3, 4, 5);
		MathLib::Static3Vector v3(3, 4, 5);

		MathLib::Matrix3x3 m1(v1, v2, v3);
		MathLib::Matrix3x3 mMul(v1 * 7, v2 * 7, v3 * 7);

		MathLib::Static3Vector vM = v1 * m1;
		MathLib::Static3Vector vMul(36, 48, 60);

		MathLib::Matrix3x3 m2 = m1 * m1;
		MathLib::Matrix3x3 mMul2(vMul, vMul, vMul);
		m1 =m1 * 7;
		EXPECT_TRUE(m1 == mMul);
		EXPECT_TRUE(vM == vMul);
		EXPECT_TRUE(m2 == mMul2);
	}
	TEST(Matrix3x3OperatorTests, MultiplicationAssignment)
	{
		MathLib::Matrix3x3 m1(1);
		MathLib::Matrix3x3 MMul(7);
		m1 *= 7;
		EXPECT_TRUE(m1==MMul);
	}
	TEST(Matrix3x3OperatorTests, Addition)
	{
		MathLib::Static3Vector v1(3, 4, 5);
		MathLib::Static3Vector v2(5, 4, 5);
		MathLib::Static3Vector v3(3, 4, 5);
		MathLib::Matrix3x3 m1(v1, v2, v3);
		MathLib::Matrix3x3 m2(v1, v2, v3);
		MathLib::Matrix3x3 mAdd(v1 * 2, v2 * 2, v3 * 2);
		m1 = m1 + m2;
		EXPECT_TRUE(mAdd==m1);
	}
	TEST(Matrix3x3OperatorTests, AdditionAssignment)
	{
		MathLib::Static3Vector v1(3, 4, 5);
		MathLib::Static3Vector v2(5, 4, 5);
		MathLib::Static3Vector v3(3, 4, 5);
		MathLib::Matrix3x3 m1(v1, v2, v3);
		MathLib::Matrix3x3 mAdd(v1 * 2, v2 * 2, v3 * 2);
		m1 += m1;
		EXPECT_TRUE(m1==mAdd);
	}
	TEST(Matrix3x3OperatorTests, Subtraction)
	{
		MathLib::Static3Vector v1(3, 4, 5);
		MathLib::Static3Vector v2(5, 4, 5);
		MathLib::Static3Vector v3(3, 4, 5);
		MathLib::Matrix3x3 m1(v1, v2, v3);
		MathLib::Matrix3x3 m2(v1, v2, v3);
		MathLib::Matrix3x3<int> mSub;
		m1 = m1 - m2;
		EXPECT_TRUE(mSub==m1);
	}
	TEST(Matrix3x3OperatorTests, SubtractionAssignment)
	{
		MathLib::Static3Vector v1(3, 4, 5);
		MathLib::Static3Vector v2(5, 4, 5);
		MathLib::Static3Vector v3(3, 4, 5);
		MathLib::Matrix3x3 m1(v1, v2, v3);
		MathLib::Matrix3x3<int> mSub;
		m1 -= m1;
		EXPECT_TRUE(m1==mSub);
	}

	TEST(Matrix3x3FunctionTests, Determinant )
	{
		MathLib::Static3Vector v1(2, -3, 1);
		MathLib::Static3Vector v2(2, 0, -1);
		MathLib::Static3Vector v3(1, 4, 5);
		MathLib::Matrix3x3 m1(v1, v2, v3);
		MathLib::Matrix3x3 m2(1);
		EXPECT_TRUE(m1.determinant() == 49);
		EXPECT_TRUE(m2.determinant() == 1);

	}
	TEST(Matrix3x3FunctionTests, Transpose)
	{
		MathLib::Static3Vector v1(1, 2, 3);
		MathLib::Static3Vector v2(4, 5, 6);
		MathLib::Static3Vector v3(7, 8, 9);
		MathLib::Matrix3x3 m1(v1, v2, v3);
		MathLib::Static3Vector v4(1, 4, 7);
		MathLib::Static3Vector v5(2, 5, 8);
		MathLib::Static3Vector v6(3, 6, 9);
		MathLib::Matrix3x3 m2(v4, v5, v6);
		m1.transpose();
		EXPECT_TRUE(m1 == m2);
	}