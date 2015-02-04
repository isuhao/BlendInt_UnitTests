#include "TextEntryTest1.hpp"
#include <BlendInt/Gui/TextEntry.hpp>
#include <BlendInt/Gui/Label.hpp>
#include <BlendInt/Gui/Dialog.hpp>
#include <BlendInt/Gui/Window.hpp>

using namespace BlendInt;

TextEntryTest1::TextEntryTest1()
: testing::Test()
{

}

TextEntryTest1::~TextEntryTest1()
{

}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(TextEntryTest1, Foo1)
{
    if(Window::Initialize()) {
        
        Window win(640, 480, "ButtonTest1");

        Dialog* dialog = Manage(new Dialog("TextEntry Test"));

        TextEntry* lineedit = Manage(new TextEntry);
        lineedit->SetText("Hello World!");

        dialog->AddWidget(lineedit);

        win.AddFrame(dialog);

        win.Exec();
        Window::Terminate();
    }

	ASSERT_TRUE(true);
}
