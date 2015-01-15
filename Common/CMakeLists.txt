# build common code

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

add_library (Common Window.cpp UnitTestContext.cpp UnitTestCursor.cpp)
target_link_libraries(Common BlendInt ${LIBS})
