#ifndef _BEZIERTEST1_HPP_
#define _BEZIERTEST1_HPP_

#include <gtest/gtest.h>

class BezierTest1: public testing::Test
{
public:
	BezierTest1 ();
	virtual ~BezierTest1 ();

protected:

	virtual void SetUp ()
	{
	}

	virtual void TearDown ()
	{
	}
};

#endif  // _BEZIERTEST1_HPP_
