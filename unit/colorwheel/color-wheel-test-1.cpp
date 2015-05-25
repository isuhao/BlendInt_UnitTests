#include <blendint/gui/dialog.hpp>
#include <blendint/gui/color-wheel.hpp>
#include <blendint/gui/window.hpp>

#include "color-wheel-test-1.hpp"

using namespace BlendInt;

ColorWheelTest1::ColorWheelTest1()
    : testing::Test()
{
  // TODO: add constructor code
}

ColorWheelTest1::~ColorWheelTest1()
{
  // TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(ColorWheelTest1, Foo1)
{
  if (Window::Initialize()) {

    Window win(640, 480, "DialogTest1");

    Dialog* dlg = new Dialog(
        "Test Dialog with title and buttons", 0,
        Dialog::DialogButtonOK | Dialog::DialogButtonApply);

    ColorWheel* wheel = new ColorWheel;
    dlg->AddWidget(wheel);
    
    dlg->Resize(dlg->GetPreferredSize());
    dlg->MoveTo((win.size().width() - dlg->size().width()) / 2,
                (win.size().height() - dlg->size().height()) / 2);

    win.AddFrame(dlg);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
