#include <string.h>
#include <stdio.h>


void *
ft_memcpy (void *dest, const void *src, size_t len)
{
  char *d = dest;
  const char *s = src;

  if ( !dest && !src)
	  return (dest);
  while (len--)
    *d++ = *s++;
  return dest;
}

void run_mem(void)
{
	char src[] =   "1234567890+-*/";
	char overlap_src[sizeof(src)];


    // Test 2: Overlapping Regions
	    strcpy(overlap_src,src);
    memcpy(0, 0, 5); // Copy "Hello" into "llo"
    printf("Test 2: Overlapping Regions memcpy   : %s\n", memcpy(NULL, NULL, 5)); // Expect "HeHello, World!"

    // Reset the string for the next test
	    strcpy(overlap_src,src);
    memmove(overlap_src + 2, overlap_src, 5); // Copy "Hello" into "llo"
    printf("Test 2: Overlapping Regions memmove  : %s\n", memmove(NULL, NULL, 5)); // Expect "HeHello, World!"
	    
	strcpy(overlap_src,src);
    ft_memcpy(overlap_src + 2, overlap_src, 5); // Copy "Hello" into "llo"
    printf("Test 2: Overlapping Regions ft_memcpy: %s\n", ft_memcpy(NULL, NULL, 5)); // Expect "HeHello, World!"
}

int main()
{
	run_mem();
}
