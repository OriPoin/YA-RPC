#!/bin/bash
res=$(curl -X POST http://localhost:8080 -H 'Content-Type: application/json' -d '{ "func": "echo", "args": "ping" }')
echo "$res"
test "$res" = '{"func":"echo","args":"ping","return":"ping"}'
res=$(curl -X POST http://localhost:8080 -H 'Content-Type: application/json' -d '{ "func": "echo", "args": "pong" }')
echo "$res"
test "$res" = '{"func":"echo","args":"pong","return":"pong"}'
res=$(curl -X POST http://localhost:8080 -H 'Content-Type: application/json' -d '{ "func": "hello", "args": "" }')
echo "$res"
test "$res" = '{ "func": "hello", "args": "", "return": "Hello, world" }'
res=$(curl -X POST http://localhost:8080 -H 'Content-Type: application/json' -d '{ "func": "None", "args": "None" }')
echo "$res"
test "$res" = '{ "func": "None", "args": "None", "return": "Error" }'