package main

import "fmt"

type Speaker interface {
    Speak()
}

type Dog struct{ Name string }
func (d Dog) Speak() { fmt.Println(d.Name, "says woof") }

type Cat struct{ Name string }
func (c Cat) Speak() { fmt.Println(c.Name, "says meow") }

func main() {
    animals := []Speaker{Dog{"Rex"}, Cat{"Mimi"}}
    for _, a := range animals { a.Speak() }
}
