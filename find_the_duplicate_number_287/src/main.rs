use std::collections::HashSet;

fn main() {
    test(vec![1,3,4,2,2]);
    test(vec![3,1,3,4,2]);
}

fn test(nums: Vec<i32>) {
    let result = find_duplicate(nums.clone());
    let nums_string = vec_to_string(&nums);

    println!("{} -> {}", nums_string, result);
}

fn vec_to_string(nums: &Vec<i32>) -> String {
    return nums
        .into_iter()
        .map(|c| c.to_string())
        .collect::<Vec<String>>()
        .join(", ");
}

fn find_duplicate(nums: Vec<i32>) -> i32 {
    let mut set: HashSet<i32> = HashSet::new();

    for i in nums {
        if !set.insert(i) {
            return i;
        }
    }

    return 0;
}