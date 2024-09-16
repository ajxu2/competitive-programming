#[allow(unused_imports)]
use std::io::{BufWriter, stdin, stdout, Write};

fn solve() {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    let mut it = s.split_whitespace().map(|i| i.parse::<i32>().unwrap());
    let (mut l, mut r) = (it.next().unwrap(), it.next().unwrap());
    if l % 2 == 0 { l += 1; }
    if r % 2 == 0 { r -= 1; }
    let num_odd = (r - l) / 2 + 1;
    println!("{}", num_odd / 2);
}

fn main() {
    let mut t = String::new();
    stdin().read_line(&mut t).unwrap();
    let t: i32 = t.trim().parse().unwrap();
    for _ in 0..t { solve(); }
}
