### Global Project Values
cmake_minimum_required (VERSION 3.18)
project (CefIssue3803)

set(CMAKE_CXX_STANDARD 17)

#echo execute_process() output
set(CMAKE_EXECUTE_PROCESS_COMMAND_ECHO STDOUT)

option(USE_UPDATED_CHROME "compile with updated CEF binaries" OFF)
option(TARGET_ARM64 "target arm64" OFF)

set(DEPS_FOLDER "${CMAKE_SOURCE_DIR}/deps")

message(STATUS "USE_UPDATED_CHROME: ${USE_UPDATED_CHROME}")
message(STATUS "TARGET_ARM64: ${TARGET_ARM64}")
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "DEPS_FOLDER: ${DEPS_FOLDER}")

### Architecture
if (TARGET_ARM64)
	set(TARGET_CPU "arm64")
	set(CMAKE_HOST_SYSTEM_PROCESSOR "arm64")
	set(CMAKE_SYSTEM_PROCESSOR "arm64")
endif()

message(STATUS "CMAKE_HOST_SYSTEM_PROCESSOR is '${CMAKE_HOST_SYSTEM_PROCESSOR}'")

### Definitions
if ("${CMAKE_BUILD_TYPE}" MATCHES ".*Debug.*")
	add_compile_definitions(_DEBUG)
	message(STATUS "Added _DEBUG definition to compile flags")
endif()

### Linux
set(CXX_STANDARD 17)
add_compile_options(-std=c++17) # Needed for std::to_string() (copied from cef source)

# Linux defines
add_compile_definitions(LINUX UNIX_ENV XMP_UNIXBuild)
# Set flags
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-fvisibility=hidden -static-libgcc -static-libstdc++ -Wl,-rpath,$ORIGIN,--exclude-libs,ALL")
set(CMAKE_SHARED_LINKER_FLAGS ${CMAKE_SHARED_LINKER_FLAGS} "-fvisibility=hidden -static-libgcc -static-libstdc++ -Wl,-rpath,$ORIGIN,--exclude-libs,ALL")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

# More flags
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Build Components
add_subdirectory (SimpleConsole)