#include <stdio.h>

// 1. List out all variables for non-ptr values
int a = 3;
int b = 17;

// 2. List out all variables for pointers
int *pa = &a;
int *pb = &b;
int **ppa = &pa;
int **ppb = &pb;

// 3. Set to number of non-ptr values
int numOrigVals = 2;
// 4. Set to number of pointers
int numOrigPtrs = 4;

// 5. Set to original string representations of each non-ptr variable
char *origValueReps[] = {"a", "b"};
// 6. Set to original string representations of each pointer variable
char *origPtrValReps[] = {"pa", "pb", "ppa", "ppb"};

// 7. Set to original value of each pointer variable
void *origPtrVals[] = {&a, &b, &pa, &pb};

// Returns the original representation as a string
char* oRep(void* newVal) {
    char* paRep = "error";
    for(int i = 0; i < numOrigPtrs; i++){
        if(newVal == origPtrVals[i]){
            return origPtrValReps[i];
        }
    }
    return paRep;
}

// Prints out all the variables in their string representation form
void printVars(int *valueVars[], void* ptrVars[]) {
    // Print out non-ptr variables first
    for(int i = 0; i < numOrigVals; i++){
        printf("%s = %d, ", origValueReps[i], *valueVars[i]);
    }
    // Then print out pointer variables
    for(int i = 0; i < numOrigPtrs; i++){
        if(i == numOrigPtrs - 1){
            printf("%s = %s\n", origPtrValReps[i], oRep(*(void**)ptrVars[i]));
        }else{
            printf("%s = %s, ", origPtrValReps[i], oRep(*(void**)ptrVars[i]));
        }
    }
}

int main() {

    //8. Add all non-ptr value variables to this list
    int *valueVars[] = {&a, &b};
    //9. Add all ptr variables to this list
    void *ptrVars[] = {&pa, &pb, &ppa, &ppb};

    printf("Originally:\n");
    printVars(valueVars, ptrVars);

    //10. Write code that actually happens here!
    *ppb = &a;
    *pa = 13;
    **ppa = b + 3;
    *ppa = *ppb;
    pa = &b;
    (**ppb)++;
    **ppa = a;

    printf("Afterwards:\n");
    printVars(valueVars, ptrVars);
}
