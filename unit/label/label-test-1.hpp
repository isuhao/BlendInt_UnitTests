#ifndef _LABELTEST1_HPP_
#define _LABELTEST1_HPP_

#include <gtest/gtest.h>

class LabelTest1: public testing::Test
{
 public:
  LabelTest1 ();
  virtual ~LabelTest1 ();

 protected:

  virtual void SetUp ()
  {

  }

  virtual void TearDown ()
  {

  }
};

#endif  // _LABELTEST1_HPP_
