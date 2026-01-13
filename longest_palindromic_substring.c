void expand(char *s, int left, int right, int *start, int *maxLen) {
    int n = strlen(s);

    while (left >= 0 && right < n && s[left] == s[right]) {
        int len = right - left + 1;
        if (len > *maxLen) {
            *maxLen = len;
            *start = left;
        }
        left--;
        right++;
    }
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        expand(s, i, i, &start, &maxLen);
        expand(s, i, i + 1, &start, &maxLen);
    }

    static char result[1001];
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}
