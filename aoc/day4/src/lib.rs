// https://adventofcode.com/2017/day/4
// part1: 451
// part2: 223

use std::fs::File;
use std::io::Read;
use std::collections::HashSet;

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn check1() {
        println!("{}", part1());
    }

    #[test]
    fn check2() {
        println!("ans={}",part2());
    }
}

fn part2() -> u32 {
    let filename = "input.txt";
    let mut f = File::open(filename).expect("file not found");
    let mut contents = String::new();
    f.read_to_string(&mut contents).expect("something went wrong");

    let is_anagram = |word1: String, word2: String| -> bool {

        if word1.len() != word2.len() {
            return false;
        }

        // TODO: Only 1 set can be used.
        let mut set1 = HashSet::new();
        let mut set2 = HashSet::new();
        for (c1, c2) in word1.chars().zip(word2.chars()) {
            if !set1.contains(&c1) {
                set1.insert(c1);
            }
            if !set2.contains(&c2) {
                set2.insert(c2);
            }
        }
        return (&set1 & &set2).len() == set1.len()
    };

    let valid = |line: &str| -> u32 {

        let v: Vec<&str> = line.split_whitespace().collect();

        
        let mut i = 0;
        for u in v.iter() {
            for w in &v[i+1..v.len()] {
                if is_anagram(u.to_string(), w.to_string()) {
                    return 0;
                }
            }
            i += 1;
        }

        1
    };

    contents.lines().map(|line| valid(line)).fold(0, |sum, yes| sum+yes)
}

fn part1() -> u32 {

    let filename = "input.txt";
    let mut f = File::open(filename).expect("file not found");
    let mut contents = String::new();
    f.read_to_string(&mut contents).expect("something went wrong");

    contents.lines().map(|line| {
        let mut hs = HashSet::new();
        let mut c = 0;
        for l in line.split_whitespace() {
            c += 1;
            hs.insert(l);
        }

        if hs.len() != c {
            0
        } else {
            1
        }
    }).fold(0, |sum, x| sum + x)

}
