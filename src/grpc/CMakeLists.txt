# generate proto 
set(PROTO_FILES proto/greeter.proto)
add_library(proto ${PROTO_FILES})
target_link_libraries(proto 
    PUBLIC 
        protobuf::libprotobuf 
        gRPC::grpc 
        gRPC::grpc++
        "$<LINK_LIBRARY:WHOLE_ARCHIVE,gRPC::grpc++_reflection>"
)

target_include_directories(proto PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# generate proto files
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET proto LANGUAGE cpp)
protobuf_generate(TARGET proto LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")

# gprc
add_executable(grpc src/main.cpp)
target_link_libraries(grpc PRIVATE proto)