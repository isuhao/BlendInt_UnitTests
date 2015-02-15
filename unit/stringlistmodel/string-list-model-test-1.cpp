#include "string-list-model-test-1.hpp"
#include <gui/string-list-model.hpp>
#include <gui/window.hpp>

using namespace BlendInt;

StringListModelTest1::StringListModelTest1()
: testing::Test()
{
	// TODO: add constructor code
}

StringListModelTest1::~StringListModelTest1()
{
	// TODO: add destructor code
}

/**
 * test StringListModel::InsertRows() method
 *
 * Expected result: 
 */
TEST_F(StringListModelTest1, Insert1)
{
	bool result = true;

	if(Window::Initialize()) {

		Window win(640, 480, "StringListModel Test: Insert1");

		{
			StringListModel model;
			ModelIndex index = model.GetRootIndex();

			for(int i = 0; i < 10; i++) {
				model.AddString("String");
			}
			// model.InsertRows(0, 5, index);
			// model.InsertRows(8, 5, index);

			model.Print();
			result = model.GetRowCount() == 10;
		}

		win.Exec();
		Window::Terminate();
	}

	ASSERT_TRUE(result);
}

/**
 * test StringListModel::RemoveRows() method
 *
 * Expected result: 
 */
TEST_F(StringListModelTest1, Remove1)
{
	bool result = true;

	if(Window::Initialize()) {

		Window win(640, 480, "StringListModel Test: Remove1");

//		{
//			StringListModel model;
//
//			ModelIndex index = model.GetRootIndex();
//
//			model.InsertRows(0, 5, index);
//
//			model.Print();
//
//			model.RemoveRows(2, 2, index);
//
//			model.Print();
//
//			result = model.GetRowCount() == 3;
//		}

		win.Exec();
		Window::Terminate();
	}

	ASSERT_TRUE(result);
}
