file(GLOB_RECURSE RAYLIB_CPP_MODULES raylib.cppm)

add_library(raylib_cpp_modules)

cmake_minimum_required(VERSION 3.28)

if(NOT COMMAND configure_cpp_module_target)
  function(configure_cpp_module_target target)
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.28)
      target_sources(${target} PUBLIC FILE_SET CXX_MODULES FILES ${RAYLIB_CPP_MODULES})
    else()
      message(WARNING "C++ modules require CMake 3.28+. Using standard compilation.")
      target_sources(${target} PRIVATE ${RAYLIB_CPP_MODULES})
    endif()
  endfunction()
endif()

configure_cpp_module_target(raylib_cpp_modules)

target_link_libraries(raylib_cpp_modules
  PUBLIC
    raylib_cpp
)

target_include_directories(raylib_cpp_modules
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(raylib_cpp_modules PUBLIC cxx_std_20)