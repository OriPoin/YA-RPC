#include "common.h"

namespace api
{
    void echo(const v8::FunctionCallbackInfo<v8::Value> &args)
    {
        v8::Isolate *isolate = args.GetIsolate();
        std::string value = std::string(*v8::String::Utf8Value(isolate, args[0]));
        args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, value.c_str()).ToLocalChecked());
    }
}

// namespace wrapper