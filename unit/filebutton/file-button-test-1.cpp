#include "file-button-test-1.hpp"
#include <blendint/gui/filebutton.hpp>
#include <blendint/gui/dialog.hpp>
#include <blendint/gui/window.hpp>

using namespace BlendInt;

FileButtonTest1::FileButtonTest1()
    : testing::Test()
{
  // TODO: add constructor code
}

FileButtonTest1::~FileButtonTest1()
{
  // TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(FileButtonTest1, Foo1)
{
  if (Window::Initialize()) {

    Window win(640, 480, "FileButton Test1");

    Dialog* dlg = new Dialog("Test Dialog with title and buttons");

    dlg->Resize(dlg->GetPreferredSize());
    dlg->MoveTo((win.size().width() - dlg->size().width()) / 2,
                (win.size().height() - dlg->size().height()) / 2);

    win.AddFrame(dlg);

    FileButton* btn = new FileButton;
    btn->MoveTo(100, 100);
    dlg->AddWidget(btn);
    
    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
