#include <stdio.h>

// 1. List out all variables for non-ptr values
int a = 24;
int b = 4;
double c = -1.1;
double d = 5.4;
char e[] = "turtle";
char f = 'o';

// 2. List out all variables for pointers
int *pa = &a;
int *pb = &b;
double *pc = &c;
double *pd = &d;
char *pf = &f;
double **ppc = &pc;
double **ppd = &pd;
char **ppf = &pf;

// 3. Set to number of non-ptr values
int numOrigVals = 6;
// 4. Set to number of pointers and strings
int numOrigPtrs = 9;

// 5. Set to original string representations of each non-ptr variable
char *origValueReps[] = {"a", "b", "c", "d", "e", "f"};
// 6. Set to original string representations of each pointer and string variable
char *origPtrValReps[] = {"pa", "pb", "pc", "pd", "e", "pf", "ppc", "ppd", "ppf"};

// 7. Set to original value of each pointer variable and string!
void *origPtrVals[] = {&a, &b, &c, &d, &e, &f, &pc, &pd, &pf};

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
// void printVars(void *valueVars[], void* ptrVars[]) {
//     // Print out non-ptr variables first
//     for(int i = 0; i < numOrigVals; i++){
//         printf("%s = %d, ", origValueReps[i], *valueVars[i]);
//     }
//     // Then print out pointer variables
//     for(int i = 0; i < numOrigPtrs; i++){
//         if(i == numOrigPtrs - 1){
//             printf("%s = %s\n", origPtrValReps[i], oRep(*(void**)ptrVars[i]));
//         }else{
//             printf("%s = %s, ", origPtrValReps[i], oRep(*(void**)ptrVars[i]));
//         }
//     }
// }

int main() {

    //8. Add all non-ptr value variables to this list
    void *valueVars[] = {&a, &b, &c, &d, &e, &f};
    //9. Add all ptr variables to this list
    void *ptrVars[] = {&pa, &pb, &pc, &pd, &e, &pf, &ppc, &ppd, &ppf};

    printf("Originally:\n");

    // printVars(valueVars, ptrVars);
    printf("%s = %d, ", origValueReps[0], *(int *)valueVars[0]);
    printf("%s = %d, ", origValueReps[1], *(int *)valueVars[1]);
    printf("%s = %f, ", origValueReps[2], *(double *)valueVars[2]);
    printf("%s = %f, ", origValueReps[3], *(double *)valueVars[3]);
    printf("%s = %s, ", origValueReps[4], (char *)valueVars[4]);
    printf("%s = %c, ", origValueReps[5], *(char *)valueVars[5]);

    printf("%s = %s, ", origPtrValReps[0], oRep(*(void**)ptrVars[0]));
    printf("%s = %s, ", origPtrValReps[1], oRep(*(void**)ptrVars[1]));
    printf("%s = %s, ", origPtrValReps[2], oRep(*(void**)ptrVars[2]));
    printf("%s = %s, ", origPtrValReps[3], oRep(*(void**)ptrVars[3]));
    printf("%s = %s, ", origPtrValReps[4], oRep((void*)ptrVars[4]));
    printf("%s = %s, ", origPtrValReps[5], oRep(*(void**)ptrVars[5]));
    printf("%s = %s, ", origPtrValReps[6], oRep(*(void**)ptrVars[6]));
    printf("%s = %s, ", origPtrValReps[7], oRep(*(void**)ptrVars[7]));
    printf("%s = %s, ", origPtrValReps[8], oRep(*(void**)ptrVars[8]));

    printf("\n");

    //10. Write code that actually happens here!

    *pa = 12;
    pb = &a;
    *pb *= -1;
    *ppc = pd;
    *pd = a + *pc;
    *pc = b;

    **ppf += 2;
    pf = e;
    pf[1] = 'a';
    pf[4] = '\0';


    // printVars(valueVars, ptrVars);

    printf("Afterwards:\n");
    printf("%s = %d, ", origValueReps[0], *(int *)valueVars[0]);
    printf("%s = %d, ", origValueReps[1], *(int *)valueVars[1]);
    printf("%s = %f, ", origValueReps[2], *(double *)valueVars[2]);
    printf("%s = %f, ", origValueReps[3], *(double *)valueVars[3]);
    printf("%s = %s, ", origValueReps[4], (char *)valueVars[4]);
    printf("%s = %c, ", origValueReps[5], *(char *)valueVars[5]);

    printf("%s = %s, ", origPtrValReps[0], oRep(*(void**)ptrVars[0]));
    printf("%s = %s, ", origPtrValReps[1], oRep(*(void**)ptrVars[1]));
    printf("%s = %s, ", origPtrValReps[2], oRep(*(void**)ptrVars[2]));
    printf("%s = %s, ", origPtrValReps[3], oRep(*(void**)ptrVars[3]));
    printf("%s = %s, ", origPtrValReps[4], oRep((void*)ptrVars[4]));
    printf("%s = %s, ", origPtrValReps[5], oRep(*(void**)ptrVars[5]));
    printf("%s = %s, ", origPtrValReps[6], oRep(*(void**)ptrVars[6]));
    printf("%s = %s, ", origPtrValReps[7], oRep(*(void**)ptrVars[7]));
    printf("%s = %s, ", origPtrValReps[8], oRep(*(void**)ptrVars[8]));

    printf("\n");
}
