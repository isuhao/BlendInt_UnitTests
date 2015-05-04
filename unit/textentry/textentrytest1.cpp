#include "textentrytest1.hpp"
#include <blendint/gui/textentry.hpp>
#include <blendint/gui/label.hpp>
#include <blendint/gui/dialog.hpp>
#include <blendint/gui/window.hpp>

using namespace BlendInt;

TextEntryTest1::TextEntryTest1 ()
    : testing::Test()
{

}

TextEntryTest1::~TextEntryTest1 ()
{

}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(TextEntryTest1, Foo1)
{
  if (Window::Initialize()) {

    Window win(640, 480, "ButtonTest1");

    Dialog* dialog = new Dialog("TextEntry Test");

    TextEntry* lineedit = new TextEntry;
    lineedit->SetText("Hello World!");

    dialog->AddWidget(lineedit);

    win.AddFrame(dialog);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
