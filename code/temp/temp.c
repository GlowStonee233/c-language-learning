#include <stdio.h>
#include <stdbool.h>
#define MAX_LENGTH 1000
void read_stdin(char buffer[], int max_size);
void print_stdout(const char buffer[]); 
int main() {
    char user_input[MAX_LENGTH]; 
    printf("Please enter your input. You can input up to %d characters.\n", MAX_LENGTH - 1);
    read_stdin(user_input, MAX_LENGTH);    
    printf("\nRead successfully!\n");
    printf("If you want to print your input, please enter 1: ");
    int choice = 0;    
    if (scanf("%d", &choice) == 1) 
    {
        if (choice == 1) 
        {
            printf("\nYour input was:\n");
            print_stdout(user_input); // 将数组传递给打印函数   
        }
    } else 
    {
        printf("Invalid input for choice.\n");
    }
    printf("\nProgram finished.\n");
    return 0;
}
void read_stdin(char buffer[], int max_size) 
{
    int i = 0;
    int c; 
    while (i < max_size - 1 && (c = getchar()) != EOF && c != '\n') 
    {
        buffer[i] = (char)c;
        i++;
    }
    buffer[i] = '\0'; 
}
void print_stdout(const char buffer[]) 
{
    int i = 0;
    while (buffer[i] != '\0') 
    {
        putchar(buffer[i]);   
        i++;
    }
    putchar('\n');   
}