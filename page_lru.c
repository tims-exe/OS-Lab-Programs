#include<stdio.h>

int check(int n, int f, int x, int rs[n], int m[f]){
    int flag[f], min_index;
    for (int i = 0; i < f; i++){
		flag[i] = 0;
	}
    while (x >= 0) {
        for (int i = 0; i < f; i++) {
            if (rs[x] == m[i] && flag[i] == 0) {
                min_index = i;
                flag[i] = 1;
                break;
            }
        }
        x--;
    }
    return min_index;
}

void main() {
    int n, f, ptr = 0, pf = 0;

    printf("Enter length of reference string : ");
    scanf("%d", &n);

    int rs[n], flag[n];
    
    printf("Enter the reference string : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0;
    }

    printf("Enter number of frames : ");
    scanf("%d", &f);
    int m[f];

    for (int i = 0; i < f; i++) {
        m[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;
                printf("\t%d:  ------\n", rs[i]);
            }
        }
        if (flag[i] == 0) {
            if (i >= f) {
                ptr = check(n, f, i, rs, m);
            }
            m[ptr] = rs[i];
            ptr = (ptr+1)%f;
            flag[i] = 1;
            pf++;
            printf("\t%d:  ", rs[i]);
			for (int k = 0; k < f; k++){
				printf("%d\t", m[k]);
			}
			printf("\tPF : %d", pf);  
			printf("\n");
        }
    }
    printf("\nNumber of Page Faults : %d\n", pf);
}




//1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6