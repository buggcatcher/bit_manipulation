#include<unistd.h>
#include<stdio.h>

unsigned char swap_bits(unsigned char octet)
{
    unsigned char shift_right = octet >> 4;
    unsigned char shift_left = octet << 4;
    unsigned char swapped_bits = shift_right + shift_left;
    return swapped_bits;
}

unsigned char reverse_bits(unsigned char octet)
{
    int i = 8;               
    unsigned char res = 0;          
    while (i > 0)                  
    {   
        res = res << 1;             
        res += octet % 2;          
        octet = octet >> 1;         
        i--;                      
    }
    return res;                    
}

void print_bits(unsigned char octet)
{
    char bits[8];
    int i = 7; 
    while (i >= 0)
    {
        bits[i] = (octet % 2) + '0'; 
        octet /= 2;                  
        i--;                         
    }
    write(1, bits, 8);             
}

int main(void)
{
    unsigned char octet = 0b00101010; // senza virolette + 0b 
    write(1, "Original: ", 10);
    print_bits(octet);
    write(1, "\n", 1);

    unsigned char reversed = reverse_bits(octet);
    write(1, "Reversed: ", 10);
    print_bits(reversed);
    write(1, "\n", 1);

    unsigned char swapped = swap_bits(octet);
    write(1, "Swapped:  ", 10);
    print_bits(swapped);
    write(1, "\n", 1);
    
    return 0;
}
