fn check_perfect_number(num: i32) -> bool {
    if num <= 1 {
        return false;
    }
    let mut result = 0;

    for n in 1..=(num as f64).sqrt() as i32 {
        if num % n == 0 {
            result += n;

            if n != 1 && n * n != num {
                result += num / n;
            }
        }
    }

    result == num
}

fn test(num: i32) {
    let result = check_perfect_number(num);
    println!("{} -> {}", num, result);
}

fn main() {
    test(28);
    test(7);
    test(99999999);
}
