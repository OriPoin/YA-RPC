# flags from gyp
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-rtti -fno-exceptions")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fno-exceptions")

add_library(wrapper SHARED wrapper.cc)
set_target_properties(wrapper PROPERTIES SUFFIX ".node")
add_library(hello api/hello.cc)
add_library(echo api/echo.cc)
target_link_libraries(wrapper hello echo)

install(TARGETS wrapper
    DESTINATION lib
)
