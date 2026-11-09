// Basic OOP-like in Odin: structs, procedures, interfaces via union
package main

import "core:fmt"

Animal :: struct {
    name: string,
    speak: proc(a: ^Animal),
}

Dog :: struct {
    using base: Animal,
}

Cat :: struct {
    using base: Animal,
}

dog_speak :: proc(a: ^Animal) {
    fmt.println(a.name, "says woof")
}

cat_speak :: proc(a: ^Animal) {
    fmt.println(a.name, "says meow")
}

main :: proc() {
    d := Dog{ base = Animal{ name = "Rex", speak = dog_speak } }
    c := Cat{ base = Animal{ name = "Mimi", speak = cat_speak } }
    d.base.speak(&d.base)
    c.base.speak(&c.base)
}
