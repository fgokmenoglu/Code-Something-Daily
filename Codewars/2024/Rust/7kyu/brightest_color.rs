/*
 * One of the common ways of representing color is the RGB color model, 
 * in which the Red, Green, and Blue primary colors of light are added together 
 * in various ways to reproduce a broad array of colors.
 * 
 * One of the ways to determine brightness of a color is 
 * to find the value V of the alternative HSV (Hue, Saturation, Value) color model. 
 * Value is defined as the largest component of a color:
 * 
 * V = max(R,G,B)
 * You are given a list of colors in 6-digit hexidecimal notation #RRGGBB. 
 * Return the brightest of these colors!
 * 
 * For example,
 * 
 * brightest(["#001000", "#000000"]) == "#001000"
 * brightest(["#ABCDEF", "#123456"]) == "#ABCDEF"
 * If there are multiple brightest colors, return the first one:
 * 
 * brightest(["#00FF00", "#FFFF00", "#01130F"]) == "#00FF00"
 * Note that both input and output should use upper case for characters A, B, C, D, E, F.
 */
fn brightest(colors: &[String]) -> String {
    fn hex_to_int(hex: &str) -> u8 {
        u8::from_str_radix(hex, 16).unwrap()
    }

    fn brightness(color: &str) -> u8 {
        let r = hex_to_int(&color[1..3]);
        let g = hex_to_int(&color[3..5]);
        let b = hex_to_int(&color[5..7]);
        r.max(g).max(b)
    }

    let mut brightest_color = &colors[0];
    let mut max_brightness = brightness(brightest_color);

    for color in colors.iter().skip(1) {
        let current_brightness = brightness(color);
        if current_brightness > max_brightness {
            brightest_color = color;
            max_brightness = current_brightness;
        }
    }

    brightest_color.to_string()
}
