# 开发文档

## C++

添加新的api不需要改动nodejs部分代码，解析传入的`int/float/string`或者其列表，完成处理，最后返回字符串即可。

### 声明

放置于`include/common.h`或者单独的头文件中

### 定义

放置于`lib/api/`中，记得向顶层wrapper中添加模块定义

## Nodejs

本项目不打算使用第三方node仓库，请保证仅有此git仓库代码，不联网的情况下，项目可以构建，并且通过测试。

### app.js

HTTP服务器，用于解析JSON，调用C++方法；最后以JSON的形式返回。

#### 可能的安全风险

使用了eval
