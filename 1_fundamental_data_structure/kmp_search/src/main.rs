fn compute_lps_array(pattern: &[char]) -> Vec<usize> {
    let mut lps = vec![0; pattern.len()];
    let mut len = 0;
    let mut i = 1;

    while i < pattern.len() {
        if pattern[i] == pattern[len]{
            len += 1;
            lps[i] = len;
            i += 1;
        } else if len > 0 {
            len = lps[len - 1];
        } else {
            lps[i] = 0;
            i += 1;
        }
    }
    lps
}

fn kmp_search(pattern: &[char], text: &[char]){
    let lps = compute_lps_array(pattern);
    for element in &lps {
        print!("{} ", element);
    }

    let mut i = 0;
    let mut j = 0;
    while i < text.len() {
        println!("{} {}", i, j);

        if text[i] == pattern[j]{
            i += 1;
            j += 1;
        }

        if j == pattern.len() {
            println!("Pattern found at index {}", i - j);
            j = lps[j - 1];
        } else if i < text.len() && text[i] != pattern[j] {
            if j != 0 {
                j = lps[j - 1];
            } else {
                i += 1;
            }
        }
    }
}

fn main() {
    //let text: Vec<char> = "ABABDABACDABABCABAB".chars().collect();
    //let pattern: Vec<char> = "ABABCABAB".chars().collect();

    let text: Vec<char> = "ABCDEFA".chars().collect();
    let pattern: Vec<char> = "ABCDEA".chars().collect();
    kmp_search(&pattern, &text);
}
