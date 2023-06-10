const ASCII_SIZE: usize = 128;

fn create_shift_table(pattern: &str) -> [usize; ASCII_SIZE]{
    let pattern_len = pattern.len();
    let mut shift_table = [pattern_len; ASCII_SIZE];

    for (index, char) in pattern.chars().enumerate().take(pattern_len - 1){
        let shift = pattern_len - index - 1;
        shift_table[char as u8 as usize] = shift;
    }

    shift_table
}

fn bm_search(text: &str, pattern: &str) -> Option<usize>{
    let pattern_len = pattern.chars().count();
    let shift_table = create_shift_table(pattern);

    for index in 32..ASCII_SIZE {
        print!("{}", index as u8 as char);
    }
    println!("");
    for index in 32..ASCII_SIZE {
        print!("{}", shift_table[index]);
    }
    println!("");
 
    let mut char_indices = text.char_indices();

    let mut skip_offset = 0;
    while let Some((start, _)) = char_indices.nth(skip_offset + pattern_len - 1 - 1){
        skip_offset = 0;
        let text_fragment = &text[start..];
        println!("Current text fragment: {}",text_fragment);

        for (pattern_char, (index, text_char)) in pattern.chars().rev().zip(text_fragment.chars().enumerate()){
            println!("{}-{}", pattern_char, text_char); 
            if pattern_char != text_char{ 
                let skip = shift_table.get(text_char as u8 as usize).unwrap_or(&pattern_len);
                println!("{}", skip);
                skip_offset = *skip + index;
                //for _ in 0..skip.saturating_sub(1){
                //    if char_indices.next().is_none() {
                //        break;
                //    }
                //}
                break;
            } else if index == 0{
                return Some(start);
            }
        }
    }
    None
}

fn main() {
    let text    = "Hoola-Hoola girls like Hooligans.";
    let pattern = "Hooligan";

    match bm_search(text, pattern){
        Some(position) => println!("Pattern found at position {}.", position),
        None => println!("Pattern not found"),
    }
}
