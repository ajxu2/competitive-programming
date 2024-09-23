// created: 09-22-2024 Sun 10:52 AM

#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};
 
#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut sc = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let t: i32 = sc.next();
    for _ in 0..t {
        let n: i32 = sc.next();
        let k: i32 = sc.next();
        let num_odd: i32 = k / 2 + if n % 2 == 1 && k % 2 == 1 { 1 } else { 0 };
        if num_odd % 2 == 0 { writeln!(out, "YES").unwrap(); }
        else { writeln!(out, "NO").unwrap(); }
    }
}
