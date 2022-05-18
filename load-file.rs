use std::fs::File;
use std::io::{BufRead, BufReader};

//Func.....

//Read the file
let mut contents:Vec<String> = Vec::new();

let _file = match File::open(path.to_string()) {
    Ok(file) => {
        let reader = BufReader::new(&file);

        for ln in reader.lines() {
            let line = ln.unwrap().trim().to_string();
            if line.len() > 0 {
                contents.push(line);
            }
        }
    }

    Err(e) => {
        println!("Fatal Error!");
        println!("{}", e);
    }
};
