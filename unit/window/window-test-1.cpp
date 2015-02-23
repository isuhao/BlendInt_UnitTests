#include "window-test-1.hpp"
#include <gui/window.hpp>
#include <gui/dialog.hpp>

using namespace BlendInt;

WindowTest1::WindowTest1()
: testing::Test()
{
	// TODO: add constructor code
}

WindowTest1::~WindowTest1()
{
	// TODO: add destructor code
}

/**
* test SetFocusedFrame()
*/
TEST_F(WindowTest1, SetFocusedFrame)
{
	if(Window::Initialize()) {

		Window win(1280, 800, "AbstractWindow::SetFocusedFrame() Test");

		{
			Dialog* dlg1 = new Dialog("Dialog1");
			DBG_SET_NAME(dlg1, "Dialog1");
			dlg1->MoveTo(50, 50);
			dlg1->Resize(200, 200);

			Dialog* dlg2 = new Dialog("Dialog2");
			DBG_SET_NAME(dlg2, "Dialog2");
			dlg2->MoveTo(300, 50);
			dlg2->Resize(200, 200);

			Dialog* dlg3 = new Dialog("Dialog3");
			DBG_SET_NAME(dlg3, "Dialog3");
			dlg3->MoveTo(550, 50);
			dlg3->Resize(200, 200);

			win.AddFrame(dlg1);
			win.AddFrame(dlg2);
			win.AddFrame(dlg3);
		}

		win.Exec();
		Window::Terminate();
	}

	ASSERT_TRUE(true);
}

/**
 * test SwapIndex(), InsertSiblingBefore(), InsertSiblingAfter() methods
 *
 * Expected result: assert true
 *
 * Move
 * 	SwapIndex()
 * 	InsertSiblingBefore()
 * 	InsertSiblingAFter()
 * to public before compile this test
 */
TEST_F(WindowTest1, Create1)
{
	if(Window::Initialize()) {

		Window win(640, 480, "Window Test");

		/*
		{
			Dialog* dlg1 = new Dialog("Dialog1");
			DBG_SET_NAME(dlg1, "Dialog1");
			dlg1->MoveTo(50, 50);
			dlg1->Resize(200, 200);

			Dialog* dlg2 = new Dialog("Dialog2");
			DBG_SET_NAME(dlg2, "Dialog2");
			dlg2->MoveTo(300, 50);
			dlg2->Resize(200, 200);

			Dialog* dlg3 = new Dialog("Dialog3");
			DBG_SET_NAME(dlg3, "Dialog3");
			dlg3->MoveTo(550, 50);
			dlg3->Resize(200, 200);

			win.AddFrame(dlg1);
			win.AddFrame(dlg2);
			win.AddFrame(dlg3);

			for(AbstractView* p = win.first_subview(); p; p = p->next_view()) {
				DBG_PRINT_MSG("sub view: %s", p->name().c_str());
			}
			DBG_PRINT_MSG("subs count: %d", win.subs_count());

			win.SwapIndex(dlg1, dlg3);

			for(AbstractView* p = win.first_subview(); p; p = p->next_view()) {
				DBG_PRINT_MSG("sub view: %s", p->name().c_str());
			}
			DBG_PRINT_MSG("subs count: %d", win.subs_count());

			win.SwapIndex(dlg1, dlg2);

			for(AbstractView* p = win.first_subview(); p; p = p->next_view()) {
				DBG_PRINT_MSG("sub view: %s", p->name().c_str());
			}
			DBG_PRINT_MSG("subs count: %d", win.subs_count());

			Dialog* dlg4 = new Dialog("Dialog4");
			DBG_SET_NAME(dlg4, "Dialog4");
			dlg4->MoveTo(50, 300);
			dlg4->Resize(200, 200);

			//win.AddFrame(dlg4);

			win.InsertSiblingBefore(dlg3, dlg4);
			win.InsertSiblingAfter(dlg2, dlg4);

			DBG_PRINT_MSG("subs count: %d", win.subs_count());
			for(AbstractView* p = win.first_subview(); p; p = p->next_view()) {
				DBG_PRINT_MSG("sub view: %s", p->name().c_str());
			}
			for(AbstractView* p = win.last_subview(); p; p = p->previous_view()) {
				DBG_PRINT_MSG("sub view: %s", p->name().c_str());
			}

		}
		*/

		win.Exec();
		Window::Terminate();
	}

	ASSERT_TRUE(true);
}

