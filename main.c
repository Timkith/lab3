#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "stack.h"
#include "wkfile.h"

int main(int argc, char *argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (argc != 3)
    {
        printf("�������� ���������� ����������. �����������: %s --file <���_�����>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "--file") != 0)
    {
        printf("�������� ��������: %s. ��������� --file\n", argv[1]);
        return 1;
    }

    obj *stack = NULL;
    FILE *file = fopen(argv[2], "r");
    if (file == NULL)
    {
        printf("������ �������� �����\n");
        return 1;
    }

    int number;
    while (fscanf(file, "%d", &number) == 1)
    {
        add_el(&stack, &stack, number);
    }
    fclose(file)


    printf("���������� ����� ����� ������ �� �����:\n");
    print_els(stack);

    sort_stack(&stack);

    printf("���������� ����� ����� ����������:\n");
    print_els(stack);

    append_stack_rows_to_file(argv[2], stack);

    del_els(&stack, &stack);
    printf("�s��� ������.\n");

    return 0;
}
