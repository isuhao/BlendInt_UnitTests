#ifndef _COLORTEST1_HPP_
#define _COLORTEST1_HPP_

#include <gtest/gtest.h>

class colorTest1: public testing::Test
{
public:
	colorTest1 ();
	virtual ~colorTest1 ();

protected:

	virtual void SetUp ()
	{
	}

	virtual void TearDown ()
	{
	}
};

#endif  // _COLORTEST1_HPP_
