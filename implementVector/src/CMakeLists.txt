file(GLOB SOURCE_FILES
     "*.h"
     "*.cpp"
)

add_executable(ImplementVector ${SOURCE_FILES})

if(MSVC)
  target_compile_options(ImplementVector PUBLIC "/m")
  #target_link_options(ImplementVector PUBLIC "/INCREMENTAL")
endif()

install(TARGETS ImplementVector RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})