package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    todos := []string{}
    scanner := bufio.NewScanner(os.Stdin)
    fmt.Println("Commands: add <text>, list, quit")
    for scanner.Scan() {
        line := strings.TrimSpace(scanner.Text())
        parts := strings.SplitN(line, " ", 2)
        switch parts[0] {
        case "add":
            if len(parts) > 1 { todos = append(todos, parts[1]); fmt.Println("added") }
        case "list":
            for i, t := range todos { fmt.Printf("%d. %s\n", i+1, t) }
        case "quit":
            return
        default:
            fmt.Println("unknown")
        }
    }
}
