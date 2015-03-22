#include <gui/splitter.hpp>
#include <gui/push-button.hpp>
#include <gui/window.hpp>
#include <gui/dialog.hpp>

#include "splitter-test-1.hpp"

using namespace BlendInt;

SplitterTest1::SplitterTest1 ()
    : testing::Test()
{
  // TODO: add constructor code
}

SplitterTest1::~SplitterTest1 ()
{
  // TODO: add destructor code
}

/**
 * test AddWidget() method
 *
 * Expected result: 
 */
TEST_F(SplitterTest1, AddWidget1)
{
  if (Window::Initialize()) {

    Window win(1280, 800, "Splitter Test1");

    Dialog* dialog1 = Manage(new Dialog("Vertical Splitter AddWidget() Test"));

    Splitter* splitter1 = Manage(new Splitter(Vertical));
    DBG_SET_NAME(splitter1, "Splitter 1");
    splitter1->Resize(450, 200);

    PushButton* btn1 = Manage(new PushButton("Button1"));
    PushButton* btn2 = Manage(new PushButton("Button2"));
    PushButton* btn3 = Manage(new PushButton("Button3"));

    splitter1->AddWidget(btn1);
    splitter1->AddWidget(btn2);
    splitter1->AddWidget(btn3);

    dialog1->AddWidget(splitter1);

    win.AddFrame(dialog1);

    Dialog* dialog2 = Manage(new Dialog("Horizontal Splitter Test"));

    Splitter* splitter2 = Manage(new Splitter(Horizontal));
    DBG_SET_NAME(splitter2, "Splitter 2");
    splitter2->Resize(450, 200);

    PushButton* btn4 = Manage(new PushButton("Button4"));
    PushButton* btn5 = Manage(new PushButton("Button5"));
    PushButton* btn6 = Manage(new PushButton("Button6"));

    splitter2->AddWidget(btn4);
    splitter2->AddWidget(btn5);
    splitter2->AddWidget(btn6);

    dialog2->AddWidget(splitter2);

    win.AddFrame(dialog2);

    dialog1->MoveTo(100, 200);

    dialog2->MoveTo(win.size().width() - 100 - dialog2->size().width(), 200);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}

/**
 * test AddWidget() method
 *
 * Expected result:
 */
TEST_F(SplitterTest1, InsertWidget1)
{
  if (Window::Initialize()) {

    Window win(1280, 800, "Splitter Test1");

    Dialog* dialog1 = Manage(new Dialog("Vertical Splitter InsertWidget() Test"));

    Splitter* splitter1 = Manage(new Splitter(Vertical));
    DBG_SET_NAME(splitter1, "Splitter 1");
    splitter1->Resize(450, 200);

    PushButton* btn1 = Manage(new PushButton("Button1"));
    PushButton* btn2 = Manage(new PushButton("Button2"));
    PushButton* btn3 = Manage(new PushButton("Button3"));

    splitter1->AddWidget(btn1);
    splitter1->AddWidget(btn2);
    splitter1->InsertWidget(1, btn3);

    dialog1->AddWidget(splitter1);

    win.AddFrame(dialog1);

    Dialog* dialog2 = Manage(new Dialog("Horizontal Splitter Test"));

    Splitter* splitter2 = Manage(new Splitter(Horizontal));
    DBG_SET_NAME(splitter2, "Splitter 2");
    splitter2->Resize(450, 200);

    PushButton* btn4 = Manage(new PushButton("Button4"));
    PushButton* btn5 = Manage(new PushButton("Button5"));
    PushButton* btn6 = Manage(new PushButton("Button6"));

    splitter2->AddWidget(btn4);
    splitter2->AddWidget(btn5);
    splitter2->InsertWidget(4, btn6);

    dialog2->AddWidget(splitter2);

    win.AddFrame(dialog2);

    dialog1->MoveTo(100, 200);

    dialog2->MoveTo(win.size().width() - 100 - dialog2->size().width(), 200);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
