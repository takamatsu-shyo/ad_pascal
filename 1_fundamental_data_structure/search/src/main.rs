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

fn main() {
    // Linear search
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

    // Binary search 1
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
}
