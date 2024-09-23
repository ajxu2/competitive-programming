// created: 09-22-2024 Sun 12:04 PM

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
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a: Vec<u32> = (0..n).map(|_| sc.next()).collect();
        a.sort();
        if n == 1 || n == 2 {
            writeln!(out, "-1").unwrap();
            continue;
        }
        let needed_sum: i64 = 2 * (a[n/2] as i64) * (n as i64) + 1;
        let ans: i64 = max(0, needed_sum - a.iter().fold(0, |acc, i| acc + (*i as i64)));
        writeln!(out, "{}", ans).unwrap();
    }
}
