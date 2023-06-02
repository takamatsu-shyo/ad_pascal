fn linear_sarch(arr: &mut Vec<i32>, target: i32) -> Option<usize>{
    
    arr.push(target); // Add sentinel

    let mut i = 0;
    while arr[i] != target {
        i += 1;
    }

    if i == arr.len() - 1 {
        None
    } else {
        Some(i)
    }
}

fn binary_search_1(a: &[i32], x: i32) -> Option<usize> {
    let mut left = 0;
    let mut right = a.len();

    while right > left {
        let middle = left + (right - left) / 2;
        println!("Current l-m-r index: {}-{}-{}", left, middle, right);

        if a[middle] == x {
            return Some(middle)
        } else if a[middle] < x {
            left = middle + 1;
        } else {
            if middle == 0 {
                break;
            }
            right = middle;
        }
    }
    None
   
}

fn binary_search_2(array: &[i32], target: i32) -> Option<usize>{
    let mut left = 0;
    let mut right = array.len();

    while left < right {
        let middle = left + (right - left) / 2;
        println!("Current l-m-r index: {}-{}-{}", left, middle, right);

        if array[middle] < target {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    if left < array.len() && array[left] == target {
        Some(left)
    } else {
        None
    }
}

fn table_search(lexicon: Vec<Vec<char>>, target_word: Vec<char>) -> bool{
    let mut left = 0;
    let mut right = lexicon.len();

    while left < right {
        let mid = left + (right - left) / 2;
        let mut index = 0;

        while lexicon[mid][index] == target_word[index] && target_word[index] != '\0'{
            index += 1;
        }

        if index < target_word.len() && lexicon[mid][index] < target_word[index] {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    if right < lexicon.len() {
        let mut index = 0;
        while lexicon[right][index] == target_word[index] && target_word[index] != '\0'{
            index += 1;
        }
        return index == target_word.len () || target_word[index] == '\0';
    }

    false
}

fn table_search_2(lexicon: Vec<Vec<char>>, target_word: Vec<char>) -> bool{
    let mut left = 0;
    let mut right = lexicon.len();

    while left < right {
        let mid = left + (right - left) / 2;
        let matched_index = lexicon[mid].iter()
            .zip(&target_word)
            .take_while(|&(a, b)| a == b && *b != '\0')
            .count();
        
        if matched_index < target_word.len() && lexicon[mid][matched_index] < target_word[matched_index]{
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    if right < lexicon.len(){
        let matched_index = lexicon[right].iter()
            .zip(&target_word)
            .take_while(|&(a, b)| a == b && *b != '\0')
            .count();

        return matched_index == target_word.len() || target_word[matched_index] == '\0';     
    }

    false
}

fn main() {
    // Linear search ----------------------------------------------------
    let mut arr = vec![10, 20, 30, 100, 50];

    let target = 110;
    match linear_sarch(&mut arr, target){
        Some(index) => println!("Element is at index{}", index),
        None => println!("Element is not preset in array"),
    }

    let target_2 = 100;
    match linear_sarch(&mut arr, target_2){
        Some(index) => println!("Element is at index {}", index),
        None => println!("Element is not preset in array"),
    }

    // Binary search ------------------------------------------------------
    let arr = [0,1,2,3,4,6,8,10];
    let x = 9;
    match binary_search_1(&arr, x){
        Some(index) => println!("Found {} at index {}", x, index),
        None => println!("{} was not found", x),
    }

    let x1 = 8;
    match binary_search_2(&arr, x1){
        Some(index) => println!("Found {} at index {}", x, index),
        None => println!("{} was not found", x),
    }
    

    // Table search --------------------------------------------------------
    let lexicon: Vec<Vec<char>> = vec![
        vec!['a','b','c','\0'],
        vec!['d','e','f','\0'],
        vec!['g','h','i','\0']
    ];
    let target_word: Vec<char> = vec!['d', 'e', 'f', '\0'];

    let is_match = table_search(lexicon.clone(), target_word.clone());
    println!("Match found: {}", is_match);

    let is_match = table_search_2(lexicon, target_word);
    println!("Match found: {}", is_match);


}
