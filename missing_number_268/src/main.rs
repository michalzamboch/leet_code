pub fn missing_number(nums: Vec<i32>) -> i32 {
    let mut max = 0;
    for i in 0..(nums.len() + 1) {
        max += i;
    }

    let sum: i32 = nums.iter().sum();

    max as i32 - sum
}

fn test(nums: Vec<i32>) {
    let result = missing_number(nums.clone());
    print(&nums);
    println!(" -> {}\n", result);
}

fn print(nums: &Vec<i32>) {
    nums.iter().for_each(|x| print!("{} ", x));
    println!();
}

fn main() {
    test(vec![3,0,1]);
    test(vec![0,1]);
    test(vec![9,6,4,2,3,5,7,0,1]);
    test(vec![0]);
}
