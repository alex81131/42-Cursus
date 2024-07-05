# Exam Rank 03
This exam has only 1 assignment:  get_next_line 👀, or if you're lucky, ft_printf that manages only s, d and x.

## Note
#### `ft_printf`
ft_input   <br>
&emsp;&emsp;else if, return   <br>
ft_putstr   <br>
&emsp;&emsp;else   <br>
&emsp;&emsp;&emsp;&emsp;while   <br>
   <br>
#### `get_next_line`
*get_next_line   <br>
&emsp;&emsp;buff[n] = '\0';   <br>
   <br>
*ft_memcpy   <br>
&emsp;&emsp;if (!dest && !src)   <br>
   <br>
*ft_strchr   <br>
&emsp;&emsp;while (*str != c)   <br>
   <br>
*check_and_return   <br>
&emsp;&emsp;if, if   <br>
   <br>
*return_next_line   <br>
&emsp;&emsp;res = ft_substr(*line, 0, i + 1);   <br>
&emsp;&emsp;next = ft_strdup(*line + i + 1);   <br>
&emsp;&emsp;if (!**line)   <br>
&emsp;&emsp;res = ft_strdup(*line);   <br>
   <br>
*ft_substr   <br>
&emsp;&emsp;ft_memcpy(res, src + start, len_res);   <br>
main   <br>
&emsp;&emsp;while (line)   <br>
&emsp;&emsp;{   <br>
&emsp;&emsp;&emsp;&emsp;printf("%s", line);   <br>
&emsp;&emsp;&emsp;&emsp;free(line);   <br>
&emsp;&emsp;&emsp;&emsp;line = get_next_line(fd);   <br>
&emsp;&emsp;}
