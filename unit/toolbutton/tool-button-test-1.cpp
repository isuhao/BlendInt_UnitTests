#include <gui/tool-button.hpp>
#include <gui/window.hpp>
#include <gui/dialog.hpp>
#include <gui/linear-layout.hpp>

#include "tool-button-test-1.hpp"

using namespace BlendInt;

ToolButtonTest1::ToolButtonTest1 ()
    : testing::Test()
{
  // TODO: add constructor code
}

ToolButtonTest1::~ToolButtonTest1 ()
{
  // TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(ToolButtonTest1, Foo1)
{
  if (Window::Initialize()) {

    Window win(640, 480, "DialogTest1");

    Dialog* dlg = new Dialog("Test ToolButton", new LinearLayout(Vertical));

    ToolButton * btn = new ToolButton();
    {
      RefPtr<Action> action(
          new Action(Window::icons()->icon_32x32(Icons::IMAGE_RGB_ALPHA),
                     "ToolButton Example"));
      btn->SetAction(action);
    }

    dlg->AddWidget(btn);

    dlg->Resize(dlg->GetPreferredSize());
    dlg->MoveTo((win.size().width() - dlg->size().width()) / 2,
                (win.size().height() - dlg->size().height()) / 2);

    win.AddFrame(dlg);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
