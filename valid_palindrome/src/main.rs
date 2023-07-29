fn is_palindrome(s: String) -> bool {
    let letters = s
        .to_lowercase()
        .chars()
        .filter(|c| c.is_alphanumeric())
        .collect::<Vec<char>>();

    if letters.len() == 0 {
        return true;
    }

    let mut i = 0;
    let mut j = letters.len() - 1;

    while i < j {
        if  letters[i] != letters[j] {
            return false;
        }

        i += 1;
        j -= 1;
    }

    true
}

fn test(s: String) {
    let result = is_palindrome(s.clone());
    println!("{}: {}", s, result);
}

fn main() {
    test("A man, a plan, a canal: Panama".to_owned());
    test("race a car".to_owned());
    test(" ".to_owned());
    test("a.".to_owned());
    test(".,".to_owned());
}
