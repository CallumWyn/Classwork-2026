#include "pch.h"
#include "CppUnitTest.h"
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OptimizationUnitTests
{
	TEST_CLASS(OptimizationUnitTests)
	{
	public:
		


		TEST_METHOD(Quadtree_Insert)
		{
			Critter critter1;
			Critter critter2;
			Quadtree quadtree1(400, 225, 800, 450, 8);

			critter1.Init(Vector2{ 100, 12 }, Vector2{ 1, 1 }, 4, "this.png");
			critter2.Init(Vector2{ 215, 125 }, Vector2{ 1, 1 }, 4, "this.png");

			quadtree1.Insert(critter1);
			quadtree1.Insert(critter2);


			Assert::IsTrue(quadtree1.Quad1.size() == 2);
		}

		TEST_METHOD(Quadtree_Update) {
			Critter critters1[6];
			Quadtree quadtree1(400, 225, 800, 450, 8);

			for (Critter& critter : critters1) {
				critter.Init(Vector2{ 100, 12 }, Vector2{ 1, 1 }, 4, "this.png");
				critter.m_isDirty = false;
				// quadtree1.Insert(critter);
			}

			quadtree1.Update(critters1, 6);

			Assert::IsTrue(quadtree1.Quad1.size() == 6);

			Critter critters2[7];

			for (Critter& critter : critters2) {
				critter.Init(Vector2{ 500, 12 }, Vector2{ 1, 1 }, 4, "this.png");
				critter.m_isDirty = false;
			}

			quadtree1.Update(critters2, 7);
			quadtree1.subQuad1.get()->Quad1;

			Assert::IsTrue(quadtree1.Quad2.size() == 7);
			Assert::IsTrue(quadtree1.Quad1.size() == 0);
		}

		TEST_METHOD(Quadtree_Subdivision) {
			Critter critters1[8];
			Quadtree quadtree1(400, 225, 800, 450, 7);

			for (Critter& critter : critters1) {
				critter.Init(Vector2{ 100, 12 }, Vector2{ 1, 1 }, 4, "this.png");
				critter.m_isDirty = false;
				// quadtree1.Insert(critter);
			}

			critters1[7].Init(Vector2{ 210, 12 }, Vector2{ 1, 1 }, 4, "this.png");

			quadtree1.Update(critters1, 8);

			Assert::IsTrue(quadtree1.subQuad1.get()->Quad1.size() == 7);

			
		}
	};
}
