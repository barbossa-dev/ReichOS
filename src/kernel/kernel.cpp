extern "C" void kernel_main() {
    const int screen_width = 80;
    const int screen_height = 25;
    char* video = (char*)0xb8000;

    const char* line1 = "Hello from C++ Kernel!";
    int len1 = 0;
    while (line1[len1]) len1++;
    int start_col1 = (screen_width - len1) / 2;
    int row1 = 10;

    for (int i = 0; i < len1; i++) {
        int offset = 2 * (row1 * screen_width + start_col1 + i);
        video[offset] = line1[i];
        video[offset + 1] = 0x0F;
    }

    const char* line2 = "product by barbossa";
    int len2 = 0;
    while (line2[len2]) len2++;
    int start_col2 = (screen_width - len2) / 2;
    int row2 = row1 + 1;

    for (int i = 0; i < len2; i++) {
        int offset = 2 * (row2 * screen_width + start_col2 + i);
        video[offset] = line2[i];
        video[offset + 1] = 0x08;
    }

    int bar_row = row2 + 2;
    int bar_start_col = 10;
    int bar_width = 60;
    char colors[7] = {0x0C, 0x0D, 0x0E, 0x0A, 0x0B, 0x09, 0x0F};

    while (true) {
        for (int shift = 0; shift < 7; shift++) {
            for (int i = 0; i < bar_width; i++) {
                int offset = 2 * (bar_row * screen_width + bar_start_col + i);
                video[offset] = 0xDB;
                video[offset + 1] = colors[(i + shift) % 7];
            }
            for (volatile int j = 0; j < 40000000; j++);
        }
    }
}
