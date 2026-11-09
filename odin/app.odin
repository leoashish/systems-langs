// Simple CLI app skeleton in Odin
package main

import "core:fmt"
import "core:os"
import "core:strings"

main :: proc() {
    fmt.println("Commands: add <text>, list, quit")
    // Odin has no simple scanner; use os.stdin read loop (simplified)
    buf: [256]byte
    todos: [dynamic]string
    for {
        n, _ := os.read(os.stdin, buf[:])
        if n <= 0 { break }
        line := strings.trim_space(string(buf[:n]))
        if line == "quit" { break }
        if strings.has_prefix(line, "add ") {
            append(&todos, line[4:])
            fmt.println("added")
        } else if line == "list" {
            for i, t in todos {
                fmt.printf("%d. %s\n", i+1, t)
            }
        } else {
            fmt.println("unknown")
        }
    }
}
