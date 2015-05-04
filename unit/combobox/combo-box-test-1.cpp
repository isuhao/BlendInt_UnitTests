#include <blendint/gui/combo-box.hpp>
#include <blendint/gui/frame.hpp>
#include <blendint/gui/linear-layout.hpp>
#include <blendint/gui/window.hpp>

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

    Frame* frame = new Frame(new LinearLayout(Vertical));

    ComboBox* combo = new ComboBox;

    {
      RefPtr<ComboListModel> model(new ComboListModel);
      ModelIndex root = model->GetRootIndex();

      model->InsertColumns(0, 2, root);
      model->InsertRows(1, 1, root);
      model->InsertRows(2, 1, root);

      ModelIndex index = root.GetChildIndex(0, 0);
      ModelIndex next;

      model->SetIcon(index,
                     AbstractWindow::icons()->icon_16x16(Icons::IMAGE_RGB));
      next = index.GetRightIndex();
      model->SetText(next, RefPtr<Text>(new Text("Combo List Row 0")));

      index = index.GetDownIndex();
      model->SetIcon(
          index, AbstractWindow::icons()->icon_16x16(Icons::IMAGE_RGB_ALPHA));
      next = index.GetRightIndex();
      model->SetText(next, RefPtr<Text>(new Text("Combo List Row 1")));

      index = index.GetDownIndex();
      model->SetIcon(index,
                     AbstractWindow::icons()->icon_16x16(Icons::IMAGE_DATA));
      next = index.GetRightIndex();
      model->SetText(next, RefPtr<Text>(new Text("Combo List Row 2")));

      combo->SetModel(model);
      combo->SetCurrentIndex(2);
    }

    frame->AddWidget(combo);

    win.AddFrame(frame);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
