#include "button-test-1.hpp"
#include <gui/button.hpp>
#include <gui/dialog.hpp>
#include <gui/window.hpp>

using namespace BlendInt;

ButtonTest1::ButtonTest1()
: testing::Test()
{
	// TODO: add constructor code
}

ButtonTest1::~ButtonTest1()
{
	// TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(ButtonTest1, Foo1)
{
	if(Window::Initialize()) {

		Window win(640, 480, "ButtonTest1");

		Dialog* dlg = new Dialog("ButtonTest1");
		win.AddFrame(dlg);

	    Button* bt1 = Manage(new Button(AbstractWindow::icons()->icon_16x16(0), "Hello World!"));
	    DBG_SET_NAME(bt1, "Button1");
	    bt1->MoveTo(200, 200);
	    bt1->SetText(String("Button1"));
	    bt1->Resize(bt1->GetPreferredSize());

	    dlg->AddWidget(bt1);

		win.Exec();
		Window::Terminate();
	}

	ASSERT_TRUE(true);
}

/**
 * test Foo() method
 *
 * Expected result:
 */
TEST_F(ButtonTest1, SetIcon1)
{
	if(Window::Initialize()) {

		Window win(640, 480, "ButtonTest1");

		Dialog* dlg = new Dialog("ButtonTest1");
		win.AddFrame(dlg);

		Button* bt1 = Manage(new Button(AbstractWindow::icons()->icon_16x16(0), "Hello World!"));
		DBG_SET_NAME(bt1, "Button1");
		//bt1->SetIcon(AbstractWindow::icons()->icon_16x16(0));
		bt1->MoveTo(200, 200);

		Size prefer = bt1->GetPreferredSize();

		DBG_PRINT_MSG("Preferred size: %d, %d", prefer.width(), prefer.height());

		bt1->Resize(120, 40);

		dlg->AddWidget(bt1);

		Button* bt2 = Manage(new Button("Hello World!"));
		DBG_SET_NAME(bt2, "Button2");
		//bt1->SetIcon(AbstractWindow::icons()->icon_16x16(0));
		bt2->MoveTo(400, 200);

		bt2->Resize(120, 40);

		dlg->AddWidget(bt2);

		Button* bt3 = Manage(new Button(AbstractWindow::icons()->icon_16x16(0), "Hello World!"));
		DBG_SET_NAME(bt3, "Button3");
		bt3->MoveTo(200, 100);
		bt3->Resize(120, 40);
		bt3->SetRoundType(RoundNone);

		dlg->AddWidget(bt3);

		Button* bt4 = Manage(new Button(AbstractWindow::icons()->icon_16x16(0), "Hello World!"));
		DBG_SET_NAME(bt4, "Button4");
		bt4->MoveTo(400, 100);
		bt4->Resize(120, 40);
		bt4->SetRoundRadius(10.f);

		dlg->AddWidget(bt4);

		win.Exec();
		Window::Terminate();
	}

	ASSERT_TRUE(true);
}

/**
 * test Foo() method
 *
 * Expected result:
 */
TEST_F(ButtonTest1, PreferSizing1)
{
	if (Window::Initialize()) {

		Window win(640, 480, "UI Editor");

		Dialog* frame = Manage(new Dialog("ButtonTest1"));
		frame->Resize(640, 480);

		win.AddFrame(frame);

		Button* bt1 = Manage(
		        new Button(AbstractWindow::icons()->icon_16x16(0),
		                "Hello World!"));
		DBG_SET_NAME(bt1, "Button1");
		//bt1->SetIcon(AbstractWindow::icons()->icon_16x16(0));
		bt1->MoveTo(200, 200);

		Size prefer = bt1->GetPreferredSize();

		DBG_PRINT_MSG("Preferred size: %d, %d", prefer.width(),
		        prefer.height());

		bt1->Resize(bt1->GetPreferredSize());

		frame->AddWidget(bt1);

		Button* bt2 = Manage(new Button("Hello World!"));
		DBG_SET_NAME(bt2, "Button2");
		//bt1->SetIcon(AbstractWindow::icons()->icon_16x16(0));
		bt2->MoveTo(400, 200);

		bt2->Resize(bt2->GetPreferredSize());

		frame->AddWidget(bt2);

		Button* bt3 = Manage(
		        new Button(AbstractWindow::icons()->icon_16x16(0),
		                "Hello World!"));
		DBG_SET_NAME(bt3, "Button3");
		bt3->MoveTo(200, 100);
		bt3->Resize(bt3->GetPreferredSize());
		bt3->SetRoundType(RoundNone);

		frame->AddWidget(bt3);

		Button* bt4 = Manage(
		        new Button(AbstractWindow::icons()->icon_16x16(0),
		                "Hello World!"));
		DBG_SET_NAME(bt4, "Button4");
		bt4->MoveTo(400, 100);
		bt4->Resize(bt4->GetPreferredSize());
		bt4->SetRoundRadius(10.f);

		frame->AddWidget(bt4);

		win.Exec();
		Window::Terminate();
	}

	ASSERT_TRUE(true);
}

/**
 * test Foo() method
 *
 * Expected result:
 */
TEST_F(ButtonTest1, PreferSizing2) {
	if (Window::Initialize()) {

		Window win(640, 480, "UI Editor");

		Dialog* frame = Manage(new Dialog("ButtonTest1"));
		frame->Resize(640, 480);

		win.AddFrame(frame);

		Button* bt1 = Manage(
		        new Button(AbstractWindow::icons()->icon_16x16(0), String()));
		DBG_SET_NAME(bt1, "Button1");
		//bt1->SetIcon(AbstractWindow::icons()->icon_16x16(0));
		bt1->MoveTo(200, 200);

		Size prefer = bt1->GetPreferredSize();

		DBG_PRINT_MSG("Preferred size: %d, %d", prefer.width(),
		        prefer.height());

		bt1->Resize(bt1->GetPreferredSize());

		frame->AddWidget(bt1);

		Button* bt2 = Manage(
		        new Button(AbstractWindow::icons()->icon_16x16(0), String()));
		DBG_SET_NAME(bt2, "Button2");
		bt2->MoveTo(300, 200);
		bt2->SetRoundType(RoundNone);

		Size prefer2 = bt2->GetPreferredSize();

		DBG_PRINT_MSG("Preferred size: %d, %d", prefer2.width(),
		        prefer2.height());

		bt2->Resize(bt2->GetPreferredSize());

		frame->AddWidget(bt2);

		win.Exec();
		Window::Terminate();
	}

	ASSERT_TRUE(true);
}

