add_library(raylib-cpp INTERFACE)

file(GLOB sources raylib/*.cpp)
set(RAYLIBCPP_HEADERS, ${sources})

install(FILES
	${RAYLIBCPP_HEADERS} DESTINATION include/
)

target_include_directories(raylib-cpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/)
