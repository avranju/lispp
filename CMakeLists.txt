cmake_minimum_required(VERSION 2.8.12)
project(lispp)

set(headers
  ./inc/stddefs.h
  ./inc/pointer_array.h
  ./inc/string_buffer.h
  ./inc/node.h
  ./inc/lexer.h
  ./inc/parser.h
)

set(sources
  ./src/pointer_array.c
  ./src/string_buffer.c
  ./src/node.c
  ./src/lexer.c
  ./src/parser.c
  ./src/lispp.c
)

include_directories(./inc)

add_executable(lispp ${headers} ${sources})