#include "BlockTest1.hpp"
#include <Common/UnitTestContext.hpp>
#include <gui/block.hpp>
#include <gui/dialog.hpp>
#include <gui/push-button.hpp>

using namespace BlendInt;

BlockTest1::BlockTest1()
: testing::Test()
{
	// TODO: add constructor code
}

BlockTest1::~BlockTest1()
{
	// TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(BlockTest1, Foo1)
{
	Init ();

    GLFWwindow* win = CreateWindow("Block - Foo1", 640, 480);

    UnitTestContext* context = Manage (new UnitTestContext);
	SetContext(context);
	context->Resize(640, 480);
	
    // TODO: add test code here

	PushButton* btn1 = Manage(new PushButton("Hello1"));
	PushButton* btn2 = Manage(new PushButton("Hello2"));
	PushButton* btn3 = Manage(new PushButton("Hello3"));

	Block* block = Manage(new Block(Vertical));
	block->AddWidget(btn1);
	block->AddWidget(btn2);
	block->AddWidget(btn3);
	block->Resize(100, 150);
	block->MoveTo(50, 50);

	Dialog* dialog = Manage(new Dialog);
	dialog->AddWidget(block);

	context->AddFrame(dialog);

    RunLoop(win);
    Terminate();

	ASSERT_TRUE(true);
}
