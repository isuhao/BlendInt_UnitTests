#include <gui/combo-box.hpp>
#include <gui/dialog.hpp>
#include <gui/window.hpp>

#include "combo-box-test-1.hpp"

using namespace BlendInt;

ComboBoxTest1::ComboBoxTest1 ()
    : testing::Test()
{
  // TODO: add constructor code
}

ComboBoxTest1::~ComboBoxTest1 ()
{
  // TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(ComboBoxTest1, Foo1)
{
  if (Window::Initialize()) {

    Window win(640, 480, "ComboBox Test1");

    Dialog* dialog = Manage(new Dialog("ComboBox Test"));

    ComboBox* combo = new ComboBox;

    dialog->AddWidget(combo);

    win.AddFrame(dialog);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
