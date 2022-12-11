# YA-RPC

[简体中文](./doc/README_zh.md)

Yet-Another RPC Framework

## Features

- Support basic data types: int, float, string
- Support At-least-once semantics (guaranteed by the HTTP protocol)
- Support RESTful calls

## Interface

- remote call float sum(float a, float b)
- remote call string uppercase(str)

## Build

need cmake, make, nodejs and npm.

```bash
num run clean # clean build and dist
npm run build # configure, build, and install C++ lib
```
