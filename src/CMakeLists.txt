file(GLOB_RECURSE priptologies_SOURCES "*.cpp")

add_executable(
  priptologies
  ${priptologies_SOURCES}
)

target_link_libraries(priptologies libpriptologies)
