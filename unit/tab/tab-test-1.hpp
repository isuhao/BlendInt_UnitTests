#ifndef _TABTEST1_HPP_
#define _TABTEST1_HPP_

#include <gtest/gtest.h>

class TabTest1: public testing::Test
{
 public:
  TabTest1 ();
  virtual ~TabTest1 ();

 protected:

  virtual void SetUp ()
  { }

  virtual void TearDown ()
  { }
};

#endif  // _TABTEST1_HPP_
