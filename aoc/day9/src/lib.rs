// 10820
// 
use std::fs::File;
use std::io::Read;

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn count_score() {
        /*
        assert_eq!(part1("{}".to_string()), 1);
        assert_eq!(part1("{{{}}}".to_string()), 6);
        assert_eq!(part1("{{},{}}".to_string()), 5);
        assert_eq!(part1("{{{},{},{{}}}}".to_string()), 16);
        assert_eq!(part1("{<a>,<a>,<a>,<a>}".to_string()), 1);
        assert_eq!(part1("{{<ab>},{<ab>},{<ab>},{<ab>}}".to_string()), 9);
        assert_eq!(part1("{{<!!>},{<!!>},{<!!>},{<!!>}}".to_string()), 9);
        assert_eq!(part1("{{<a!>},{<a!>},{<a!>},{<ab>}}".to_string()), 3);
        */

        let filename = "input";
        let mut f = File::open(filename).expect("file not found");
        let mut contents = String::new();
        f.read_to_string(&mut contents).expect("something went wrong");
        println!("score={}", part1(contents));

    }

    #[test]
    fn count_garbage() {
    /*
        assert_eq!(part2("<>"), 0);
        assert_eq!(part2("<random characters>"),17);
        assert_eq!(part2("<<<<>"), 3);
        assert_eq!(part2("<{!>}>"), 2);
        assert_eq!(part2("<!!>"), 0);
        assert_eq!(part2("<!!!>>"), 0);
        assert_eq!(part2("<{o\"i!a,<{i<a>"), 10);
        */

        let filename = "input";
        let mut f = File::open(filename).expect("file not found");
        let mut contents = String::new();
        f.read_to_string(&mut contents).expect("something went wrong");
        println!("score={}", part2(contents.as_str()));
    }
}

fn part1(contents: String) -> u32 {

    let mut score: u32 = 0;

    let mut in_garbage = false;
    let mut previous: char = '?';
    let mut stack: Vec<char> = vec![];

    for ch in contents.chars() {

        match ch {

            '{' => {
                if !in_garbage {
                    stack.push('{');
                }
            },

            '}' => {
                if !in_garbage {
                    score += stack.len() as u32;
                    stack.pop();
                }
            },

            '<' => {
                in_garbage = true;
            },

            '>' => {
                if in_garbage && previous != '!' {
                    in_garbage = false;
                }
            },

            '!' => {
                if in_garbage && previous == '!' {
                    previous = '?';
                    continue;
                }
            }

            _ => {},

        }

        previous = ch;

    }

    return score;
}

fn part2(contents: &str) -> u32 {

    let mut garbage_count: u32 = 0;

    let mut in_garbage = false;
    let mut previous: char = '?';
    let mut skip = false;

    for ch in contents.chars() {

        if skip {
            skip = false;
            continue;
        }

        if in_garbage {
            if ch == '!' {
                skip = true;
                continue;
            }
        }


        match ch {
        
            '<' => {
                if !in_garbage {
                    in_garbage = true;
                    continue
                }
            }, 

            '>' => {
                in_garbage = false;
            },

            _ => {},

        }

        if in_garbage {
            garbage_count += 1;
        }
        previous = ch;
    }

    return garbage_count;
}
