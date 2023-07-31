use std::collections::HashMap;

pub fn is_anagram(s: String, t: String) -> bool {
    let letters_map = create_anagram_map(&s, &t);
    empty_map(&letters_map)
}

pub fn create_anagram_map(s: &str, t: &str) -> HashMap<char, i32> {
    let mut letters_map = HashMap::new();

    for l in s.chars() {
        *letters_map.entry(l).or_insert(0) += 1;
    }

    for l in t.chars() {
        *letters_map.entry(l).or_insert(0) -= 1;
    }

    letters_map
}

pub fn empty_map(map: &HashMap<char, i32>) -> bool {
    for (_, value) in map {
        if *value != 0 {
            return false;
        }
    }

    true
}

pub fn print_map(map: &HashMap<char, i32>) {
    for (key, value) in map {
        println!("{}: {}", key, value);
    }
}

pub fn test(s: String, t: String) {
    let result = is_anagram(s.clone(), t.clone());
    println!("\"{}\" : \"{}\" -> {}", &s, &t, result);
}

fn main() {
    test("anagram".to_owned(), "nagaram".to_owned());
    test("rat".to_owned(), "car".to_owned());
}
