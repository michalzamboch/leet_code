pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
    transpose(matrix);
    reverse(matrix);
}

pub fn transpose(matrix: &mut Vec<Vec<i32>>) {
     for i in 0..matrix.len() {
        for j in 0..i {
            let tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
}

pub fn reverse(matrix: &mut Vec<Vec<i32>>) {
     for i in 0..matrix.len() {
        matrix[i].reverse();
    }
}

pub fn test(matrix: &mut Vec<Vec<i32>>) {
    print(matrix);
    rotate(matrix);
    
    println!("");
    print(matrix);
    println!("\n------------------\n");
}

pub fn print(matrix: &Vec<Vec<i32>>) {
    for i in 0..matrix.len() {
        for j in 0..matrix[0].len() {
            print!("{} ", matrix[i][j]);
        }
        print!("\n");
    }
}

fn main() {
    let mut v = vec![
        vec![1, 2, 3],
        vec![4, 5, 6],
        vec![7, 8, 9]
    ];
    test(&mut v);
    
    v = vec![
        vec![5, 1, 9, 11],
        vec![2, 4, 8, 10],
        vec![13, 3, 6, 7],
        vec![15, 14, 12, 16]
    ];
    test(&mut v);

    v = vec![
        vec![1, 2],
        vec![4, 5]
    ];
    test(&mut v);
}
