#include "color-test-1.hpp"
#include <core/color.hpp>

using namespace BlendInt;

colorTest1::colorTest1()
: testing::Test()
{
	// TODO: add constructor code
}

colorTest1::~colorTest1()
{
	// TODO: add destructor code
}

TEST_F(colorTest1, Equal1)
{
	Color color1(Palette::White);
	Color color2(Palette::White);

	ASSERT_TRUE(color1 == color2);
}

TEST_F(colorTest1, NotEqual1)
{
	Color color1(Palette::White);
	Color color2(Palette::Black);

	ASSERT_TRUE(color1 != color2);
}

