fn straight_insertion(array: &mut [i32]){
    for i in 1..array.len(){
        let x = array[i];
        let mut j = i;
        while j > 0 && x < array[j - 1]{
            array[j] = array[j - 1];
            j -= 1;
        }
        array[j] = x;
    }
}

fn binary_insertion(array: &mut [i32]){
    for i in 1..array.len(){
        let x = array[i];
        let mut left = 0;
        let mut right = i;
        while left < right{
            let mid = left + (right - left) / 2;
            if array[mid] <= x {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        for j in (right+1..=i).rev() {
            array[j] = array[j - 1];
        }
        array[right] = x;
    }
}


fn main() {
    let mut array_to_sort = vec![5, 2, 4, 6, 1, 3];
    straight_insertion(&mut array_to_sort);
    println!("Straight insertion / After sorting {:?}", array_to_sort);

    let mut array_to_sort2 = vec![50, 20, 40, 60, 10, 30];
    binary_insertion(&mut array_to_sort2);
    println!("Binary insertion / After sorting {:?}", array_to_sort);


}
