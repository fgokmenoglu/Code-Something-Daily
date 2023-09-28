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
std::string encrypt(std::string text, int n)
{
    if (text.empty() || n <= 0)
      return text;
  
    std::string temp = "";
    
    // std::cout << text << std::endl;
  
    for (int i = 1; i <= n; i++)
    {      
      for (unsigned long i = 0; i < text.size(); i++)
        if (i % 2 == 1)
          temp.push_back(text[i]); 
  
      for (unsigned long i = 0; i < text.size(); i++)
        if (i % 2 == 0)
          temp.push_back(text[i]);
      
      text = temp;
      // std::cout << text << std::endl;
      temp = "";
    }
  
    return text;
}

std::string decrypt(std::string encryptedText, int n)
{
    return encryptedText;
}
