#include <gui/splitter.hpp>
#include <gui/button.hpp>
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
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(SplitterTest1, Foo1)
{
  if (Window::Initialize()) {

    Window win(1280, 800, "Splitter Test1");

    Dialog* dialog1 = Manage(new Dialog("Vertical Splitter Test"));

    Splitter* splitter1 = Manage(new Splitter(Vertical));
    DBG_SET_NAME(splitter1, "Splitter 1");
    splitter1->Resize(450, 200);

    Button* btn1 = Manage(new Button("Button1"));
    Button* btn2 = Manage(new Button("Button2"));
    Button* btn3 = Manage(new Button("Button3"));

    splitter1->AddWidget(btn1);
    splitter1->AddWidget(btn2);
    splitter1->AddWidget(btn3);

    dialog1->AddWidget(splitter1);

    win.AddFrame(dialog1);

    Dialog* dialog2 = Manage(new Dialog("Horizontal Splitter Test"));

    Splitter* splitter2 = Manage(new Splitter(Horizontal));
    DBG_SET_NAME(splitter2, "Splitter 2");
    splitter2->Resize(450, 200);

    Button* btn4 = Manage(new Button("Button4"));
    Button* btn5 = Manage(new Button("Button5"));
    Button* btn6 = Manage(new Button("Button6"));

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
