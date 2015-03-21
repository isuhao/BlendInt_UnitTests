#include <gui/frame-splitter.hpp>
#include <gui/model-viewport.hpp>

#include <gui/frame.hpp>
#include <gui/push-button.hpp>
#include <gui/linear-layout.hpp>
#include <gui/window.hpp>

#include "frame-splitter-test-1.hpp"

using namespace BlendInt;

FrameSplitterTest1::FrameSplitterTest1()
: testing::Test()
{
	// TODO: add constructor code
}

FrameSplitterTest1::~FrameSplitterTest1()
{
	// TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
/*
TEST_F(FrameSplitterTest1, AddFrame1)
{
	Init ();

    GLFWwindow* win = CreateWindow("FrameSplitter - Foo1", 1280, 800);

    // TODO: add test code here
    UnitTestContext* context = Manage (new UnitTestContext);
	DBG_SET_NAME(context, "Context");
	SetContext(context);
	context->Resize(1280, 800);

	FrameSplitter* fs = Manage(new FrameSplitter(Vertical));
	DBG_SET_NAME(fs, "FrameSplitter");
	fs->MoveTo(20, 20);
	fs->Resize(1240, 760);

	Viewport* f1 = Manage(new Viewport);
	DBG_SET_NAME(f1, "Frame1");
	Frame* f2 = Manage(new Frame);
	DBG_SET_NAME(f2, "Frame2");
	f2->Resize(240, 100);

	fs->AddFrame(f1);
	fs->AddFrame(f2, PreferredHeight);

	context->AddFrame(fs);

	//Viewport* f3 = Manage(new Viewport);
	//DBG_SET_NAME(f3, "Frame3");

//	Frame* f3 = Manage(new Frame(Horizontal));
//	DBG_SET_NAME(f3, "Frame3");
//
//	PushButton* btn1 = Manage(new PushButton("Hello"));
//	DBG_SET_NAME(btn1, "Button1");
//	f3->AddWidget(btn1);
//	PushButton* btn2 = Manage(new PushButton("Hello"));
//	DBG_SET_NAME(btn2, "Button2");
//	f3->AddWidget(btn2);
//
//	fs->AddFrame(f1);
//	fs->AddFrame(f2);
//
//	FrameSplitter* vsplitter = Manage(new FrameSplitter(Vertical));
//	vsplitter->SetPosition(100, 100);
//	vsplitter->Resize(1000, 700);
//
//	vsplitter->AddFrame(f3);
//	vsplitter->AddFrame(fs);
//
//	context->AddFrame(vsplitter);
//
//	vsplitter->SetPosition(20, 20);
//	vsplitter->Resize(1240, 760);

    RunLoop(win);
    Terminate();

	ASSERT_TRUE(true);
}
*/

/**
 * test Foo() method
 *
 * Expected result:
 */
/*
TEST_F(FrameSplitterTest1, GetFrame1)
{
	Init ();

    GLFWwindow* win = CreateWindow("FrameSplitter - Foo1", 1280, 800);

    // TODO: add test code here
    UnitTestContext* context = Manage (new UnitTestContext);
	DBG_SET_NAME(context, "Context");
	SetContext(context);
	context->Resize(1280, 800);

	FrameSplitter* fs = Manage(new FrameSplitter(Horizontal));
	DBG_SET_NAME(fs, "FrameSplitter");
	fs->MoveTo(20, 20);
	fs->Resize(1240, 760);

	Viewport* f1 = Manage(new Viewport);
	DBG_SET_NAME(f1, "Frame1");
	Frame* f2 = Manage(new Frame);
	DBG_SET_NAME(f2, "Frame2");
	f2->Resize(240, 100);

	fs->AddFrame(f1);
	fs->AddFrame(f2);

	Frame* frame1 = fs->GetFrame(0);
	Frame* frame2 = fs->GetFrame(1);

	Frame* frame0 = fs->GetFrame(2);

	context->AddFrame(fs);

    RunLoop(win);
    Terminate();

	ASSERT_TRUE((frame1 == f1) && (frame2 == f2) && (frame0 == 0));
}
*/

/**
 * test Foo() method
 *
 * Expected result:
 */
TEST_F(FrameSplitterTest1, InsertFrame1)
{
  if(Window::Initialize()) {

    Window win(1280, 800, "InsertFrame1");

    FrameSplitter* fs = Manage(new FrameSplitter(Horizontal));
    DBG_SET_NAME(fs, "FrameSplitter");
    fs->MoveTo(20, 20);
    fs->Resize(1240, 760);

    ModelViewport* f1 = Manage(new ModelViewport);
    DBG_SET_NAME(f1, "Frame1");
    ModelViewport* f2 = Manage(new ModelViewport);
    DBG_SET_NAME(f2, "Frame2");
    f2->Resize(240, 100);

    fs->InsertFrame(0, f1);
    fs->InsertFrame(0, f2);

    win.AddFrame(fs);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
