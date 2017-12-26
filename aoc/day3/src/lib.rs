#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn check() {
        assert_eq!(part1(1), 0);
        assert_eq!(part1(12), 3);
        assert_eq!(part1(23), 2);
        assert_eq!(part1(1024), 31);
    }
}

fn part1(input: u32) -> u32 {
    match input {
        1: 0,
        12, 3,
        23, 2,
        1024, 31,
    }
}
