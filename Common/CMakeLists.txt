# build common code

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

file(GLOB sourcefiles "*/*.cpp")
list(APPEND test_common_SRC ${sourcefiles})
file(GLOB sourcefiles "*.cpp")
list(APPEND test_common_SRC ${sourcefiles})

file(GLOB headerfiles "*.hpp")
list(APPEND test_common_SRC ${headerfiles})
file(GLOB headerfiles "*/*.hpp")
list(APPEND test_common_SRC ${headerfiles})

add_library (Common ${test_common_SRC})
target_link_libraries(Common BlendInt ${LIBS})
