pub fn combination_sum2(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
    let mut result: Vec<Vec<i32>> = Vec::new();
    let mut current: Vec<i32> = Vec::new();
    let mut candidates = candidates;
    candidates.sort(); 
    backtrack(&candidates, &mut current, &mut result, target, 0);

    fn backtrack(candidates: &Vec<i32>, current: &mut Vec<i32>, result: &mut Vec<Vec<i32>>, target: i32, start: usize) {
        if target == 0 {
            result.push(current.clone()); 
            return;
        }
        for i in start..candidates.len() {
            if i > start && candidates[i] == candidates[i-1] {
                continue;
            }
            let candidate = candidates[i];
            if candidate > target {
                break;
            }
            current.push(candidate);
            backtrack(candidates, current, result, target-candidate, i+1); 
            current.pop();
        }
    }

    return result;
}

fn test(candidates: Vec<i32>, target: i32) {
    let results = combination_sum2(candidates.clone(), target);

    print(&candidates);
    println!(" -> {}", target);
    for res in results.iter() {
        print(res);
    }
    
    print!("\n");
}

fn print(v: &Vec<i32>) {
    for i in v.iter() {
        print!("{}, ", i);
    }

    print!("\n");
}

fn main() {
    test(vec![10,1,2,7,6,1,5], 8);
    test(vec![2,5,2,1,2], 5);
}
