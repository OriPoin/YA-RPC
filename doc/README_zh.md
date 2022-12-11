# YA-RPC

一个简易RPC框架

## 特性

- 支持基本数据类型：int, float, string
- 支持 At-least-once 语义(HTTP协议保证)
- 支持RESTful调用

## 接口

- 远程调用 float sum(float a, float b)
- 远程调用 string uppercase(str)

## 构建

需要安装cmake, make完成C++部分的构建；nodejs部分需要基础的nodejs和npm即可，不使用第三方库。

```bash
num run clean # 清理构建产物
npm run build # 构建C++库
```
