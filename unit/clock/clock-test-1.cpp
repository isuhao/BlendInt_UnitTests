#include "clock-test-1.hpp"

#include <blendint/gui/clock.hpp>
#include <blendint/gui/window.hpp>
#include <blendint/gui/dialog.hpp>

using namespace BlendInt;

ClockTest1::ClockTest1()
: testing::Test()
{
	// TODO: add constructor code
}

ClockTest1::~ClockTest1()
{
	// TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(ClockTest1, Foo1)
{
	if(Window::Initialize()) {

		Window win(640, 480, "Clock Test");

		Dialog* dialog = new Dialog("Clock Test");
		dialog->MoveTo(100, 100);

		Clock* clock = new Clock;
		clock->Resize(200, 200);
		clock->MoveTo(25, 25);
		dialog->AddWidget(clock);
		dialog->Resize(dialog->GetPreferredSize());

		win.AddFrame(dialog);

		clock->Start();

		win.Exec();
		Window::Terminate();
	}

	ASSERT_TRUE(true);
}
