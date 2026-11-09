// Simple CLI app: todo list
use std::io::{self, BufRead, Write};

fn main() {
    let mut todos: Vec<String> = Vec::new();
    let stdin = io::stdin();
    println!("Commands: add <text>, list, quit");
    for line in stdin.lock().lines() {
        let line = line.unwrap();
        let parts: Vec<&str> = line.splitn(2, ' ').collect();
        match parts[0] {
            "add" => {
                if parts.len() > 1 { todos.push(parts[1].to_string()); println!("added"); }
            }
            "list" => {
                for (i, t) in todos.iter().enumerate() { println!("{}. {}", i+1, t); }
            }
            "quit" => break,
            _ => println!("unknown"),
        }
    }
}
