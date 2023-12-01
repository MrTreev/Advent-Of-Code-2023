fn main() {
    let mut total: i64 = 0;
    let mut calval = String::with_capacity(2);
    for line in std::io::stdin().lines() {
        let buffer = line.expect("Shit");
        calval.push(buffer.chars().nth(buffer.find(char::is_numeric).unwrap()).unwrap());
        calval.push(buffer.chars().nth(buffer.rfind(char::is_numeric).unwrap()).unwrap());
        println!("{}", calval);
        total += calval.parse::<i64>().unwrap();
        calval.clear()
    }
    println!("Total: {}", total)
}
