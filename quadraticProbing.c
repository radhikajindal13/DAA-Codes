#include<stdio.h>
#include<stdbool.h>

// Size of Hash Table
#define SIZE 10

int hashTable[SIZE], c1, c2;

// Initialize the Hash Table with Invalid Value : -1
void init(){
    for (int i = 0;i < SIZE;i++){
        hashTable[i] = -1;
    }
}

// Display the Hash Table
void displayHashTable(){
    for (int i = 0;i < SIZE;i++){
        printf("| %d ", hashTable[i]);
    }
    printf("|\n");
}

// Insert Key in Table
/*
 * Formula: h(k, i) = [h'(k) + c1*i + c2*i*i] mod m
 * where, m = Size of Hash Table
 *        h'(k) = key mod m
 *        c1, c2 = Constants
 *        mod = % Operator
*/
void insertQuad(int key){
    int index = 0, m = SIZE;
    int hKey = key%m;
    for(int i = 0;i < SIZE;i++){
        index = (hKey + i*c1 + i*i*c2)%m;
        if (hashTable[index] == -1){
            hashTable[index] = key;
            return;
        }
    }
    printf("Key Cannot be Placed in Hash Table!\n");
}

// Search for Key
int searchQuad(int toFind){
    int index = 0, m = SIZE;
    int hKey = toFind%m;
    for (int i = 0;i < SIZE;i++){
        index = (hKey + i*c1 + i*i*c2)%m;
        if (hashTable[index] == toFind){
            return index;
        }
        else if (hashTable[index] == -1){
            return -1;
        }
    }
    return -1;
}

// Delete a Key
void deleteQuad(int toDelete){
    int index = searchQuad(toDelete);
    if (index == -1){
        printf("%d is not Present in the Hash Table, Cannot be Deleted!\n", toDelete);
    }
    else{
        hashTable[index] = -1;
    }
}

// Quadratic Probing
void quadraticProbing(){
    int choice, flag = -1;
    printf("Value of c1 and c2 Constants: ");
    scanf("%d %d", &c1, &c2);
    while(true){
        printf("1. Insert\t 2. Delete\t 3. Search\t 4. Display\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int key;
                printf("Insert Key to Insert: ");
                scanf("%d", &key);
                insertQuad(key);
                break;
            }
            case 2:{
                int toDelete;
                printf("Which Value to Delete: ");
                scanf("%d", &toDelete);
                deleteQuad(toDelete);
                break;
            }
            case 3:{
                int toFind;
                printf("Which Value to Find: ");
                scanf("%d", &toFind);
                int index = searchQuad(toFind);
                if(index == -1){
                    printf("Element Does not Exist in the Hash Table.\n");
                }
                else{
                    printf("%d is Present at %d Index in Hash Table.\n", toFind, index);
                }
                break;
            }
            case 4:{
                displayHashTable();
                break;
            }
            default:{
                flag = 1;
            }
        }
        if (flag == 1){
            break;
        }
        printf("\n");
    }
}

// The Main Function
int main(void){
    init();
    quadraticProbing();
    return 0;
}