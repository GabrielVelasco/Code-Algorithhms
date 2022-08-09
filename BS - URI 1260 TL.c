#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXS 10500

/*
    char str[30] = { 0 }; initialize str with length 0
*/

typedef struct tree{
    char name[35];
    float val;

}tree;

tree arrTree[MAXS];
char treeName[35] = { 0 }, buf;

int compare(const void *p1, const void *p2){
    tree a = *(tree*)p1, 
          b = *(tree*)p2;

    return strcmp(a.name, b.name);
}

void insertionSort(int len){
    int i, j;
    char key[35];

    for (i = 1; i < len; i++) { 
        strcpy(key, arrTree[i].name);
        j = i - 1; 
 
        while (j >= 0 && (strcmp(arrTree[j].name, key) > 0) ){ 
            strcpy(arrTree[j+1].name, arrTree[j].name);
            j --; 
        } 
        strcpy(arrTree[j+1].name, key);
    } 
}

int binSearch(int len){
    insertionSort(len); 

    int l = 0, r = len - 1, mid;
    while(l <= r){
        mid = (l + (r-l)/2);

        if(strcmp(arrTree[mid].name, treeName) == 0){ // found
            return mid;
        }else if(strcmp(arrTree[mid].name, treeName) < 0){ // arrTree[mid].name < targetName
            l = mid + 1;
        }else{ // arrTree[mid].name > targetName
            r = mid - 1;
        }
    }

    return -1;
}

int main(){
    int t, ch = false; scanf("%d", &t);
    scanf("%c%[^\n]", &buf, treeName); // read buffer and than empty line
    while(t--){
        if(ch)  printf("\n");
        int len = 0, count = 0, index = 0;
        while(true){
            scanf("%c%[^\n]", &buf, treeName);
            if(!strlen(treeName))   break; // end of test case if str length == 0
            count ++;
            index = binSearch(len); // finds if tree already exists at arrTree
            if(index != -1){
                arrTree[index].val ++; // count one more for this especific tree
            }else{
                strcpy(arrTree[len].name, treeName); 
                arrTree[len].val ++;
                len ++;
            }
            memset(treeName, 0, sizeof(treeName));
        }

        insertionSort(len);
        for(int i = 0; i < len; i++){
            float q = arrTree[i].val;
            float value2 = (100.00/count)*q;
            printf("%s %.4f\n", arrTree[i].name, value2);
        }
        memset(arrTree, 0, sizeof(arrTree));
        ch = true;
    }

    return 0;
}