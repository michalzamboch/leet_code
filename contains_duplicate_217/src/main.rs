use std::collections::HashSet;

fn main() {
    test(vec![1, 2, 3, 1]);
    test(vec![1, 2, 3, 4]);
    test(vec![1, 1, 1, 3, 3, 4, 3, 2, 4, 2]);
}

fn test(arr: Vec<i32>) {
    let str_vec = vec_to_str(arr.clone());
    let result = contains_duplicate(arr);
    println!("{} -> {}", str_vec, result);
}

fn vec_to_str(arr: Vec<i32>) -> String {
    let vec_str: Vec<String> = arr.into_iter().map(|item| item.to_string()).collect();
    let result = vec_str.join(", ");
    format!("[{}]", result)
}

pub fn contains_duplicate(nums: Vec<i32>) -> bool {
    let mut set: HashSet<i32> = HashSet::new();
    for i in nums {
        if set.contains(&i) {
            return true;
        } else {
            set.insert(i);
        }
    }

    false
}
