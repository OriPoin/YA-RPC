#include <node.h>

namespace api
{
    void hello(const v8::FunctionCallbackInfo<v8::Value> &args);
    void echo(const v8::FunctionCallbackInfo<v8::Value> &args);
    std::string Sum(std::string value);
    std::string Uppercase(std::string value);
} // namespace api
