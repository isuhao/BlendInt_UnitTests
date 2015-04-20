# CMake file for blendint project
#

file(GLOB test_HEADERS "*.hpp")
file(GLOB test_SRC "*.cpp")

add_executable(testFreetype ${test_HEADERS} ${test_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(testFreetype blendint Common gtest ${LIBS})
