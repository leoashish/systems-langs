# Systems Languages: examples

Examples for C++, Rust, Go, and Odin covering basic OOP, concurrency, and a
small CLI app.

## Layout

```
systems-langs/
├── cpp/     (oop.cpp, concurrency.cpp, app.cpp)
├── rust/    (oop.rs, concurrency.rs, app.rs)
├── go/      (oop.go, concurrency.go, app.go)
└── odin/    (oop.odin, concurrency.odin, app.odin)
```

## Build/run

- C++: `g++ -std=c++17 oop.cpp -o oop && ./oop`
- Rust: `rustc oop.rs -o oop && ./oop`
- Go: `go run oop.go`
- Odin: `odin run oop.odin` (requires Odin installed)
EOF