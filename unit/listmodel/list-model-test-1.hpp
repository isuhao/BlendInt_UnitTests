#ifndef _LISTMODELTEST1_HPP_
#define _LISTMODELTEST1_HPP_

#include <gtest/gtest.h>

#include <blendint/gui/abstract-list-model.hpp>

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

  ListModel ();

  virtual ~ListModel ();

  // A test function:

  virtual int GetRowCount (const BI::ModelIndex& parent =
      BI::ModelIndex()) const;

  virtual int GetColumnCount (const BI::ModelIndex& parent =
      BI::ModelIndex()) const;

  virtual int GetPreferredColumnWidth (int index, const BI::ModelIndex& parent =
                                           BI::ModelIndex()) const override;

  virtual int GetPreferredRowHeight (int index, const BI::ModelIndex& parent =
                                         BI::ModelIndex()) const override;

  BI::Size CheckRowColumnCount () const;

private:

  int rows_;

  int columns_;

};

#endif  // _LISTMODELTEST1_HPP_
