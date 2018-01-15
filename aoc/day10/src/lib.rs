#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn it_works() {
        println!("ans: {}", part1());
    }
}

fn part1() -> u32 {
    
    let contents = "46,41,212,83,1,255,157,65,139,52,39,254,2,86,0,204".to_string();
    let lengths: Vec<usize> = contents.split(',')
                            .filter_map(|c| c.parse::<usize>().ok() )
                            .collect();

    const MAX_LIST_LEN: usize = 256;
    let mut list = [0; MAX_LIST_LEN];
    for i in {0..list.len()} { list[i] = i; }

    let mut s: usize = 0;
    let mut e: usize = 0;
    let mut cp: usize = 0;
    let mut skip_size: usize = 0;

    for len in &lengths {

        s = cp;
        e = cp + len;

        while s < e {

            list.swap(s % MAX_LIST_LEN, e % MAX_LIST_LEN);
            
            s += 1;
            e -= 1;
        }

        cp += len + skip_size;
        skip_size += 1;

    }


    list[0] as u32 * list[1] as u32

}
