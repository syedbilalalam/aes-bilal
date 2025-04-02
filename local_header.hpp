#include <iostream>
#include <string>
// // Circlular left shift (This function is written by ChatGPT);
// unsigned int circularLeftShift(unsigned int num, int shift) {
//     // Assuming the size of unsigned int is 32 bits
//     unsigned int numOfBits = sizeof(num) * 8;  // Get the number of bits (e.g., 32 for 32-bit unsigned int)
    
//     // Perform the shift
//     return (num << shift) | (num >> (numOfBits - shift));
// }

// Only works with unsigned values
unsigned long long str2dec64bit(std::string strText){

    const size_t stringLength = strText.length();
    unsigned long long outputData = 0;
    unsigned long long tenthValue = 1;

    for(int i=(stringLength-1); i>=0; i--){
        std::cout<<(tenthValue)<<std::endl;
        if(strText[i] < 48 || strText[i] > 57 )
            break;
        outputData += (strText[i]-48)*tenthValue;
        tenthValue *=10;
    }
    return outputData;
}

unsigned int str2dec(std::string strText){

    const size_t stringLength = strText.length();
    unsigned int outputData = 0;
    unsigned int tenthValue = 1;

    for(int i=(stringLength-1); i>=0; i--){
        std::cout<<(tenthValue)<<std::endl;
        if(strText[i] < 48 || strText[i] > 57 )
            break;
        outputData += (strText[i]-48)*tenthValue;
        tenthValue *=10;
    }
    return outputData;
}

// Only works with unsigned ints
unsigned char* hex2dec(std::string hexString){
    const size_t inputStringLength = hexString.length();
    if(inputStringLength%2)
        return NULL;

    const unsigned char hexPreDefineValues[2][16] = {
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'},
        {0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
    };
    static unsigned char* outputArr = new unsigned char[inputStringLength];
    int count = 0;
    for(int i=0; i<inputStringLength; i+=2){
        int finalDecByte = 0;
        for(int j=0; j< 16; j++){
            if(hexPreDefineValues[0][j] == hexString[i]){
                finalDecByte += (16*hexPreDefineValues[1][j]);
            }
            if(hexPreDefineValues[0][j] == hexString[i+1]){
                finalDecByte += (hexPreDefineValues[1][j]);
            }
        }
        outputArr[i/2] = finalDecByte;
    }
    return outputArr;
}