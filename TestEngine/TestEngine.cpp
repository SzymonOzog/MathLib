//the code here is just a test for MathLib, the code here is highly based on the code from 
//here: https://github.com/OneLoneCoder/videos/blob/master/OneLoneCoder_olcEngine3D_Part1.cpp

#include <iostream>
#include "MathLib.h"
#include "olcPixelGameEngine.h"

class testEngine : public olc::PixelGameEngine
{
public:
	testEngine()
	{
		sAppName = "testEngine";
	}
private:
	std::vector<MathLib::Matrix3x3<float>> triangles;
	MathLib::Matrix3x3<float> matRotY, matRotX;
	MathLib::Matrix3x3<float> matProj;
	MathLib::Static3Vector<float> vecProj;
	float fRotX, fRotY;
	float fZOffset;
	float fRotSpeed;
public:
	bool OnUserCreate() override
	{
		triangles = 
		{
			// SOUTH
			{ {0.0f, 0.0f, 0.0f},	 {0.0f, 1.0f, 0.0f},	{1.0f, 1.0f, 0.0f} },
			{ {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 0.0f},	{1.0f, 0.0f, 0.0f} },

			// EAST                                                      
			{ {1.0f, 0.0f, 0.0f},    {1.0f, 1.0f, 0.0f},    {1.0f, 1.0f, 1.0f} },
			{ {1.0f, 0.0f, 0.0f},    {1.0f, 1.0f, 1.0f},    {1.0f, 0.0f, 1.0f} },
			  				   		 
			// NORTH                 
			{ {1.0f, 0.0f, 1.0f},    {1.0f, 1.0f, 1.0f},    {0.0f, 1.0f, 1.0f} },
			{ {1.0f, 0.0f, 1.0f},    {0.0f, 1.0f, 1.0f},    {0.0f, 0.0f, 1.0f} },
			  				   		
			// WEST                
			{ {0.0f, 0.0f, 1.0f},    {0.0f, 1.0f, 1.0f},    {0.0f, 1.0f, 0.0f} },
			{ {0.0f, 0.0f, 1.0f},    {0.0f, 1.0f, 0.0f},    {0.0f, 0.0f, 0.0f} },
			  				   	
			// TOP             
			{ {0.0f, 1.0f, 0.0f},    {0.0f, 1.0f, 1.0f},    {1.0f, 1.0f, 1.0f} },
			{ {0.0f, 1.0f, 0.0f},    {1.0f, 1.0f, 1.0f},    {1.0f, 1.0f, 0.0f} },

			// BOTTOM                                                    
			{ {1.0f, 0.0f, 1.0f},    {0.0f, 0.0f, 1.0f},    {0.0f, 0.0f, 0.0f} },
			{ {1.0f, 0.0f, 1.0f},    {0.0f, 0.0f, 0.0f},    {1.0f, 0.0f, 0.0f} },
		};
		float fNear = 0.1f;
		float fFar = 1000.0f;
		float fFov = 90.0f;
		float fAspectRatio = (float)ScreenHeight() / (float)ScreenWidth();
		float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);
		
		matProj =
		{
			{fAspectRatio*fFovRad, 0,0},
			{0, fFovRad, 0 },
			{0, 0,  fFar / (fFar - fNear) }
		};
		fRotX = 0.0f;
		fRotY = 0.0f;
		fZOffset = -(fFar * fNear) / (fFar - fNear);
		fRotSpeed = 1.0f;
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override
	{	// Clear Screen
		Clear(olc::VERY_DARK_BLUE);

		if (GetKey(olc::UP).bHeld)
		{
			fRotX += fRotSpeed * fElapsedTime;
		}

		if (GetKey(olc::DOWN).bHeld)
		{
			fRotX -= fRotSpeed * fElapsedTime;
		}

		if (GetKey(olc::LEFT).bHeld)
		{
			fRotY -= fRotSpeed * fElapsedTime;
		}

		if (GetKey(olc::RIGHT).bHeld)
		{
			fRotY += fRotSpeed * fElapsedTime;
		}
		matRotX =
		{
			{1, 0,			  0			  },
			{0, cosf(fRotX), -sinf(fRotX) },
			{0, sinf(fRotX),  cosf(fRotX) }
		};
		matRotY =
		{
			{cosf(fRotY),  0,  sinf(fRotY) },
			{0,			   1,  0          },
			{-sinf(fRotY), 0,  cosf(fRotY) }
		};

		for (auto tri : triangles)
		{
			MathLib::Matrix3x3<float> newTriangle = tri;
			//rotate 
			newTriangle = newTriangle * matRotX * matRotY;

			//Offset into the screen
			newTriangle[0][2] += 3.0f;
			newTriangle[1][2] += 3.0f;
			newTriangle[2][2] += 3.0f;

			//Project from 3D to 2D
			newTriangle = newTriangle * matProj;
			newTriangle[0] /= newTriangle[0][2];
			newTriangle[1] /= newTriangle[1][2];
			newTriangle[2] /= newTriangle[2][2];

			// Scale into view
			newTriangle[0][0] += 1.0f; newTriangle[0][1] += 1.0f;
			newTriangle[1][0] += 1.0f; newTriangle[1][1] += 1.0f;
			newTriangle[2][0] += 1.0f; newTriangle[2][1] += 1.0f;
			newTriangle[0][0] *= 0.5f * (float)ScreenWidth();
			newTriangle[0][1] *= 0.5f * (float)ScreenHeight();
			newTriangle[1][0] *= 0.5f * (float)ScreenWidth();
			newTriangle[1][1] *= 0.5f * (float)ScreenHeight();
			newTriangle[2][0] *= 0.5f * (float)ScreenWidth();
			newTriangle[2][1] *= 0.5f * (float)ScreenHeight();

			DrawTriangle(newTriangle[0][0], newTriangle[0][1],
				newTriangle[1][0], newTriangle[1][1],
				newTriangle[2][0], newTriangle[2][1]);

		}

		return true;
	}
};
	int main()
	{
		MathLib::Matrix3x3<int> m;
		testEngine engine;
		if (engine.Construct(256, 240, 4, 4))
			engine.Start();
	}
