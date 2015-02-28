# CMake file for BlendInt project
#

file(GLOB test_HEADERS "*.hpp")
file(GLOB test_SRC "*.cpp")

add_executable(testListModel ${test_HEADERS} ${test_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(testListModel BlendInt gtest ${LIBS})
