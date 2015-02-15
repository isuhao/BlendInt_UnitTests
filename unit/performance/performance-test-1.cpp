#include "performance-test-1.hpp"

#include <gui/button.hpp>
#include <gui/label.hpp>
#include <gui/linear-layout.hpp>
#include <gui/abstract-round-frame.hpp>
#include <gui/toolbox.hpp>
#include <gui/dialog.hpp>
#include <gui/window.hpp>

using namespace BlendInt;

PerformanceTest1::PerformanceTest1()
: testing::Test()
{
	// TODO: add constructor code
}

PerformanceTest1::~PerformanceTest1()
{
	// TODO: add destructor code
}

/**
 * Test layout performance
 */
TEST_F(PerformanceTest1, Layout1)
{
	if(Window::Initialize()) {

		Window win(1280, 800, "Clock Test");

		Dialog* dlg = Manage(new Dialog("Performance Test 1"));
		dlg->Resize(800, 720);

		int max_x = 20;
		int max_y = 20;

		//int x_pos = 50;
		//int y_pos = 5;
		for(int i = 0; i < max_y; i++)
		{
			LinearLayout* layout = Manage(new LinearLayout);

			for(int j = 0; j < max_x; j++)
			{
				Button* btn = Manage(new Button);
				//btn[j]->SetPreferredSize(25, btn[j]->size().height());
				layout->AddWidget(btn);
			}

			//layout[i]->MoveTo(x_pos, y_pos);
			//layout[i]->Resize(layout[i]->GetPreferredSize());

			//y_pos += 40;

			dlg->AddWidget(layout);
		}

		dlg->Resize(dlg->GetPreferredSize());

		win.AddFrame(dlg);

		win.Exec();
		Window::Terminate();
	}

    ASSERT_TRUE(true);
}


/**
 * Test layout performance
 */
/*
TEST_F(PerformanceTest1, Layout2)
{
    Init();
    GLFWwindow* win = CreateWindow("Button Test - Foo1", 1280, 800);

	// TODO: add test code here
    UnitTestContext* context = Manage (new UnitTestContext);
	DBG_SET_NAME(context, "Context");
	SetContext(context);
	context->Resize(1280, 800);

    LinearLayout* layout2 = Manage(new LinearLayout(Vertical));

    Dialog* frame2 = Manage(new Dialog);

    int max_x = 20;
    int max_y = 20;

    for(int i = 0; i < max_y; i++)
    {
    	LinearLayout* layout = Manage(new LinearLayout);

        for(int j = 0; j < max_x; j++)
        {
        	Button* btn = Manage(new Button);
            //btn[j]->SetPreferredSize(25, btn[j]->size().height());
        	layout->AddWidget(btn);
        }

        layout2->AddWidget(layout);
    }

    frame2->SetLayout(layout2);
    frame2->Resize(800, 720);

    context->AddFrame(frame2);

    RunLoop(win);
    Terminate();

    ASSERT_TRUE(true);
}
*/

/**
 * Test layout performance
 */
/*
TEST_F(PerformanceTest1, Layout3)
{
    Init();
    GLFWwindow* win = CreateWindow("Button Test - Foo1", 1280, 800);

	// TODO: add test code here
    UnitTestContext* context = Manage (new UnitTestContext);
	DBG_SET_NAME(context, "Context");
	SetContext(context);
	context->Resize(1280, 800);

    StaticPanel* mainframe = Manage(new StaticPanel);

    StaticPanel* frame1 = Manage(new StaticPanel);
    StaticPanel* frame2 = Manage(new StaticPanel);
    StaticPanel* frame3 = Manage(new StaticPanel);

    mainframe->MoveTo(100, 100);

    int max_x = 10;
    int max_y = 10;

    LinearLayout* layout1 = Manage(new LinearLayout(Vertical));
    for(int i = 0; i < max_y; i++)
    {
    	LinearLayout* layout = Manage(new LinearLayout);

        for(int j = 0; j < max_x; j++)
        {
        	Button* btn = Manage(new Button);
            //btn[j]->SetPreferredSize(25, btn[j]->size().height());
        	layout->Append(btn);
        }

        layout1->Append(layout);
    }

    frame1->Setup(layout1);
    frame1->Resize(frame1->GetPreferredSize());

    LinearLayout* layout2 = Manage(new LinearLayout(Vertical));
    for(int i = 0; i < max_y; i++)
    {
    	LinearLayout* layout = Manage(new LinearLayout);

        for(int j = 0; j < max_x; j++)
        {
        	Button* btn = Manage(new Button);
            //btn[j]->SetPreferredSize(25, btn[j]->size().height());
        	layout->Append(btn);
        }

        layout2->Append(layout);
    }

    frame2->Setup(layout2);
    frame2->Resize(frame2->GetPreferredSize());

    LinearLayout* layout3 = Manage(new LinearLayout(Vertical));
    for(int i = 0; i < max_y; i++)
    {
    	LinearLayout* layout = Manage(new LinearLayout);

        for(int j = 0; j < max_x; j++)
        {
        	Button* btn = Manage(new Button);
            //btn[j]->SetPreferredSize(25, btn[j]->size().height());
        	layout->Append(btn);
        }

        layout3->Append(layout);
    }

    frame3->Setup(layout3);
    frame3->Resize(frame3->GetPreferredSize());

    LinearLayout* mainlayout = Manage(new LinearLayout);

    mainlayout->Append(layout1);
    mainlayout->Append(layout2);
    mainlayout->Append(layout3);

    mainframe->Setup(mainlayout);
    mainframe->Resize(mainframe->GetPreferredSize());

    context->Append(mainframe);

    RunLoop(win);
    Terminate();

    ASSERT_TRUE(true);
}
*/

/**
 * test Foo() method
 *
 * Expected result: 
 */
/*
TEST_F(PerformanceTest1, Foo1)
{
	Init ();
	GLFWwindow* window = CreateWindow("Performance - Foo1");

	// TODO: add test code here

    int max = 800;
    Button* btn[max];
    int x_pos = 0;
    int y_pos = 0;
    for(int i = 0, j = 1; i < max; i++, j++)
    {
        btn[i] = new Button;
        btn[i]->MoveTo(x_pos, y_pos);
        btn[i]->Resize(48, 24);
        btn[i]->Register();

        x_pos += 50;
        if(j % 25 == 0) {
            x_pos = 0;
            y_pos += 25;
        }
    }

	RunLoop(window);

	Terminate();

	ASSERT_TRUE(true);
}
*/

/*
TEST_F(PerformanceTest1, Performance2)
{
	Init ();
	GLFWwindow* window = CreateWindow("Performance - 2");

	// TODO: add test code here

    int max = 800;
    Widget* label[max];
    int x_pos = 0;
    int y_pos = 0;
    for(int i = 0, j = 1; i < max; i++, j++)
    {
        label[i] = new Widget;
        label[i]->MoveTo(x_pos, y_pos);
        label[i]->Resize(48, 24);
        label[i]->Register();

        x_pos += 50;
        if(j % 25 == 0) {
            x_pos = 0;
            y_pos += 25;
        }
    }

	RunLoop(window);

	Terminate();

	ASSERT_TRUE(true);
}
*/
