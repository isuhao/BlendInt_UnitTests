#include <blendint/gui/window.hpp>
#include <blendint/gui/color-selector.hpp>

#include "color-selector-test-1.hpp"

using namespace BlendInt;

ColorSelectorTest1::ColorSelectorTest1()
    : testing::Test()
{
  // TODO: add constructor code
}

ColorSelectorTest1::~ColorSelectorTest1()
{
  // TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(ColorSelectorTest1, Foo1)
{
  if (Window::Initialize()) {

    Window win(640, 480, "DialogTest1");

    ColorSelector* cs = new ColorSelector;
    
    cs->MoveTo((win.size().width() - cs->size().width()) / 2,
                (win.size().height() - cs->size().height()) / 2);

    win.AddFrame(cs);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
