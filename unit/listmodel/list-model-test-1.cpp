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

Size ListModel::CheckRowColumnCount () const
{
	ModelIndex root = GetRootIndex();
	ModelIndex index = root.GetChildIndex();

	int column_count = 0;
	int row_count = 0;
	int last_column_count = 0;

	ModelIndex i = index;
	ModelIndex j;

	while(i.valid()) {

		if(row_count == 0) {
			assert(!i.GetUpIndex().valid());
		}

		j = i;
		column_count = 0;
		while(j.valid()) {
			column_count++;
			j = j.GetRightIndex();
		}

		// DBG_PRINT_MSG("last columns: %d, colum count: %d", last_column_count, column_count);

		if(row_count != 0) {
			assert(column_count == last_column_count);
		}

		last_column_count = column_count;

		row_count++;
		i = i.GetDownIndex();
	}

	// DBG_PRINT_MSG("columns: %d, rows: %d", column_count, row_count);

	return Size(column_count, row_count);
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
        	ModelIndex root = model.GetRootIndex();
        	model.InsertColumns(0, 4, root);

        	Size result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 4) && (result.height() == 1));

        	model.InsertRows(0, 3, root);
        	result = model.CheckRowColumnCount();

           	ASSERT_TRUE((result.width() == 4) && (result.height() == 4));
        }

        {
        	ListModel model;
        	ModelIndex root = model.GetRootIndex();
        	Size result;

        	model.InsertRows(0, 2, root);
        	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 1) && (result.height() == 2));

        	model.InsertRows(4, 2, root);	// append
        	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 1) && (result.height() == 4));

        	model.InsertRows(0, 2, root);	// insert 0
        	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 1) && (result.height() == 6));

        	model.InsertRows(1, 2, root);	// insert 1
        	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 1) && (result.height() == 8));

        	model.InsertColumns(0, 2, root);	// insert 0 column
        	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 3) && (result.height() == 8));

        	model.InsertColumns(1, 2, root);	// insert 0 column
        	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 5) && (result.height() == 8));

        	model.InsertColumns(6, 2, root);	// append
        	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 7) && (result.height() == 8));

           	// test remove rows:

           	model.RemoveRows(0, 2, root);
           	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 7) && (result.height() == 6));

           	model.RemoveRows(2, 2, root);
           	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 7) && (result.height() == 4));

           	model.RemoveRows(3, 1, root);
           	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 7) && (result.height() == 3));

           	// test remove columns:

           	model.RemoveColumns(0, 2, root);
           	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 5) && (result.height() == 3));

           	model.RemoveColumns(2, 2, root);
           	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 3) && (result.height() == 3));

           	model.RemoveColumns(2, 1, root);
           	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 2) && (result.height() == 3));

           	model.RemoveColumns(0, 4, root);
           	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 0) && (result.height() == 0));

        	model.InsertColumns(0, 2, root);	// insert 0 column
        	result = model.CheckRowColumnCount();
           	ASSERT_TRUE((result.width() == 2) && (result.height() == 1));

        }

        win.Exec();
        Window::Terminate();
    }

	ASSERT_TRUE(true);
}
