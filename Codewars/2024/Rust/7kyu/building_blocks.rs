/*
 * Write a class Block that creates a block.
 *
 * Requirements
 * The constructor should take an array as an argument, 
 * this will contain 3 integers of the form [width, length, height] 
 * from which the Block should be created.
 *
 * Define these methods:
 * new -> initialize the `Block` from the provided array of u32
 * // all the methods must return a u32
 * get_width() -> width of the `Block`
 * get_length() -> length of the `Block`
 * get_height() -> height of the `Block`
 * get_volume() -> volume of the `Block`
 * get_surface_area() -> surface area of the `Block`
 *
 * Examples
 * let b = Block::new(&[2,4,6]) -> create a `Block` object with a width of `2` a length of `4` and a height of `6`
 * b.get_width() -> return 2
 * b.get_length() -> return 4
 * b.get_height() -> return 6
 * b.get_volume() -> return 48
 * b.get_surface_area() -> return 88
 * 
 * Note: no error checking is needed
 */
struct Block {
    width: u32,
    length: u32,
    height: u32,
}

impl Block {
    // Initialize the `Block` from the provided array of u32
    fn new(dimensions: &[u32; 3]) -> Block {
        Block {
            width: dimensions[0],
            length: dimensions[1],
            height: dimensions[2],
        }
    }

    // Method to get the width of the `Block`
    fn get_width(&self) -> u32 {
        self.width
    }

    // Method to get the length of the `Block`
    fn get_length(&self) -> u32 {
        self.length
    }

    // Method to get the height of the `Block`
    fn get_height(&self) -> u32 {
        self.height
    }

    // Method to calculate the volume of the `Block`
    fn get_volume(&self) -> u32 {
        self.width * self.length * self.height
    }

    // Method to calculate the surface area of the `Block`
    fn get_surface_area(&self) -> u32 {
        2 * (self.width * self.length + self.width * self.height + self.length * self.height)
    }
}
