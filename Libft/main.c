/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:20:52 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/26 16:16:05 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int test_ft_isalpha(void)
{
    int cases[] = {'A', 'z', '5', 'b', ' ', '0', '\n', EOF};
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        if (isalpha(cases[i]) != ft_isalpha(cases[i]))
        {
            printf("ft_isalpha(%c / %d) -> FAILED! : expected -> %d, got -> %d\n", 
                cases[i], cases[i], isalpha(cases[i]), ft_isalpha(cases[i]));
            return 0;
        }
    }
    printf("ft_isalpha -> PASSED!\n");
    return 1;
}

int test_ft_isdigit(void)
{
    int cases[] = {'A', 'z', '5', 'b', ' ', '0', '\n', EOF};
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        if (isdigit(cases[i]) != ft_isdigit(cases[i]))
        {
            printf("ft_isdigit(%c / %d) -> FAILED! : expected -> %d, got -> %d\n", 
                cases[i], cases[i], isdigit(cases[i]), ft_isdigit(cases[i]));
            return 0;
        }
    }
    printf("ft_isdigit -> PASSED!\n");
    return 1;
}

int test_ft_isalnum(void)
{
    int cases[] = {'A', 'z', '5', 'b', ' ', '0', '\n', EOF};
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        if (isalnum(cases[i]) != ft_isalnum(cases[i]))
        {
            printf("ft_isalnum(%c / %d) -> FAILED! : expected -> %d, got -> %d\n", 
                cases[i], cases[i], isalnum(cases[i]), ft_isalnum(cases[i]));
            return 0;
        }
    }
    printf("ft_isalnum -> PASSED!\n");
    return 1;
}

void run_memcpy_tests(void)
{
    char source[] = "Hello, World!";
    char overlap_src[] = "Hello, World!";
    char dest_std[20]; // For standard memcpy
    char dest_ft[20];  // For your ft_memcpy

    // Test 1: Basic Copy
    memcpy(dest_std, source, strlen(source) + 1); // +1 to include null terminator
    ft_memcpy(dest_ft, source, strlen(source) + 1);
    if (strcmp(dest_std, dest_ft) == 0)
    {
        printf("Test 1: Basic Copy: PASS\n");
    }
    else
    {
        printf("Test 1: Basic Copy: FAIL\n");
        printf("Expected: %s\n", dest_std);
        printf("Got: %s\n", dest_ft);
    }

    // Test 2: Overlapping Regions
    ft_memcpy(overlap_src + 2, overlap_src, 5); // Copy "Hello" into "llo"
    printf("Test 2: Overlapping Regions ft_memcpy: %s\n", overlap_src); // Expect "HeHello, World!"

    // Reset the string for the next test
    strcpy(overlap_src, "Hello, World!");
    memcpy(overlap_src + 2, overlap_src, 5); // Copy "Hello" into "llo"
    printf("Test 2: Overlapping Regions std memcpy: %s\n", overlap_src); // Expect "HeHello, World!"

    // Test 4: Edge Case (0 bytes)
    memcpy(dest_std, source, 0);
    ft_memcpy(dest_ft, source, 0);
    if (strcmp(dest_std, dest_ft) == 0)
    {
        printf("Test 4: Copy 0 bytes: PASS\n");
    }
    else
    {
        printf("Test 4: Copy 0 bytes: FAIL\n");
    }
}

int main(void)
{
    printf("<---------- Output --------->\n\n");
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    run_memcpy_tests();
    
    return 0;
}

