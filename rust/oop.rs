// Basic OOP in Rust: structs, traits, impl
trait Speak {
    fn speak(&self);
}

struct Dog { name: String }
struct Cat { name: String }

impl Speak for Dog {
    fn speak(&self) { println!("{} says woof", self.name); }
}
impl Speak for Cat {
    fn speak(&self) { println!("{} says meow", self.name); }
}

fn main() {
    let animals: Vec<Box<dyn Speak>> = vec![
        Box::new(Dog { name: "Rex".into() }),
        Box::new(Cat { name: "Mimi".into() }),
    ];
    for a in animals { a.speak(); }
}
