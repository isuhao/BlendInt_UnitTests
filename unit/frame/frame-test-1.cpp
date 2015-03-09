#include <gui/frame.hpp>
#include <gui/linear-layout.hpp>
#include <gui/button.hpp>
#include <gui/window.hpp>

#include "frame-test-1.hpp"

using namespace BlendInt;

FrameTest1::FrameTest1()
: testing::Test()
{
	// TODO: add constructor code
}

FrameTest1::~FrameTest1()
{
	// TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(FrameTest1, Foo1)
{
  if(Window::Initialize()) {

    Window win(640, 480, "FrameTest1");

    LinearLayout* layout = new LinearLayout(Vertical);
    DBG_SET_NAME(layout, "LinearLayout");

    Frame* frame = new Frame(layout);
    DBG_SET_NAME(frame, "Frame");

    Button* btn1 = new Button("Button1");
    DBG_SET_NAME(btn1, "Button1");
    Button* btn2 = new Button("Button2");
    DBG_SET_NAME(btn2, "Button2");
    Button* btn3 = new Button("Button3");
    DBG_SET_NAME(btn3, "Button3");

    frame->AddWidget(btn1);
    frame->AddWidget(btn2);
    frame->AddWidget(btn3);

    frame->Resize(frame->GetPreferredSize());
    frame->MoveTo((win.size().width() - frame->size().width()) / 2,
            (win.size().height() - frame->size().height()) / 2);

    win.AddFrame(frame);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
