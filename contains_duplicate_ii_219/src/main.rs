use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut map: HashMap<i32, Vec<i32>> = HashMap::new();

        for n in 0..nums.len() {
            if map.contains_key(&nums[n]) {
                map.get_mut(&nums[n]).unwrap().push(n as i32);
            } else {
                map.insert(nums[n], vec![n as i32]);
            }
        }

        for i in map.values() {
            if i.len() > 1 {
                let result = Solution::correct(&i, k);
                if result {
                    return true;
                }
            }
        }

        false
    }

    fn correct(arr: &Vec<i32>, k: i32) -> bool {
        let result = false;

        for i in 0..arr.len() {
            for j in i..arr.len() {
                let not_eq = i != j;
                let less = (arr[i] - arr[j]).abs() <= k;
                if not_eq && less {
                    return true;
                }
            }
        }

        return result;
    }
}

fn test(nums: Vec<i32>, k: i32) {
    let result = Solution::contains_nearby_duplicate(nums.clone(), k);
    println!("{}: {:?} - {}", result, nums, k);
}

fn main() {
    test([1, 2, 3, 1].into(), 3);
    test([1, 0, 1, 1].into(), 1);
    test([1, 2, 3, 1, 2, 3].into(), 2);
}
