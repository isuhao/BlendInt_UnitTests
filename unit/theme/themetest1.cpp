#include "ThemeTest1.hpp"
#include <Common/Window.hpp>

#include <blendint/stock/icons.hpp>
#include <Common/UnitTestContext.hpp>

#include <iostream>

#include <list>
#include <set>

using namespace BlendInt;

ThemeTest1::ThemeTest1()
: testing::Test()
{
	// TODO: add constructor code
}

ThemeTest1::~ThemeTest1()
{
	// TODO: add destructor code
}

TEST_F(ThemeTest1, Save1)
{
    Init();
    GLFWwindow* win = CreateWindow("Save theme test", 640, 480);

    UnitTestContext* context = Manage (new UnitTestContext);
	DBG_SET_NAME(context, "Context");
	SetContext(context);
	context->Resize(640, 480);


    RunLoop(win);
    Terminate();

	ASSERT_TRUE(true);
}

/**
 * test new Object 
 *
 * Expected result: 
 */
TEST_F(ThemeTest1, Load1)
{
    Init();
    GLFWwindow* win = CreateWindow("Load theme test", 640, 480);

    UnitTestContext* context = Manage (new UnitTestContext);
	DBG_SET_NAME(context, "Context");
	SetContext(context);
	context->Resize(640, 480);


    RunLoop(win);
    Terminate();

	ASSERT_TRUE(true);
}
