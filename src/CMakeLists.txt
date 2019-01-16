find_package(Raylib)

file(GLOB SOURCES
    *.h
    *.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} raylib ${CMAKE_DL_LIBS})
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)