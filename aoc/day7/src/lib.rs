// 1275

use std::fs::File;
use std::io::Read;
use std::collections::{HashMap, HashSet};

#[cfg(test)]
mod tests {
    
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(part1(), 4);
    }
}

#[derive(Debug)]
struct Node<'a> {
    weight: u32,
    children:  Vec<&'a str>,

    // Excluding node's own weight.
    carrying_weight: u32,

}

impl<'a> Node<'a> {
    fn new(weight: u32, children: Vec<&str>, carrying_weight: u32) -> Node {
        Node{
            weight: weight,
            children: children,
            carrying_weight: carrying_weight,
        }
    }

    fn find_odd_weight(&self, adj_list: &'a HashMap<&str, Node>) -> Option<&'a str> {
        let mut hm: HashMap<u32, u32> = HashMap::new();
        for child in &self.children {
            let node = adj_list.get(child).unwrap();
            let counter = hm.entry(node.carrying_weight+node.weight).or_insert(0);
            *counter += 1;
        }
        if hm.len() == 1 {
            return None;
        } 
        match hm.len() {
            1 => return None,
            2 => {
                for (node_weight, frequency) in hm.iter() {
                    if *frequency == 1 {
                        for child in &self.children {
                            let node = adj_list.get(child).unwrap();
                            if node.carrying_weight + node.weight == *node_weight {
                                return Some(child);
                            }
                        }
                        break;
                    }
                }
                return None;
            },
            _ => panic!("multiple nodes with different weight")
        }
    }
}

#[allow(dead_code)]
fn part1() -> u32 {

    let filename = "input";
    let mut f = File::open(filename).expect("file not found");
    let mut contents = String::new();
    f.read_to_string(&mut contents).expect("something went wrong");

    let mut adj_list: HashMap<&str, Node> = HashMap::new();

    for l in contents.lines() {

        let c: Vec<&str> = l.split_whitespace().collect(); 

        let node_name = c.get(0).unwrap();

        let s = c.get(1).unwrap();
        let node_weight = s[1..s.len()-1].parse::<u32>().unwrap();

        if c.len() > 2 { // Not a leaf.
            let mut alist: Vec<&str> = vec![];
            for i in {3..c.len()} {
                if i != c.len()-1 { // remove comma.
                    alist.push(&c[i][0..c[i].len()-1]);
                } else {
                    alist.push(&c[i][0..c[i].len()]);
                }
            }
            adj_list.insert(node_name, Node::new(node_weight, alist, 0));
        } else { // Is leaf.
            adj_list.insert(node_name, Node::new(node_weight, vec![], 0));
        }
    }

    let root = "dgoocsw";
    //let root = "a";

    // Set carrying_weight of all nodes via DFS.
    let mut stack: Vec<&str> = vec![root];
    let mut seen: HashSet<&str> = HashSet::new();

    while stack.len() > 0 {

        let top = stack[stack.len()-1];
        if seen.contains(top) {
            let cloned_children;
            {
                stack.pop();
                let seen_node = adj_list.get(top).unwrap();
                cloned_children= seen_node.children.clone();
            }
            let mut carrying_weight = 0;
            for child in cloned_children {
                let child_node = adj_list.get(child).unwrap();
                carrying_weight += child_node.weight + child_node.carrying_weight;
            }
            let node = adj_list.get_mut(top).unwrap();
            (*node).carrying_weight = carrying_weight;
            continue;
        }

        seen.insert(top);
        let node = adj_list.get(top).unwrap();
        for child in &node.children {
            stack.push(child);
        }
    }

    let _ans = 0;
    stack = vec![root];
    while stack.len() > 0 {
        let top = stack.pop().unwrap();
        let cur_node = adj_list.get(top).unwrap();

        let odd_node = cur_node.find_odd_weight(&adj_list);
        match odd_node {
            Some(node_name) => {
                stack.push(node_name);
            },
            None => {
                println!("odd one weight: {} name:{}", cur_node.weight, top);
            }
        }
    }

    println!("root: {}", root);
    let root_node = adj_list.get(root).unwrap();
    for child in &root_node.children {
        let child_node = adj_list.get(child).unwrap();
        println!("{} {} {}", child, child_node.carrying_weight + child_node.weight, child_node.weight);
    }

    root_node.carrying_weight
}
