/*
 * Unit test for FileButton
 */

#include <gtest/gtest.h>
#include <blendint/gui/window.hpp>

int main (int argc, char* argv[])
{
    BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

    testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
