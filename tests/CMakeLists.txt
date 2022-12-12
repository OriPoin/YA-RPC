# boost.test dependency
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(sum_test sum_test.cc)
target_link_libraries(sum_test sum ${Boost_LIBRARIES})
add_test(NAME sum_test COMMAND sum_test)

add_executable(uppercase_test uppercase_test.cc)
target_link_libraries(uppercase_test uppercase ${Boost_LIBRARIES})
add_test(NAME uppercase_test COMMAND uppercase_test)