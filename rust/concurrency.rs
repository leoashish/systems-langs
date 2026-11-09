// Concurrency in Rust: threads, channels, mutex
use std::sync::{Arc, Mutex};
use std::thread;
use std::sync::mpsc;

fn main() {
    // threads + mutex
    let counter = Arc::new(Mutex::new(0));
    let mut handles = vec![];
    for _ in 0..4 {
        let c = Arc::clone(&counter);
        handles.push(thread::spawn(move || {
            for _ in 0..1000 {
                *c.lock().unwrap() += 1;
            }
        }));
    }
    for h in handles { h.join().unwrap(); }
    println!("counter = {}", *counter.lock().unwrap());

    // channels
    let (tx, rx) = mpsc::channel();
    thread::spawn(move || { tx.send(42).unwrap(); });
    println!("received = {}", rx.recv().unwrap());
}
