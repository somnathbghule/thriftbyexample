#include "gen-cpp/helloSvc.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <iostream>
 
using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;
using namespace std;

int main() {
    std::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
    std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    helloSvcClient client(protocol);
 
    try {
        transport->open();
        std::string msg;
        client.getMessage(msg, "world!");
        std::cout << msg << std::endl;
    } catch(...) {
        std::cout << "Client caught an exception" << std::endl;
    }
    transport->close();
}
