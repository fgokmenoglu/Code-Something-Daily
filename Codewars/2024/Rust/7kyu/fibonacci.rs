/*
 * Create function fib that returns n'th element of Fibonacci sequence (classic programming task).
 */
fn fib(n: u32) -> u32 {
    if n == 0 {
        return 0;
    } else if n == 1 {
        return 1;
    }

    let mut a = 0;
    let mut b = 1;
    
    for _ in 2..=n {
        let next = a + b;
        a = b;
        b = next;
    }
    b
}

// ALTERNATIVE
fn fib(n: u32) -> u32 {
    match n {
        0 => 0,
        1 => 1,
        _ => fib(n - 1) + fib(n - 2)
    }
}
