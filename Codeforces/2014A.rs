// created: 09-22-2024 Sun 01:59 AM

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
        let mut cur: i32 = 0;
        let mut ans: i32 = 0;
        for _ in 0..n {
            let a: i32 = sc.next();
            if a >= k { cur += a; }
            else if a == 0 && cur > 0 { ans += 1; cur -= 1; }
        }
        writeln!(out, "{}", ans).unwrap();
    }
}
