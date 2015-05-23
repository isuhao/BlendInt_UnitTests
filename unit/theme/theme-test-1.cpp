#include <blendint/gui/window.hpp>
#include <blendint/stock/icons.hpp>
#include <iostream>
#include <list>
#include <set>

#include "theme-test-1.hpp"

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
  if(Window::Initialize()) {
    Window win(640, 480, "Theme Save Test");

    theme()->Save("test.xml");

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}

/**
 * test new Object 
 *
 * Expected result: 
 */
TEST_F(ThemeTest1, Load1)
{
  if(Window::Initialize()) {
    Window win(640, 480, "Theme Load Test");

    theme()->Load("test.xml");

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
