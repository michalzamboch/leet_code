pub fn array_pair_sum(nums: Vec<i32>) -> i32 {
    let mut tmp = nums;
    tmp.sort();

    let n = tmp.len();
    let mut ans = 0;

    let mut i = 0;
    while i < n {
        ans += tmp[i];

        i += 2;
    }

    ans
}

fn test(nums: Vec<i32>) {
    print(&nums);
    let result = array_pair_sum(nums);
    println!(" -> {}", result);
}

fn print(nums: &Vec<i32>) {
    for i in nums {
        print!("{} ", i);
    }

    println!("");
}

fn main() {
    test(vec![1,4,3,2]);
    test(vec![6,2,6,5,1,2]);
}
