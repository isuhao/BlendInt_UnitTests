#include "tab-button-test-1.hpp"
#include <blendint/gui/tab-button.hpp>
#include <blendint/gui/window.hpp>
#include <blendint/gui/dialog.hpp>
#include <blendint/gui/tab-header.hpp>

using namespace BlendInt;

TabButtonTest1::TabButtonTest1()
    : testing::Test()
{
  // TODO: add constructor code
}

TabButtonTest1::~TabButtonTest1()
{
  // TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(TabButtonTest1, Foo1)
{
  if (Window::Initialize()) {

    Window win(640, 480, "TabButton Test1");

    Dialog* dlg = new Dialog("Test Dialog with title and buttons");

    dlg->Resize(dlg->GetPreferredSize());
    dlg->MoveTo((win.size().width() - dlg->size().width()) / 2,
                (win.size().height() - dlg->size().height()) / 2);

    dlg->AddWidget(new TabButton("Tab Button"));

    TabHeader* header = new TabHeader;
    header->AddButton (new TabButton("Button1"));
    header->AddButton (new TabButton("Button2"));
    dlg->AddWidget(header);

    win.AddFrame(dlg);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
