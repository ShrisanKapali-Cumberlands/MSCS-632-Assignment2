// This function takes ownership of a String.
// When 's' goes out of scope, its memory will be automatically freed.
fn process_string_ownership(s: String) {
    println!("Processing string (owned): {}", s);
    // 's' is dropped here, and its memory is reclaimed.
}

// This function borrows a String. It does not take ownership.
// The caller retains ownership, and the borrowed reference must be valid
fn process_string_borrowed(s: &str) {
    println!("Processing string (borrowed): {}", s);
}

// This function creates a String and returns ownership.
fn create_string() -> String {
    let new_string = String::from("Hello World!");
    println!("Created string: {}", new_string);
    new_string // Ownership is moved out of this function
}

fn main() {
    println!("--- Assignment Part 2 : Rust Memory Management ---");

    // 1. Transfer of Ownership to my_string
    let my_string = create_string(); // my_string now owns the String
    println!("Original string owner my_string: {}", my_string);

    // After this call, my_string will no longer own the String.
    // It's moved into process_string_ownership.
    process_string_ownership(my_string);
    // println!("Attempting to use my_string after move: {}", my_string);
    // ^ This commented line if uncommented would cause a compile-time error: "borrow of moved value: `my_string`"

    println!("\n--- Demonstrating Borrowing ---");
    let another_string = String::from("Borrowing the string!");
    println!("Another string in main: {}", another_string);

    // We pass a reference (&<variable_name>) to the function.
    // main function still owns 'another_string'.
    process_string_borrowed(&another_string);
    println!(
        "After Borrow Another string : {}",
        another_string
    );

    // Rust automatically drops 'another_string' when it goes out of scope here.
    println!("--- End of Rust program ---");
}
