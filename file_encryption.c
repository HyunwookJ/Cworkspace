#include <stdio.h>

// 간단한 XOR 암호화 함수
void encryptFile(FILE* inputFile, FILE* outputFile, char key) {
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        ch = ch ^ key; // XOR 연산으로 암호화
        fputc(ch, outputFile);
    }
}

// 파일 복호화 함수
void decryptFile(FILE* encryptedFile, FILE* decryptedFile, char key) {
    encryptFile(encryptedFile, decryptedFile, key); // XOR 연산으로 복호화
}

int main() {
    char inputFilepath[100];
    char encryptedFilepath[100];
    char decryptedFilepath[100];
    char key;

    // 입력 파일 경로 및 키 입력
    printf("원본 파일 경로를 입력하세요: ");
    scanf("%s", inputFilepath);

    printf("암호화된 파일 경로를 입력하세요: ");
    scanf("%s", encryptedFilepath);

    printf("복호화된 파일 경로를 입력하세요: ");
    scanf("%s", decryptedFilepath);

    printf("암호화 키를 입력하세요 (한 글자): ");
    scanf(" %c", &key);

    // 파일 암호화
    FILE* inputFile = fopen(inputFilepath, "rb");
    FILE* encryptedFile = fopen(encryptedFilepath, "wb");
    encryptFile(inputFile, encryptedFile, key);
    fclose(inputFile);
    fclose(encryptedFile);
    printf("파일이 성공적으로 암호화되었습니다.\n");

    // 파일 복호화
    encryptedFile = fopen(encryptedFilepath, "rb");
    FILE* decryptedFile = fopen(decryptedFilepath, "wb");
    decryptFile(encryptedFile, decryptedFile, key);
    fclose(encryptedFile);
    fclose(decryptedFile);
    printf("파일이 성공적으로 복호화되었습니다.\n");

    return 0;
}
