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

fn shaker_sort(a: &mut [i32]){
    let mut k;
    let mut l = 0;
    let mut r = a.len() - 2;

    loop {
        k = r;
        for j in (l..=r).rev() {
            if a[j] > a[j+1] {
                a.swap(j, j+1);
                k = j;
            }
        }
        l = k + 1;
        if l > r { break; }

        k = 1;
        for j in l..=r {
            if a[j] > a[j+1] {
                a.swap(j, j+1);
                k = j;
            }
        }
        r = k - 1;
        if l > r { break; }
    }
}


fn main() {
    let mut array_to_sort = vec![5, 2, 4, 6, 1, 3];
    straight_insertion(&mut array_to_sort);
    println!("Straight insertion / After sorting {:?}", array_to_sort);

    let mut array_to_sort2 = vec![50, 20, 40, 60, 10, 30];
    binary_insertion(&mut array_to_sort2);
    println!("Binary insertion / After sorting {:?}", array_to_sort2);

    let mut array_to_sort3 = vec![53, 23, 43, 63, 13, 33];
    shaker_sort(&mut array_to_sort3);
    println!("Shaker sort / After sorting {:?}", array_to_sort3);

}
