#include "list-model-test-1.hpp"
#include <gui/abstract-list-model.hpp>
#include <gui/window.hpp>

using namespace BlendInt;

ListModelTest1::ListModelTest1()
: testing::Test()
{
	// TODO: add constructor code
}

ListModelTest1::~ListModelTest1()
{
	// TODO: add destructor code
}

ListModel::ListModel()
: AbstractListModel(),
  rows_(0),
  columns_(0)
{

}

ListModel::~ListModel ()
{
}

void ListModel::Test(int column, int count)
{
	ModelIndex root = GetRootIndex();

	if(InsertColumns(column, count, root)) {

		ModelIndex index = root.GetChildIndex();

		int columns = 0;
		int rows = 0;

		ModelIndex i = index;

		while(i.valid()) {
			rows++;
			i = i.GetDownIndex();
		}

		i = index;
		while(i.valid()) {
			columns++;
			i = i.GetRightIndex();
		}

		DBG_PRINT_MSG("rows: %d, columns: %d", rows, columns);

	} else {
		DBG_PRINT_MSG("%s", "fail to add columns");
	}
}

int ListModel::GetRowCount (const BI::ModelIndex& parent) const
{
	return rows_;
}

int ListModel::GetColumnCount (const BI::ModelIndex& parent) const
{
	return columns_;
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(ListModelTest1, Model1)
{
    if(Window::Initialize()) {

        Window win(640, 480, "List Model Test");	// Just create an opengl context

        {
        	ListModel model;
        	model.Test(0, 2);
        }

        win.Exec();
        Window::Terminate();
    }

	ASSERT_TRUE(true);
}
