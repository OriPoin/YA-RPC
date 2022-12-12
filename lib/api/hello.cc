#include "common.h"

namespace api
{
    void hello(const v8::FunctionCallbackInfo<v8::Value> &args)
    {
        v8::Isolate *isolate = args.GetIsolate();
        std::string helloString = "Hello, world";
        args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, helloString.c_str()).ToLocalChecked());
    }
}

// namespace api