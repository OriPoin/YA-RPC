#include <node.h>

namespace api
{
    void hello(const v8::FunctionCallbackInfo<v8::Value> &args);
    void echo(const v8::FunctionCallbackInfo<v8::Value> &args);
    void sum(const v8::FunctionCallbackInfo<v8::Value> &args);
} // namespace api
