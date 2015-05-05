#include "managed-ptr-test-1.hpp"
#include <blendint/gui/window.hpp>
#include <blendint/gui/dialog.hpp>
#include <blendint/gui/managed-ptr.hpp>

using namespace BlendInt;

ManagedPtrTest1::ManagedPtrTest1()
    : testing::Test()
{
  // TODO: add constructor code
}

ManagedPtrTest1::~ManagedPtrTest1()
{
  // TODO: add destructor code
}

/**
 * test SetFocusedFrame()
 */
TEST_F(ManagedPtrTest1, reference_count)
{
  if(Window::Initialize()) {

    Window win(1280, 800, "AbstractWindow::SetFocusedFrame() Test");

    Dialog* dlg1 = new Dialog("Dialog1");
    DBG_SET_NAME(dlg1, "Dialog1");
    dlg1->MoveTo(50, 50);
    dlg1->Resize(200, 200);
    
    Dialog* dlg2 = new Dialog("Dialog2");
    DBG_SET_NAME(dlg2, "Dialog2");
    dlg2->MoveTo(300, 50);
    dlg2->Resize(200, 200);
    
    Dialog* dlg3 = new Dialog("Dialog3");
    DBG_SET_NAME(dlg3, "Dialog3");
    dlg3->MoveTo(550, 50);
    dlg3->Resize(200, 200);
    
    win.AddFrame(dlg1);
    win.AddFrame(dlg2);
    win.AddFrame(dlg3);

    // use managedptr:
    for(ManagedPtr p = win.GetFirstSubView(); p; ++p)
    {
      DBG_PRINT_MSG("reference count: %d", p->reference_count());
    }

    for(AbstractView* p = win.GetFirstSubView(); p; p = win.GetNextSubView(p))
    {
      DBG_PRINT_MSG("reference count: %d", p->reference_count());
    }

    for(ManagedPtr p = win.GetLastSubView(); p; --p)
    {
      DBG_PRINT_MSG("reference_count: %d", p->reference_count());
    }
    
    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
