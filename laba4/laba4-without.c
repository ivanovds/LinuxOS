#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>
 
int main(int argc, char *argv[])
{
    char buff[2048];
    //Открытие файла
    int file = open("1.txt", O_RDWR);
    int file2;
    if(file == -1){
            printf("Ошибка!");
         }
    //Вывод содержимого
    read(file, buff, 2048);
    printf("Содержимое файла:%s", buff);
    //Обнуляем буфер
    memset(buff, 0, 2048);
    printf("Введите строку, которую следует дописать в файл  ");
    //Считывание строки
    scanf("%s", buff);
    //Смещение
    if(lseek(file, 0, SEEK_SET)==-1){
    printf("lseek error");
    };
    //Запись в файл
    write(file, buff, strlen(buff));
    close(file);
    return 0; 
}
