/*
 * Implement a pseudo-encryption algorithm which given a string S and an integer N concatenates all the odd-indexed characters of S with all the even-indexed characters of S, this process should be repeated N times.
 * 
 * Examples:
 * encrypt("012345", 1)  =>  "135024"
 * encrypt("012345", 2)  =>  "135024"  ->  "304152"
 * encrypt("012345", 3)  =>  "135024"  ->  "304152"  ->  "012345"
 * 
 * encrypt("01234", 1)  =>  "13024"
 * encrypt("01234", 2)  =>  "13024"  ->  "32104"
 * encrypt("01234", 3)  =>  "13024"  ->  "32104"  ->  "20314"
 *
 * Together with the encryption function, you should also implement a decryption function which reverses the process.
 * If the string S is an empty value or the integer N is not positive, return the first argument without changes.
 */
std::string encrypt(std::string text, int n) {
    if (text.empty() || n <= 0)
        return text;

    while (n--) {
        std::string ans;
        
        for (size_t i = 1; i < text.length(); i += 2)
            ans += text[i];
            
        for (size_t i = 0; i < text.length(); i += 2)
            ans += text[i];

        text = ans;
    }
    
    return text;
}

std::string decrypt(std::string encryptedText, int n) {
    if (encryptedText.empty() || n <= 0)
        return encryptedText;

    while (n--) {
        std::string ans(encryptedText.length(), ' ');

        int j = 0;
        
        for (size_t i = 1; i < ans.length(); i += 2)
            ans[i] = encryptedText[j++];

        for (size_t i = 0; i < ans.length(); i += 2)
            ans[i] = encryptedText[j++];

        encryptedText = ans;
    }

    return encryptedText;
}
