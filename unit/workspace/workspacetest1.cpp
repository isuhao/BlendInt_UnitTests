#include "WorkspaceTest1.hpp"
#include <Common/UnitTestContext.hpp>
#include <Common/UnitTestCursor.hpp>
#include <blendint/gui/workspace.hpp>
#include <blendint/gui/viewport.hpp>
#include <blendint/gui/push-button.hpp>
#include <blendint/gui/toggle-button.hpp>
#include <blendint/gui/dialog.hpp>
#include <BlendInt/Stock/Cursor.hpp>
#include <blendint/gui/tool-button.hpp>

using namespace BlendInt;

WorkspaceTest1::WorkspaceTest1()
: testing::Test()
{
	// TODO: add constructor code
}

WorkspaceTest1::~WorkspaceTest1()
{
	// TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(WorkspaceTest1, Foo1)
{
	Init ();

    GLFWwindow* win = CreateWindow("Workspace - Foo1", 1280, 800);
	Context::cursor->RegisterCursorType (new UnitTestCursor(win));

    UnitTestContext* context = Manage (new UnitTestContext);
	DBG_SET_NAME(context, "Context");
	SetContext(context);
	context->Resize(1280, 800);
	
    // TODO: add test code here

	Workspace* workspace = Manage(new Workspace);
	workspace->Resize(1280, 800);

	Frame* left = Manage(new Frame(Vertical));
	ToggleButton* btn1 = Manage(new ToggleButton("Hello1"));
	ToggleButton* btn2 = Manage(new ToggleButton("Hello2"));
	ToggleButton* btn3 = Manage(new ToggleButton("Hello3"));
	left->AddWidget(btn1);
	left->AddWidget(btn2);
	left->AddWidget(btn3);

	Frame* right = Manage(new Frame(Vertical));
	ToggleButton* btn4 = Manage(new ToggleButton("Hello4"));
	ToggleButton* btn5 = Manage(new ToggleButton("Hello5"));
	ToggleButton* btn6 = Manage(new ToggleButton("Hello6"));
	right->AddWidget(btn4);
	right->AddWidget(btn5);
	right->AddWidget(btn6);

	Frame* header = Manage(new Frame(Horizontal));
	ToolButton* toolbtn1 = Manage(new ToolButton);
	ToolButton* toolbtn2 = Manage(new ToolButton);
	ToolButton* toolbtn3 = Manage(new ToolButton);
	header->AddWidget(toolbtn1);
	header->AddWidget(toolbtn2);
	header->AddWidget(toolbtn3);

	Viewport* view = Manage(new Viewport);

	workspace->SetLeftFrame(left);
	workspace->SetMainFrame(view);
	workspace->SetRightFrame(right);
	workspace->SetHeaderFrame(header);

	context->AddFrame(workspace);

	context->LinkResizeEvent(workspace);
    RunLoop(win);
    Terminate();

	ASSERT_TRUE(true);
}
