#include <iostream>
#include <string>
#include <gfucn.hpp>

int main(){
    unsigned char actionBlock[4][4] = {};
    unsigned char keyBlocks[15][4][4] = {};
    std::string inputText = "", secretKey;
   
    
    // Taking user input
    std::cout<<"Enter your input";
    // std::cin>>inputText;

    // Taking user key
    std::cout<<"Enter your key";
    // std::cin>>secretKey;
    secretKey = "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824";

    std:: cout<<"Sec key: "<<secretKey<<std::endl;
    // Storing the secret key in buffers
    unsigned char* secretKeyBuffers = hex2dec(secretKey);


    // Converting the secert key to binary format
    int secretKeyIndex = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            keyBlocks[0][j][i] = secretKeyBuffers[secretKeyIndex++];
        }
    }

    // Since its 256 bit encryption so other of provided secret key is continued
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            keyBlocks[1][j][i] = secretKeyBuffers[secretKeyIndex++];
        }
    }
    // Driving the other keys
    for(int i=2; i<15; i++){
        unsigned char* gfuncValue = gFunc(keyBlocks[i-1][3], i-2);
        for(int j=0; j<4; j++)
            keyBlocks[i][0][j] =  gfuncValue[j] ^ keyBlocks[i-1][0][j];

        for(int j=0; j<4; j++)
            keyBlocks[i][1][j] = keyBlocks[i-1][1][j] ^ keyBlocks[i][0][j];

        for(int j=0; j<4; j++)
            keyBlocks[i][2][j] = keyBlocks[i-1][2][j] ^ keyBlocks[i][1][j];

        for(int j=0; j<4; j++)
            keyBlocks[i][3][j] = keyBlocks[i-1][3][j] ^ keyBlocks[i][2][j];
        
    }

    // Printing all keys 
    for(int i=0; i<15; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                printf("%d ", keyBlocks[i][j][k]);
                printf(" | ");
            }
            std::cout<<"\n"<<std::endl;
        }
        std::cout<<"\n\n";
        printf("\n");
        printf("\n");
        printf("\n");

    }
    
    
    return 0;
}