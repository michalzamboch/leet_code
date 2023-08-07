use std::collections::HashSet;

pub fn single_number(nums: Vec<i32>) -> i32 {
    let mut set: HashSet<i32> = HashSet::new();

    for num in nums {
        if set.contains(&num) {
            set.remove(&num);
        }
        else {
            set.insert(num);
        }
    }
    
    match set.iter().next() {
        Some(&x) => x as i32,
        None => -1
    }
}

fn test(nums: Vec<i32>) {
    let result = single_number(nums.clone());
    print(&nums);
    println!(" -> {}", result);
}

fn print(nums: &Vec<i32>) {
    for i in nums {
        print!("{} ", *i);
    }
    println!("");
}

fn main() {
    test(vec![2,2,1]);
    test(vec![4,1,2,1,2]);
    test(vec![1]);
}
