# Minimal Common Lisp s-expression parser in C

This is a small Common Lisp s-expression parser written in C as an academic
exercise. Being a CMake project you can do the following to build and run after
you have cloned the repo if you've got [cmake](https://cmake.org/) and a C
compiler installed on your PC:

```
cd lispp
mkdir build && cd build
cmake ..
cmake --build .
```

And then run a binary called `lispp` or `lispp.exe` to make it parse and print
the parse tree for an s-expression. Here's what you'd see printed to stdout:

```
Lisp Code: (sum (gen-multiples (gen-series 1000) 3 5))

Parse Tree:
   <list>
      sum
      <list>
         gen-multiples
         <list>
            gen-series
            1000
         3
         5
```
