// https://adventofcode.com/2017/day/5
// part1: 372139
// part2: 29629538

use std::io::prelude::*;
use std::fs::File;

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn test_part1() {
        assert_eq!(part1("sample.input"), 5);
        assert_eq!(part1("input"), 372139);
    }

    #[test]
    fn test_part2() {
        assert_eq!(part2("sample.input"), 10);
        assert_eq!(part2("input"), 29629538);
    }
}

// --- Day 5: A Maze of Twisty Trampolines, All Alike ---
fn part1(filename: &str) -> u32 {
    let mut f = File::open(filename).expect("file not found");
    let mut contents = String::new();
    f.read_to_string(&mut contents).expect("something went wrong");

    let mut v: Vec<i32> = contents
            .lines()
            .map(|v| v.parse::<i32>().unwrap())
            .collect();

    let mut i: usize = 0;
    let mut steps = 0;
    loop {
        let cur = v[i];
        steps += 1;
        v[i] = cur + 1;
        if (i as i32 + cur < 0) || (i as i32 + cur >= v.len() as i32) {
            break;
        }
        i = (i as i32 + cur) as usize;
    }

    steps

}

fn part2(filename: &str) -> u32 {
    let mut f = File::open(filename).expect("file not found");
    let mut contents = String::new();
    f.read_to_string(&mut contents).expect("something went wrong");

    let mut v: Vec<i32> = contents
            .lines()
            .map(|v| v.parse::<i32>().unwrap())
            .collect();

    let mut i: usize = 0;
    let mut steps = 0;
    loop {
        let cur = v[i];
        steps += 1;
        if cur > 2 {
            v[i] = cur - 1;
        } else {
            v[i] = cur + 1;
        }
        if (i as i32 + cur < 0) || (i as i32 + cur >= v.len() as i32) {
            break;
        }
        i = (i as i32 + cur) as usize;
    }

    steps

}
