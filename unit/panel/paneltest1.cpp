#include "PanelTest1.hpp"
#include <blendint/gui/panel.hpp>
#include <Common/UnitTestContext.hpp>
#include <blendint/gui/dialog.hpp>
#include <blendint/gui/push-button.hpp>
#include <blendint/gui/linear-layout.hpp>

using namespace BlendInt;

PanelTest1::PanelTest1()
: testing::Test()
{
	// TODO: add constructor code
}

PanelTest1::~PanelTest1()
{
	// TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(PanelTest1, Foo1)
{
	Init ();

    GLFWwindow* win = CreateWindow("Panel - Foo1", 1280, 800);
    UnitTestContext* context = Manage (new UnitTestContext);
	DBG_SET_NAME(context, "Context");
	SetContext(context);
	context->Resize(1280, 800);

    // TODO: add test code here

	Panel* p = Manage(new Panel);
	p->SetRoundType(RoundAll);
	p->SetRoundRadius(10.f);
	p->MoveTo(50, 50);

	Dialog* dialog = Manage(new Dialog);
	dialog->MoveTo(100, 100);
	dialog->Resize(600, 500);

	dialog->AddWidget(p);

	PushButton* btn1 = Manage(new PushButton("Button1"));
	PushButton* btn2 = Manage(new PushButton("Button2"));

	LinearLayout* layout = Manage(new LinearLayout);
	layout->AddWidget(btn1);
	layout->AddWidget(btn2);

	Panel* panel2 = Manage(new Panel);
	PushButton* btn3 = Manage(new PushButton("Button3"));
	btn3->MoveTo(20, 20);
	panel2->AddWidget(btn3);

	layout->AddWidget(panel2);

//	dialog->AddWidget(layout);
	p->SetLayout(layout);

	context->AddFrame(dialog);

	p->Resize(400, 300);

	DBG_PRINT_MSG("btn1: %d, %d", btn1->position().x(), btn1->position().y());

    RunLoop(win);
    Terminate();

	ASSERT_TRUE(true);
}
