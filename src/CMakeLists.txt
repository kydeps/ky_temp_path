find_package(glog)
find_package(GTest)

add_library(ky_temp_path temp_path.cc)
target_link_libraries(ky_temp_path PRIVATE glog::glog)
KyDepsPackageLibraryTarget(ky_temp_path "ky")

add_executable(temp_path_test temp_path_test.cc)
target_link_libraries(temp_path_test PRIVATE ky_temp_path::ky_temp_path
                                             GTest::gtest GTest::gtest_main)
gtest_discover_tests(temp_path_test)
