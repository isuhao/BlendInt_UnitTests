#include "list-view-test-1.hpp"
#include <gui/list-view.hpp>
#include <gui/filesystem-model.hpp>
#include <gui/window.hpp>
#include <gui/dialog.hpp>
#include <gui/linear-layout.hpp>
#include <gui/string-list-model.hpp>

using namespace BlendInt;

ListViewTest1::ListViewTest1 ()
    : testing::Test()
{
  // TODO: add constructor code
}

ListViewTest1::~ListViewTest1 ()
{
  // TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(ListViewTest1, Foo1)
{
  if (Window::Initialize()) {

    Window win(640, 480, "ListView Test1");

    Dialog* dlg = new Dialog("Test ListView", new LinearLayout(Vertical),
                             Dialog::DialogButtonOK);

    ListView* list = new ListView;
    {
      RefPtr<StringListModel> model(new StringListModel);
      model->AddString("Row 0");
      model->AddString("Row 1");
      model->AddString("Row 2");

      list->SetModel(model);
    }

    dlg->AddWidget(list);

    dlg->Resize(dlg->GetPreferredSize());
    dlg->MoveTo((win.size().width() - dlg->size().width()) / 2,
                (win.size().height() - dlg->size().height()) / 2);

    win.AddFrame(dlg);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
