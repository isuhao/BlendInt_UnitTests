#ifndef _FCCONFIGTEST1_HPP_
#define _FCCONFIGTEST1_HPP_

#include <gtest/gtest.h>

class FcConfigTest1: public testing::Test
{
public:
	FcConfigTest1 ();
	virtual ~FcConfigTest1 ();

protected:

	virtual void SetUp ()
	{
	}

	virtual void TearDown ()
	{
	}
};

#endif  // _FCCONFIGTEST1_HPP_
