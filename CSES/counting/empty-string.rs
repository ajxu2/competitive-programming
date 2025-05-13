// created: 10-14-2024 Mon 02:41 PM

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

const MOD: usize = 1000000007;

fn fexp(mut a: usize, mut b: usize) -> usize {
    let mut ans = 1;
    while b > 0 {
        if (b & 1) == 1 {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    ans
}

fn inv(a: usize) -> usize {
    fexp(a, MOD - 2)
}

fn main() {
    let mut sc = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let s_str: String = sc.next();
    let s = s_str.as_bytes();
    let n = s.len();
    if n % 2 == 1 {
        writeln!(out, "0").unwrap();
        return;
    }
    let mut fac = vec![0; n + 1];
    fac[0] = 1;
    for i in 1..=n {
        fac[i] = fac[i - 1] * i % MOD;
    }
    let mut ifac = vec![0; n + 1];
    ifac[n] = inv(fac[n]);
    for i in (0..n).rev() {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }
    let binom = |n: usize, k: usize| fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
    let mut dp = vec![vec![0; n+1]; n+1];
    for i in 0..n {
        dp[i + 1][i] = 1;
    }
    for len in (2..=n).step_by(2) {
        for l in 0..=n-len {
            let r = l + len - 1;
            for i in (l+1..=r).step_by(2) {
                if s[l] == s[i] {
                    dp[l][r] += dp[l+1][i-1] * dp[i+1][r] % MOD * binom(len / 2, (i - l + 1) / 2) % MOD;
                    dp[l][r] %= MOD;
                }
            }
        }
    }
    writeln!(out, "{}", dp[0][n-1]).unwrap();
}
