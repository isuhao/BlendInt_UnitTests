# CMake file for blendint project
#

file(GLOB test_SRC "*.cpp")

add_executable(testFileBrowser ${test_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(testFileBrowser blendint Common gtest ${LIBS})
