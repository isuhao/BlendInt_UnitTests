#ifndef _FRAMETEST1_HPP_
#define _FRAMETEST1_HPP_

#include <gtest/gtest.h>

class FrameTest1: public testing::Test
{
public:
	FrameTest1 ();
	virtual ~FrameTest1 ();

protected:

	virtual void SetUp ()
	{

	}

	virtual void TearDown ()
	{

	}
};

#endif  // _FRAMETEST1_HPP_
