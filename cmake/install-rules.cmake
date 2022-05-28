if(PROJECT_IS_TOP_LEVEL)
  set(CMAKE_INSTALL_INCLUDEDIR include/raylib_cpp CACHE PATH "")
endif()

# Project is configured with no languages, so tell GNUInstallDirs the lib dir
set(CMAKE_INSTALL_LIBDIR lib CACHE PATH "")

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package raylib_cpp)

install(
    DIRECTORY include/
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT raylib_cpp_Development
)

install(
    TARGETS raylib_cpp_raylib_cpp
    EXPORT raylib_cppTargets
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
    ARCH_INDEPENDENT
)

# Allow package maintainers to freely override the path for the configs
set(
    raylib_cpp_INSTALL_CMAKEDIR "${CMAKE_INSTALL_DATADIR}/${package}"
    CACHE PATH "CMake package config location relative to the install prefix"
)
mark_as_advanced(raylib_cpp_INSTALL_CMAKEDIR)

install(
    FILES cmake/install-config.cmake
    DESTINATION "${raylib_cpp_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT raylib_cpp_Development
)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${raylib_cpp_INSTALL_CMAKEDIR}"
    COMPONENT raylib_cpp_Development
)

install(
    EXPORT raylib_cppTargets
    NAMESPACE raylib_cpp::
    DESTINATION "${raylib_cpp_INSTALL_CMAKEDIR}"
    COMPONENT raylib_cpp_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
