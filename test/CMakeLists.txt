include(GoogleTest)

file(GLOB_RECURSE priptologies_test_SOURCES "*.cpp")

add_executable(
  priptologies_test
  ${priptologies_test_SOURCES}
)
target_link_libraries(priptologies_test gtest gtest_main)

gtest_discover_tests(priptologies_test)
