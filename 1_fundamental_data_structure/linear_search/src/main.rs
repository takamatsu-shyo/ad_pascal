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

fn main() {
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


}
