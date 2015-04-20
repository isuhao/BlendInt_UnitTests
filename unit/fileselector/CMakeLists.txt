# CMake file for blendint project
#

file(GLOB test_SRC "*.cpp")

add_executable(testFileSelector ${test_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(testFileSelector blendint gtest ${LIBS})
