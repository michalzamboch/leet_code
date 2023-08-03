use std::collections::HashSet;

pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
    if !valid_lines(&board) {
        return false;
    }

    if !valid_columns(&board) {
        return false;
    }

    if !valid_quads(&board) {
        return false;
    }

    true
}

pub fn valid_quads(board: &Vec<Vec<char>>) -> bool {
    for x in 0..3 {
        for y in 0..3 {
            if !valid_quad(&board, y * 3, x * 3) {
                return false;
            }
        }
    }
    
    true
}

pub fn valid_quad(board: &Vec<Vec<char>>, y: usize, x: usize) -> bool {
    let mut set = HashSet::<char>::new();
    
    for i in x..x + 3 {
        for j in y..y + 3 {
            if board[i][j] == '.' {
                continue;
            }

            if set.contains(&board[i][j]) {
                return false;
            }
            else {
                set.insert(board[i][j]);
            } 
        }
    }

    true
}

pub fn valid_columns(board: &Vec<Vec<char>>) -> bool {
    let mut v = Vec::<char>::new();

    for i in 0..9 {
        for j in 0..9 {
            v.push(board[j][i]);
        }
        if !valid_line(&v) {
            return false;
        }
        v.clear();
    }

    true
}

pub fn valid_lines(board: &Vec<Vec<char>>) -> bool {
    for i in board.iter() {
        if !valid_line(i) {
            return false;
        }
    }

    true
}

pub fn valid_line(line: &Vec<char>) -> bool {
    let mut set = HashSet::<char>::new();
    
    for i in line.iter() {
        if *i == '.' {
            continue;
        }

        if set.contains(i) {
            return false;
        }
        else {
            set.insert(*i);
        }
    }
    
    true
}

pub fn test(board: Vec<Vec<char>>) {
    let result = is_valid_sudoku(board.clone());
    print(&board);
    
    println!(" -> {} \n", result);
}

pub fn print(board: &Vec<Vec<char>>) {
    for i in board.iter() {
        for j in i.iter() {
            print!("{} ", j);
        }
        print!("\n");
    }
}

fn main() {
    let mut board = vec![
        vec!['5','3','.','.','7','.','.','.','.'],
        vec!['6','.','.','1','9','5','.','.','.'],
        vec!['.','9','8','.','.','.','.','6','.'],
        vec!['8','.','.','.','6','.','.','.','3'],
        vec!['4','.','.','8','.','3','.','.','1'],
        vec!['7','.','.','.','2','.','.','.','6'],
        vec!['.','6','.','.','.','.','2','8','.'],
        vec!['.','.','.','4','1','9','.','.','5'],
        vec!['.','.','.','.','8','.','.','7','9']
    ];
    test(board);

    board = vec![
        vec!['8','3','.','.','7','.','.','.','.'],
        vec!['6','.','.','1','9','5','.','.','.'],
        vec!['.','9','8','.','.','.','.','6','.'],
        vec!['8','.','.','.','6','.','.','.','3'],
        vec!['4','.','.','8','.','3','.','.','1'],
        vec!['7','.','.','.','2','.','.','.','6'],
        vec!['.','6','.','.','.','.','2','8','.'],
        vec!['.','.','.','4','1','9','.','.','5'],
        vec!['.','.','.','.','8','.','.','7','9']
    ];
    test(board);
}
