unsigned int binary_to_uint(const char *b)
{
 unsigned int result = 0;
 int i = 0;
 while (b[i] != '\0')
 if (b[i] == '1')
 result = result * 2 + 1;
 else if (b[i] == '0')
 result *= 2;
 else
 return (0);
 i++;
 }
 return (result);
}
