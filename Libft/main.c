/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:20:52 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/27 15:51:56 by abdnasse         ###   ########.fr       */
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
	char s[] = "Hello, World!";
	char d[] = "Hello, World!";

    	ft_memcpy(s + 6, s, 5);
    	printf("memcpy  ft_: %s\n", s);

    	memcpy(d + 6, d, 5);
  	printf("memcpy  std: %s\n", d);

}

int test_ft_memmove(void)
{
	char s[] = "Hello, World!";
	char d[] = "Hello, World!";
	
	memmove(0, 0 , 5);
	printf("memmove std: %s \n",s);
	ft_memmove(d + 6, s , 5);
	printf("memmove ft_: %s \n", d);
	return 1;
}

int main(void)
{
    printf("<---------- Output --------->\n\n");
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    run_memcpy_tests();
    test_ft_memmove();

    return 0;
}

