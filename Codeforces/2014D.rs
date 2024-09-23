// created: 09-22-2024 Sun 03:33 PM

#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write, Stdout};
 
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

fn solve(sc: &mut Scanner, out: &mut BufWriter<Stdout>) {
    let n: usize = sc.next();
    let d: usize = sc.next();
    let k: usize = sc.next();
    let a: Vec<(usize, usize)> = (0..k)
        .map(|_| (sc.next::<usize>() - 1, sc.next::<usize>() - 1))
        .collect();
    let mut start: Vec<usize> = vec![0; n+1];
    let mut end: Vec<usize> = vec![0; n+1];
    for (l, r) in a {
        start[l] += 1;
        end[r+1] += 1;
    }
    for i in (0..n).rev() { start[i] += start[i+1]; }
    for i in 1..=n { end[i] += end[i-1]; }
    let mut brother: usize = 0;
    let mut brother_idx: usize = 0;
    let mut mother: usize = k;
    let mut mother_idx: usize = 0;
    for i in 0..=n-d {
        let overlap: usize = k - end[i] - start[i+d];
        if overlap > brother {
            brother = overlap; brother_idx = i;
        }
        if overlap < mother {
            mother = overlap; mother_idx = i;
        }
    }
    writeln!(out, "{} {}", brother_idx + 1, mother_idx + 1).unwrap();
}

fn main() {
    let mut sc = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let tt: usize = sc.next();
    for _ in 0..tt { solve(&mut sc, &mut out); }
}
