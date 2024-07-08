# Exam Rank 03
This exam has only 1 assignment:  get_next_line 👀, or if you're lucky, ft_printf that manages only s, d and x.

## Note
#### `ft_printf`
- ft_input：else if 後直接 return   <br>
- ft_putstr：else 後再 while   <br>
   <br>
#### `get_next_line`
只有 strjoin 以外的 str-function 都不用保護   <br>
<br>
- *get_next_line   <br>
&emsp;&emsp;buff[n] = '\0';   <br>
- *ft_strchr：很短 只有 while (*str != c)   <br>
- *check_and_return：更短  只有兩個 if、*line 沒有括弧   <br>
- *return_next_line：<br>
&emsp;&emsp;- 注意 (*line)[len] 的存在條件   <br>
&emsp;&emsp;- free 2次 *line，一次在 if (!**line)   <br>
&emsp;&emsp;- 出來 res = ft_strdup(*line);   <br>
- main   <br>
用 line 裝 get_next_line，free 完再 recall
