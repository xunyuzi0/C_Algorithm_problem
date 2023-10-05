#include <stdio.h>
#include <string.h>

void DeleteCopy(char str[], int m, int t) {
    int s = strlen(str); // 获取字符串长度
    if (m >= s || t >= (s - m)) {
        printf("Invalid input.\n");
        return;
    }
    
    // 计算删除后的字符串长度
    int newLength = s - t;
    
    // 删除子串
    for (int i = m; i < s - t; i++) {
        str[i] = str[i+t];
    }
    
    // 将删除后的结果复制到数组末尾
    for (int i = s; i < s + t; i++) {
        str[i] = str[i - newLength];
    }
    
    // 添加字符串结束符
    str[newLength] = '\0';
    
    printf("Result: %s\n", str);
}

