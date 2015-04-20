# CMake file for blendint project
#

file(GLOB test_SRC "*.cpp")

add_executable(testHBlock ${test_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(testHBlock blendint Common gtest ${LIBS})
