cmake_minimum_required(VERSION 3.10)
project(ZiroAI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the CURL_ROOT_DIR to the path where you installed the CURL library
set(CURL_ROOT_DIR C:/curl)

# Find the libcurl package
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})

# Add all header files
include_directories(include/model)
include_directories(include/data)
include_directories(include/file_io)
include_directories(include/web)

# Set the include directories
include_directories(include ${CURL_INCLUDE_DIRS})

# Add source files
file(GLOB_RECURSE SOURCES 
	"src/*.cpp"
	"src/model/*.cpp"
    "src/data/*.cpp"
    "src/file_io/*.cpp"
    "src/web/*.cpp"
)

# Add the executable
add_executable(ziroai ${SOURCES} "src/main.cpp")

# Link the libcurl library
target_link_libraries(ziroai PRIVATE ${CURL_LIBRARIES})

# Add any necessary libraries here, e.g. for deep learning frameworks
# target_link_libraries(ziroai <library_name>)
