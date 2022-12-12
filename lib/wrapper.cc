#include "common.h"

namespace wrapper
{
  void uppercase(const v8::FunctionCallbackInfo<v8::Value> &args)
  {
    v8::Isolate *isolate = args.GetIsolate();
    std::string value = std::string(*v8::String::Utf8Value(isolate, args[0]));
    std::string result = api::Uppercase(value);
    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, result.c_str()).ToLocalChecked());
  }

  void sum(const v8::FunctionCallbackInfo<v8::Value> &args)
  {
    v8::Isolate *isolate = args.GetIsolate();
    std::string value = std::string(*v8::String::Utf8Value(isolate, args[0]));
    std::string result = api::Sum(value);
    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, result.c_str()).ToLocalChecked());
  }

  void Initialize(v8::Local<v8::Object> exports)
  {
    NODE_SET_METHOD(exports, "hello", api::hello);
    NODE_SET_METHOD(exports, "echo", api::echo);
    NODE_SET_METHOD(exports, "sum", sum);
    NODE_SET_METHOD(exports, "uppercase", uppercase);
  }
  NODE_MODULE(wrapper, Initialize)
}

// namespace wrapper