#include "dialog-test-1.hpp"

#include <gui/dialog.hpp>
#include <gui/window.hpp>

using namespace BlendInt;

DialogTest1::DialogTest1()
: testing::Test()
{
	// TODO: add constructor code
}

DialogTest1::~DialogTest1()
{
	// TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(DialogTest1, Foo1)
{
	if(Window::Initialize()) {

		Window win(640, 480, "DialogTest1");

		Dialog* dlg = new Dialog("Test Dialog with title and buttons", Dialog::DialogButtonOK | Dialog::DialogButtonApply);

		dlg->Resize(dlg->GetPreferredSize());
		dlg->MoveTo((win.size().width() - dlg->size().width()) / 2,
		        (win.size().height() - dlg->size().height()) / 2);

		win.AddFrame(dlg);

		win.Exec();
		Window::Terminate();
	}

	ASSERT_TRUE(true);
}
