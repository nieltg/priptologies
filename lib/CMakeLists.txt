file(GLOB_RECURSE libpriptologies_SOURCES "*.cpp")

add_library(
  libpriptologies
  STATIC
  ${libpriptologies_SOURCES}
)
