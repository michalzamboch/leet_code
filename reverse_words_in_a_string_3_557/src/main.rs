pub fn reverse_words(s: String) -> String {
    let parts = s.split(" ");
    let mut result = "".to_owned();

    for part in parts {
        let reversed: String = part.chars().rev().collect();
        
        result.push_str(&reversed);
        result.push_str(" ");
    }

    result.pop();
    result
}

pub fn test(s: String) {
    let result = reverse_words(s.clone());
    println!("{} -> \"{}\"", s, result);
}

fn main() {
    test("Hello, world!".to_owned());
    test("Let's take LeetCode contest".to_owned());
    test("God Ding".to_owned());
}
