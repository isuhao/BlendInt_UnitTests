/*
 * VLayoutTest1.cpp
 *
 *  Created on: 2013��12��7��
 *      Author: zhanggy
 */

#include "VLayoutTest1.hpp"
#include <BlendInt/Interface.hpp>
#include <BlendInt/Gui/VLayout.hpp>
#include <blendint/gui/linear-layout.hpp>
#include <blendint/gui/abstract-round-widget.hpp>

using namespace BlendInt;

VLayoutTest1::VLayoutTest1()
: testing::Test()
{
	// TODO Auto-generated constructor stub

}

VLayoutTest1::~VLayoutTest1() {
	// TODO Auto-generated destructor stub
}

// test default Add() method
TEST_F(VLayoutTest1, Add1)
{
	Init ();
	GLFWwindow* window = CreateWindow("Vertical Layout Test", 640, 480);

	// add test code here
	Context* context = Manage(new Context);
#ifdef DEBUG
	context->set_name("Context");
#endif
	Interface::instance->SetCurrentContext(context);

	VLayout* vlayout = Manage(new VLayout);

	vlayout->SetPosition(100, 100);

	AbstractRoundWidget* widget1 = Manage(new AbstractRoundWidget);
	AbstractRoundWidget* widget2 = Manage(new AbstractRoundWidget);
	AbstractRoundWidget* widget3 = Manage(new AbstractRoundWidget);

	LinearLayout* hlayout = Manage(new LinearLayout);
	hlayout->Append(widget2);
	hlayout->Append(widget3);

	vlayout->Append(widget1);
	vlayout->Append(hlayout);

	context->Append(vlayout);

	RunLoop(window);

	Terminate();

	ASSERT_TRUE(true);
}
