
pub fn detect_capital_use(word: String) -> bool {
    let mut upper = 0;
    let mut lower = 0;
    let first_letter_up = word.chars().nth(0).unwrap().is_uppercase();
    
    for i in word.chars() {
        if i.is_lowercase() {
            lower += 1;
        }
        if i.is_uppercase() {
            upper += 1;
        }
    }

    return 
        (upper == 1 && first_letter_up) ||
        upper == word.len() ||
        lower == word.len();    
}

fn test(word: String) {
    let result = detect_capital_use(word.clone());
    println!("{} -> {}", word, result);
}

fn main() {
    test("USA".to_owned());
    test("leetcode".to_owned());
    test("Google".to_owned());
    test("FlaG".to_owned());
}
