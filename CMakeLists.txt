# config
set(CMAKE_TOOLCHAIN_FILE "./tools/vcpkg/scripts/buildsystems/vcpkg.cmake")
cmake_minimum_required(VERSION 3.20)
project(communcation-protocols)

# output
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 3rd party
find_package(fmt      CONFIG REQUIRED)
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC     CONFIG REQUIRED)

# services
add_subdirectory("src/grpc")