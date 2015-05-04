#ifndef _OBJECTTEST1_HPP_
#define _OBJECTTEST1_HPP_

#include <gtest/gtest.h>
#include <blendint/core/object.hpp>

class TestMe: public BlendInt::Object
{
 public:

  TestMe ();

  virtual ~TestMe ();
};

class ObjectTest1: public testing::Test
{
 public:
  ObjectTest1 ();
  virtual ~ObjectTest1 ();

 protected:

  virtual void SetUp ()
  {
  }

  virtual void TearDown ()
  {
  }
};

#endif  // _OBJECTTEST1_HPP_
