# CMake file for blendint project
#

file(GLOB test_SRC "*.cpp")

add_executable(testPopupFrame ${test_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(testPopupFrame blendint Common gtest ${LIBS})
