#ifndef _LISTMODELTEST1_HPP_
#define _LISTMODELTEST1_HPP_

#include <gtest/gtest.h>

#include <gui/abstract-list-model.hpp>

class ListModelTest1: public testing::Test
{
public:
	ListModelTest1 ();
	virtual ~ListModelTest1 ();

protected:

	virtual void SetUp ()
	{
	}

	virtual void TearDown ()
	{
	}
};

namespace BI = BlendInt;

class ListModel: public BlendInt::AbstractListModel
{

public:

	ListModel();

	virtual ~ListModel();

	// A test function:

	bool TestModel1 (int column, int count);
    
    bool TestModel2 (int row, int count);

	virtual int GetRowCount (const BI::ModelIndex& parent = BI::ModelIndex()) const;

	virtual int GetColumnCount (const BI::ModelIndex& parent = BI::ModelIndex()) const;

private:

	int rows_;

	int columns_;

};

#endif  // _LISTMODELTEST1_HPP_
