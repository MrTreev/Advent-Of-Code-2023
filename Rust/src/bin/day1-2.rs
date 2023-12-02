fn match_numwrd(numwrd: &str) -> Option<usize>{
    let wrdidx = numwrd.len();
    if numwrd.find("one")? < wrdidx{ Some(1) }
    else if numwrd.find("two")? < wrdidx{ Some(2) }
    else if numwrd.find("three")? < wrdidx{ Some(3) }
    else if numwrd.find("four")? < wrdidx{ Some(4) }
    else if numwrd.find("five")? < wrdidx{ Some(5) }
    else if numwrd.find("six")? < wrdidx{ Some(6) }
    else if numwrd.find("seven")? < wrdidx{ Some(7) }
    else if numwrd.find("eight")? < wrdidx{ Some(8) }
    else if numwrd.find("nine")? < wrdidx{ Some(9) }
    else {None}
}

fn rmatch_numwrd(numwrd: &str) -> Option<usize>{
    let wrdidx = 0;
    if numwrd.find("one")? < wrdidx{ Some(1) }
    else if numwrd.rfind("two")? > wrdidx{ Some(2) }
    else if numwrd.rfind("three")? > wrdidx{ Some(3) }
    else if numwrd.rfind("four")? > wrdidx{ Some(4) }
    else if numwrd.rfind("five")? > wrdidx{ Some(5) }
    else if numwrd.rfind("six")? > wrdidx{ Some(6) }
    else if numwrd.rfind("seven")? > wrdidx{ Some(7) }
    else if numwrd.rfind("eight")? > wrdidx{ Some(8) }
    else if numwrd.rfind("nine")? > wrdidx{ Some(9) }
    else {None}
}

fn get_lhs(buffer: &String) -> Option<char> {
    let idx;
    let num_idx = buffer.find(char::is_numeric).unwrap();
    let wrd_idx = match_numwrd(buffer.as_str());
    if wrd_idx.is_none(){idx = num_idx;}
    else {idx = std::cmp::min(wrd_idx?, num_idx);}
    Some(buffer.chars().nth(idx).unwrap())
}

fn get_rhs(buffer: &String) -> Option<char> {
    let idx;
    let num_idx = buffer.rfind(char::is_numeric).unwrap();
    let wrd_idx = rmatch_numwrd(buffer.as_str());
    if wrd_idx.is_none(){idx = num_idx;}
    else {idx = std::cmp::max(wrd_idx?, num_idx);}
    Some(buffer.chars().nth(idx).unwrap())
}

fn main() -> Result<(), std::io::ErrorKind> {
    let mut total: i64 = 0;
    let mut calval = String::with_capacity(2);
    for line in std::io::stdin().lines() {
        let buffer = line.expect("Shit");
        calval.push(get_lhs(&buffer).ok_or(std::io::ErrorKind::InvalidData)?);
        calval.push(get_rhs(&buffer).ok_or(std::io::ErrorKind::InvalidData)?);
        println!("{}", calval);
        total += calval.parse::<i64>().unwrap();
        calval.clear();
    }
    println!("Total: {}", total);
    return Ok(())
}
