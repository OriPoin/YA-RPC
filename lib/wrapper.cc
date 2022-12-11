#include "common.h"

namespace wrapper
{
  void Initialize(v8::Local<v8::Object> exports)
  {
    NODE_SET_METHOD(exports, "hello", api::hello);
    NODE_SET_METHOD(exports, "echo", api::echo);
  }
  NODE_MODULE(wrapper, Initialize)
}

// namespace wrapper