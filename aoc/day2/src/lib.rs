// https://adventofcode.com/2017/day/2
// part1: 58975
// part2: 308

use std::io::prelude::*;
use std::fs::File;

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn test_part1() {
    }

    #[test]
    fn test_part2() {
        println!("{}", part2());
    }
}

fn part2() -> u32 {
    let filename = "part2.input";
    let mut f = File::open(filename).expect("file not found");
    let mut contents = String::new();
    f.read_to_string(&mut contents).expect("something went wrong");

    let ans = contents.lines().map(|line| {

        let mut res = Vec::new();

        for num in line.split_whitespace() {
            res.push(num.parse::<u32>().unwrap());
        }
        res

    }).map(|numbers| {

        let mut i = 0;
        let mut res = 0;

        while i < numbers.len() { 
            let a = &numbers[i+1..numbers.len()];
            let val = &numbers[i];
            let mut found = false;
            res = 0;
            for cal in a {
                if val % cal == 0 {
                    res = val / cal;
                    found = true;
                } else if cal % val == 0 {
                    res = cal / val;
                    found = true;
                }
            }

            if found {
                break;
            }
            i += 1;
        }

        res

    }).fold(0, |sum, x| x+sum);

    ans
}

fn part1() -> u32 {
    
    let filename = "day2-part1.input";

    let mut f = File::open(filename).expect("file not found");
    let mut contents = String::new();
    f.read_to_string(&mut contents).expect("something went wrong");

    let ans = contents.lines().map(|line| {

        let mut res = Vec::new();

        for num in line.split_whitespace() {
            res.push(num.parse::<u32>().unwrap());
        }
        res

    }).map(|numbers| {

        if numbers.len() == 0 {
            return 0;
        }

        let min_max = 1000000;
        let max_min = 0;

        let min = numbers.iter().fold(min_max, |min, v| *v.min(&min));
        let max = numbers.iter().fold(max_min, |max, v| *v.max(&max));

        println!("min={} max={}", min, max);
        max - min
    }).fold(0, |sum, x| x+sum);

    println!("{}", ans);

    ans

}
