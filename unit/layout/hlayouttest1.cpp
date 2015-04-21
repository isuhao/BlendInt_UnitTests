#include "HLayoutTest1.hpp"

#include <BlendInt/Interface.hpp>
#include <blendint/gui/linear-layout.hpp>
#include <BlendInt/Gui/VLayout.hpp>
#include <blendint/gui/abstract-round-widget.hpp>

#include <boost/smart_ptr.hpp>

using namespace BlendInt;

// test the default Add() method
TEST_F(HLayoutTest1, Mix1)
{
	Init();
	GLFWwindow* window = CreateWindow("Mix Layout Test 1", 640, 480);

	// add test code here
	Context* context = Manage(new Context);
#ifdef DEBUG
	context->set_name("Context");
#endif
	Interface::instance->SetCurrentContext(context);

	LinearLayout* hlayout = Manage(new LinearLayout);
	hlayout->SetPosition(100, 100);

	AbstractRoundWidget* widget1 = Manage(new AbstractRoundWidget);
	AbstractRoundWidget* widget2 = Manage(new AbstractRoundWidget);
	AbstractRoundWidget* widget3 = Manage(new AbstractRoundWidget);

	VLayout* vlayout = Manage(new VLayout);
	vlayout->Append(widget2);
	vlayout->Append(widget3);

	hlayout->Append(widget1);
	hlayout->Append(vlayout);

	context->Append(hlayout);

	RunLoop(window);

	Terminate();

	ASSERT_TRUE(true);
}
