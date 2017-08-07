const int max_buffer_size = 1048576; // 1 Megabyte
char buffer[max_buffer_size];
char* maxChar = buffer;
char* curChar = buffer;

inline char get_next_char() {
    if (curChar == maxChar) {
        int read = fread(buffer, 1, max_buffer_size, stdin);
        maxChar = buffer + read;
        curChar = buffer;
    }
    return *(curChar++);
}

int get_next_int(){
    char c;
    do
        c = get_next_char();
    while ((c < '0' || c > '9') && (c != '-'));

    int sign = 1;
    if (c == '-') {
        sign = -1;
        c = get_next_char();
    }

    int number = 0;
    do {
        number = (number * 10) + (c - '0');
        c = get_next_char();
    } while (c >= '0' && c <= '9');

    return number * sign;
}