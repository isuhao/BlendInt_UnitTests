#include "Texture2DTest1.hpp"
#include <blendint/opengl/gl-texture2d.hpp>

using namespace BlendInt;

Texture2DTest1::Texture2DTest1()
: testing::Test()
{
	// TODO: add constructor code
}

Texture2DTest1::~Texture2DTest1()
{
	// TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(Texture2DTest1, Foo1)
{
	Init ();
	GLFWwindow* window = CreateWindow("GLTexture2D - Foo1", 640, 480);

	// TODO: add test code here

	RunLoop(window);

	Terminate();

	ASSERT_TRUE(true);
}
