use std::cmp;

pub fn max_area(height: Vec<i32>) -> i32 {
    let mut area = 0;
    let mut left = 0;
    let mut right = height.len() - 1;

    while left < right {
        let current_area = cmp::min(height[left], height[right]) * (right as i32 - left as i32);
        area = cmp::max(area, current_area);

        if height[left] < height[right] {
            left += 1;
        }
        else {
            right -= 1;
        }
    }

    area
}

pub fn test(height: Vec<i32>) {
    let area = max_area(height.clone());
    for i in height.iter() {
        print!("{} ", i);
    }
    println!("-> {}", area);
}

fn main() {
    test(vec![1,8,6,2,5,4,8,3,7]);
    test(vec![1,1]);
}
