#include <blendint/gui/slider.hpp>
#include <blendint/gui/dialog.hpp>
#include <blendint/gui/window.hpp>

#include "slider-test-1.hpp"

using namespace BlendInt;

SliderTest1::SliderTest1 ()
    : testing::Test()
{
  // TODO: add constructor code
}

SliderTest1::~SliderTest1 ()
{
  // TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(SliderTest1, Foo1)
{
  if (Window::Initialize()) {

    Window win(640, 480, "Slider Test 1");

    Dialog* dialog = new Dialog("Slider Test 1");

    Slider* sl = new Slider;
    dialog->AddWidget(sl);

    win.AddFrame(dialog);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
