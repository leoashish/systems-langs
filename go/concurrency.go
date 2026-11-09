package main

import (
    "fmt"
    "sync"
)

func main() {
    var mu sync.Mutex
    counter := 0
    var wg sync.WaitGroup
    for i := 0; i < 4; i++ {
        wg.Add(1)
        go func(id int) {
            defer wg.Done()
            for j := 0; j < 1000; j++ {
                mu.Lock()
                counter++
                mu.Unlock()
            }
            fmt.Println("worker", id, "done")
        }(i)
    }
    wg.Wait()
    fmt.Println("counter =", counter)

    // channel
    ch := make(chan int, 1)
    go func() { ch <- 42 }()
    fmt.Println("received =", <-ch)
}
