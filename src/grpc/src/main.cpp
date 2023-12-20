#include "proto/greeter.pb.h"
#include "proto/greeter.grpc.pb.h"

#include <grpc/grpc.h>
#include <grpc++/server_builder.h>

#include <iostream>
#include <memory>

using namespace service;


class GreeterService : public service::Greeter::Service {
public:
    ::grpc::Status SayHello(::grpc::ServerContext* ctx, const SayHelloRequest* req, SayHelloResponse* res) override {
        std::cout << "Server: SayHello" << std::endl;

        // params
        const std::string name = req->name();

        // output
        res->set_message("Hello " + name);

        // done
        return grpc::Status::OK;
    }
};

int main() {

    // configure
    grpc::ServerBuilder builder;
    builder.AddListeningPort("0.0.0.0:8000", grpc::InsecureServerCredentials());
    std::cout << "server listening on 0.0.0.0:8000\n";

    // add services
    GreeterService greeterService;
    builder.RegisterService(&greeterService);

    // start the server
    std::unique_ptr<grpc::Server> server{builder.BuildAndStart()};
    server->Wait();
    return 0;
}