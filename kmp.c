// Implementing KMP algorithm

#include<stdio.h>
#include<conio.h>

combineTwoStrings(char s1[], int m, char s2[], int n, char s[]) {
     int i,j;
    // put s1 in s
    for(i=0,j=0;i<m;i++) {
        s[j++] = s1[i];
    }
    // put $ in s
    s[j++] = '$';
    //put s2 in s
    for(i=0;i<n;i++) {
        s[j++] = s2[i];
    }
}

computePrefixFunction(char s[], char lps[], int len) {
    int border =0;
    lps[0] = 0;
    int i;
    for(i=1; i<len; i++) {
        while(border >0 && s[i] != s[border]) {
            border = lps[border-1];
        }
        if(s[i] == s[border]) {
            border = border + 1;
        }
        else {
            border = 0;
        }
        lps[i] = border;
    }
}

kmp(char pat[],int m, char text[], int n) {
    char s[m+n+1];
    char lps[m+n+1];
    int i;
    // concatenate pat and text in s, with a $ in between
    combineTwoStrings(pat,m, text, n, s);
    // compute prefix function of s
    computePrefixFunction(s, lps, m+n+1);
    // start from text position in lps and check if lps[i] == M. ==> print i-2M
    for(i=m+1; i< m+n+1; i++) {
            if(lps[i] == m)
                printf("\nPatter occurs at position %d in text\n", i-2*m);
    }
}

int main() {
    int m, n;
    
    printf("Enter length of pattern : ");
    scanf("%d", &m);
    char pat[m];
    printf("\nEnter the pattern : ");
    scanf("%s", pat);
    
    printf("\nEnter the length of text : ");
    scanf("%d", &n);
    char text[n];
    printf("\nEnter the text : ");
    scanf("%s", text);

    kmp(pat, m, text, n);
    getch();
    return 0;
}
