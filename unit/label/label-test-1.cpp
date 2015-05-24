#include <blendint/gui/window.hpp>
#include <blendint/gui/linear-layout.hpp>
#include <blendint/gui/frame.hpp>
#include <blendint/gui/label.hpp>

#include "label-test-1.hpp"

using namespace BlendInt;

LabelTest1::LabelTest1()
    : testing::Test()
{
  // TODO: add constructor code
}

LabelTest1::~LabelTest1()
{
  // TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(LabelTest1, Resize1)
{
  if (Window::Initialize()) {

    Window win(640, 480, "Label Test -- Resize1");

    Frame* frame = new Frame(new LinearLayout);

    frame->Resize(500, 400);
    frame->MoveTo((win.size().width() - frame->size().width()) / 2,
                  (win.size().height() - frame->size().height()) / 2);

    // Font my_font ("Droid Sans", 24);

    Label* label1 = new Label("Hello, World1!");
    label1->SetText("3D Mesh is loaded");
    // label1->SetFont(my_font);
    label1->SetForeground(Color(0xF0B0E0EF));
    label1->SetBackground(Color(0x101010A0));
    label1->Resize(label1->GetPreferredSize());
    label1->Resize(300, 40);
    //label1->MoveTo(200, 200);

    frame->AddWidget(label1);

    win.AddFrame(frame);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(LabelTest1, Font1)
{

  if (Window::Initialize()) {

    Window win(640, 480, "Label Test -- Set Font 1");

    Frame* frame = new Frame(new LinearLayout);

    frame->Resize(500, 400);
    frame->MoveTo((win.size().width() - frame->size().width()) / 2,
                  (win.size().height() - frame->size().height()) / 2);


    //Font my_font ("Droid Sans", 24);
    //Font my_shadow_font ("Droid Sans", 24);
    //my_shadow_font.SetShadow(true, 2.5f, -2.f);

    Label* label1 = new Label("Hello, World1!");
    label1->SetText("3D Mesh is loaded");
    //label1->SetFont(my_font);
    label1->SetForeground(Color(0xF0B0E0EF));
    label1->SetBackground(Color(0x101010A0));
    label1->Resize(label1->GetPreferredSize());
    //	label1->Resize(300, 200);
    // label1->MoveTo(200, 200);

    Label* label2 = new Label("Hello, World2!");
    //label2->SetFont(my_shadow_font);
    label2->SetBackground(Color(0xAF60E0BF));
    label2->Resize(label2->GetPreferredSize());
    // label2->MoveTo(200, 100);

    label1->Resize(label1->GetPreferredSize());

    frame->AddWidget(label1);
    frame->AddWidget(label2);
    
    win.AddFrame(frame);

    win.Exec();
    Window::Terminate();
  }

  ASSERT_TRUE(true);
}
