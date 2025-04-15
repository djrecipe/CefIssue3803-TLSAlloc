### Global Project Values
cmake_minimum_required (VERSION 3.8)
project ("SimpleConsole")
file(GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
# Add executable target
add_executable (SimpleConsole
	${SOURCES}
)
# Position Independant Code
add_compile_options(-fPIC)
# Remove any automatically added file prefix
set_target_properties(SimpleConsole PROPERTIES PREFIX "")
### Linux
# Copy files
add_custom_command(
	TARGET SimpleConsole POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
			${DEPS_FOLDER}
			${CMAKE_CURRENT_BINARY_DIR})
# Set link options
target_link_options(SimpleConsole PRIVATE -static-libgcc -static-libstdc++)
# Link!
target_link_libraries(SimpleConsole
PRIVATE "-ldl"
)