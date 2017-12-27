// https://adventofcode.com/2017/day/6
// part1: 7864
// part2: 1695

/*
    Influenced by https://github.com/sciyoshi/advent-of-rust-2017/blob/master/src/day6/mod.rs
    Couldn't figure out:
    1. how to use hash.
    2. how to get max out of vector.
*/

use std::collections::HashMap;

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn test_part1() {
        assert_eq!(5, part1("0 2 7 0"));
    }

    #[test]
    fn test_part2() {
        assert_eq!(4, part2("0 2 7 0"));
        println!("{}", part2("0   5   10  0   11  14  13  4   11  8   8   7   1   4   12  11"));
    }
}

fn part1(data: &str) -> u32 {
    let mut input: Vec<_> = data
                .split_whitespace()
                .map(|v| v.parse::<u32>().unwrap())
                .collect();

    let mut seen = HashMap::new();
    let l = input.len();
    let mut count = 0;

    while !seen.contains_key(&input) {
        seen.insert(input.clone(), 1);
        let (i, &mx) = input
            .iter()
            .rev()
            .enumerate()
            .max_by_key(|x| {x.1})
            .unwrap();
        let i = l-i-1;
        input[i] = 0;
        for j in 1..(mx+1) as usize {
            input[(i+j) % l] += 1;
        }

        count += 1;

    }

    count
}

fn part2(data: &str) -> u32 {
    let mut input: Vec<_> = data
                .split_whitespace()
                .map(|v| v.parse::<u32>().unwrap())
                .collect();

    let mut seen = HashMap::new();
    let l = input.len();
    let mut count: u32 = 0;

    while !seen.contains_key(&input) {
        seen.insert(input.clone(), count);
        let (i, &mx) = input
            .iter()
            .rev()
            .enumerate()
            .max_by_key(|x| {x.1})
            .unwrap();
        let i = l-i-1;
        input[i] = 0;
        for j in 1..(mx+1) as usize {
            input[(i+j) % l] += 1;
        }

        count += 1;

    }

    count - seen.get(&input).unwrap() 
}
