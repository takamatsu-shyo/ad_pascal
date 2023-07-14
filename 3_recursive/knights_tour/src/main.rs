const MAX_SIZE: usize = 100;

fn try_move(i: usize, x: usize, y: usize, board: &mut [[usize; MAX_SIZE]; MAX_SIZE], n: usize) -> bool{
    let dx = [2, 1, -1, -2, -2, -1, 1, 2];
    let dy = [1, 2, 2, 1, -1, -2, -2, -1];
    let nsqr = n * n;
    let mut k = 0;
    let (mut u, mut v): (isize, isize);
    let mut q1 = false; // a move was success

    while !q1 && (k < 8) {
        u = x as isize + dx[k];
        v = y as isize + dy[k];
        if u >= 0 && (u as usize) < n && v >= 0 && (v as usize) < n && board[u as usize][v as usize] == 0 {
            board[u as usize][v as usize] = i;
            if i < nsqr {
                q1 = try_move(i+1, u as usize, v as usize, board, n);
                if !q1 {
                    board[u as usize][v as usize] = 0;
                } 
            }else {
                q1 = true;
            }
        }
        k += 1;
    }
    q1
}

fn clear_board(board: &mut [[usize; MAX_SIZE]; MAX_SIZE], n: usize){
    for i in 0..n {
        for j in 0..n {
            board[i][j] = 0;
        }
    }
}

fn knight_tour(start_x: usize, start_y: usize, n: usize) -> Option<[[usize; MAX_SIZE]; MAX_SIZE]> {
    let mut board = [[0; MAX_SIZE]; MAX_SIZE];
    clear_board(&mut board, n);
    board[start_x][start_y] = 1;
    if try_move(2, start_x, start_y, &mut board, n){
        Some(board)
    } else {
        None
    }
}

fn main() {
    let n = 6;
    match knight_tour(0, 0, n) {
        Some(board) => {
            for i in 0..n {
                for j in 0..n {
                    print!("{:2} ", board[i][j]);
                }
                println!();
            }
        }
        None => println!("Tour not possible from given start point!"),
    }
}
