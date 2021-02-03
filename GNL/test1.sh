cc -Wall -Werror -Wextra -fsanitize=address main.c get_next_line.c -o get_next_line
./get_next_line < file.txt > result.txt
cat result.txt | cat -e > result_nl.txt
cat file.txt | cat -e > real_result.txt
diff result_nl.txt real_result.txt > diff.txt
if [ -s diff.txt ]
then
	echo "There are mistakes ! Check diff.txt and result_nl.txt (This is the result from your gnl)"
else
	echo "YOU SUCCEED ! Good job !"
	rm -rf diff.txt result_nl.txt
fi
rm result.txt  real_result.txt get_next_line
