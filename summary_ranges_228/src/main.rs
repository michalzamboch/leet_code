
fn main() {
    test(vec![0,1,2,4,5,7]);
    test(vec![0,2,3,4,6,8,9]);
}

fn test(nums: Vec<i32>) {
    let result = summary_ranges(nums.clone());

    let nums_print = vec_i32_str(&nums);
    let result_print = vec_string_str(&result);

    println!("{}\n{}\n", nums_print, result_print);
}

fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
    let mut result: Vec<String> = Vec::new();
    let mut i = 0;

    while i < nums.len() {
        let current_num = nums[i];
        
        while i + 1 < nums.len() && nums[i] + 1 == nums[i + 1] {
            i += 1;
        }
        
        if current_num != nums[i] {
            result.push(format!("{}->{}", current_num, nums[i]));
        }
        else {
            result.push(format!("{}", nums[i]));
        }
        
        i += 1;
    }

    return result;
}

fn vec_i32_str(nums: &Vec<i32>) -> String {
    return nums
        .into_iter()
        .map(|c| c.to_string())
        .collect::<Vec<String>>()
        .join(", ");
}

fn vec_string_str(nums: &Vec<String>) -> String {
    return nums
        .into_iter()
        .map(|c| format!("\"{}\"", c))
        .collect::<Vec<String>>()
        .join(", ");
}