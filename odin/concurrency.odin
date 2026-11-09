// Concurrency in Odin: threads (core:thread), channels (core:sync)
package main

import "core:fmt"
import "core:thread"
import "core:sync"

main :: proc() {
    mu: sync.Mutex
    counter := 0
    // spawn threads
    t1 := thread.create(proc() {
        for i in 0..<1000 {
            sync.lock(&mu)
            counter += 1
            sync.unlock(&mu)
            _ = i
        }
    })
    t2 := thread.create(proc() {
        for i in 0..<1000 {
            sync.lock(&mu)
            counter += 1
            sync.unlock(&mu)
            _ = i
        }
    })
    thread.join(t1)
    thread.join(t2)
    fmt.println("counter =", counter)
}
