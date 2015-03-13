/*
 * Unit test for color
 */

#include <gtest/gtest.h>
#include <gui/window.hpp>

int main (int argc, char* argv[])
{
	BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
