fn match_numwrd(numwrd: &str) -> usize{
    match numwrd {
        "one" => panic!("test"),
        "two" => panic!("test"),
        "three" => panic!("test"),
        "four" => panic!("test"),
        "five" => panic!("test"),
        "six" => panic!("test"),
        "seven" => panic!("test"),
        "eight" => panic!("test"),
        "nine" => panic!("test"),
        _ => panic!("test"),
    }
}

fn get_lhs(buffer: &String) -> char {
    let wrd_idx = match_numwrd(buffer.as_str());
    let num_idx = buffer.find(char::is_numeric).unwrap();
    return buffer.chars().nth(std::cmp::min(wrd_idx, num_idx)).unwrap()
}

fn get_rhs(buffer: &String) -> char {
    let num_idx = buffer.chars().nth(buffer.rfind(char::is_numeric).unwrap()).unwrap();
    return num_idx
}

fn main() {
    let mut total: i64 = 0;
    let mut calval = String::with_capacity(2);
    for line in std::io::stdin().lines() {
        let buffer = line.expect("Shit");
        calval.push(get_lhs(&buffer));
        calval.push(get_rhs(&buffer));
        println!("{}", calval);
        total += calval.parse::<i64>().unwrap();
        calval.clear()
    }
    println!("Total: {}", total)
}
