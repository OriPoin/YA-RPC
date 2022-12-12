#include "common.h"
#include <algorithm>
#include <string>

namespace api
{
    std::string doUppercase(std::string value)
    {
        std::transform(value.begin(), value.end(), value.begin(), ::toupper);
        return value;
    }
    void uppercase(const v8::FunctionCallbackInfo<v8::Value> &args)
    {
        v8::Isolate *isolate = args.GetIsolate();
        std::string value = std::string(*v8::String::Utf8Value(isolate, args[0]));
        std::string result = doUppercase(value);
        args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, result.c_str()).ToLocalChecked());
    }
} // namespace api
