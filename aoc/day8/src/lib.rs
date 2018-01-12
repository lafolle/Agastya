use std::fs::File;
use std::io::Read;
use std::collections::HashMap;

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn it_works() {
        part1();
    }
}

/*
use std::collections::BinaryHeap;
use std::cmp::Ordering;
#[derive(Eq, PartialEq)]
struct Register<'a> {
    name: &'a str,
    val: i32,
}

impl<'a> Register<'a> {
    fn new(name: &'a str, val: i32) -> Self {
        Register {
            name: name,
            val: val,
        }
    }
}

impl<'a> Ord for Register<'a> {
    fn cmp(&self, other: &Reg) -> Ordering {
        self.val.cmp(&other.val)
    }
}

impl<'a> PartialOrd for Register<'a> {
    fn partial_cmp(&self, other: &Reg) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

enum Operation {
    Inc,
    Dec,
}

impl Operation {
    fn parse(ops: &str) -> Self {
        match ops {
            "inc" => Operation::Inc,
            "dec" => Operation::Dec,
            _ => panic!("invalid operation!")
        }
    }
}

enum BinaryOperator {
    LessThan
    GreaterThan
    LessThanEqualTo
    GreaterThanEqualTo
    EqualTo
    NotEqualTo
}

struct Cond<'a> {
    lope: &'a str,
    operator: BinaryOperator,
    rope: i32,
}

impl Cond {

    fn new(cond: &str) -> Self {
        let v: Vec<&str> = cond.split_whitespace().collect();
        Cond{
            lope: v[1],
            operator: Cond::get_operator(v[2]),
            rope: v[3].parse::<i32>().unwrap(),
        }
    }

    fn get_operator(op: &str) -> BinaryOperator {
        match op {
            "<" => BinaryOperator::LessThan,
            ">" => BinaryOperator::GreaterThan,
            "<=" => BinaryOperator::LessThanEqualTo,
            ">=" => BinaryOperator::GreaterThanEqualTo,
            "==" => BinaryOperator::EqualTo,
            "!=" => BinaryOperator::NotEqualTo,
            _ => panic!("humse na ho payega!")
        }
    }
}

struct Instruction {
    reg: Reg
    operation: Operation,
    cond: Cond,
}

impl Instruction {

    fn new(op: Operation, cond: Cond) -> Self {
        Instruction {
            operation: op,
            cond: cond,
        }
    }

}

struct Machine {
    registers: BinaryHeap<Reg>,
    instructions: Vec<Instruction>,
}

impl Machine {

    fn new(instructions: Vec<Instruction>) -> Self {
        Machine {
            registers: BinaryHeap::new(),
            instructions: instructions,
        }
    }

    fn run(&mut self) {
        for ins in &self.instructions {
            self.execute_instruction(ins);
        }
    }

    fn execute_instruction(&mut self, ins: Instruction) {
    }

    fn top_register(&self) -> &Reg {
    }
}
*/

fn part1() {
    // List of instructions.
    // Execute each of them.

    let filename = "input";
    let mut f = File::open(filename).expect("file not found");
    let mut contents = String::new();
    f.read_to_string(&mut contents).expect("something went wrong");

    let mut highest_ever: i32 = -100000;
    let mut reg_values: HashMap<&str, i32> = HashMap::new();
    for line in contents.lines() {
        let ins: Vec<&str> = line.split_whitespace().collect(); 

        if ins.len() == 0 {
            continue;
        }

        let reg: &str = ins[0];
        reg_values.entry(reg).or_insert(0); // mutable.
        let action: &str = ins[1];
        let action_operand: i32 = ins[2].parse::<i32>().unwrap();

        let cond_register = ins[4];
        let left_operand = *reg_values.entry(cond_register).or_insert(0); // mutable.
        //let left_operand = *reg_values.get(cond_register).unwrap(); // immutable.
        let operator = ins[5];
        let right_operand = ins[6].parse::<i32>().unwrap();

        let is_cond_true: bool = match operator {
            "<" => left_operand < right_operand,
            "<=" => left_operand <= right_operand,
            ">" => left_operand > right_operand,
            ">=" => left_operand >= right_operand,
            "==" => left_operand == right_operand,
            "!=" => left_operand != right_operand,
            _ => panic!("invalid operator"),
        };

        if is_cond_true {

            let reg_val = reg_values.get_mut(reg).unwrap(); 
            let new_val = match action {
                "inc" => *reg_val + action_operand,
                "dec" => *reg_val - action_operand,
                _ => panic!("invalid action!"),
            };
            *reg_val = new_val;
            if new_val > highest_ever {
                highest_ever = new_val;
            }
        }

    }

    let mut max_val: i32 = -1000000;
    for  val in reg_values.values() {
        if *val > max_val {
            max_val = *val;
        }
    }

    println!("ans = {}, highest ever: {}", max_val, highest_ever);

}
