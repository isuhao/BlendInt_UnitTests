#include "tab-test-1.hpp"
#include <blendint/gui/tab.hpp>
#include <blendint/gui/label.hpp>
#include <blendint/gui/push-button.hpp>
#include <blendint/gui/dialog.hpp>
#include <blendint/gui/window.hpp>

using namespace BlendInt;

TabTest1::TabTest1()
    : testing::Test()
{
  // TODO: add constructor code
}

TabTest1::~TabTest1()
{
  // TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(TabTest1, Foo1)
{
  if (Window::Initialize()) {

    Window win(640, 480, "TabButton Test1");

    Dialog* dlg = new Dialog("Test Dialog with title and buttons");

    Tab* tab = new Tab;
    tab->AddWidget("Tab1", new PushButton("Button1"));
    tab->AddWidget("Tab2", new PushButton("Button2"));

    dlg->AddWidget(tab);

    dlg->Resize(dlg->GetPreferredSize());
    dlg->MoveTo((win.size().width() - dlg->size().width()) / 2,
                (win.size().height() - dlg->size().height()) / 2);

    win.AddFrame(dlg);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
