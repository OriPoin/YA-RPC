# flags from gyp
# FIXME: gyp use -fno-rtti -fno-exceptions, here are disabled, maybe bugs
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(wrapper SHARED wrapper.cc)
set_target_properties(wrapper PROPERTIES SUFFIX ".node")
add_library(hello api/hello.cc)
add_library(echo api/echo.cc)
add_library(sum api/sum.cc)
add_library(uppercase api/uppercase.cc)
target_link_libraries(wrapper hello echo sum uppercase)

install(TARGETS wrapper
    DESTINATION lib
)
