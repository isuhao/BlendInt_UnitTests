#include "ToolBoxTest1.hpp"
#include <gui/frame.hpp>
#include <gui/push-button.hpp>
#include <gui/window.hpp>
#include <Common/UnitTestContext.hpp>

using namespace BlendInt;

ToolBoxTest1::ToolBoxTest1()
: testing::Test()
{
	// TODO: add constructor code
}

ToolBoxTest1::~ToolBoxTest1()
{
	// TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(ToolBoxTest1, Foo1)
{
	Init ();

    GLFWwindow* win = CreateWindow("Frame - Foo1", 1280, 800);

    // TODO: add test code here
    UnitTestContext* context = Manage (new UnitTestContext);
	DBG_SET_NAME(context, "Context");
	SetContext(context);
	context->Resize(1280, 800);

    Frame* tb1 = Manage(new Frame(Vertical));
    DBG_SET_NAME(tb1, "ToolBox1");
    tb1->MoveTo(200, 200);

//    Frame* tb2 = Manage(new Frame(Vertical));
//    tb2->SetPosition(700, 100);

    context->AddFrame(tb1);
//    context->AddFrame(tb2);

    PushButton* btn1 = Manage(new PushButton("Hello, World!"));
    DBG_SET_NAME(btn1, "Button1");
    btn1->Resize(200, 50);
    //PushButton* btn2 = Manage(new PushButton("Hello2"));
    //PushButton* btn3 = Manage(new PushButton("Hello3"));
//    PushButton* btn4 = Manage(new PushButton("Hello4"));
//    PushButton* btn5 = Manage(new PushButton("Hello5"));
//    PushButton* btn6 = Manage(new PushButton("Hello6"));

    tb1->AddWidget(btn1);
    //tb1->AddWidget(btn2);
    //tb1->AddWidget(btn3);

//    tb2->Add(btn4);
//    tb2->Add(btn5);
//    tb2->Add(btn6);

    tb1->RequestRedraw();

    RunLoop(win);
    Terminate();

	ASSERT_TRUE(true);
}
