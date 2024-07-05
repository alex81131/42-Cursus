# Exam Rank 03
This exam has only 1 assignment:  get_next_line 👀, or if you're lucky, ft_printf that manages only s, d and x.

## Note
### `ft_printf`
ft_input   <br>
	else if, return   <br>
ft_putstr   <br>
	else   <br>
		while   <br>
   <br>
### `get_next_line`
*get_next_line   <br>
	buff[n] = '\0';   <br>
   <br>
*ft_memcpy   <br>
	if (!dest && !src)   <br>
   <br>
*ft_strchr   <br>
	while (*str != c)   <br>
   <br>
*check_and_return   <br>
	if, if   <br>
   <br>
*return_next_line   <br>
	res = ft_substr(*line, 0, i + 1);   <br>
	next = ft_strdup(*line + i + 1);   <br>
	if (!**line)   <br>
	res = ft_strdup(*line);   <br>
   <br>
*ft_substr   <br>
      ft_memcpy(res, src + start, len_res);   <br>
main   <br>
	while (line)   <br>
	{   <br>
		printf("%s", line);   <br>
		free(line);
		line = get_next_line(fd);
	}
